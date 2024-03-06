// advent4.h
#include <action_descriptions.h>
#include <avr/pgmspace.h>
#include <stddef.h>
#include <stdlib.h>

#define ACTION_DESCRIPTIONS_SMALL_LENGTH 62
#define ACTION_DESCRIPTIONS_MEDIUM_LENGTH 186
#define ACTION_DESCRIPTIONS_LONG_LENGTH 520

#define AMOUNT_OF_ACTION_DESCRIPTIONS_SMALL 117
#define AMOUNT_OF_ACTION_DESCRIPTIONS_MEDIUM 68
#define AMOUNT_OF_ACTION_DESCRIPTIONS_LONG 12

#define DESCRIPTION_51_LENGTH 1309
#define DESCRIPTION_142_LENGTH 1395

const char actionsDescriptionsSmall[AMOUNT_OF_ACTION_DESCRIPTIONS_SMALL][ACTION_DESCRIPTIONS_SMALL_LENGTH] PROGMEM = {
        // 2
        "A little dwarf with a big knife blocks your way.\n",
        // 4
        "There is a threatening little dwarf in the room with you!\n",
        // 5
        "One sharp, nasty knife is thrown at you!\n",
        // 6
        "None of them hit you!\n",
        // 7
        "One of them gets you!\n",
        // 8
        "A hollow voice says \"Plugh\".\n",
        // 9
        "There is no way to go that direction.\n",
        // 12
        "I don't know how to apply that word here.\n",
        // 13
        "I don't understand that!\n",
        // 14
        "I'm game.  Would you care to explain how?\n",
        // 17
        "If you prefer, simply type W rather than West.\n",
        // 18
        "Are you trying to catch the bird?\n",
        // 20
        "Are you trying to somehow deal with the snake?\n",
        // 22
        "Do you really want to quit now?\n",
        // 23
        "You fell into a pit and broke every bone in your body!\n",
        // 24
        "You are already carrying it!\n",
        // 25
        "You can't be serious!\n",
        // 27
        "You can catch the bird, but you cannot carry it.\n",
        // 28
        "There is nothing here with a lock!\n",
        // 29
        "You aren't carrying it!\n",
        // 31
        "You have no keys!\n",
        // 32
        "It has no lock.\n",
        // 33
        "I don't know how to lock or unlock such a thing.\n",
        // 34
        "It was already locked.\n",
        // 35
        "The grate is now locked.\n",
        // 36
        "The grate is now unlocked.\n",
        // 37
        "It was already unlocked.\n",
        // 38
        "You have no source of light.\n",
        // 39
        "Your lamp is now on.\n",
        // 40
        "Your lamp is now off.\n",
        // 42
        "Nothing happens.\n",
        // 43
        "Where?\n",
        // 44
        "There is nothing here to attack.\n",
        // 45
        "The little bird is now dead.  Its body disappears.\n",
        // 46
        "Attacking the snake both doesn't work and is very dangerous.\n",
        // 47
        "You killed a little dwarf.\n",
        // 48
        "You attack a little dwarf, but he dodges out of the way.\n",
        // 49
        "With what? Your bare hands?\n",
        // 50
        "Good try, but that is an old worn-out magic word.\n",
        // 52
        "It misses!\n",
        // 53
        "It gets you!\n",
        // 54
        "OK\n",
        // 55
        "You can't unlock the keys.\n",
        // 58
        "I need more detailed instructions to do that.\n",
        // 60
        "I don't know that word.\n",
        // 61
        "What?\n",
        // 62
        "Are you trying to get into the cave?\n",
        // 67
        "Blasting requires dynamite.\n",
        // 68
        "I'm as confused as you are.\n",
        // 70
        "Your feet are now wet.\n",
        // 71
        "I think I just lost my appetite.\n",
        // 72
        "Thank you.  It was delicious!\n",
        // 74
        "The bottle of water is now empty.\n",
        // 76
        "Peculiar.  Nothing unexpected happens.\n",
        // 77
        "Your bottle is empty and the ground is wet.\n",
        // 78
        "You can't pour that.\n",
        // 79
        "Watch it!\n",
        // 80
        "Which way?\n",
        // 86
        "Okay, If you're so smart, do it yourself!  I'm leaving!\n",
        // 87 88 89 90
        "Reserved\n",
        // 93
        "You can't go through a locked steel grate!\n",
        // 94
        "I believe what you want is right here with you.\n",
        // 95
        "You don't fit through a two-inch slit!\n",
        // 97
        "There is no way across the fissure.\n",
        // 98
        "You're not carrying anything.\n",
        // 99
        "You are currently holding the following:\n",
        // 101
        "The snake has now devoured your bird.\n",
        // 102
        "There's nothing here it wants to eat (Except perhaps you).\n",
        // 104
        "You have nothing in which to carry it.\n",
        // 105
        "Your bottle is already full.\n",
        // 106
        "There is nothing here with which to fill the bottle.\n",
        // 107
        "Your bottle is now full of water.\n",
        // 108
        "Your bottle is now full of oil.\n",
        // 109
        "You can't fill that.\n",
        // 110
        "Don't be ridiculous!\n",
        // 111
        "The door is extremely rusty and refuses to open.\n",
        // 113
        "The hinges are quite thoroughly rusted now and won't budge.\n",
        // 122
        "You don't have anything strong enough to open the clam.\n",
        // 123
        "You don't have anything strong enough to open the oyster.\n",
        // 127
        "There are faint rustling noises from the darkness behind\n"
        "you.\n",
        // 137
        "Oh, leave the poor unhappy bird alone.\n",
        // 138
        "I daresay whatever you want is around here somewhere.\n",
        // 140
        "You can't get there from here.\n",
        // 141
        "You are being followed by a very large, tame bear.\n",
        // 143
        "Do you indeed wish to quit now?\n",
        // 144
        "There is nothing here with which to fill the vase.\n",
        // 146
        "It is beyond your power to do that.\n",
        // 147
        "I don't know how.\n",
        // 148
        "It is too far up for you to reach.\n",
        // 150
        "The shell is very strong and impervious to attack.\n",
        // 152
        "The axe bounces harmlessly off the dragon's thick scales.\n",
        // 153
        "The dragon looks rather nasty.  You'd best not try to get by.\n",
        // 155
        "On what?\n",
        // 160
        "The troll refuses to let you cross.\n",
        // 161
        "There is no longer any way across the chasm.\n",
        // 165
        "With what?  Your bare hands?  Against HIS bear hands??\n",
        // 166
        "The bear is confused;  he only wants to be your friend.\n",
        // 167
        "For crying out loud, the poor thing is already dead!\n",
        // 169
        "The bear is still chained to the wall.\n",
        // 170
        "The chain is still locked.\n",
        // 171
        "The chain is now unlocked.\n",
        // 172
        "The chain is now locked.\n",
        // 173
        "There is nothing here to which the chain can be locked.\n",
        // 174
        "There is nothing here to eat.\n",
        // 175
        "Do you want the hint?\n",
        // 176
        "Do you need help getting out of the maze?\n",
        // 177
        "You can make the passages look less alike by dropping things.\n",
        // 178
        "Are you trying to explore beyond the plover room?\n",
        // 180
        "Do you need help getting out of here?\n",
        // 181
        "Don't go west.\n",
        // 184
        "Your lamp has run out of power.\n",
        // 190
        "I'm afraid the magazine is written in Dwarvish.\n",
        // 194
        "It says the same thing it did before.\n",
        // 195
        "I'm afraid I don't understand.\n",
        // 196
        "\"Congratulations on bringing light into the dark-room!\"\n",
        // 200
        "Is this acceptable?\n",
        // 201
        "There's no point in suspending a demonstration game.\n"
};
const char actionDescriptionsMedium[AMOUNT_OF_ACTION_DESCRIPTIONS_MEDIUM][ACTION_DESCRIPTIONS_MEDIUM_LENGTH] PROGMEM = {
        // 3
        "A little dwarf just walked around a corner, saw you,\n"
        "threw a little axe at you which missed, cursed, and ran away.\n",
        // 10
        "I am unsure how you are facing.  Use compass points or\n"
        "nearby objects.\n",
        // 11
        "I don't know in from out here.  Use compass points or name\n"
        "something in the general direction you want to go.\n",
        // 15
        "Sorry, but I am not allowed to give more detail.  I will\n"
        "repeat the long description of your location.\n",
        // 16
        "It is now pitch dark.  If you proceed you will likely fall\n"
        "into a pit.\n",
        // 19
        "The bird is frightened right now and you cannot catch\n"
        "it no matter what you try.  Perhaps you might try later.\n",
        // 21
        "You can't kill the snake, or drive it away, or avoid it,\n"
        "or anything like that.  There is a way to get by, but you\n"
        "don't have the necessary resources right now.\n",
        // 26
        "The bird was unafraid when you entered, but as you approach\n"
        "it becomes disturbed and you cannot catch it.\n",
        // 30
        "The little bird attacks the green snake, and in an\n"
        "astounding flurry drives the snake away.\n",
        // 41
        "There is no way to get past the bear to unlock the chain,_\n"
        "which is probably just as well.\n",
        // 56
        "You have crawled around in some little holes and wound up\n"
        "back in the main passage.\n",
        // 57
        "I don't know where the cave is, but hereabouts no stream\n"
        "can run on the surface for very long.  I would try the stream.\n",
        // 58
        "I need more detailed instructions to do that.\n",
        // 59
        "I can only tell you what you see as you move about and\n"
        "manipulate things.  I cannot tell you where remote things are.\n",
        // 63
        "The grate is very solid and has a hardened steel lock.  You\n"
        "cannot enter without a key, and there are no keys nearby.\n"
        "I would recommend looking elsewhere for the keys.\n",
        // 66
        "Digging without a shovel is quite impractical.  Even with a\n"
        "shovel progress is unlikely.\n",
        // 69
        "Mist is a white vapor, usually water.  Seen from time to time\n"
        "in caverns.  It can be found anywhere but is frequently a\n"
        "sign of a deep pit leading down to water.\n",
        // 73
        "You have taken a drink from the stream.  The water tastes\n"
        "strongly of minerals, but is not unpleasant.  It is extremely\n"
        "cold.\n",
        // 75
        "Rubbing the electric lamp is not particularly rewarding.\n"
        "Anyway, nothing exciting happens.\n",
        // 81
        "Oh dear, you seem to have gotten yourself killed.  I might\n"
        "be able to help you out, but I've never really done this\n"
        "before.  Do you want me to try to reincarnate you?\n",
        // 83
        "You clumsy oaf, you've done it again!  I don't know how long\n"
        "I can keep this up.  Do you want me to try reincarnating\n"
        "you again?\n",
        // 84
        "Okay, now where did I put my orange smoke? ... > POOF! <\n"
        "Everything disappears in a dense cloud of orange smoke.\n",
        // 85
        "Now you've really done it!  I'm out of orange smoke!  You\n"
        "don't expect me to do a decent reincarnation without any\n"
        "orange smoke, do you?\n",
        // 91
        "Sorry, but I no longer seem to remember how it was you\n"
        "got here.\n",
        // 92
        "You can't carry anything more.  You'll have to drop something\n"
        "first.\n",
        // 96
        "I respectfully suggest you go across the bridge instead\n"
        "of jumping.\n",
        // 100
        "It's not hungry (It's merely pinin' for the Fjords).  Besides\n"
        "You have no bird seed.\n",
        // 103
        "You fool, Dwarves eat only coal!  Now you've made\n"
        "him REALLY mad !!\n",
        // 112
        "The plant indignantly shakes the oil off its leaves and asks:\n"
        "\"Water?\".\n",
        // 114
        "The oil has freed up the hinges so that the door will now move,\n"
        "although it requires some effort.\n",
        // 115
        "The plant has exceptionally deep roots and cannot be pulled free.\n",
        // 116
        "The Dwarves' knives vanish as they strike the walls of the cave.\n",
        // 117
        "Something you're carrying won't fit through the tunnel with\n"
        "you.  You'd best take inventory and drop something.\n",
        // 118
        "You can't fit this five-foot clam through that little passage!\n",
        // 119
        "You can't fit this five foot oyster through that little passage!\n",
        // 120
        "I advise you to put down the clam before opening it. >STRAIN!<\n",
        // 121
        "I advise you to put down the oyster before opening it.\n"
        ">WRENCH!<\n",
        // 125
        "The oyster creaks open, revealing nothing but oyster inside.\n"
        "It promptly snaps shut again.\n",
        // 126
        "You have crawled around in some little holes and found your\n"
        "way blocked by a recent cave-in.  You are now back in the\n"
        "main passage.\n",
        // 129
        "A sepulchral voice reverberating through the cave says:\n"
        "\"Cave closing soon.  All adventurers exit immediately\n"
        "through main office.\"\n",
        // 130
        "A mysterious recorded voice groans into life and announces:\n"
        "\"This exit is closed.  Please leave via main office.\"\n",
        // 131
        "It looks as though you're dead.  Well, seeing as how it's so\n"
        "close to closing time anyway, I think we'll just call it a day.\n",
        // 135
        "There is a loud explosion, and you are suddenly splashed across\n"
        "the walls of the room.\n",
        // 136
        "The resulting ruckus has awakened the Dwarves.  There are now\n"
        "several threatening little Dwarves in the room with you!\n"
        "Most of them throw knives at you!  All of them get you!\n",
        // 139
        "I don't know the word \"stop\".   Use \"quit\" if you want to\n"
        "give up.\n",
        // 145
        "The sudden change in temperature has delicately shattered\n"
        "the vase.\n",
        // 149
        "You killed a little Dwarf.  The body vanished in a cloud\n"
        "of greasy black smoke.\n",
        // 151
        "What's the matter, can't you read?  Now you'd best start\n"
        "over.\n",
        // 154
        "The little bird attacks the green dragon, and in an\n"
        "astounding flurry gets burnt to a cinder.  The ashes blow away.\n",
        // 156
        "Okay, from now on I'll only describe a place in full the\n"
        "first time you come to it.  To get the full description\n"
        "say \"look\".\n",
        // 157
        "Trolls are close relatives with the rocks and have skin as\n"
        "tough as that of a rhinoceros.  The troll fends off your\n"
        "blows effortlessly.\n",
        // 158
        "The troll deftly catches the axe, examines it carefully,\n"
        "and tosses it back, declaring, \"Good workmanship,\n"
        "but it's not valuable enough.\".\n",
        // 159
        "The troll catches your treasure and scurries away out of sight.\n",
        // 163
        "The bear lumbers toward the troll, who lets out a\n"
        "startled shriek and scurries away.  The bear soon gives\n"
        "up pursuit and wanders back.\n",
        // 164
        "The axe misses and lands near the bear where you can't get\n"
        "at it.\n",
        // 168
        "The bear eagerly wolfs down your food, after which he seems\n"
        "to calm down considerably, and even becomes rather friendly.\n",
        // 179
        "There is a way to explore that region without having to\n"
        "worry about falling into a pit.  None of the objects\n"
        "available is immediately useful in descovering the secret.\n",
        // 182
        "Gluttony is not one of the Troll's vices.  Avarice, however, is.\n",
        // 185
        "There's not much point in wandering around out here, and you\n"
        "can't explore the cave without a lamp.  So let's just call\n"
        "it a day.\n",
        // 187
        "Your lamp is getting dim.  You'd best go back for\n"
        "those batteries.\n",
        // 188
        "Your lamp is getting dim.. I'm taking the liberty of replacing\n"
        "the batteries.\n",
        // 189
        "Your lamp is getting dim, and you're out of spare batteries.\n"
        "You'd best start wrapping this up.\n",
        // 191
        "\"This is not the maze where the pirate leaves his treasure\n"
        "chest.\"\n",
        // 192
        "Hmm, this looks like a clue, which means it'll cost you 10\n"
        "points to read it.  Should I go ahead and read it anyway?\n",
        // 193
        "It says, \"There is something strange about this place,\n"
        "such that one of the words I've always known now has\n"
        "a new effect.\"\n",
        // 197
        "You strike the mirror a resounding blow, whereupon it\n"
        "shatters into a myriad tiny fragments.\n",
        // 198
        "You have taken the vase and hurled it delicately to the\n"
        "ground.\n",
        // 199
        "You prod the nearest Dwarf, who wakes up grumpily, takes\n"
        "one look at you, curses, and grabs for his axe.\n",
};
const char actionDescriptionsLong[AMOUNT_OF_ACTION_DESCRIPTIONS_LONG][ACTION_DESCRIPTIONS_LONG_LENGTH] PROGMEM = {
        // 1
        "Somewhere nearby is Colossal Cave, where others have found fortunes in \n"
        "treasure and gold, though it is rumored that some who enter are never \n"
        "seen again.  Magic is said to work in the cave.  I will be your eyes \n"
        "and hands.  Direct me with commands of 1 or 2 words.  I should warn \n"
        "you that I look at only the first five letters of each word, so you'll \n"
        "have to enter \"Northeast\" as \"ne\" to distinguish it from \"North\".  \n"
        "(Should you get stuck, type \"help\" for some general hints).\n"
        "\n",
        // 64
        "The trees of the forest are large hardwood oak and maple,\n"
        "with an occasional grove of pine or spruce.  There is quite\n"
        "a bit of undergrowth, largely birch and ash saplings plus\n"
        "nondescript bushes of various sorts.  This time of year \n"
        "visibility is quite restricted by all the leaves, but travel\n"
        "is quite easy if you detour around the spruce and berry\n"
        "bushes.\n",
        // 65
        "\n"
        "                              Welcome to \n"
        "\n"
        "                       Colossal Cave Adventure!\n"
        "\n"
        "\n"
        "               Original development by Willie Crowther.\n"
        "                  Major features added by Don Woods.\n"
        "                 Conversion to BDS C by J. R. Jaeger.\n"
        "                Unix standardization by Jerry D. Pohl.\n"
        "            Port to QNX 4 and bug fixes by James Lummel.\n"
        "\n"
        "Would you like instructions?\n"
        "\n",
        // 82
        "All right.  But don't blame me if something goes wr......\n"
        "                    --- POOF !! ---\n"
        "You are engulfed in a cloud of orange smoke.  Coughing and\n"
        "gasping, you emerge from the smoke and find...\n",
        // 124
        "A glistening pearl falls out of the clam and rolls away.\n"
        "Goodness, this must really be an oyster.  (I never was\n"
        "very good at identifying bivalves.)  Whatever it is,\n"
        "it has now snapped shut again.\n",
        // 128
        "Out from the shadows behind you pounces a bearded pirate!\n"
        "\"Har, har\" he chortles, \"I'll just take all this booty and\n"
        "hide it away with me chest deep in the maze!\".  He snatches\n"
        "your treasure and vanishes into the gloom.\n",
        // 132
        "The sepulchral voice entones, \"The cave is now closed.\"  As\n"
        "the echoes fade, there is a blinding flash of light (and a\n"
        "small puff of orange smoke). . . . \n"
        "As your eyes refocus you look around and find...\n",
        // 133
        "There is a loud explosion, and a twenty-foot hole appears in\n"
        "the far wall, burying the Dwarves in the rubble.  You march\n"
        "through the hole and find yourself in the main office, where\n"
        "a cheering band of friendly elves carry the conquering\n"
        "adventurer off into the sunset.\n",
        // 134
        "There is a loud explosion, and a twenty-foot hole appears in\n"
        "the far wall, burying the snakes in the rubble.  A river of\n"
        "molten lava pours in through the hole, destroying\n"
        "everything in its path, including you!!\n",
        // 162
        "Just as you reach the other side, the bridge buckles beneath\n"
        "the weight of the bear, which was still following you around.\n"
        "You scrabble desperately for support, but as the bridge \n"
        "collapses you stumble back and fall into the chasm.\n",
        // 183
        "Your lamp is getting dim.. You'd best start wrapping this up,\n"
        "unless you can find some fresh batteries.  I seem to recall\n"
        "there's a vending machine in the maze.  Bring some coins\n"
        "with you.\n",
        // 186
        "There are faint rustling noises from the darkness behind you.\n"
        "As you turn toward them, the beam of your lamp falls across a\n"
        "bearded pirate.  He is carrying a large chest.  \"Shiver me\n"
        "timbers!\"  he cries, \"I've been spotted!  I'd best hide\n"
        "meself off to the maze and hide me chest!\".  With that,\n"
        "he vanished into the gloom.\n",
};


