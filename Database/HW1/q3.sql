SELECT sets.name, themes.name
FROM sets
JOIN themes ON sets.theme_id = themes.id
WHERE sets.year = 2017;