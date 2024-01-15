SELECT sets.name AS sets_name, themes.name AS themes_name
FROM sets
JOIN themes ON sets.theme_id = themes.id
WHERE sets.year = 2017;