// 51
const char actionDescription_51[DESCRIPTION_51_LENGTH] PROGMEM =
        "I know of places, actions, and things.  Most of my vocabulary \n"
        "describes places and is used to move you there.  To move, try words \n"
        "like forest, building, downstream, enter, east, west, north, south, up \n"
        "or down.  \n"
        "I know about a few special objects, like a black rod hidden in the \n"
        "cave.  These objects can be manipulated using some of the action words \n"
        "I know. Usually you will need to give both the object and action words \n"
        "(In either order), but sometimes I can infer the object from the verb \n"
        "alone.  Some objects also imply verbs; in particular, \"inventory\" \n"
        "implies \"take inventory\", which causes me to give you a list of what \n"
        "you're carrying.\n"
        "The objects have side effects; for instance, the rod scares the bird. \n"
        "Usually people having trouble moving just need to try a few more \n"
        "words.  Usually people trying unsuccessfully to manipulate an object \n"
        "are attempting something beyond their (or my!) capabilities and should \n"
        "try a completely different tack.\n"
        "To speed the game up, you can sometimes move long distances with a \n"
        "single word.  For example, \"building\" usually gets you to the building \n"
        "from anywhere above ground except when lost in the forest.  Also, note \n"
        "that cave passages turn a lot, and that leaving a room to the north \n"
        "does not guarantee entering the next from the south. Good luck!\n";

