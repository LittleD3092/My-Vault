-- clear the tables if they exist
DROP TABLE IF EXISTS inventory_parts;
DROP TABLE IF EXISTS inventory_sets;
DROP TABLE IF EXISTS colors;
DROP TABLE IF EXISTS inventories;
DROP TABLE IF EXISTS parts;
DROP TABLE IF EXISTS sets;
DROP TABLE IF EXISTS part_categories;
DROP TABLE IF EXISTS themes;

-- themes.csv
CREATE TABLE themes(
    id INT PRIMARY KEY,
    name VARCHAR(100),
    parent_id INT
);
\copy themes FROM './archive/themes.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM themes LIMIT 10;

-- part_categories.csv
CREATE TABLE part_categories(
    id INT PRIMARY KEY,
    name VARCHAR(100)
);
\copy part_categories FROM './archive/part_categories.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM part_categories LIMIT 10;

-- sets.csv
CREATE TABLE sets(
    set_num VARCHAR(40) PRIMARY KEY,
    name VARCHAR(100),
    year INT,
    theme_id INT,
    num_parts INT,
    FOREIGN KEY (theme_id) REFERENCES themes(id)
);
\copy sets FROM './archive/sets.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM sets LIMIT 10;

-- parts.csv
CREATE TABLE parts(
    part_num VARCHAR(40) PRIMARY KEY,
    name VARCHAR(400),
    part_cat_id INT,
    FOREIGN KEY (part_cat_id) REFERENCES part_categories(id)
);
\copy parts FROM './archive/parts.csv' DELIMITER ',' CSV HEADER;
-- insert dummy rows for missing part numbers
INSERT INTO parts (part_num) VALUES 
    ('48002'),
    ('2476'),
    ('3650'),
    ('rb00164'),
    ('2495c01'),
    ('3010pb036u'),
    ('6932'),
    ('7049'),
    ('4285'),
    ('52345'),
    ('70973c01'),
    ('4738ac01'),
    ('19807'),
    ('60364pr0003'),
    ('92355'),
    ('3680c02'),
    ('4502w');
SELECT * FROM parts LIMIT 10;

-- inventories.csv
CREATE TABLE inventories(
    id INT PRIMARY KEY,
    version INT,
    set_num VARCHAR(40),
    FOREIGN KEY (set_num) REFERENCES sets(set_num)
);
\copy inventories FROM './archive/inventories.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM inventories LIMIT 10;

-- colors.csv
CREATE TABLE colors(
    id INT PRIMARY KEY,
    name VARCHAR(60),
    rgb VARCHAR(7),
    is_trans BOOLEAN
);
\copy colors FROM './archive/colors.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM colors LIMIT 10;

-- inventory_sets.csv
CREATE TABLE inventory_sets(
    id SERIAL PRIMARY KEY,
    inventory_id INT,
    set_num VARCHAR(40),
    quantity INT,
    FOREIGN KEY (inventory_id) REFERENCES inventories(id),
    FOREIGN KEY (set_num) REFERENCES sets(set_num)
);
\copy inventory_sets (inventory_id, set_num, quantity) FROM './archive/inventory_sets.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM inventory_sets LIMIT 10;

-- inventory_parts.csv
CREATE TABLE inventory_parts(
    id SERIAL PRIMARY KEY,
    inventory_id INT,
    part_num VARCHAR(40),
    color_id INT,
    quantity INT,
    is_spare BOOLEAN,
    FOREIGN KEY (inventory_id) REFERENCES inventories(id),
    FOREIGN KEY (part_num) REFERENCES parts(part_num),
    FOREIGN KEY (color_id) REFERENCES colors(id)
);
\copy inventory_parts (inventory_id, part_num, color_id, quantity, is_spare) FROM './archive/inventory_parts.csv' DELIMITER ',' CSV HEADER;
SELECT * FROM inventory_parts LIMIT 10;