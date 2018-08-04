 #### ####   ###   #### #####
#     #   # #   # #     #
 ###  ####  ##### #     #####
    # #     #   # #     #
####  #     #   #  #### #####

#### ####  ##### #####  #### ##### ##### ####
#    #   # #       #   #       #   #     #   #
#### ####  #####   #   #  ##   #   ##### ####
#    #  #  #       #   #   #   #   #     #  #
#    #   # ##### #####  ###    #   ##### #   #

╔════════════════════╗
║The Galaxy          ║
╚════════════════════╝
"The Galaxy" is laid out on a 256*256 chart with X and Y ranges of 
-128 to 127 (range of int8_t).

The X and Y values of the galaxy correspond to one light year each, 
with the total area of the galaxy being 65536 square light years.

╔════════════════════╗
║Star Systems        ║
╚════════════════════╝ 
Each star system is given a randomly generated coodinate on the 
galaxy map with 32 systems being generated per game. Each system
can posess a minimum of 1 planet and a maximum of 3 planets with a 
cap of 64 planets per galaxy.

╔════════════════════╗
║Planets             ║
╚════════════════════╝
Planets can fall into three basic classifications with many subclassifications:

-Terrestrial
    -Icy
    -Cold
    -Temperate
    -Hot
    -Very Hot
-Habitable
    -Water
    -Desert
    -Forested
    -Fertile
    -City
-Gas
    -Icy
    -Cold
    -Temperate
    -Hot
    -Very Hot

Each planet posesses a commercial station where supplies can be 
bought and sold and contracts can be accepted and submitted. 
Prices of supplies bought and sold at a given planet's station
vary based on the needs and production of said planet. Production
types are:

-Agricultural (Habitable only)
-Industrial   (Habitable and Terrestrial only)
-Extraction
-Settlement   (Habitable and Terrestrial only)
-Spaceport    (Habitable and Terrestrial only)

╔════════════════════╗
║The Market          ║
╚════════════════════╝