// 142
const char actionDescription_142[DESCRIPTION_142_LENGTH] PROGMEM =
        "If you want to end your adventure early, say \"quit\".  To suspend your \n"
        "adventure such that you can continue later say \"suspend\" (or \"pause\" \n"
        "or \"save\").  To load a previously saved game, say 'load' or 'restore'.  \n"
        "To see how well you're doing, say \"score\".  To get full credit for a \n"
        "treasure, you must have left it safely in the building, though you get \n"
        "partial credit just for locating it. You lose points for getting \n"
        "killed, or for quitting, though the former costs you more. \n"
        "There are also points based on how much (If any) of the cave you've \n"
        "managed to explore;  in particular, there is a large bonus just for \n"
        "getting in (to distinguish the beginners from the rest of the pack), \n"
        "and there are other ways to determine whether you've been through some \n"
        "of the more harrowing sections. \n"
        "If you think you've found all the treasures, just keep exploring for a \n"
        "while.  If nothing interesting happens, you haven't found them all \n"
        "yet.  If something interesting DOES happen, it means you're getting a \n"
        "bonus and have an opportunity to garner many more points in the \n"
        "master's section.\n"
        "I may occasionally offer hints in you seem to be having trouble.  If I \n"
        "do, I'll warn you in advance how much it will affect your score to \n"
        "accept the hints.  Finally, to save paper, you may specify \"brief\", \n"
        "which tells me never to repeat the full description of a place unless \n"
        "you explicitly ask me to.\n";
