1. ER diagram with entity sets and relationship sets, with or without attributes. Add constraints if needed. (30pts) (if it is hard to include your ER diagram in the .pdf file, you can submit the diagram separately)
Ans:
(The ER diagram is submitted separately)

2. Provide print screens of the 1) AWS RDS launch page, and 2) the way you connect to the AWS RDS (PostgreSQL console tool, pgAdmin, or other IDE’s connection page, with the same IP or URL with your AWS RDS) (10pts)
Ans:
AWS RDS launch page:
![[Pasted image 20231125130450.png]]
I connect to the AWS RDS using pgAdmin:
![[Pasted image 20231125130551.png]]
The URL in the RDS database matches the URL specified in pgAdmin:
![[Pasted image 20231125130719.png]]
![[Pasted image 20231125130739.png]]
3. Please provide the schema after decomposition, of each table, and a print screen to show that the tables have been created in your database on AWS RDS. (10+10pts) 
Ans:
(The relational model is submitted separately)
```sql
CREATE TABLE country_number (
    country_number int,
    country_name varchar(128),
    PRIMARY KEY (country_name)
);
CREATE TABLE country (
    two_letter_country_code varchar(2),
    country_name varchar(128),
    PRIMARY KEY (two_letter_country_code),
    UNIQUE (country_name),
    FOREIGN KEY (country_name)
        REFERENCES country_number(country_name)
);
CREATE TABLE continent (
    continent_name varchar(128),
    continent_code varchar(2),
    PRIMARY KEY (continent_code),
    UNIQUE (continent_name)
);
CREATE TABLE region (
    region_code varchar(2),
    region_name varchar(128),
    PRIMARY KEY (region_code),
    UNIQUE (region_name)
);
CREATE TABLE country_code_3to2 (
    two_letter_country_code varchar(2),
    three_letter_country_code varchar(3),
    PRIMARY KEY (three_letter_country_code),
    FOREIGN KEY (two_letter_country_code) 
        REFERENCES country(two_letter_country_code),
    UNIQUE (two_letter_country_code)
);
CREATE TABLE country_in_continent (
    two_letter_country_code varchar(2),
    continent_code varchar(2),
    PRIMARY KEY (two_letter_country_code, continent_code),
    FOREIGN KEY (two_letter_country_code) 
        REFERENCES country(two_letter_country_code),
    FOREIGN KEY (continent_code)
        REFERENCES continent(continent_code)
);
CREATE TABLE entry (
    country_code varchar(3),
    date date,
    region_code varchar(2),
    jurisdiction varchar(128),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code)
        REFERENCES country_code_3to2(three_letter_country_code),
    FOREIGN KEY (region_code)
        REFERENCES region(region_code)
);
CREATE TABLE containment_and_closure_policies (
    country_code varchar(3),
    date date,
    c1m_school_closing numeric(3, 2),
    c1m_flag boolean,
    c2m_workplace_closing numeric(3, 2),
    c2m_flag boolean,
    c3m_cancel_public_events numeric(3, 2),
    c3m_flag boolean,
    c4m_restrictions_on_gatherings numeric(3, 2),
    c4m_flag boolean,
    c5m_close_public_transport numeric(3, 2),
    c5m_flag boolean,
    c6m_stay_at_home_requirements numeric(3, 2),
    c6m_flag boolean,
    c7m_restrictions_on_internal_movement numeric(3, 2),
    c7m_flag boolean,
    c8ev_international_travel_controls numeric(3, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE economic_policies (
    country_code varchar(3),
    date date,
    e1_income_support numeric(3, 2),
    e1_flag boolean,
    e2_debt_contract_relief numeric(3, 2),
    e3_fiscal_measures numeric(20, 2),
    e4_international_support numeric(20, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE health_system_policies (
    country_code varchar(3),
    date date,
    h1_public_information_campaigns numeric(3, 2),
    h1_flag boolean,
    h2_testing_policy numeric(3, 2),
    h3_contact_tracing numeric(3, 2),
    h4_emergency_investment_in_healthcare numeric(20, 2),
    h5_investment_in_vaccines numeric(20, 2),
    h6m_facial_coverings numeric(3, 2),
    h6m_flag boolean,
    h7_vaccination_policy numeric(3, 2),
    h7_flag boolean,
    h8m_protection_of_elderly_people numeric(3, 2),
    h8m_flag boolean,
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE miscellaneous_policies (
    country_code varchar(3),
    date date,
    m1_wildcard varchar(128),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE vaccination_policies (
    country_code varchar(3),
    date date,
    v1_vaccine_prioritization_summary int,
    v2a_vaccine_availability_summary int,
    v2b_vaccine_general_population_summary varchar(128),
    v2c_vaccine_at_risk_summary varchar(128),
    v2d_medically_clinically_vulnerable_non_elderly int,
    v2e_education int,
    v2f_frontline_workers_non_healthcare int,
    v2g_frontline_workers_healthcare int,
    v3_vaccine_financial_support_summary int,
    v4_mandatory_vaccination_summary boolean,
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE status (
    country_code varchar(3),
    date date,
    confirmed_cases int,
    confirmed_deaths int,
    majority_vaccinated varchar(2),
    population_vaccinated numeric(20, 2),
    stringency_index numeric(20, 2),
    stringency_index_for_display numeric(20, 2),
    government_response_index_average numeric(20, 2),
    government_response_index_for_display numeric(20, 2),
    containment_health_index_average numeric(20, 2),
    containment_health_index_for_display numeric(20, 2),
    economic_support_index numeric(20, 2),
    economic_support_index_for_display numeric(20, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
```
Using the following script, I created the schema above:
```sql
DROP TABLE IF EXISTS status;
DROP TABLE IF EXISTS vaccination_policies;
DROP TABLE IF EXISTS miscellaneous_policies;
DROP TABLE IF EXISTS health_system_policies;
DROP TABLE IF EXISTS economic_policies;
DROP TABLE IF EXISTS containment_and_closure_policies;
DROP TABLE IF EXISTS entry;
DROP TABLE IF EXISTS country_in_continent;
DROP TABLE IF EXISTS country_code_3to2;
DROP TABLE IF EXISTS region;
DROP TABLE IF EXISTS continent;
DROP TABLE IF EXISTS country;

CREATE TEMP TABLE temp_country_csv (
    continent_name varchar(128),
    continent_code varchar(2),
    country_name varchar(128),
    two_letter_country_code varchar(2),
    three_letter_country_code varchar(3),
    country_number int
);
\copy temp_country_csv FROM '/home/littled3092/Documents/My-Vault/Database/HW2/archive/country-and-continent-codes-list-csv.csv' DELIMITER ',' CSV HEADER;
INSERT INTO temp_country_csv (continent_name, continent_code, country_name, two_letter_country_code, three_letter_country_code, country_number)
VALUES ('Europe', 'EU', 'Kosovo', 'RK', 'RKS', 383);

CREATE TEMP TABLE temp_oxcgrt (
    country_name varchar(128),
    country_code varchar(3),
    region_name varchar(128),
    region_code varchar(2),
    jurisdiction varchar(128),
    date date,
    c1m_school_closing numeric(3, 2),
    c1m_flag boolean,
    c2m_workplace_closing numeric(3, 2),
    c2m_flag boolean,
    c3m_cancel_public_events numeric(3, 2),
    c3m_flag boolean,
    c4m_restrictions_on_gatherings numeric(3, 2),
    c4m_flag boolean,
    c5m_close_public_transport numeric(3, 2),
    c5m_flag boolean,
    c6m_stay_at_home_requirements numeric(3, 2),
    c6m_flag boolean,
    c7m_restrictions_on_internal_movement numeric(3, 2),
    c7m_flag boolean,
    c8ev_international_travel_controls numeric(3, 2),
    e1_income_support numeric(3, 2),
    e1_flag boolean,
    e2_debt_contract_relief numeric(3, 2),
    e3_fiscal_measures numeric(20, 2),
    e4_international_support numeric(20, 2),
    h1_public_information_campaigns numeric(3, 2),
    h1_flag boolean,
    h2_testing_policy numeric(3, 2),
    h3_contact_tracing numeric(3, 2),
    h4_emergency_investment_in_healthcare numeric(20, 2),
    h5_investment_in_vaccines numeric(20, 2),
    h6m_facial_coverings numeric(3, 2),
    h6m_flag boolean,
    h7_vaccination_policy numeric(3, 2),
    h7_flag boolean,
    h8m_protection_of_elderly_people numeric(3, 2),
    h8m_flag boolean,
    m1_wildcard varchar(128),
    v1_vaccine_prioritization_summary int,
    v2a_vaccine_availability_summary int,
    v2b_vaccine_general_population_summary varchar(128),
    v2c_vaccine_at_risk_summary varchar(128),
    v2d_medically_clinically_vulnerable_non_elderly int,
    v2e_education int,
    v2f_frontline_workers_non_healthcare int,
    v2g_frontline_workers_healthcare int,
    v3_vaccine_financial_support_summary int,
    v4_mandatory_vaccination_summary boolean,
    confirmed_cases int,
    confirmed_deaths int,
    majority_vaccinated varchar(2),
    population_vaccinated numeric(20, 2),
    stringency_index numeric(20, 2),
    stringency_index_for_display numeric(20, 2),
    government_response_index_average numeric(20, 2),
    government_response_index_for_display numeric(20, 2),
    containment_health_index_average numeric(20, 2),
    containment_health_index_for_display numeric(20, 2),
    economic_support_index numeric(20, 2),
    economic_support_index_for_display numeric(20, 2)
);
\copy temp_oxcgrt FROM '/home/littled3092/Documents/My-Vault/Database/HW2/archive/OxCGRT_nat_latest.csv' DELIMITER ',' CSV HEADER;

CREATE TABLE country_number (
    country_number int,
    country_name varchar(128),
    PRIMARY KEY (country_name)
);
CREATE TABLE country (
    two_letter_country_code varchar(2),
    country_name varchar(128),
    PRIMARY KEY (two_letter_country_code),
    UNIQUE (country_name),
    FOREIGN KEY (country_name)
        REFERENCES country_number(country_name)
);
CREATE TABLE continent (
    continent_name varchar(128),
    continent_code varchar(2),
    PRIMARY KEY (continent_code),
    UNIQUE (continent_name)
);
CREATE TABLE region (
    region_code varchar(2),
    region_name varchar(128),
    PRIMARY KEY (region_code),
    UNIQUE (region_name)
);
CREATE TABLE country_code_3to2 (
    two_letter_country_code varchar(2),
    three_letter_country_code varchar(3),
    PRIMARY KEY (three_letter_country_code),
    FOREIGN KEY (two_letter_country_code) 
        REFERENCES country(two_letter_country_code),
    UNIQUE (two_letter_country_code)
);
CREATE TABLE country_in_continent (
    two_letter_country_code varchar(2),
    continent_code varchar(2),
    PRIMARY KEY (two_letter_country_code, continent_code),
    FOREIGN KEY (two_letter_country_code) 
        REFERENCES country(two_letter_country_code),
    FOREIGN KEY (continent_code)
        REFERENCES continent(continent_code)
);
CREATE TABLE entry (
    country_code varchar(3),
    date date,
    region_code varchar(2),
    jurisdiction varchar(128),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code)
        REFERENCES country_code_3to2(three_letter_country_code),
    FOREIGN KEY (region_code)
        REFERENCES region(region_code)
);
CREATE TABLE containment_and_closure_policies (
    country_code varchar(3),
    date date,
    c1m_school_closing numeric(3, 2),
    c1m_flag boolean,
    c2m_workplace_closing numeric(3, 2),
    c2m_flag boolean,
    c3m_cancel_public_events numeric(3, 2),
    c3m_flag boolean,
    c4m_restrictions_on_gatherings numeric(3, 2),
    c4m_flag boolean,
    c5m_close_public_transport numeric(3, 2),
    c5m_flag boolean,
    c6m_stay_at_home_requirements numeric(3, 2),
    c6m_flag boolean,
    c7m_restrictions_on_internal_movement numeric(3, 2),
    c7m_flag boolean,
    c8ev_international_travel_controls numeric(3, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE economic_policies (
    country_code varchar(3),
    date date,
    e1_income_support numeric(3, 2),
    e1_flag boolean,
    e2_debt_contract_relief numeric(3, 2),
    e3_fiscal_measures numeric(20, 2),
    e4_international_support numeric(20, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE health_system_policies (
    country_code varchar(3),
    date date,
    h1_public_information_campaigns numeric(3, 2),
    h1_flag boolean,
    h2_testing_policy numeric(3, 2),
    h3_contact_tracing numeric(3, 2),
    h4_emergency_investment_in_healthcare numeric(20, 2),
    h5_investment_in_vaccines numeric(20, 2),
    h6m_facial_coverings numeric(3, 2),
    h6m_flag boolean,
    h7_vaccination_policy numeric(3, 2),
    h7_flag boolean,
    h8m_protection_of_elderly_people numeric(3, 2),
    h8m_flag boolean,
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE miscellaneous_policies (
    country_code varchar(3),
    date date,
    m1_wildcard varchar(128),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE vaccination_policies (
    country_code varchar(3),
    date date,
    v1_vaccine_prioritization_summary int,
    v2a_vaccine_availability_summary int,
    v2b_vaccine_general_population_summary varchar(128),
    v2c_vaccine_at_risk_summary varchar(128),
    v2d_medically_clinically_vulnerable_non_elderly int,
    v2e_education int,
    v2f_frontline_workers_non_healthcare int,
    v2g_frontline_workers_healthcare int,
    v3_vaccine_financial_support_summary int,
    v4_mandatory_vaccination_summary boolean,
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);
CREATE TABLE status (
    country_code varchar(3),
    date date,
    confirmed_cases int,
    confirmed_deaths int,
    majority_vaccinated varchar(2),
    population_vaccinated numeric(20, 2),
    stringency_index numeric(20, 2),
    stringency_index_for_display numeric(20, 2),
    government_response_index_average numeric(20, 2),
    government_response_index_for_display numeric(20, 2),
    containment_health_index_average numeric(20, 2),
    containment_health_index_for_display numeric(20, 2),
    economic_support_index numeric(20, 2),
    economic_support_index_for_display numeric(20, 2),
    PRIMARY KEY (country_code, date),
    FOREIGN KEY (country_code, date)
        REFERENCES entry(country_code, date)
);

INSERT INTO country_number (country_number, country_name)
SELECT DISTINCT country_number, country_name
FROM temp_country_csv;

INSERT INTO country (two_letter_country_code, country_name)
SELECT DISTINCT two_letter_country_code, country_name
FROM temp_country_csv;

INSERT INTO continent (continent_name, continent_code)
SELECT DISTINCT continent_name, continent_code
FROM temp_country_csv;

INSERT INTO region (region_name, region_code)
SELECT DISTINCT region_name, region_code
FROM temp_oxcgrt
WHERE region_code IS NOT NULL;

INSERT INTO country_code_3to2 (two_letter_country_code, three_letter_country_code)
SELECT DISTINCT two_letter_country_code, three_letter_country_code
FROM temp_country_csv
WHERE three_letter_country_code IS NOT NULL;

INSERT INTO country_in_continent (two_letter_country_code, continent_code)
SELECT DISTINCT two_letter_country_code, continent_code
FROM temp_country_csv;

INSERT INTO entry (country_code, date, region_code, jurisdiction)
SELECT DISTINCT country_code, date, region_code, jurisdiction
FROM temp_oxcgrt;

INSERT INTO containment_and_closure_policies (country_code, date, c1m_school_closing, c1m_flag, c2m_workplace_closing, c2m_flag, c3m_cancel_public_events, c3m_flag, c4m_restrictions_on_gatherings, c4m_flag, c5m_close_public_transport, c5m_flag, c6m_stay_at_home_requirements, c6m_flag, c7m_restrictions_on_internal_movement, c7m_flag, c8ev_international_travel_controls)
SELECT DISTINCT country_code, date, c1m_school_closing, c1m_flag, c2m_workplace_closing, c2m_flag, c3m_cancel_public_events, c3m_flag, c4m_restrictions_on_gatherings, c4m_flag, c5m_close_public_transport, c5m_flag, c6m_stay_at_home_requirements, c6m_flag, c7m_restrictions_on_internal_movement, c7m_flag, c8ev_international_travel_controls
FROM temp_oxcgrt;

INSERT INTO economic_policies (country_code, date, e1_income_support, e1_flag, e2_debt_contract_relief, e3_fiscal_measures, e4_international_support)
SELECT DISTINCT country_code, date, e1_income_support, e1_flag, e2_debt_contract_relief, e3_fiscal_measures, e4_international_support
FROM temp_oxcgrt;

INSERT INTO health_system_policies (country_code, date, h1_public_information_campaigns, h1_flag, h2_testing_policy, h3_contact_tracing, h4_emergency_investment_in_healthcare, h5_investment_in_vaccines, h6m_facial_coverings, h6m_flag, h7_vaccination_policy, h7_flag, h8m_protection_of_elderly_people, h8m_flag)
SELECT DISTINCT country_code, date, h1_public_information_campaigns, h1_flag, h2_testing_policy, h3_contact_tracing, h4_emergency_investment_in_healthcare, h5_investment_in_vaccines, h6m_facial_coverings, h6m_flag, h7_vaccination_policy, h7_flag, h8m_protection_of_elderly_people, h8m_flag
FROM temp_oxcgrt;

INSERT INTO miscellaneous_policies (country_code, date, m1_wildcard)
SELECT DISTINCT country_code, date, m1_wildcard
FROM temp_oxcgrt;

INSERT INTO vaccination_policies (country_code, date, v1_vaccine_prioritization_summary, v2a_vaccine_availability_summary, v2b_vaccine_general_population_summary, v2c_vaccine_at_risk_summary, v2d_medically_clinically_vulnerable_non_elderly, v2e_education, v2f_frontline_workers_non_healthcare, v2g_frontline_workers_healthcare, v3_vaccine_financial_support_summary, v4_mandatory_vaccination_summary)
SELECT DISTINCT country_code, date, v1_vaccine_prioritization_summary, v2a_vaccine_availability_summary, v2b_vaccine_general_population_summary, v2c_vaccine_at_risk_summary, v2d_medically_clinically_vulnerable_non_elderly, v2e_education, v2f_frontline_workers_non_healthcare, v2g_frontline_workers_healthcare, v3_vaccine_financial_support_summary, v4_mandatory_vaccination_summary
FROM temp_oxcgrt;

INSERT INTO status (country_code, date, confirmed_cases, confirmed_deaths, majority_vaccinated, population_vaccinated, stringency_index, stringency_index_for_display, government_response_index_average, government_response_index_for_display, containment_health_index_average, containment_health_index_for_display, economic_support_index, economic_support_index_for_display)
SELECT DISTINCT country_code, date, confirmed_cases, confirmed_deaths, majority_vaccinated, population_vaccinated, stringency_index, stringency_index_for_display, government_response_index_average, government_response_index_for_display, containment_health_index_average, containment_health_index_for_display, economic_support_index, economic_support_index_for_display
FROM temp_oxcgrt;

DROP TABLE IF EXISTS temp_country_csv;
DROP TABLE IF EXISTS temp_oxcgrt;
```
The result of the `\dt` command shows that the tables are created:
![[Pasted image 20231125231905.png]]
4. Clearly indicate the level of normal form, test the level of normal form for each table (10pts)
Ans:
For a table to satisfy 1NF, the table must follow the rules:
- No repeating group.
- The domains of all attributes are single value and atomic.
- A column should contain values that are the same type.
- Each column should have a unique name.
- Order in which data is saved doesn't matter.

