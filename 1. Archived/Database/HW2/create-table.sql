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