const uint8_t shortMsg[] PROGMEM  = {2, 4, 5, 6, 7, 8, 9, 12, 13, 14, 17, 18, 20, 22, 23, 24, 25, 27, 28, 29, 31, 32, 33, 34, 35,
                                                                  36, 37, 38, 39, 40, 42, 43, 44, 45, 46, 47, 48, 49, 50, 52, 53, 54, 55, 58, 60, 61, 62, 67,
                                                                  68, 70, 71, 72, 74, 76, 77, 78, 79, 80, 86, 87, 93, 94, 95, 97, 98, 99, 101, 102, 104, 105,
                                                                  106, 107, 108, 109, 110, 111, 113, 122, 123, 127, 137, 138, 140, 141, 143, 144, 146, 147, 148,
                                                                  150, 152, 153, 155, 160, 161, 165, 166, 167, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178,
                                                                  180, 181, 184, 190, 194, 195, 196, 200, 201};
const uint8_t mediumMsg[] PROGMEM = {3, 10, 11, 15, 16, 19, 21, 26, 30, 41, 56, 57, 58, 59, 63, 66, 69, 73, 75, 81, 83, 84, 85,
                                                                     91, 92, 96, 100, 103, 112, 114, 115, 116, 117, 118, 119, 120, 121, 125, 126, 129, 130, 131,
                                                                     135, 136, 139, 145, 149, 151, 154, 156, 157, 158, 159, 163, 164, 168, 179, 182, 185, 187,
                                                                     188, 189, 191, 192, 193, 197, 198, 199};
