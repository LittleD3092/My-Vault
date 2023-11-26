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