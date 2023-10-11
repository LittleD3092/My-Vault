
# Question 1

1. The process of creating the “lego” databases (can be screenshot and/or SQL/non-SQL statements with text explanation) (8pts)
    

Ans:

I changed the user to `postgres` and accessed the `psql` terminal:

```sh
# change user to `postgres`
sudo -i -u postgres

# use `psql` terminal to create database and account
psql
```

After using `psql` to access the terminal, I typed the following commands to create a data base:

```sql
-- create a database named lego
CREATE DATABASE lego;

-- use \l to list all database and confirm the creation
\l
```

And following commands to create a user and grant access to the database previously created:

```sql
-- create a user with password
CREATE USER littled3092 WITH ENCRYPTED PASSWORD 'password';

-- give access to the user
GRANT ALL PRIVILEGES ON DATABASE lego TO littled3092
GRANT ALL PRIVILEGES ON SCHEMA public TO littled3092;
GRANT pg_read_server_files TO littled3092;
```

After creating database and user, I switched back to my original account using:

```sql
-- exit `psql` terminal
\q
```

```sh
# exit account `postgres`
exit

# enter `psql` with new account
psql -U littled3092 -d lego -h localhost -W
```

---

# Question 2

2. The process of importing eight required .csv files into lego database (can be screenshot and/or SQL/non-SQL statements with text explanation). Please include/describe the data type and keys of the imported table in your screenshot, SQL statements, and explanations (32pts)
    

Ans:

I uses the following script:

```sql
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
```

The 8 tables are created separately, and each table creation contains three steps:

1. `CREATE TABLE`: Create an empty table.
2. `\copy`: Copy from a `csv` file. I originally used `COPY`, but `\copy` offers relative path, and this provides portability.
3. `SELECT`: Prints first 10 entries for me to check.

The script above contains 2 other features:

- It `DROP` tables that it is going to create. This allows me to debug and run the script multiple times.
- The `csv` file `parts.csv` does not contain all `part_num` for table `inventory_parts` to generate foreign keys. Therefore, the missing `part_num` are added manually in the script.

I used the following command to execute this script:

```sh
psql -U littled3092 -d lego -f q2.sql
```

---

# Question 3

3. The SQL statements and output results of 4a (10pts). If the SQL statements or output results are not provided, you will not get the points.
    

Ans:

The script:

```sql
SELECT sets.name AS sets_name, themes.name AS themes_name
FROM sets
JOIN themes ON sets.theme_id = themes.id
WHERE sets.year = 2017;
```

The output:

```txt
                         sets_name                         |       themes_name        
-----------------------------------------------------------+--------------------------
 Assembly Square                                           | Modular Buildings
 Carousel                                                  | Creator
 Creative Builder Box                                      | Classic
 Creative Box                                              | Classic
 Blue Creative Box                                         | Classic
 Red Creative Box                                          | Classic
 Green Creative Box                                        | Classic
 Orange Creative Box                                       | Classic
 Demolition Site                                           | Juniors
 Police Truck Chase                                        | Juniors
 Anna & Elsa's Frozen Playground                           | Juniors
 Batman vs. Mr. Freeze                                     | Juniors
 Fire Patrol Suitcase                                      | Juniors
 Mia's Farm Suitcase                                       | Juniors
 Andrea and Stephanie's Beach Holiday                      | Juniors
 Miles' Space Adventures                                   | Duplo
 My First Number Train                                     | Duplo
 My First Plane                                            | Duplo
 My First Bird                                             | Duplo
 Sydney                                                    | Skylines
 Chicago                                                   | Skylines
 London                                                    | Skylines
 Solomon R. Guggenheim Museum&reg;                         | Architecture
 The Mushroom Island                                       | Minecraft
 The Nether Railway                                        | Minecraft
 The Ice Spikes                                            | Minecraft
 The Jungle Temple                                         | Minecraft
 The Witch Hut                                             | Minecraft
 The Waterfall Base                                        | Minecraft
 LEGO Ideas NASA Apollo Saturn V                           | LEGO Ideas and CUUSOO
 Fire Car                                                  | Fire
 Police Helicopter                                         | Police
 Police Car                                                | Police
 Hot Rod                                                   | City
 Knighton Rider                                            | Nexo Knights
 Motor Horse polybag                                       | Nexo Knights
 Shrunken Headquarters                                     | Nexo Knights
 Gymnastic Bar                                             | Friends
 Emma's Pool Slide                                         | Friends
 The Milano                                                | Marvel
 Turtle                                                    | Creature
 U-Wing Fighter                                            | Star Wars Rogue One
 The Mini Batmobile                                        | Batman
 The Joker Battle Training                                 | Batman
 The Mini Batwing                                          | Batman
 Krypto Saves the Day                                      | Super Heroes
 Disco Batman - Tears of Batman                            | Batman
 R2-D2                                                     | Star Wars
 Blue Express                                              | Creator
 Red Racer                                                 | Creator
 Mighty Dinosaurs                                          | Creator
 Robo Explorer 1                                           | Creator
 Beachside Vacation                                        | Creator
 Seaplane Adventures                                       | Creator
 Park Street Townhouse                                     | Creator
 Space Shuttle Explorer                                    | Creator
 Modular Poolside Holiday                                  | Creator
 Modular Modern Home                                       | Creator
 Modular Family Villa                                      | Creator
 Turbo Track Racer                                         | Creator
 Puffin                                                    | Pick A Model
 Hedgehog Storage                                          | Friends
 Brick Calendar                                            | Gear
 Iconic Chess Set                                          | Game
 Romantic Valentine Picnic                                 | Valentine
 Easter Egg Hunt -2017                                     | Easter
 Monthly Mini Model Build January 2017 - Narwhal           | Monthly Mini Model Build
 Monthly Mini Model Build February 2017 - Raccoon          | Monthly Mini Model Build
 Monthly Mini Model Build March 2017 - Platypus            | Monthly Mini Model Build
 Monthly Mini Model Build April 2017 - Chick               | Monthly Mini Model Build
 Monthly Mini Model Build May 2017 - Racecar               | Monthly Mini Model Build
 Monthly Mini Model Build June 2017 - Dragonfly            | Monthly Mini Model Build
 Mini VW Beetle                                            | Creator
 Friends Tic-Tac-Toe                                       | Friends
 Berry's Kitchen                                           | Disney Princess
 Petite's Royal Stable                                     | Disney Princess
 Anna's Snow Adventure                                     | Disney Princess
 Elsa's Magical Ice Palace                                 | Disney Princess
 Naida's Gondola & the Goblin Thief                        | Elves
 The Capture of Sophie Jones                               | Elves
 The Goblin King's Evil Dragon                             | Elves
 Aira's Airship & the Amulet Chase                         | Elves
 Magic Rescue from the Goblin Village                      | Elves
 Batgirl Batjet Chase                                      | Super Heroes
 Super Hero High School                                    | Super Heroes
 Lashina" Tank                                             | Super Heroes
 Bumblebee Helicopter                                      | Super Heroes
 Wonder Woman Dorm                                         | Super Heroes
 Puppy Championship                                        | Friends
 Puppy Parade                                              | Friends
 Puppy Pampering                                           | Animals
 Puppy Playground                                          | Animals
 Puppy Treats & Tricks                                     | Animals
 Emma's Photo Studio                                       | Friends
 Mia's Beach Scooter                                       | Friends
 Olivia's Creative Lab                                     | Friends
 Stephanie's Friendship Cakes                              | Friends
 Andrea's Musical Duet                                     | Friends
 Heartlake Gift Delivery                                   | Friends
 Heartlake Pizzeria                                        | Friends
 Heartlake Sports Center                                   | Friends
 Heartlake Summer Pool                                     | Friends
 Stephanie's House                                         | Friends
 Batman                                                    | Brickheadz
 Batgirl                                                   | Brickheadz
 Robin                                                     | Brickheadz
 The Joker                                                 | Brickheadz
 Captain America                                           | Brickheadz
 Iron Man                                                  | Brickheadz
 Black Widow                                               | Brickheadz
 The Hulk                                                  | Brickheadz
 Captain Jack Sparrow                                      | Brickheadz
 Captain Armando Salazar                                   | Brickheadz
 Belle                                                     | Brickheadz
 Beast                                                     | Brickheadz
 Ultralight Helicopter                                     | Technic
 Stunt Bike                                                | Technic
 Stunt Truck                                               | Technic
 Roadwork Crew                                             | Technic
 Telehandler                                               | Technic
 Container Yard                                            | Technic
 BMW R 1200 GS Adventure                                   | Technic
 Technic 40 year anniversary model (42057 + 42061 + 42063) | Technic
 Ocean Explorer                                            | Technic
 RC Tracked Racer                                          | Technic
 Air Race Jet                                              | Technic
 LEGO My Travel Companion                                  | LEGO Exclusive
 Animal - Beaver                                           | Pick A Model
 Digger                                                    | Pick A Model
 ATV Arrest                                                | Police
 Police Starter Set                                        | Police
 Tow Truck Trouble                                         | Police
 High-speed Chase                                          | Police
 Mobile Command Center                                     | Police
 Bulldozer Break-In                                        | Police
 Police Station                                            | Police
 Money Transporter                                         | Police
 Auto Transport Heist                                      | Police
 Race Plane                                                | Airport
 Buggy                                                     | Traffic
 Stunt Truck                                               | City
 Fishing Boat                                              | City
 ATV Race Team                                             | Traffic
 4x4 with Catamaran                                        | City
 Pizza Van                                                 | Traffic
 Dragster Transporter                                      | City
 Sweeper & Excavator                                       | City
 Jungle Halftrack Mission                                  | Jungle
 Jungle Mobile Lab                                         | Jungle
 King's Guard Artillery                                    | Nexo Knights
 Lance's Twin Jouster                                      | Nexo Knights
 Ruina's Lock & Roller                                     | Nexo Knights
 The Three Brothers                                        | Nexo Knights
 Clay's Falcon Fighter Blaster                             | Nexo Knights
 Jestro's Headquarters                                     | Nexo Knights
 Aaron's Stone Destroyer                                   | Nexo Knights
 Lance vs. lightning                                       | Nexo Knights
 Battle Suit Clay                                          | Nexo Knights
 Battle Suit Macy                                          | Nexo Knights
 Battle Suit Aaron                                         | Nexo Knights
 Battle Suit Axl                                           | Nexo Knights
 Battle Suit Lance                                         | Nexo Knights
 Combo NEXO Powers Wave 1                                  | Nexo Knights
 The Vermillion Attack                                     | Ninjago
 Desert Lightning                                          | Ninjago
 Destiny's Shadow                                          | Ninjago
 Vermillion Invader                                        | Ninjago
 Samurai VXL                                               | Ninjago
 Dawn of Iron Doom                                         | Ninjago
 Dragon's Forge                                            | Ninjago
 The Joker Balloon Escape                                  | Batman
 Mr. Freeze Ice Attack                                     | Batman
 Catwoman Catcycle Chase                                   | Batman
 The Riddler Riddle Racer                                  | Batman
 Clayface Splat Attack                                     | Batman
 Clayface" Splat Attack                                    | Batman
 The Batmobile                                             | Batman
 LEGO® Batman Movie - The Joker™ Notorious Lowrider        | Batman
 The Joker" Notorious Lowrider                             | Batman
 Killer Croc Tail-Gator                                    | Batman
 The Scuttler                                              | Batman
 Batcave Break-in                                          | Batman
 Scarecrow" Special Delivery                               | Batman
 The Penguin™ Arctic Roller                                | Batman
 Arkham Asylum                                             | Batman
 Scarecrow" Fearful Face-off                               | Batman
 Bane" Toxic Truck Attack                                  | Batman
 Two-Face" Double Demolition                               | Batman
 The Batwing                                               | Batman
 Lobster-Lovin’ Batman™                                    | Batman
 Pink Power Batgirl™                                       | Batman
 Red Hood™                                                 | Batman
 The Eraser™                                               | Batman
 Nurse Harley Quinn™                                       | Batman
 Orca™                                                     | Batman
 Zodiac Master™                                            | Batman
 Catman™                                                   | Batman
 March Harriet™                                            | Batman
 The Calculator™                                           | Batman
 King Tut™                                                 | Batman
 Glam Metal Batman™                                        | Batman
 The Mime™                                                 | Batman
 The LEGO Batman Movie Series - Complete                   | Collectible Minifigures
 Fairy Batman™                                             | Batman
 Clan of the Cave Batman™                                  | Batman
 Vacation Batman™                                          | Batman
 Barbara Gordon™                                           | Batman
 Commissioner Gordon™                                      | Batman
 The Joker™ – Arkham Asylum                                | Batman
 Dick Grayson™                                             | Batman
 Professional Surfer                                       | Series 17 Minifigures
 Battle Dwarf                                              | Series 17 Minifigures
 Retro Spaceman                                            | Series 17 Minifigures
 Yuppie                                                    | Series 17 Minifigures
 Rocket Boy                                                | Series 17 Minifigures
 Dance Instructor                                          | Series 17 Minifigures
 Elf-Girl                                                  | Series 17 Minifigures
 Highwayman                                                | Series 17 Minifigures
 Minifigures - Series 17 - Complete 16 Sets                | Series 17 Minifigures
 LEGO Minifigures Series 17 - All Parts                    | Series 17 Minifigures
 Circus Strong Man                                         | Series 17 Minifigures
 Gourmet Chef                                              | Series 17 Minifigures
 Corn Cob Guy                                              | Series 17 Minifigures
 Veterinarian                                              | Series 17 Minifigures
 Hot Dog Man                                               | Series 17 Minifigures
 Butterfly Girl                                            | Series 17 Minifigures
 Roman Gladiator                                           | Series 17 Minifigures
 Connoisseur                                               | Series 17 Minifigures
 Silent Mary                                               | Pirates of the Caribbean
 Michael Knight and K.I.T.T. Knight Ryder Fun Pack         | Dimensions
 Snowspeeder                                               | Star Wars
 U-wing                                                    | Star Wars
 U-wing                                                    | Star Wars Rogue One
 Tie Striker Microfighter                                  | Mini
 Y-wing                                                    | Star Wars
 Krennics Imperial Shuttle Microfighter                    | Mini
 Rebel Trooper Battle Pack                                 | Star Wars Rogue One
 Imperial Trooper Battle Pack                              | Star Wars Rogue One
 First Order Transport Speeder Battle Pack                 | Star Wars Episode 8
 Bounty Hunter Speeder Bike" Battle Pack                   | Star Wars
 Yoda's Jedi Starfighter                                   | Star Wars Clone Wars
 Duel on Naboo                                             | Star Wars Episode 1
 The Phantom                                               | Star Wars Rebels
 Battle on Scarif                                          | Star Wars Rogue One
 Y-Wing Starfighter                                        | Star Wars Rogue One
 Luke's Landspeeder                                        | Star Wars Episode 4/5/6
 Desert Skiff Escape                                       | Star Wars
 A-Wing Starfighter                                        | Star Wars
 Jakku Quadjumper                                          | Star Wars
 Rathtar" Escape                                           | Star Wars Episode 7
 Republic Fighter Tank                                     | Star Wars Episode 3
 Darth Vader" Transformation                               | Planet Series 3
 Tracker I                                                 | Star Wars
 The Arrowhead                                             | Star Wars
 Jedi Starfighter" With Hyperdrive                         | Star Wars Episode 2
 Scarif Stormtrooper                                       | Star Wars
 Chirrut Îmwe                                              | Star Wars
 Baze Malbus                                               | Star Wars
 Stormtrooper" Commander                                   | Star Wars
 Scout Trooper" & Speeder Bike                             | Star Wars Episode 4/5/6
 Mercedes-AMG GT3                                          | Speed Champions
 Bugatti Chiron                                            | Speed Champions
 Scuderia Ferrari SF16-H                                   | Speed Champions
 McLaren 720S                                              | Speed Champions
 2016 Ford GT & 1966 Ford GT40                             | Speed Champions
 Ferrari FXX K & Development Center                        | Speed Champions
 MERCEDES AMG PETRONAS Formula One" Team                   | Speed Champions
 Mighty Micros: Superman™ vs. Bizarro™                     | Superman
 Mighty Micros: Batman vs. Killer Moth                     | Batman
 Mighty Micros: Wonder Woman vs. Doomsday                  | Super Heroes
 Mighty Micros: Spider-Man vs. Scorpion                    | Spider-Man
 Mighty Micros: Iron Man vs. Thanos                        | Super Heroes
 Mighty Micros: Wolverine vs. Magneto                      | Marvel
 Wonder Woman" Warrior Battle                              | Super Heroes
 Captain America Jet Pursuit                               | Marvel
 Iron Man: Detroit Steel Strikes                           | Marvel
 Hulk vs. Red Hulk                                         | Marvel
 Ravager Attack                                            | Guardians of the Galaxy
 Ayesha's Revenge                                          | Guardians of the Galaxy
 The Milano vs. The Abilisk                                | Guardians of the Galaxy
 ATM Heist Battle                                          | Marvel
 Beware the Vulture                                        | Marvel
 Elves Roblin Bag Charm                                    | Elves
 NINJAGO Accessory Set                                     | Ninjago
 Flash Speeder                                             | Star Wars
 Policeman and Crook Foil Pack                             | Police
 Bear in Ice Cave foil pack                                | Friends
 The LEGO Batman Movie: Chaos in Gotham City               | Books
 Clay and Training Stand                                   | Nexo Knights
 Robin                                                     | Nexo Knights
 Kanan Jarrus foilpack                                     | Star Wars Rebels
 The Ghost                                                 | Star Wars Rebels
 TIE Advanced foil pack                                    | Star Wars
 Vulture Droid foil pack                                   | Star Wars Episode 3
 A-Wing                                                    | Star Wars Rebels
 Wishing Well                                              | Friends
(296 rows)


```