const uint8_t longMsg[] PROGMEM = {1, 64, 65, 82, 124, 128, 132, 133, 134, 162, 183, 186};
char * getActionDescription(uint8_t msgNumber) {
    char * stringToReturn = NULL;

    if (msgNumber == 51) {
        stringToReturn = (char *) malloc(DESCRIPTION_51_LENGTH);
        strcpy_P(stringToReturn, actionDescription_51);
        return stringToReturn;
    } else if (msgNumber == 142) {
        stringToReturn = (char *) malloc(DESCRIPTION_142_LENGTH);
        strcpy_P(stringToReturn, actionDescription_142);
        return stringToReturn;
    }


    for (uint8_t i = 0; i < AMOUNT_OF_ACTION_DESCRIPTIONS_SMALL; i++) {
        if (pgm_read_byte(&shortMsg[i]) == msgNumber) {
            stringToReturn = (char *) malloc(ACTION_DESCRIPTIONS_SMALL_LENGTH);
            strcpy_P(stringToReturn, actionsDescriptionsSmall[i]);
            return stringToReturn;
        }
    }

    for (uint8_t i = 0; i < AMOUNT_OF_ACTION_DESCRIPTIONS_MEDIUM; i++) {
        if (pgm_read_byte(&mediumMsg[i]) == msgNumber) {
            stringToReturn = (char *) malloc(ACTION_DESCRIPTIONS_MEDIUM_LENGTH);
            strcpy_P(stringToReturn, actionDescriptionsMedium[i]);
            return stringToReturn;
        }
    }

    for (uint8_t i = 0; i < AMOUNT_OF_ACTION_DESCRIPTIONS_LONG; i++) {
        if (pgm_read_byte(&longMsg[i]) == msgNumber) {
            stringToReturn = (char *) malloc(ACTION_DESCRIPTIONS_LONG_LENGTH);
            strcpy_P(stringToReturn, actionDescriptionsLong[i]);
            return stringToReturn;
        }
    }
    return stringToReturn;
}