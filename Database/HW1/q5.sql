SELECT themes.name, COUNT(sets.theme_id) AS num_sets
FROM sets
JOIN themes ON sets.theme_id = themes.id
GROUP BY themes.name
ORDER BY num_sets DESC
LIMIT 1;