I used the following command to execute the script:

```sh
psql -U littled3092 -d lego -f q3.sql > q3-output.txt
```

---

# Question 4

4. The SQL statements and output results of 4b (10pts)
    

Ans:

The SQL statements:

```sql
SELECT year, COUNT(*) AS num_sets
FROM sets
WHERE year BETWEEN 1950 AND 2017
GROUP BY year
ORDER BY num_sets DESC;
```

The output results:

```txt
 year | num_sets 
------+----------
 2014 |      713
 2015 |      665
 2012 |      615
 2016 |      596
 2013 |      593
 2011 |      503
 2002 |      447
 2010 |      444
 2003 |      415
 2009 |      402
 2004 |      371
 2008 |      349
 2001 |      339
 2005 |      330
 2000 |      327
 1998 |      325
 2007 |      321
 1999 |      300
 2017 |      296
 2006 |      283
 1987 |      209
 1997 |      192
 1996 |      144
 1985 |      139
 1994 |      128
 1995 |      128
 1986 |      123
 1992 |      115
 1989 |      115
 1993 |      111
 1991 |      107
 1977 |       92
 1966 |       89
 1980 |       88
 1990 |       85
 1979 |       82
 1981 |       79
 1984 |       76
 1982 |       76
 1978 |       73
 1969 |       69
 1988 |       68
 1976 |       68
 1973 |       67
 1983 |       57
 1971 |       45
 1958 |       42
 1962 |       40
 1974 |       39
 1972 |       38
 1975 |       31
 1970 |       29
 1955 |       28
 1968 |       25
 1957 |       21
 1967 |       21
 1963 |       18
 1961 |       17
 1954 |       14
 1956 |       12
 1964 |       11
 1965 |       10
 1950 |        7
 1959 |        4
 1953 |        4
 1960 |        3
(66 rows)


```

The shell command of executing the sql:

```sh
psql -U littled3092 -d lego -f q4.sql > q4-output.txt
```

---

# Question 5

5. The SQL statements and output results of 4c (10pts)
    

Ans:

The SQL statements:

```sql
SELECT themes.name, COUNT(sets.theme_id) AS num_sets
FROM sets
JOIN themes ON sets.theme_id = themes.id
GROUP BY themes.name
ORDER BY num_sets DESC
LIMIT 1;
```

The output results:

```txt
     name     | num_sets 
--------------+----------
 Supplemental |      496
(1 row)


```

The shell command:

```sh
psql -U littled3092 -d lego -f q5.sql > q5-output.txt
```

---

# Question 6

6. The SQL statements and output results of 4d (10pts)
    

Ans:

The SQL statements:

```sql
SELECT themes.name, AVG(sets.num_parts) AS avg_parts
FROM sets
JOIN themes ON sets.theme_id = themes.id
GROUP BY themes.name
ORDER BY avg_parts ASC;
```

The outputs:

