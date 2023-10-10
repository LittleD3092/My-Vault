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

3. The SQL statements and output results of 4a (10pts). If the SQL statements or output results are not provided, you will not get the points.
    

Ans:

The script:

```sql
SELECT sets.name, themes.name
FROM sets
JOIN themes ON sets.theme_id = themes.id
WHERE sets.year = 2017;
```

The output:

```txt
                           name                            |           name           
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

4. The SQL statements and output results of 4b (10pts)
    

Ans:



5. The SQL statements and output results of 4c (10pts)
    

Ans:

  

6. The SQL statements and output results of 4d (10pts)
    

Ans:

  

7. The SQL statements and output results of 4e (10pts)
    

Ans:

  

8. The SQL statements and output results of 4f (10pts)
    

Ans: