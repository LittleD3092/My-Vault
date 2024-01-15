SELECT colors.name, COUNT(parts.part_num) AS num_parts
FROM colors
JOIN inventory_parts ON colors.id = inventory_parts.color_id
JOIN parts ON inventory_parts.part_num = parts.part_num
GROUP BY colors.name
ORDER BY num_parts DESC
LIMIT 10;