```txt
             name              |        avg_parts        
-------------------------------+-------------------------
 Wooden Box Set                | -1.00000000000000000000
 Samsonite                     |  0.00000000000000000000
 Key Chain                     |  0.18181818181818181818
 Imperial Guards               |  1.00000000000000000000
 Power Functions               |      1.8823529411764706
 Control Lab                   |      2.0000000000000000
 Planet Series 1               |      3.0000000000000000
 Western                       |      3.0000000000000000
 Value Packs                   |      3.1666666666666667
 Minifig Pack                  |      3.5000000000000000
 Classic Town                  |      3.8181818181818182
 Indiana Jones                 |      4.0000000000000000
 Series 14 Minifigures         |      5.3684210526315789
 The Hobbit                    |      5.5000000000000000
 DFB Minifigures               |      5.6470588235294118
 Series 15 Minifigures         |      6.3684210526315789
 Series 16 Minifigures         |      7.1764705882352941
 Tohunga                       |      8.0000000000000000
 The Simpsons                  |      8.7894736842105263
 Series 10 Minifigures         |      9.3500000000000000
 Series 5 Minifigures          |      9.5789473684210526
 Series 9 Minifigures          |      9.5789473684210526
 The LEGO Movie Series         |      9.5789473684210526
 Series 1 Minifigures          |      9.7368421052631579
 Series 3 Minifigures          |      9.7368421052631579
 Series 2 Minifigures          |      9.7894736842105263
 Series 11 Minifigures         |      9.8421052631578947
 Advent Sub-Set                |      9.8854166666666667
 Series 4 Minifigures          |     10.0000000000000000
 Belville                      |     10.0689655172413793
 Series 13 Minifigures         |     10.1052631578947368
 Series 6 Minifigures          |     10.1052631578947368
 Series 12 Minifigures         |     10.2105263157894737
 Series 7 Minifigures          |     10.2631578947368421
 Series 8 Minifigures          |     10.2631578947368421
 Team GB                       |     11.0000000000000000
 Jumbo Bricks                  |     11.0000000000000000
 Gear                          |     11.1260162601626016
 Scala                         |     12.8461538461538462
 Series 17 Minifigures         |     12.8888888888888889
 Xalax                         |     13.0625000000000000
 Matoran of Light              |     13.1428571428571429
 Agori                         |     14.8333333333333333
 Adventurers                   |     15.0000000000000000
 The Lord of the Rings         |     17.2500000000000000
 Matoran of Mata Nui           |     18.4615384615384615
 Stars                         |     18.8333333333333333
 Ben 10                        |     19.0000000000000000
 Aquazone                      |     20.0000000000000000
 Collectible Minifigures       |     20.6875000000000000
 Bohrok                        |     20.9230769230769231
 Matoran of Voya Nui           |     21.0000000000000000
 Dinosaurs                     |     23.0714285714285714
 Turaga                        |     23.6923076923076923
 HO 1:87 Vehicles              |     24.0000000000000000
 Matoran of Metru Nui          |     24.4285714285714286
 Bohrok Va                     |     24.5454545454545455
 4 Juniors                     |     26.0000000000000000
 Service Packs                 |     26.6570247933884298
 Vahki                         |     26.7333333333333333
 Rahaga                        |     28.0000000000000000
 Books                         |     28.1052631578947368
 Basic Model                   |     28.1086956521739130
 Clikits                       |     28.4761904761904762
 Toa Metru                     |     30.9090909090909091
 Fabuland                      |     30.9518072289156627
 Toa Nuva                      |     31.3750000000000000
 Matoran of Mahri Nui          |     31.4000000000000000
 Train                         |     31.6853932584269663
 Bohrok-Kal                    |     32.5000000000000000
 Rahkshi                       |     33.4400000000000000
 Toa                           |     34.0769230769230769
 LEGO Exclusive                |     36.0000000000000000
 Piraka                        |     36.4285714285714286
 Toa Hagah                     |     36.6666666666666667
 Toa Hordika                   |     37.5000000000000000
 Toa Inika                     |     38.7500000000000000
 Animals                       |     39.0000000000000000
 Pick A Model                  |     39.2666666666666667
 Monthly Mini Model Build      |     39.2876712328767123
 Duplo                         |     39.6164383561643836
 X-Pod                         |     40.6842105263157895
 Series 4                      |     41.4615384615384615
 City                          |     41.4634146341463415
 Visorak                       |     42.0000000000000000
 Western                       |     42.5000000000000000
 Glatorian Legends             |     45.0000000000000000
 Glatorian                     |     46.2857142857142857
 Phantoka                      |     46.4285714285714286
 Barraki                       |     47.1428571428571429
 Series 6                      |     48.0000000000000000
 Studios                       |     48.7735849056603774
 Mistika                       |     49.4285714285714286
 Post Office                   |     50.4000000000000000
 Bionicle                      |     51.7536231884057971
 Soft Bricks                   |     51.8000000000000000
 RoboRiders                    |     52.1724137931034483
 Holiday                       |     52.2500000000000000
 Basketball                    |     53.0882352941176471
 Toa Mahri                     |     53.5714285714285714
 Heroes                        |     54.0909090909090909
 Throwbot Slizer               |     55.0588235294117647
 NXT                           |     55.2222222222222222
 Food & Drink                  |     55.6451612903225806
 Sports                        |     55.7500000000000000
 Planet Series 2               |     55.7500000000000000
 Constraction                  |     55.9500000000000000
 Universe                      |     56.0000000000000000
 Bulk Bricks                   |     56.5120000000000000
 Series 1                      |     58.2222222222222222
 Series 5                      |     58.3333333333333333
 Planet Series 4               |     60.5000000000000000
 Series 2                      |     61.2222222222222222
 Series 7                      |     62.8888888888888889
 Series 9                      |     63.8888888888888889
 Hero Factory                  |     64.1111111111111111
 Series 3                      |     64.4444444444444444
 Gravity Games                 |     64.8181818181818182
 Series 8                      |     65.3333333333333333
 Castle                        |     66.7209302325581395
 Fairy-Tale                    |     67.3720930232558140
 WeDo                          |     67.4166666666666667
 Pirates                       |     67.5400000000000000
 Soccer                        |     68.7352941176470588
 Easter                        |     69.4583333333333333
 Protectors                    |     69.5000000000000000
 Vehicle                       |     69.7500000000000000
 Supplemental                  |     73.8266129032258065
 Hockey                        |     74.0588235294117647
 UFO                           |     75.0526315789473684
 Disney's Mickey Mouse         |     76.3333333333333333
 Villains                      |     76.6666666666666667
 Extreme Team                  |     78.4285714285714286
 Halloween                     |     78.7857142857142857
 Island Xtreme Stunts          |     78.9230769230769231
 My Own Train                  |     81.9302325581395349
 Seasonal                      |     82.8000000000000000
 Mini                          |     82.9245283018867925
 Aquasharks                    |     83.1666666666666667
 Rock Raiders                  |     84.0000000000000000
 Insectoids                    |     84.1578947368421053
 Mission Deep Sea              |     84.7058823529411765
 Drome Racers                  |     86.5116279069767442
 Racers                        |     86.6666666666666667
 Golden Land                   |     87.6666666666666667
 Toa Okoto                     |     88.3333333333333333
 Orient Expedition             |     88.9642857142857143
 Znap                          |     89.0000000000000000
 LEGO Brand Store              |     89.1444444444444444
 Life On Mars                  |     90.4230769230769231
 Dimensions                    |     90.7931034482758621
 Valentine                     |     91.3333333333333333
 Blacktron II                  |     91.4285714285714286
 Fright Knights                |     92.5625000000000000
 Dino Island                   |     93.2631578947368421
 Spider-Man 2                  |     94.5000000000000000
 Legoland                      |     95.1250000000000000
 Ninja                         |     95.3225806451612903
 Knights Kingdom II            |     96.5072463768115942
 Minitalia                     |     98.3125000000000000
 Promotional                   |    100.0000000000000000
 Thanksgiving                  |    100.6666666666666667
 Star Wars Expanded Universe   |    102.0000000000000000
 Space Port                    |    103.1428571428571429
 Ice Planet 2002               |    106.1818181818181818
 Speedorz                      |    106.9615384615384615
 Gas Station                   |    107.2500000000000000
 Recreation                    |    107.4878048780487805
 Outback                       |    107.6000000000000000
 Desert                        |    108.3076923076923077
 Crusaders                     |    109.0000000000000000
 Legoland Parks                |    111.3043478260869565
 Legend Beasts                 |    111.6000000000000000
 Hospital                      |    114.2093023255813953
 Star Wars Episode 8           |    115.0000000000000000
 Gears                         |    115.1111111111111111
 Classic Space                 |    116.7303370786516854
 Brickheadz                    |    119.7142857142857143
 Space Police II               |    121.7500000000000000
 Space                         |    123.2173913043478261
 Technic                       |    123.4551724137931034
 Wolfpack                      |    124.6666666666666667
 Knights Kingdom I             |    125.0000000000000000
 Lion Knights                  |    127.0000000000000000
 Tiny Turbos                   |    128.5652173913043478
 Superman                      |    129.0000000000000000
 Futuron                       |    129.0526315789473684
 4.5V                          |    130.5227272727272727
 Friends                       |    130.6282527881040892
 Spyrius                       |    131.8888888888888889
 Airjitzu                      |    132.0000000000000000
 Paradisa                      |    132.0555555555555556
 Town Plan                     |    132.0750000000000000
 Playhouse                     |    132.6428571428571429
 Power Racers                  |    132.9615384615384615
 Juniors                       |    134.4545454545454545
 Res-Q                         |    134.9000000000000000
 Christmas                     |    134.9750000000000000
 Iron Man                      |    137.6000000000000000
 Boat                          |    139.0454545454545455
 Aquanauts                     |    140.5000000000000000
 12V                           |    140.6600000000000000
 Race                          |    143.1754385964912281
 Black Knights                 |    143.9285714285714286
 EV3                           |    144.0000000000000000
 Skull Spiders                 |    145.0000000000000000
 Speed Slammers                |    147.5000000000000000
 Building Set with People      |    148.5312500000000000
 Justice League                |    149.2727272727272727
 Royal Knights                 |    149.4444444444444444
 Homemaker                     |    149.6250000000000000
 Alpha Team                    |    150.3333333333333333
 Classic Basic                 |    151.7464788732394366
 Indians                       |    152.2222222222222222
 Pirates I                     |    154.9534883720930233
 Titans                        |    155.5862068965517241
 Fire                          |    158.4274809160305344
 M:Tron                        |    159.8888888888888889
 Sorcerer's Stone              |    163.1428571428571429
 Police                        |    166.8850574712643678
 Cars                          |    167.1176470588235294
 Forestmen                     |    168.0000000000000000
 Star Wars                     |    168.2464454976303318
 Nexo Knights                  |    170.2571428571428571
 Jurassic Park III             |    171.5000000000000000
 Jungle                        |    173.5833333333333333
 Station                       |    174.1500000000000000
 Arctic                        |    177.0000000000000000
 Aquaraiders I                 |    178.0000000000000000
 Warriors                      |    178.2941176470588235
 Stingrays                     |    179.0000000000000000
 X-Men                         |    179.6666666666666667
 Bricktober                    |    180.6250000000000000
 Exploriens                    |    183.5555555555555556
 Airport                       |    185.1976744186046512
 Radio Control                 |    185.4615384615384615
 Spider-Man                    |    186.4375000000000000
 Riding Cycle                  |    188.2142857142857143
 Coast Guard                   |    188.8750000000000000
 Power Miners                  |    189.8260869565217391
 Creator                       |    191.7871485943775100
 World City                    |    193.1428571428571429
 Time Cruisers                 |    193.8888888888888889
 Super Heroes                  |    197.0434782608695652
 Cowboys                       |    197.2307692307692308
 Other                         |    199.3783783783783784
 Hydronauts                    |    203.4000000000000000
 Toy Story                     |    204.5333333333333333
 Islanders                     |    205.0000000000000000
 Cargo                         |    205.7500000000000000
 Basic                         |    205.8113207547169811
 Pharaoh's Quest               |    206.8888888888888889
 Black Falcons                 |    208.0000000000000000
 Launch Command                |    208.3333333333333333
 Space Police I                |    211.3333333333333333
 Ninjago                       |    213.8952879581151832
 Imperial Soldiers             |    214.3333333333333333
 Disney Princess               |    214.9629629629629630
 Exo-Force                     |    215.8297872340425532
 Prisoner of Azkaban           |    217.7272727272727273
 Imperial Armada               |    219.0000000000000000
 Star Wars Episode 7           |    219.2631578947368421
 Disney                        |    219.5789473684210526
 Designer Sets                 |    220.0714285714285714
 Legends of Chima              |    221.0952380952380952
 Alien Conquest                |    226.6000000000000000
 Star Wars Other               |    226.7916666666666667
 Chamber of Secrets            |    227.3000000000000000
 Atlantis                      |    228.0434782608695652
 Harbor                        |    229.2608695652173913
 Game                          |    230.2363636363636364
 Marvel                        |    230.8666666666666667
 Fusion                        |    238.0000000000000000
 Advent                        |    239.3333333333333333
 Ferries                       |    240.0666666666666667
 Mission Deep Freeze           |    240.1250000000000000
 Freestyle                     |    242.5573770491803279
 Dino Attack                   |    245.2000000000000000
 Space Police III              |    246.0000000000000000
 Spybiotics                    |    246.7500000000000000
 Dark Forest                   |    249.6666666666666667
 Robot                         |    249.8000000000000000
 RoboForce                     |    250.0000000000000000
 9V                            |    250.1698113207547170
 RCX                           |    250.4827586206896552
 Expert Builder                |    252.2750000000000000
 Star Wars Episode 1           |    253.5294117647058824
 Pirates III                   |    254.7777777777777778
 Jungle Rescue                 |    259.1666666666666667
 Traffic                       |    261.2091503267973856
 Divers                        |    262.4444444444444444
 Star Wars Episode 3           |    264.1190476190476190
 Guardians of the Galaxy       |    268.0000000000000000
 Construction                  |    269.3608247422680412
 Creature                      |    270.3333333333333333
 Aquaraiders II                |    274.3333333333333333
 Fantasy Era                   |    276.2142857142857143
 Factory                       |    277.2926829268292683
 Vehicles                      |    279.0000000000000000
 Batman                        |    280.4946236559139785
 Kingdoms                      |    287.7500000000000000
 Star Wars Episode 2           |    289.1428571428571429
 Planet Series 3               |    290.0000000000000000
 Blacktron I                   |    290.5714285714285714
 Inventor                      |    291.0000000000000000
 Dino 2010                     |    292.0000000000000000
 The Battle of the Five Armies |    293.3333333333333333
 Last Crusade                  |    294.0000000000000000
 Pirates II                    |    295.4545454545454545
 World Racers                  |    296.2500000000000000
 Harry Potter                  |    297.0384615384615385
 Classic Castle                |    298.4285714285714286
 Architecture                  |    300.6440677966101695
 Competition                   |    302.6470588235294118
 The Desolation of Smaug       |    303.5000000000000000
 Scooby-Doo                    |    304.8333333333333333
 Hobby Sets                    |    305.1666666666666667
 Off-Road                      |    307.4772727272727273
 Elves                         |    308.2333333333333333
 Avengers                      |    310.0370370370370370
 The Lone Ranger               |    310.2500000000000000
 Prince of Persia              |    310.6666666666666667
 Raiders of the Lost Ark       |    311.8000000000000000
 Arctic Technic                |    312.2500000000000000
 SpongeBob SquarePants         |    312.3571428571428571
 Mars Mission                  |    313.5263157894736842
 An Unexpected Journey         |    314.2222222222222222
 Dino                          |    317.7142857142857143
 Building                      |    318.5357142857142857
 Town                          |    323.0142857142857143
 Farm                          |    323.2777777777777778
 Star Wars Rebels              |    323.3600000000000000
 Star Wars Clone Wars          |    325.0735294117647059
 Speed Champions               |    327.9130434782608696
 The Fellowship of the Ring    |    329.4000000000000000
 Teenage Mutant Ninja Turtles  |    335.0476190476190476
 Star Wars Rogue One           |    340.7857142857142857
 Classic                       |    343.0000000000000000
 Kingdom of the Crystal Skull  |    347.2500000000000000
 Unitron                       |    349.2500000000000000
 Learning                      |    354.1666666666666667
 RC Train                      |    357.8636363636363636
 Speed Racer                   |    360.2500000000000000
 Playsets                      |    361.9230769230769231
 Galaxy Squad                  |    364.0000000000000000
 Discovery                     |    364.7500000000000000
 Monster Fighters              |    369.1333333333333333
 Rahi                          |    373.2000000000000000
 Pirates of the Caribbean      |    384.5882352941176471
 Track System                  |    385.0000000000000000
 Basic Set                     |    390.6575875486381323
 The LEGO Movie                |    392.0689655172413793
 Skylines                      |    395.0000000000000000
 Angry Birds                   |    395.5000000000000000
 Vikings                       |    398.2857142857142857
 Jurassic World                |    404.5714285714285714
 Universal Building Set        |    417.3235294117647059
 Goblet of Fire                |    417.8000000000000000
 Ferrari                       |    420.1562500000000000
 Ultra Agents                  |    420.4666666666666667
 Agents                        |    429.7692307692307692
 Battle Vehicles               |    430.3333333333333333
 Temple of Doom                |    448.0000000000000000
 My Own Creation               |    454.6666666666666667
 Educational and Dacta         |    473.2424242424242424
 Minecraft                     |    508.9259259259259259
 Master Building Academy       |    539.0000000000000000
 The Return of the King        |    545.3333333333333333
 Ghostbusters                  |    552.0000000000000000
 Avatar                        |    562.0000000000000000
 Trains                        |    580.6000000000000000
 LEGO Ideas and CUUSOO         |    592.2352941176470588
 Star Wars Episode 4/5/6       |    592.5270270270270270
 Model                         |    628.5909090909090909
 Model Team                    |    683.1875000000000000
 Mindstorms                    |    708.6666666666666667
 eLAB                          |    713.0000000000000000
 Lamborghini                   |    770.0000000000000000
 Williams F1                   |    787.5000000000000000
 The Two Towers                |    869.2000000000000000
 Order of the Phoenix          |    904.0000000000000000
 FIRST LEGO League             |   1387.0000000000000000
 Ultimate Collector Series     |   1680.3333333333333333
 Sculptures                    |   1716.6956521739130435
 Mosaic                        |   1843.2500000000000000
 Modular Buildings             |   2350.5833333333333333
(386 rows)


```

