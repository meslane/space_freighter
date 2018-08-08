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
galaxy map with 64 systems being generated per game. Each system 
contains one Planet each. Stars are classified based on spectral 
classification and generated based on real-life probabilties.
A list of spectral types and their probabilties, both real-life 
and in-game are given below:

Type-O: 0.00003%, 1%
Type-B: 0.125%,   3%
Type-A: 0.625%,   6% 
Type-F: 3.03%,   10%
Type-G: 7.5%,    15%
Type-K: 12%,     20%
Type-M: 76%,     45%

Probablilties of each type of planet being generated change based on
the type of the parent star. Probabilities of this are given below,
ordered as T-H-G:

O: 15-80-5
B: 20-70-10
A: 30-55-15
F: 
G: 35-35-30
K:
M:

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
-Undeveloped

╔════════════════════╗
║The Market          ║
╚════════════════════╝
The market of Space Freighter changes based on political changes in 
the galaxy, just as in real life. Many of these changes are represented
as events that can occur on a planetwide of galaxywide scale. Events change
the prices that goods are bought and sold for in the areas where they occur 
as well as on a universal level. A list of possible events is given below:

-Famine
-Drought
-Epidemic
-Natural Disaster
    -Earthquake
    -Storm
    -Meteor Impact 
-Civil War
-War 

╔════════════════════╗
║Religions           ║
╚════════════════════╝
8 religions are generated per game with different properties and principles.
A religion's size variable is the number of planets that follow it. By default,
a planet's religion is listed as NONE. During generation, each religion has a 
certian probability of being accepted by a given planet based on its SIZE 
factor. The SIZE factor of a religion is a randomly generated value ranging 
from 1 to 10. During generation, if the religion value of a given religion <= 
the randomly generated value, then said planet will accept that religion assuming
it has not already accepted one. Properties of each are given below:

Type:
-Monotheistic (one god)
    -Eutheistic (god is all-good)
    -Dystheistic (god is neither all-good nor all-bad)
    -Mistheistic (god is all-bad)
    -Deistic (god don't give a shit about you)
-Polytheistic (many gods)
    -Traditional (no supreme god)
    -Henotheistic (yes supreme god)
    -Kathenotheistic (gods take turns being supreme)
-Animistic (everything has a spirit)
-Pantheistic (the universe is god) 
-Autotheistic (everyone can become god)

Religions also have a VIOLENCE factor based in part on random chance and in part
on which type of religion they are. For example, mistheistic religions are more
likely to be more violent than eutheistic ones, and so on. 