SELECT
    themes_name,
    colors_name,
    total_quantity
FROM(
    SELECT 
        themes.name AS themes_name, 
        colors.name AS colors_name, 
        SUM(inventory_parts.quantity) AS total_quantity,
        RANK() OVER (PARTITION BY themes.name ORDER BY SUM(inventory_parts.quantity) DESC) AS rank
    FROM inventory_parts
        JOIN colors ON inventory_parts.color_id = colors.id
        JOIN inventories ON inventory_parts.inventory_id = inventories.id
        JOIN sets ON inventories.set_num = sets.set_num
        JOIN themes ON sets.theme_id = themes.id
    GROUP BY themes.name, colors.name
) AS ranked_table
WHERE rank = 1;