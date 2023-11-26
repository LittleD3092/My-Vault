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