The relations in the schema provided satisfy 1NF because of the following reasons:
- Because all tables are first separated based on their category, they satisfy the "no repeating group" rule.
- Because all tables can be created using sql, they must have single value attributes, and is atomic.
- According to the codebook, the data of a same column is of the same type.
- Checking the csv chart given, each column has a unique name.
- The only order of the chart is the date, and I included it in the `entry` table.

The relations satisfy 2NF because there are duplicate `country_code` and `date`, and the only way to identify any data is to use the composite key `country_code` and `date`. This means that there is no partial dependency.

For `containment_and_closure_policies`, `economic_policies`, `health_system_policies`, `miscellaneous_policies`, `vaccination_policies`, and `status`, the attributes have similar properties in the perspective of functional dependency. Therefore, we can prove for one attribute, and it can apply to all of the attributes.

The functional dependencies:

$$
F = \left\{
	\begin{array}{l}
		(\text{country\_code, date}) \rightarrow \text{country\_code} \\
		(\text{country\_code, date}) \rightarrow
		\text{date} \\
		(\text{country\_code, date}) \rightarrow \text{c1m}
	\end{array}
\right.
$$

The first two dependencies are trivial. In the third dependency, `(country_code, date)` is a superkey. Therefore, the tables mentioned above are 3NF. Also, they are BCNF because each `(country_code, date)` is unique.

For the `entry` table, the functional dependencies:

$$F = \left\{
	\begin{array}{l}
		\text{(country\_code, date)} \rightarrow \text{country\_code} \\
		\text{(country\_code, date)} \rightarrow \text{date} \\
		\text{(country\_code, date)} \rightarrow \text{region\_code} \\
		\text{(country\_code, date)} \rightarrow \text{jurisdiction}
	\end{array}
\right.$$

The first 2 dependencies are trivial. In the last 2 dependencies, the `(country_code, date)` key is a superkey of the table. Therefore, the `entry` table is 3NF. Also, the table is BCNF because each `(country_code, date)` is unique.

Applying similar procedure to other tables, we can see that all tables are 3NF and BCNF.

5. List the functional dependency of each table. (10pts)
Ans:
```
country_number
{
    country_name -> country_number
}

country
{
    two_letter_country_code -> country_name
}

continent
{
    continent_code -> continent_name
}

region
{
    region_code -> region_name
}

country_code_3to2
{
    three_letter_country_code -> two_letter_country_code
}

country_in_continent
{
    (two_letter_country_code, continent_code) -> 
        two_letter_country_code
    (two_letter_country_code, continent_code) -> 
        continent_code
}

entry
{
    (country_code, date) -> region_code
    (country_code, date) -> jurisdiction
}

containment_and_closure_policies
{
    (country_code, date) -> c1m_school_closing
    (country_code, date) -> c1m_flag
    (country_code, date) -> c2m_workplace_closing
    (country_code, date) -> c2m_flag
    (country_code, date) -> c3m_cancel_public_events
    (country_code, date) -> c3m_flag
    (country_code, date) -> c4m_restrictions_on_gatherings
    (country_code, date) -> c4m_flag
    (country_code, date) -> c5m_close_public_transport
    (country_code, date) -> c5m_flag
    (country_code, date) -> c6m_stay_at_home_requirements
    (country_code, date) -> c6m_flag
    (country_code, date) -> c7m_restrictions_on_internal_movement
    (country_code, date) -> c7m_flag
    (country_code, date) -> c8ev_international_travel_controls
}

economic_policies
{
    (country_code, date) -> e1_income_support
    (country_code, date) -> e1_flag
    (country_code, date) -> e2_debt_contract_relief
    (country_code, date) -> e3_fiscal_measures
    (country_code, date) -> e4_international_support
}

health_system_policies
{
    (country_code, date) -> h1_public_information_campaigns
    (country_code, date) -> h1_flag
    (country_code, date) -> h2_testing_policy
    (country_code, date) -> h3_contact_tracing
    (country_code, date) -> h4_emergency_investment_in_healthcare
    (country_code, date) -> h5_investment_in_vaccines
    (country_code, date) -> h6m_facial_coverings
    (country_code, date) -> h6m_flag
    (country_code, date) -> h7_vaccination_policy
    (country_code, date) -> h7_flag
    (country_code, date) -> h8m_protection_of_elderly_people
    (country_code, date) -> h8m_flag
}

miscellaneous_policies
{
    (country_code, date) -> m1_wildcard
}

vaccination_policies
{
    (country_code, date) -> v1_vaccine_prioritization_summary
    (country_code, date) -> v2a_vaccine_availability_summary
    (country_code, date) -> v2b_vaccine_general_population_summary
    (country_code, date) -> v2c_vaccine_at_risk_summary
    (country_code, date) -> v2d_medically_clinically_vulnerable_non_elderly
    (country_code, date) -> v2e_education
    (country_code, date) -> v2f_frontline_workers_non_healthcare
    (country_code, date) -> v2g_frontline_workers_healthcare
    (country_code, date) -> v3_vaccine_financial_support_summary
    (country_code, date) -> v4_mandatory_vaccination_summary
}

status
{
    (country_code, date) -> confirmed_cases
    (country_code, date) -> confirmed_deaths
    (country_code, date) -> majority_vaccinated
    (country_code, date) -> population_vaccinated
    (country_code, date) -> stringency_index
    (country_code, date) -> stringency_index_for_display
    (country_code, date) -> government_response_index_average
    (country_code, date) -> government_response_index_for_display
    (country_code, date) -> containment_health_index_average
    (country_code, date) -> containment_health_index_for_display
    (country_code, date) -> economic_support_index
    (country_code, date) -> economic_support_index_for_display
}
```

6. The SQL statements (in .sql file) and output results of 4a (10pts)
Ans:
The SQL statements:
```sql
WITH stringency(continent, country_name, date, stringency) AS (
    SELECT continent.continent_name, country.country_name, entry.date, status.stringency_index_for_display
    FROM entry
    JOIN status ON entry.country_code = status.country_code AND entry.date = status.date
    JOIN country_code_3to2 ON entry.country_code = country_code_3to2.three_letter_country_code
    JOIN country ON country_code_3to2.two_letter_country_code = country.two_letter_country_code
    JOIN country_in_continent ON country_code_3to2.two_letter_country_code = country_in_continent.two_letter_country_code
    JOIN continent ON country_in_continent.continent_code = continent.continent_code
    WHERE entry.date = '2020-04-01' OR entry.date = '2021-04-01' OR entry.date = '2022-04-01' OR entry.date = '2022-12-01' OR entry.date = '2023-12-01'
),
max_temp_stringency(continent, date, stringency_index) AS (
    SELECT stringency.continent AS continent, stringency.date AS date, MAX(stringency.stringency) AS stringency_index
    FROM stringency
    GROUP BY continent, date
),
max_stringency(continent, country_name, date, stringency_index) AS (
    SELECT stringency.continent AS continent, stringency.country_name AS country_name, stringency.date AS date, stringency.stringency AS stringency_index
    FROM stringency
    JOIN max_temp_stringency ON stringency.continent = max_temp_stringency.continent AND stringency.date = max_temp_stringency.date AND stringency.stringency = max_temp_stringency.stringency_index
),
min_temp_stringency(continent, date, stringency_index) AS (
    SELECT stringency.continent AS continent, stringency.date AS date, MIN(stringency.stringency) AS stringency_index
    FROM stringency
    GROUP BY continent, date
),
min_stringency(continent, country_name, date, stringency_index) AS (
    SELECT stringency.continent AS continent, stringency.country_name AS country_name, stringency.date AS date, stringency.stringency AS stringency_index
    FROM stringency
    JOIN min_temp_stringency ON stringency.continent = min_temp_stringency.continent AND stringency.date = min_temp_stringency.date AND stringency.stringency = min_temp_stringency.stringency_index
)
(SELECT *, 'max' AS max_or_min FROM max_stringency) UNION 
(SELECT *, 'min' AS max_or_min FROM min_stringency) ORDER BY max_or_min ASC, date ASC, continent ASC;
```
The output results:
```
   continent   |                country_name                 |    date    | stringency_index | max_or_min 
---------------+---------------------------------------------+------------+------------------+------------
 Africa        | Congo, Republic of the                      | 2020-04-01 |            97.22 | max
 Asia          | India, Republic of                          | 2020-04-01 |           100.00 | max
 Asia          | Georgia                                     | 2020-04-01 |           100.00 | max
 Asia          | Jordan, Hashemite Kingdom of                | 2020-04-01 |           100.00 | max
 Asia          | Sri Lanka, Democratic Socialist Republic of | 2020-04-01 |           100.00 | max
 Asia          | Philippines, Republic of the                | 2020-04-01 |           100.00 | max
 Europe        | Serbia, Republic of                         | 2020-04-01 |           100.00 | max
 Europe        | Georgia                                     | 2020-04-01 |           100.00 | max
 North America | Honduras, Republic of                       | 2020-04-01 |           100.00 | max
 Oceania       | New Zealand                                 | 2020-04-01 |            96.30 | max
 South America | Argentina, Argentine Republic               | 2020-04-01 |           100.00 | max
 Africa        | Mauritius, Republic of                      | 2021-04-01 |            96.30 | max
 Asia          | Timor-Leste, Democratic Republic of         | 2021-04-01 |            85.19 | max
 Europe        | Greece, Hellenic Republic                   | 2021-04-01 |            87.96 | max
 North America | Honduras, Republic of                       | 2021-04-01 |            82.41 | max
 Oceania       | Papua New Guinea, Independent State of      | 2021-04-01 |            62.04 | max
 South America | Venezuela, Bolivarian Republic of           | 2021-04-01 |            87.96 | max
 Africa        | Seychelles, Republic of                     | 2022-04-01 |            56.48 | max
 Asia          | Myanmar, Union of                           | 2022-04-01 |            78.70 | max
 Europe        | Ukraine                                     | 2022-04-01 |            60.16 | max
 North America | Dominica, Commonwealth of                   | 2022-04-01 |            59.41 | max
 Oceania       | Vanuatu, Republic of                        | 2022-04-01 |            85.19 | max
 South America | Suriname, Republic of                       | 2022-04-01 |            50.65 | max
 Africa        | Burundi, Republic of                        | 2020-04-01 |            13.89 | min
 Asia          | Tajikistan, Republic of                     | 2020-04-01 |            19.44 | min
 Europe        | Belarus, Republic of                        | 2020-04-01 |            12.04 | min
 North America | Nicaragua, Republic of                      | 2020-04-01 |            15.74 | min
 Oceania       | Kiribati, Republic of                       | 2020-04-01 |            40.74 | min
 South America | Guyana, Co-operative Republic of            | 2020-04-01 |            57.41 | min
 Africa        | Tanzania, United Republic of                | 2021-04-01 |             8.33 | min
 Asia          | Lao People's Democratic Republic            | 2021-04-01 |            16.67 | min
 Europe        | Russian Federation                          | 2021-04-01 |            36.57 | min
 North America | Nicaragua, Republic of                      | 2021-04-01 |            13.89 | min
 Oceania       | Kiribati, Republic of                       | 2021-04-01 |            22.22 | min
 Oceania       | New Zealand                                 | 2021-04-01 |            22.22 | min
 Oceania       | Vanuatu, Republic of                        | 2021-04-01 |            22.22 | min
 South America | Bolivia, Republic of                        | 2021-04-01 |            25.00 | min
 Africa        | Gabon, Gabonese Republic                    | 2022-04-01 |            11.11 | min
 Asia          | Mongolia                                    | 2022-04-01 |             0.00 | min
 Europe        | Andorra, Principality of                    | 2022-04-01 |             8.33 | min
 North America | Dominican Republic                          | 2022-04-01 |             8.33 | min
 North America | Nicaragua, Republic of                      | 2022-04-01 |             8.33 | min
 Oceania       | Fiji, Republic of the Fiji Islands          | 2022-04-01 |            32.42 | min
 South America | Uruguay, Eastern Republic of                | 2022-04-01 |            14.82 | min
(44 rows)
```

7. The SQL statements (in .sql file) and output results of 4b (10pts)
Ans:
The SQL statements:
```sql
WITH over_stringency_tttemp(continent, country_name, date, stringency, new_cases) AS (
    SELECT continent.continent_name, country.country_name, entry.date, status.stringency_index_for_display, 
        status.confirmed_cases - LAG(status.confirmed_cases, 1) OVER (PARTITION BY country.country_name ORDER BY status.date)
    FROM entry
    JOIN status ON entry.country_code = status.country_code AND entry.date = status.date
    JOIN country_code_3to2 ON entry.country_code = country_code_3to2.three_letter_country_code
    JOIN country ON country_code_3to2.two_letter_country_code = country.two_letter_country_code
    JOIN country_in_continent ON country_code_3to2.two_letter_country_code = country_in_continent.two_letter_country_code
    JOIN continent ON country_in_continent.continent_code = continent.continent_code
), over_stringency_ttemp(continent, country_name, date, stringency, seven_day_avg) AS (
    SELECT continent, country_name, date, stringency,
        AVG(new_cases) OVER (PARTITION BY country_name ORDER BY date ROWS BETWEEN 6 PRECEDING AND CURRENT ROW)
    FROM over_stringency_tttemp
), over_stringency_temp(continent, country_name, date, stringency, seven_day_avg) AS (
    SELECT continent, country_name, date, stringency,
        CASE WHEN seven_day_avg = 0 THEN 0.1 ELSE seven_day_avg END
    FROM over_stringency_ttemp
    WHERE date = '2020-04-01' OR date = '2021-04-01' OR date = '2022-04-01' OR date = '2022-12-01'
), over_stringency(continent, country_name, date, over_stringency_index) AS (
    SELECT over_stringency_temp.continent, over_stringency_temp.country_name, over_stringency_temp.date, over_stringency_temp.stringency / over_stringency_temp.seven_day_avg
    FROM over_stringency_temp
), over_stringency_highest_temp (continent, date, over_stringency_index) AS (
    SELECT over_stringency.continent, over_stringency.date, MAX(over_stringency.over_stringency_index)
    FROM over_stringency
    GROUP BY continent, date
), over_stringency_highest (continent, country_name, date, over_stringency_index, highest_or_lowest) AS (
    SELECT over_stringency.continent, over_stringency.country_name, over_stringency.date, over_stringency.over_stringency_index, 'highest'
    FROM over_stringency
    JOIN over_stringency_highest_temp ON over_stringency.continent = over_stringency_highest_temp.continent AND over_stringency.date = over_stringency_highest_temp.date AND over_stringency.over_stringency_index = over_stringency_highest_temp.over_stringency_index
), over_stringency_lowest_temp (continent, date, over_stringency_index) AS (
    SELECT over_stringency.continent, over_stringency.date, MIN(over_stringency.over_stringency_index)
    FROM over_stringency
    GROUP BY continent, date
), over_stringency_lowest (continent, country_name, date, over_stringency_index, highest_or_lowest) AS (
    SELECT over_stringency.continent, over_stringency.country_name, over_stringency.date, over_stringency.over_stringency_index, 'lowest'
    FROM over_stringency
    JOIN over_stringency_lowest_temp ON over_stringency.continent = over_stringency_lowest_temp.continent AND over_stringency.date = over_stringency_lowest_temp.date AND over_stringency.over_stringency_index = over_stringency_lowest_temp.over_stringency_index
)
(SELECT * FROM over_stringency_highest) UNION
(SELECT * FROM over_stringency_lowest) ORDER BY highest_or_lowest ASC, date ASC, continent ASC;
```
The output results:
```
   continent   |                 country_name                  |    date    |  over_stringency_index   | highest_or_lowest 
---------------+-----------------------------------------------+------------+--------------------------+-------------------
 Africa        | Lesotho, Kingdom of                           | 2020-04-01 |     907.4000000000000000 | highest
 Asia          | Timor-Leste, Democratic Republic of           | 2020-04-01 |     750.0000000000000000 | highest
 Europe        | Georgia                                       | 2020-04-01 |      25.9259259259259262 | highest
 North America | Belize                                        | 2020-04-01 | 525.00000000000000001050 | highest
 Oceania       | Tonga, Kingdom of                             | 2020-04-01 |     935.2000000000000000 | highest
 South America | Suriname, Republic of                         | 2020-04-01 | 249.54999999999999999626 | highest
 Africa        | Congo, Republic of the                        | 2021-04-01 |     472.2000000000000000 | highest
 Asia          | Tajikistan, Republic of                       | 2021-04-01 |     287.0000000000000000 | highest
 Europe        | Faroe Islands                                 | 2021-04-01 |     481.5000000000000000 | highest
 North America | Greenland                                     | 2021-04-01 |     370.4000000000000000 | highest
 Oceania       | Fiji, Republic of the Fiji Islands            | 2021-04-01 |     490.7000000000000000 | highest
 South America | Suriname, Republic of                         | 2021-04-01 |      13.3132432432432433 | highest
 Africa        | Guinea, Republic of                           | 2022-04-01 |     463.0000000000000000 | highest
 Asia          | Macao, Special Administrative Region of China | 2022-04-01 |     324.1000000000000000 | highest
 Europe        | Faroe Islands                                 | 2022-04-01 |     111.1000000000000000 | highest
 North America | El Salvador, Republic of                      | 2022-04-01 |     332.2000000000000000 | highest
 Oceania       | Kiribati, Republic of                         | 2022-04-01 | 106.13750000000000000027 | highest
 South America | Guyana, Co-operative Republic of              | 2022-04-01 |       5.1800000000000000 | highest
 Africa        | South Africa, Republic of                     | 2020-04-01 |   0.91761549925484351755 | lowest
 Asia          | Iran, Islamic Republic of                     | 2020-04-01 |   0.01953100699844479005 | lowest
 Europe        | Spain, Kingdom of                             | 2020-04-01 |   0.01092119480614618244 | lowest
 North America | United States of America                      | 2020-04-01 |   0.00319914241883157705 | lowest
 Oceania       | Australia, Commonwealth of                    | 2020-04-01 |   0.19979983987189751804 | lowest
 South America | Brazil, Federative Republic of                | 2020-04-01 |   0.12185427370387669313 | lowest
 Africa        | Cameroon, Republic of                         | 2021-04-01 |   0.01473706251869578223 | lowest
 Asia          | India, Republic of                            | 2021-04-01 |   0.00088742307970355701 | lowest
 Europe        | France, French Republic                       | 2021-04-01 |   0.00178579672804986114 | lowest
 North America | United States of America                      | 2021-04-01 |   0.00084979770333144797 | lowest
 Oceania       | Papua New Guinea, Independent State of        | 2021-04-01 |   0.21681477783325012478 | lowest
 South America | Brazil, Federative Republic of                | 2021-04-01 |   0.00096355922815759453 | lowest
 Africa        | Botswana, Republic of                         | 2022-04-01 |   0.00233860881277660189 | lowest
 Asia          | Mongolia                                      | 2022-04-01 |   0.00000000000000000000 | lowest
 Europe        | France, French Republic                       | 2022-04-01 |   0.00013628130182056675 | lowest
 North America | United States of America                      | 2022-04-01 |   0.00106509267319273276 | lowest
 Oceania       | Australia, Commonwealth of                    | 2022-04-01 |   0.00074588068110742504 | lowest
 South America | Brazil, Federative Republic of                | 2022-04-01 |   0.00137557483525340162 | lowest
(36 rows)
```