The shell command to execute the script:

```sh
psql -U littled3092 -d lego -f q6.sql > q6-output.txt
```

---

# Question 7

7. The SQL statements and output results of 4e (10pts)
    

Ans:

The SQL statements:

```sql
SELECT colors.name, COUNT(parts.part_num) AS num_parts
FROM colors
JOIN inventory_parts ON colors.id = inventory_parts.color_id
JOIN parts ON inventory_parts.part_num = parts.part_num
GROUP BY colors.name
ORDER BY num_parts DESC
LIMIT 10;
```

The output results:

```txt
       name        | num_parts 
-------------------+-----------
 Black             |    115176
 White             |     66549
 Light Bluish Gray |     55317
 Red               |     50217
 Dark Bluish Gray  |     43913
 Yellow            |     38837
 Blue              |     29857
 Light Gray        |     25339
 Reddish Brown     |     14168
 Tan               |     13681
(10 rows)


```

The shell command for executing the script:

```sh
psql -U littled3092 -d lego -f q7.sql > q7-output.txt
```

---

# Question 8

8. The SQL statements and output results of 4f (10pts)
    

Ans:

The SQL statements:

```sql
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
```

The output results:

```txt
          themes_name          |    colors_name    | total_quantity 
-------------------------------+-------------------+----------------
 12V                           | Black             |           2520
 4.5V                          | Black             |           3243
 4 Juniors                     | White             |             48
 9V                            | Black             |           4122
 Advent                        | Red               |            132
 Advent Sub-Set                | Red               |            172
 Adventurers                   | Black             |              9
 Agents                        | Black             |           1391
 Agori                         | Black             |             14
 Airjitzu                      | Black             |            250
 Airport                       | White             |           7104
 Alien Conquest                | Light Bluish Gray |            497
 Alpha Team                    | Black             |            293
 Angry Birds                   | Light Bluish Gray |            559
 Animals                       | White             |            137
 An Unexpected Journey         | Reddish Brown     |            665
 Aquanauts                     | Yellow            |            469
 Aquaraiders I                 | Black             |            235
 Aquaraiders II                | Black             |            738
 Aquasharks                    | Black             |            283
 Aquazone                      | Chrome Silver     |              9
 Architecture                  | White             |           4646
 Arctic                        | Black             |            681
 Arctic Technic                | Light Gray        |            380
 Atlantis                      | Black             |           1156
 Avatar                        | Dark Bluish Gray  |            391
 Avengers                      | Black             |           1995
 Barraki                       | Black             |             85
 Basic                         | Red               |           6077
 Basic Model                   | Black             |            467
 Basic Set                     | Red               |          20235
 Basketball                    | Red               |            333
 Batman                        | Black             |           7638
 Battle Vehicles               | Black             |           1270
 Belville                      | White             |             60
 Ben 10                        | Dark Blue         |             17
 Bionicle                      | Black             |           1063
 Black Falcons                 | Light Gray        |            669
 Black Knights                 | Black             |            865
 Blacktron I                   | Black             |           1577
 Blacktron II                  | Black             |            728
 Boat                          | White             |           1176
 Bohrok                        | Black             |            115
 Bohrok-Kal                    | Light Gray        |             66
 Bohrok Va                     | Black             |            170
 Books                         | Black             |            336
 Brickheadz                    | Black             |            355
 Bricktober                    | Trans-Clear       |            243
 Building                      | White             |           2929
 Building Set with People      | Red               |           1516
 Bulk Bricks                   | Black             |           1462
 Cargo                         | Black             |           1020
 Cars                          | Black             |           1215
 Castle                        | Black             |           1244
 Chamber of Secrets            | Black             |            513
 Christmas                     | White             |           2083
 City                          | Black             |           2381
 Classic                       | White             |            756
 Classic Basic                 | Red               |           2400
 Classic Castle                | Yellow            |           1112
 Classic Space                 | Light Gray        |           3076
 Classic Town                  | Red               |              8
 Clikits                       | Trans-Dark Pink   |            533
 Coast Guard                   | White             |           1339
 Collectible Minifigures       | Yellow            |             75
 Competition                   | Black             |           3140
 Constraction                  | Black             |            332
 Construction                  | Black             |          16891
 Control Lab                   | Dark Gray         |              1
 Control Lab                   | Black             |              1
 Cowboys                       | Black             |            792
 Creator                       | White             |           7051
 Creature                      | Black             |            814
 Crusaders                     | Light Gray        |            283
 Dark Forest                   | Black             |            301
 Desert                        | Black             |            696
 Designer Sets                 | Black             |           1796
 DFB Minifigures               | White             |             47
 Dimensions                    | Black             |           1147
 Dino                          | Yellow            |            452
 Dino 2010                     | Black             |            465
 Dino Attack                   | Black             |            364
 Dino Island                   | Light Gray        |            404
 Dinosaurs                     | Light Gray        |             81
 Discovery                     | Light Gray        |            893
 Disney                        | White             |           1173
 Disney Princess               | White             |           1102
 Disney's Mickey Mouse         | Red               |            104
 Divers                        | Black             |            886
 Drome Racers                  | Black             |           1717
 Duplo                         | Red               |           1292
 Easter                        | Yellow            |            380
 Educational and Dacta         | Yellow            |           1986
 eLAB                          | Black             |            293
 Elves                         | Black             |           1015
 EV3                           | Black             |            776
 Exo-Force                     | Black             |           3373
 Expert Builder                | Light Gray        |           3311
 Exploriens                    | White             |            743
 Extreme Team                  | Black             |            525
 Fabuland                      | Yellow            |            911
 Factory                       | Black             |           2515
 Fairy-Tale                    | White             |            691
 Fantasy Era                   | Light Bluish Gray |           1593
 Farm                          | Black             |           1736
 Ferrari                       | Red               |           5255
 Ferries                       | White             |           2159
 Fire                          | Red               |           5875
 FIRST LEGO League             | Black             |           8150
 Food & Drink                  | White             |            646
 Forestmen                     | Black             |            497
 Freestyle                     | Yellow            |           3277
 Friends                       | White             |           7458
 Fright Knights                | Light Gray        |            422
 Fusion                        | Tan               |            113
 Futuron                       | White             |           1299
 Galaxy Squad                  | Black             |            774
 Game                          | Black             |           2220
 Gas Station                   | White             |            389
 Gear                          | White             |            534
 Gears                         | Red               |            454
 Ghostbusters                  | Black             |            117
 Glatorian                     | Black             |             86
 Glatorian Legends             | Black             |             91
 Goblet of Fire                | Black             |            434
 Golden Land                   | Dark Pink         |             80
 Gravity Games                 | White             |            143
 Guardians of the Galaxy       | Black             |            463
 Halloween                     | Black             |            362
 Harbor                        | Black             |           2309
 Harry Potter                  | Black             |           1578
 Heroes                        | Black             |            627
 Hero Factory                  | Black             |            412
 HO 1:87 Vehicles              | Black             |             24
 Hobby Sets                    | Black             |           1907
 Hockey                        | Black             |            421
 Holiday                       | Brown             |            114
 Homemaker                     | White             |           1532
 Hospital                      | White             |           1769
 Hydronauts                    | Black             |            325
 Ice Planet 2002               | Blue              |            337
 Imperial Armada               | Black             |            251
 Imperial Soldiers             | Black             |            397
 Indians                       | Black             |            371
 Insectoids                    | Black             |            498
 Inventor                      | Black             |            274
 Iron Man                      | Black             |            139
 Islanders                     | Black             |            386
 Island Xtreme Stunts          | Black             |            291
 Jumbo Bricks                  | Blue              |             13
 Jungle                        | Black             |            417
 Jungle Rescue                 | Reddish Brown     |            250
 Juniors                       | White             |            568
 Jurassic Park III             | Black             |             91
 Jurassic World                | Dark Bluish Gray  |            609
 Justice League                | Black             |            322
 Key Chain                     | White             |             10
 Kingdom of the Crystal Skull  | Dark Bluish Gray  |            541
 Kingdoms                      | Light Bluish Gray |           1089
 Knights Kingdom I             | Black             |            621
 Knights Kingdom II            | Black             |           1691
 Lamborghini                   | Black             |            675
 Last Crusade                  | Light Bluish Gray |            203
 Launch Command                | White             |            355
 Learning                      | White             |            428
 Legend Beasts                 | White             |            123
 Legends of Chima              | Black             |           3377
 LEGO Brand Store              | Black             |           1415
 LEGO Exclusive                | Black             |              6
 LEGO Ideas and CUUSOO         | Light Bluish Gray |           1837
 Legoland                      | White             |            199
 Legoland Parks                | Yellow            |            504
 Life On Mars                  | Light Gray        |            483
 Lion Knights                  | Light Gray        |            777
 Mars Mission                  | Black             |           1727
 Marvel                        | Black             |            605
 Master Building Academy       | Black             |           2225
 Matoran of Light              | Dark Bluish Gray  |             19
 Matoran of Mahri Nui          | Black             |             53
 Matoran of Mata Nui           | Black             |             61
 Matoran of Metru Nui          | Dark Bluish Gray  |             66
 Matoran of Voya Nui           | Black             |             34
 Mindstorms                    | Black             |            836
 Minecraft                     | Light Bluish Gray |           2303
 Mini                          | Light Bluish Gray |           1090
 Minifig Pack                  | Black             |              4
 Minitalia                     | Red               |            691
 Mission Deep Freeze           | Black             |            609
 Mission Deep Sea              | Black             |            548
 Mistika                       | Black             |             92
 Model                         | Black             |           4031
 Model Team                    | Light Gray        |           3246
 Modular Buildings             | Light Bluish Gray |           6828
 Monster Fighters              | Light Bluish Gray |           1526
 Monthly Mini Model Build      | White             |            504
 Mosaic                        | White             |           4973
 M:Tron                        | Black             |            657
 My Own Creation               | Light Gray        |            486
 My Own Train                  | Black             |           1728
 Nexo Knights                  | Black             |           2198
 Ninja                         | Black             |            917
 Ninjago                       | Black             |           9441
 NXT                           | Black             |            840
 Off-Road                      | Black             |           5894
 Order of the Phoenix          | Light Bluish Gray |            266
 Orient Expedition             | Black             |            564
 Other                         | Light Bluish Gray |           2928
 Outback                       | Light Gray        |            126
 Paradisa                      | White             |           1008
 Phantoka                      | Black             |             82
 Pharaoh's Quest               | Tan               |            409
 Pick A Model                  | Black             |            132
 Piraka                        | Black             |             64
 Pirates                       | Black             |           1272
 Pirates I                     | Black             |           2730
 Pirates II                    | Black             |            657
 Pirates III                   | Black             |            474
 Pirates of the Caribbean      | Black             |           1859
 Planet Series 2               | Light Bluish Gray |             64
 Planet Series 3               | Black             |             87
 Planet Series 4               | Black             |             42
 Playhouse                     | White             |            582
 Playsets                      | Black             |           1290
 Police                        | White             |           7571
 Post Office                   | Red               |            114
 Power Functions               | Light Bluish Gray |             19
 Power Miners                  | Black             |            990
 Power Racers                  | Black             |           2871
 Prince of Persia              | Dark Bluish Gray  |            370
 Prisoner of Azkaban           | Light Bluish Gray |            436
 Promotional                   | White             |            416
 Protectors                    | Black             |             97
 Race                          | Black             |           5890
 Racers                        | Black             |            154
 Radio Control                 | Black             |            893
 Rahaga                        | Black             |             44
 Rahi                          | Black             |            897
 Rahkshi                       | Dark Gray         |            198
 Raiders of the Lost Ark       | Dark Bluish Gray  |            359
 RC Train                      | Black             |           2402
 RCX                           | Light Gray        |           2703
 Recreation                    | White             |            884
 Res-Q                         | Black             |            519
 Riding Cycle                  | Black             |           2231
 RoboForce                     | Black             |            473
 RoboRiders                    | Black             |            756
 Robot                         | Black             |            400
 Rock Raiders                  | Black             |            317
 Royal Knights                 | Light Gray        |            476
 Scala                         | White             |             29
 Scooby-Doo                    | Light Bluish Gray |            284
 Sculptures                    | White             |           8917
 Seasonal                      | White             |            238
 Series 1                      | Black             |             97
 Series 10 Minifigures         | Black             |             26
 Series 11 Minifigures         | Black             |             30
 Series 12 Minifigures         | Black             |             26
 Series 13 Minifigures         | Black             |             24
 Series 14 Minifigures         | Black             |             31
 Series 15 Minifigures         | Black             |             27
 Series 16 Minifigures         | Black             |             43
 Series 17 Minifigures         | Black             |             61
 Series 1 Minifigures          | Black             |             31
 Series 2                      | Black             |            149
 Series 2 Minifigures          | Black             |             40
 Series 3                      | Black             |            157
 Series 3 Minifigures          | Black             |             29
 Series 4                      | Black             |            156
 Series 4 Minifigures          | Black             |             31
 Series 5                      | Black             |             91
 Series 5 Minifigures          | Black             |             30
 Series 6                      | Black             |            131
 Series 6 Minifigures          | Black             |             30
 Series 7                      | Light Bluish Gray |            102
 Series 7 Minifigures          | Black             |             30
 Series 8                      | White             |            164
 Series 8 Minifigures          | Black             |             35
 Series 9                      | Black             |            205
 Series 9 Minifigures          | Black             |             29
 Service Packs                 | Black             |           1573
 Skull Spiders                 | Black             |             78
 Skylines                      | Tan               |            483
 Soccer                        | White             |           1905
 Soft Bricks                   | Red               |             96
 Sorcerer's Stone              | Light Gray        |            519
 Space                         | Blue              |            810
 Space Police I                | Black             |            710
 Space Police II               | Black             |            541
 Space Police III              | Black             |           1227
 Space Port                    | White             |            819
 Speed Champions               | Black             |           2049
 Speedorz                      | Black             |            389
 Speed Racer                   | Black             |            523
 Speed Slammers                | Black             |            519
 Spider-Man                    | Black             |           1156
 Spider-Man 2                  | Black             |             40
 SpongeBob SquarePants         | Red               |            521
 Sports                        | White             |             65
 Spybiotics                    | Black             |            628
 Spyrius                       | Black             |            712
 Stars                         | Dark Bluish Gray  |             18
 Star Wars                     | Black             |           8935
 Star Wars Clone Wars          | Light Bluish Gray |           5824
 Star Wars Episode 1           | Light Bluish Gray |           2049
 Star Wars Episode 2           | Light Bluish Gray |           1308
 Star Wars Episode 3           | Light Bluish Gray |           2653
 Star Wars Episode 4/5/6       | Light Bluish Gray |          20151
 Star Wars Episode 7           | Dark Bluish Gray  |            903
 Star Wars Episode 8           | Light Bluish Gray |             29
 Star Wars Expanded Universe   | Dark Bluish Gray  |             62
 Star Wars Expanded Universe   | Black             |             62
 Star Wars Other               | Black             |           1617
 Star Wars Rebels              | Light Bluish Gray |           2613
 Star Wars Rogue One           | Light Bluish Gray |           1265
 Station                       | White             |           1273
 Stingrays                     | Black             |            261
 Studios                       | Black             |            595
 Super Heroes                  | Black             |            959
 Superman                      | Black             |            286
 Supplemental                  | Red               |           6816
 Team GB                       | White             |             23
 Technic                       | Black             |          18917
 Teenage Mutant Ninja Turtles  | Light Bluish Gray |           1426
 Temple of Doom                | Dark Bluish Gray  |            261
 Thanksgiving                  | Reddish Brown     |            113
 The Battle of the Five Armies | Dark Bluish Gray  |            324
 The Desolation of Smaug       | Dark Bluish Gray  |            536
 The Fellowship of the Ring    | Dark Bluish Gray  |            561
 The Hobbit                    | Black             |              3
 The Hobbit                    | Tan               |              3
 The Hobbit                    | Reddish Brown     |              3
 The LEGO Movie                | Black             |           2561
 The LEGO Movie Series         | Black             |             31
 The Lone Ranger               | Black             |            584
 The Lord of the Rings         | Dark Bluish Gray  |             15
 The Return of the King        | Black             |            786
 The Simpsons                  | Black             |             32
 The Two Towers                | Black             |           1781
 Throwbot Slizer               | Black             |            472
 Time Cruisers                 | Light Gray        |            507
 Tiny Turbos                   | Black             |           3063
 Titans                        | Black             |           1948
 Toa                           | Black             |            210
 Toa Hagah                     | Black             |             41
 Toa Hordika                   | Dark Bluish Gray  |             72
 Toa Inika                     | Black             |             65
 Toa Mahri                     | Black             |             85
 Toa Metru                     | Black             |             77
 Toa Nuva                      | Black             |             96
 Toa Okoto                     | Black             |            140
 Tohunga                       | Black             |              9
 Town                          | White             |           4300
 Town Plan                     | White             |           2426
 Toy Story                     | Black             |            439
 Toy Story                     | Dark Bluish Gray  |            439
 Track System                  | Black             |            368
 Traffic                       | Black             |          12121
 Train                         | Black             |            854
 Trains                        | Dark Bluish Gray  |            640
 Turaga                        | Black             |            170
 UFO                           | Black             |            567
 Ultimate Collector Series     | Black             |           1843
 Ultra Agents                  | Black             |           1811
 Unitron                       | Black             |            632
 Universal Building Set        | Red               |           3117
 Universe                      | White             |             24
 Vahki                         | Black             |             88
 Valentine                     | Red               |            330
 Vehicle                       | Black             |             96
 Vehicles                      | Black             |            193
 Vikings                       | Black             |            639
 Villains                      | Black             |            957
 Visorak                       | Black             |             55
 Warriors                      | Black             |            890
 WeDo                          | White             |            138
 Western                       | Chrome Gold       |             18
 Williams F1                   | Black             |            962
 Wolfpack                      | Light Gray        |            126
 World City                    | Dark Gray         |            606
 World Racers                  | Black             |            809
 Xalax                         | Black             |             45
 X-Men                         | Black             |            182
 X-Pod                         | Black             |            113
 Znap                          | Black             |            427
(384 rows)


```

The shell command used to execute the script:

```sh
psql -U littled3092 -d lego -f q8.sql > q8-output.txt
```