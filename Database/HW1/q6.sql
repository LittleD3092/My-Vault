SELECT themes.name, AVG(sets.num_parts) AS avg_parts
FROM sets
JOIN themes ON sets.theme_id = themes.id
GROUP BY themes.name
ORDER BY avg_parts ASC;