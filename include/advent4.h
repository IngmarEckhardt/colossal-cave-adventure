#include <avr/pgmspace.h>

#define ADVENTTXT4_SIZE 201
const char adv4_string_1[] PROGMEM = "Somewhere nearby is Colossal Cave, where others have found fortunes in \ntreasure and gold, though it is rumored that some who enter are never \nseen again.  Magic is said to work in the cave.  I will be your eyes \nand hands.  Direct me with commands of 1 or 2 words.  I should warn \nyou that I look at only the first five letters of each word, so you'll \nhave to enter \"Northeast\" as \"ne\" to distinguish it from \"North\".  \n(Should you get stuck, type \"help\" for some general hints).\n\n";
const char adv4_string_2[] PROGMEM = "A little dwarf with a big knife blocks your way.\n";
const char adv4_string_3[] PROGMEM = "A little dwarf just walked around a corner, saw you,\nthrew a little axe at you which missed, cursed, and ran away.\n";
const char adv4_string_4[] PROGMEM = "There is a threatening little dwarf in the room with you!\n";
const char adv4_string_5[] PROGMEM = "One sharp, nasty knife is thrown at you!\n";
const char adv4_string_6[] PROGMEM = "None of them hit you!\n";
const char adv4_string_7[] PROGMEM = "One of them gets you!\n";
const char adv4_string_8[] PROGMEM = "A hollow voice says \"Plugh\".\n";
const char adv4_string_9[] PROGMEM = "There is no way to go that direction.\n";
const char adv4_string_10[] PROGMEM = "I am unsure how you are facing.  Use compass points or\nnearby objects.\n";
const char adv4_string_11[] PROGMEM = "I don't know in from out here.  Use compass points or name\nsomething in the general direction you want to go.\n";
const char adv4_string_12[] PROGMEM = "I don't know how to apply that word here.\n";
const char adv4_string_13[] PROGMEM = "I don't understand that!\n";
const char adv4_string_14[] PROGMEM = "I'm game.  Would you care to explain how?\n";
const char adv4_string_15[] PROGMEM = "Sorry, but I am not allowed to give more detail.  I will\nrepeat the long description of your location.\n";
const char adv4_string_16[] PROGMEM = "It is now pitch dark.  If you proceed you will likely fall\ninto a pit.\n";
const char adv4_string_17[] PROGMEM = "If you prefer, simply type W rather than West.\n";
const char adv4_string_18[] PROGMEM = "Are you trying to catch the bird?\n";
const char adv4_string_19[] PROGMEM = "The bird is frightened right now and you cannot catch\nit no matter what you try.  Perhaps you might try later.\n";
const char adv4_string_20[] PROGMEM = "Are you trying to somehow deal with the snake?\n";
const char adv4_string_21[] PROGMEM = "You can't kill the snake, or drive it away, or avoid it,\nor anything like that.  There is a way to get by, but you\ndon't have the necessary resources right now.\n";
const char adv4_string_22[] PROGMEM = "Do you really want to quit now?\n";
const char adv4_string_23[] PROGMEM = "You fell into a pit and broke every bone in your body!\n";
const char adv4_string_24[] PROGMEM = "You are already carrying it!\n";
const char adv4_string_25[] PROGMEM = "You can't be serious!\n";
const char adv4_string_26[] PROGMEM = "The bird was unafraid when you entered, but as you approach\nit becomes disturbed and you cannot catch it.\n";
const char adv4_string_27[] PROGMEM = "You can catch the bird, but you cannot carry it.\n";
const char adv4_string_28[] PROGMEM = "There is nothing here with a lock!\n";
const char adv4_string_29[] PROGMEM = "You aren't carrying it!\n";
const char adv4_string_30[] PROGMEM = "The little bird attacks the green snake, and in an\nastounding flurry drives the snake away.\n";
const char adv4_string_31[] PROGMEM = "You have no keys!\n";
const char adv4_string_32[] PROGMEM = "It has no lock.\n";
const char adv4_string_33[] PROGMEM = "I don't know how to lock or unlock such a thing.\n";
const char adv4_string_34[] PROGMEM = "It was already locked.\n";
const char adv4_string_35[] PROGMEM = "The grate is now locked.\n";
const char adv4_string_36[] PROGMEM = "The grate is now unlocked.\n";
const char adv4_string_37[] PROGMEM = "It was already unlocked.\n";
const char adv4_string_38[] PROGMEM = "You have no source of light.\n";
const char adv4_string_39[] PROGMEM = "Your lamp is now on.\n";
const char adv4_string_40[] PROGMEM = "Your lamp is now off.\n";
const char adv4_string_41[] PROGMEM = "There is no way to get past the bear to unlock the chain,_\nwhich is probably just as well.\n";
const char adv4_string_42[] PROGMEM = "Nothing happens.\n";
const char adv4_string_43[] PROGMEM = "Where?\n";
const char adv4_string_44[] PROGMEM = "There is nothing here to attack.\n";
const char adv4_string_45[] PROGMEM = "The little bird is now dead.  Its body disappears.\n";
const char adv4_string_46[] PROGMEM = "Attacking the snake both doesn't work and is very dangerous.\n";
const char adv4_string_47[] PROGMEM = "You killed a little dwarf.\n";
const char adv4_string_48[] PROGMEM = "You attack a little dwarf, but he dodges out of the way.\n";
const char adv4_string_49[] PROGMEM = "With what? Your bare hands?\n";
const char adv4_string_50[] PROGMEM = "Good try, but that is an old worn-out magic word.\n";
const char adv4_string_51[] PROGMEM = "I know of places, actions, and things.  Most of my vocabulary \ndescribes places and is used to move you there.  To move, try words \nlike forest, building, downstream, enter, east, west, north, south, up \nor down.  \nI know about a few special objects, like a black rod hidden in the \ncave.  These objects can be manipulated using some of the action words \nI know. Usually you will need to give both the object and action words \n(In either order), but sometimes I can infer the object from the verb \nalone.  Some objects also imply verbs; in particular, \"inventory\" \nimplies \"take inventory\", which causes me to give you a list of what \nyou're carrying.\nThe objects have side effects; for instance, the rod scares the bird. \nUsually people having trouble moving just need to try a few more \nwords.  Usually people trying unsuccessfully to manipulate an object \nare attempting something beyond their (or my!) capabilities and should \ntry a completely different tack.\nTo speed the game up, you can sometimes move long distances with a \nsingle word.  For example, \"building\" usually gets you to the building \nfrom anywhere above ground except when lost in the forest.  Also, note \nthat cave passages turn a lot, and that leaving a room to the north \ndoes not guarantee entering the next from the south. Good luck!\n";
const char adv4_string_52[] PROGMEM = "It misses!\n";
const char adv4_string_53[] PROGMEM = "It gets you!\n";
const char adv4_string_54[] PROGMEM = "OK\n";
const char adv4_string_55[] PROGMEM = "You can't unlock the keys.\n";
const char adv4_string_56[] PROGMEM = "You have crawled around in some little holes and wound up\nback in the main passage.\n";
const char adv4_string_57[] PROGMEM = "I don't know where the cave is, but hereabouts no stream\ncan run on the surface for very long.  I would try the stream.\n";
const char adv4_string_58[] PROGMEM = "I need more detailed instructions to do that.\n";
const char adv4_string_59[] PROGMEM = "I can only tell you what you see as you move about and\nmanipulate things.  I cannot tell you where remote things are.\n";
const char adv4_string_60[] PROGMEM = "I don't know that word.\n";
const char adv4_string_61[] PROGMEM = "What?\n";
const char adv4_string_62[] PROGMEM = "Are you trying to get into the cave?\n";
const char adv4_string_63[] PROGMEM = "The grate is very solid and has a hardened steel lock.  You\ncannot enter without a key, and there are no keys nearby.\nI would recommend looking elsewhere for the keys.\n";
const char adv4_string_64[] PROGMEM = "The trees of the forest are large hardwood oak and maple,\nwith an occasional grove of pine or spruce.  There is quite\na bit of undergrowth, largely birch and ash saplings plus\nnondescript bushes of various sorts.  This time of year \nvisibility is quite restricted by all the leaves, but travel\nis quite easy if you detour around the spruce and berry\nbushes.\n";
const char adv4_string_65[] PROGMEM = "\n                              Welcome to \n\n                       Colossal Cave Adventure!\n\n\n               Original development by Willie Crowther.\n                  Major features added by Don Woods.\n                 Conversion to BDS C by J. R. Jaeger.\n                Unix standardization by Jerry D. Pohl.\n            Port to QNX 4 and bug fixes by James Lummel.\n\nWould you like instructions?\n\n";
const char adv4_string_66[] PROGMEM = "Digging without a shovel is quite impractical.  Even with a\nshovel progress is unlikely.\n";
const char adv4_string_67[] PROGMEM = "Blasting requires dynamite.\n";
const char adv4_string_68[] PROGMEM = "I'm as confused as you are.\n";
const char adv4_string_69[] PROGMEM = "Mist is a white vapor, usually water.  Seen from time to time\nin caverns.  It can be found anywhere but is frequently a\nsign of a deep pit leading down to water.\n";
const char adv4_string_70[] PROGMEM = "Your feet are now wet.\n";
const char adv4_string_71[] PROGMEM = "I think I just lost my appetite.\n";
const char adv4_string_72[] PROGMEM = "Thank you.  It was delicious!\n";
const char adv4_string_73[] PROGMEM = "You have taken a drink from the stream.  The water tastes\nstrongly of minerals, but is not unpleasant.  It is extremely\ncold.\n";
const char adv4_string_74[] PROGMEM = "The bottle of water is now empty.\n";
const char adv4_string_75[] PROGMEM = "Rubbing the electric lamp is not particularly rewarding.\nAnyway, nothing exciting happens.\n";
const char adv4_string_76[] PROGMEM = "Peculiar.  Nothing unexpected happens.\n";
const char adv4_string_77[] PROGMEM = "Your bottle is empty and the ground is wet.\n";
const char adv4_string_78[] PROGMEM = "You can't pour that.\n";
const char adv4_string_79[] PROGMEM = "Watch it!\n";
const char adv4_string_80[] PROGMEM = "Which way?\n";
const char adv4_string_81[] PROGMEM = "Oh dear, you seem to have gotten yourself killed.  I might\nbe able to help you out, but I've never really done this\nbefore.  Do you want me to try to reincarnate you?\n";
const char adv4_string_82[] PROGMEM = "All right.  But don't blame me if something goes wr......\n                    --- POOF !! ---\nYou are engulfed in a cloud of orange smoke.  Coughing and\ngasping, you emerge from the smoke and find...\n";
const char adv4_string_83[] PROGMEM = "You clumsy oaf, you've done it again!  I don't know how long\nI can keep this up.  Do you want me to try reincarnating\nyou again?\n";
const char adv4_string_84[] PROGMEM = "Okay, now where did I put my orange smoke? ... > POOF! <\nEverything disappears in a dense cloud of orange smoke.\n";
const char adv4_string_85[] PROGMEM = "Now you've really done it!  I'm out of orange smoke!  You\ndon't expect me to do a decent reincarnation without any\norange smoke, do you?\n";
const char adv4_string_86[] PROGMEM = "Okay, If you're so smart, do it yourself!  I'm leaving!\n";
const char adv4_string_87[] PROGMEM = "Reserved\n";
const char adv4_string_88[] PROGMEM = "Reserved\n";
const char adv4_string_89[] PROGMEM = "Reserved\n";
const char adv4_string_90[] PROGMEM = "Reserved\n";
const char adv4_string_91[] PROGMEM = "Sorry, but I no longer seem to remember how it was you\ngot here.\n";
const char adv4_string_92[] PROGMEM = "You can't carry anything more.  You'll have to drop something\nfirst.\n";
const char adv4_string_93[] PROGMEM = "You can't go through a locked steel grate!\n";
const char adv4_string_94[] PROGMEM = "I believe what you want is right here with you.\n";
const char adv4_string_95[] PROGMEM = "You don't fit through a two-inch slit!\n";
const char adv4_string_96[] PROGMEM = "I respectfully suggest you go across the bridge instead\nof jumping.\n";
const char adv4_string_97[] PROGMEM = "There is no way across the fissure.\n";
const char adv4_string_98[] PROGMEM = "You're not carrying anything.\n";
const char adv4_string_99[] PROGMEM = "You are currently holding the following:\n";
const char adv4_string_100[] PROGMEM = "It's not hungry (It's merely pinin' for the Fjords).  Besides\nYou have no bird seed.\n";
const char adv4_string_101[] PROGMEM = "The snake has now devoured your bird.\n";
const char adv4_string_102[] PROGMEM = "There's nothing here it wants to eat (Except perhaps you).\n";
const char adv4_string_103[] PROGMEM = "You fool, Dwarves eat only coal!  Now you've made\nhim REALLY mad !!\n";
const char adv4_string_104[] PROGMEM = "You have nothing in which to carry it.\n";
const char adv4_string_105[] PROGMEM = "Your bottle is already full.\n";
const char adv4_string_106[] PROGMEM = "There is nothing here with which to fill the bottle.\n";
const char adv4_string_107[] PROGMEM = "Your bottle is now full of water.\n";
const char adv4_string_108[] PROGMEM = "Your bottle is now full of oil.\n";
const char adv4_string_109[] PROGMEM = "You can't fill that.\n";
const char adv4_string_110[] PROGMEM = "Don't be ridiculous!\n";
const char adv4_string_111[] PROGMEM = "The door is extremely rusty and refuses to open.\n";
const char adv4_string_112[] PROGMEM = "The plant indignantly shakes the oil off its leaves and asks:\n\"Water?\".\n";
const char adv4_string_113[] PROGMEM = "The hinges are quite thoroughly rusted now and won't budge.\n";
const char adv4_string_114[] PROGMEM = "The oil has freed up the hinges so that the door will now move,\nalthough it requires some effort.\n";
const char adv4_string_115[] PROGMEM = "The plant has exceptionally deep roots and cannot be pulled free.\n";
const char adv4_string_116[] PROGMEM = "The Dwarves' knives vanish as they strike the walls of the cave.\n";
const char adv4_string_117[] PROGMEM = "Something you're carrying won't fit through the tunnel with\nyou.  You'd best take inventory and drop something.\n";
const char adv4_string_118[] PROGMEM = "You can't fit this five-foot clam through that little passage!\n";
const char adv4_string_119[] PROGMEM = "You can't fit this five foot oyster through that little passage!\n";
const char adv4_string_120[] PROGMEM = "I advise you to put down the clam before opening it. >STRAIN!<\n";
const char adv4_string_121[] PROGMEM = "I advise you to put down the oyster before opening it.\n>WRENCH!<\n";
const char adv4_string_122[] PROGMEM = "You don't have anything strong enough to open the clam.\n";
const char adv4_string_123[] PROGMEM = "You don't have anything strong enough to open the oyster.\n";
const char adv4_string_124[] PROGMEM = "A glistening pearl falls out of the clam and rolls away.\nGoodness, this must really be an oyster.  (I never was\nvery good at identifying bivalves.)  Whatever it is,\nit has now snapped shut again.\n";
const char adv4_string_125[] PROGMEM = "The oyster creaks open, revealing nothing but oyster inside.\nIt promptly snaps shut again.\n";
const char adv4_string_126[] PROGMEM = "You have crawled around in some little holes and found your\nway blocked by a recent cave-in.  You are now back in the\nmain passage.\n";
const char adv4_string_127[] PROGMEM = "There are faint rustling noises from the darkness behind\nyou.\n";
const char adv4_string_128[] PROGMEM = "Out from the shadows behind you pounces a bearded pirate!\n\"Har, har\" he chortles, \"I'll just take all this booty and\nhide it away with me chest deep in the maze!\".  He snatches\nyour treasure and vanishes into the gloom.\n";
const char adv4_string_129[] PROGMEM = "A sepulchral voice reverberating through the cave says:\n\"Cave closing soon.  All adventurers exit immediately\nthrough main office.\"\n";
const char adv4_string_130[] PROGMEM = "A mysterious recorded voice groans into life and announces:\n\"This exit is closed.  Please leave via main office.\"\n";
const char adv4_string_131[] PROGMEM = "It looks as though you're dead.  Well, seeing as how it's so\nclose to closing time anyway, I think we'll just call it a day.\n";
const char adv4_string_132[] PROGMEM = "The sepulchral voice entones, \"The cave is now closed.\"  As\nthe echoes fade, there is a blinding flash of light (and a\nsmall puff of orange smoke). . . . \nAs your eyes refocus you look around and find...\n";
const char adv4_string_133[] PROGMEM = "There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the Dwarves in the rubble.  You march\nthrough the hole and find yourself in the main office, where\na cheering band of friendly elves carry the conquering\nadventurer off into the sunset.\n";
const char adv4_string_134[] PROGMEM = "There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the snakes in the rubble.  A river of\nmolten lava pours in through the hole, destroying\neverything in its path, including you!!\n";
const char adv4_string_135[] PROGMEM = "There is a loud explosion, and you are suddenly splashed across\nthe walls of the room.\n";
const char adv4_string_136[] PROGMEM = "The resulting ruckus has awakened the Dwarves.  There are now\nseveral threatening little Dwarves in the room with you!\nMost of them throw knives at you!  All of them get you!\n";
const char adv4_string_137[] PROGMEM = "Oh, leave the poor unhappy bird alone.\n";
const char adv4_string_138[] PROGMEM = "I daresay whatever you want is around here somewhere.\n";
const char adv4_string_139[] PROGMEM = "I don't know the word \"stop\".   Use \"quit\" if you want to\ngive up.\n";
const char adv4_string_140[] PROGMEM = "You can't get there from here.\n";
const char adv4_string_141[] PROGMEM = "You are being followed by a very large, tame bear.\n";
const char adv4_string_142[] PROGMEM = "If you want to end your adventure early, say \"quit\".  To suspend your \nadventure such that you can continue later say \"suspend\" (or \"pause\" \nor \"save\").  To load a previously saved game, say 'load' or 'restore'.  \nTo see how well you're doing, say \"score\".  To get full credit for a \ntreasure, you must have left it safely in the building, though you get \npartial credit just for locating it. You lose points for getting \nkilled, or for quitting, though the former costs you more. \nThere are also points based on how much (If any) of the cave you've \nmanaged to explore;  in particular, there is a large bonus just for \ngetting in (to distinguish the beginners from the rest of the pack), \nand there are other ways to determine whether you've been through some \nof the more harrowing sections. \nIf you think you've found all the treasures, just keep exploring for a \nwhile.  If nothing interesting happens, you haven't found them all \nyet.  If something interesting DOES happen, it means you're getting a \nbonus and have an opportunity to garner many more points in the \nmaster's section.\nI may occasionally offer hints in you seem to be having trouble.  If I \ndo, I'll warn you in advance how much it will affect your score to \naccept the hints.  Finally, to save paper, you may specify \"brief\", \nwhich tells me never to repeat the full description of a place unless \nyou explicitly ask me to.\n";
const char adv4_string_143[] PROGMEM = "Do you indeed wish to quit now?\n";
const char adv4_string_144[] PROGMEM = "There is nothing here with which to fill the vase.\n";
const char adv4_string_145[] PROGMEM = "The sudden change in temperature has delicately shattered\nthe vase.\n";
const char adv4_string_146[] PROGMEM = "It is beyond your power to do that.\n";
const char adv4_string_147[] PROGMEM = "I don't know how.\n";
const char adv4_string_148[] PROGMEM = "It is too far up for you to reach.\n";
const char adv4_string_149[] PROGMEM = "You killed a little Dwarf.  The body vanished in a cloud\nof greasy black smoke.\n";
const char adv4_string_150[] PROGMEM = "The shell is very strong and impervious to attack.\n";
const char adv4_string_151[] PROGMEM = "What's the matter, can't you read?  Now you'd best start\nover.\n";
const char adv4_string_152[] PROGMEM = "The axe bounces harmlessly off the dragon's thick scales.\n";
const char adv4_string_153[] PROGMEM = "The dragon looks rather nasty.  You'd best not try to get by.\n";
const char adv4_string_154[] PROGMEM = "The little bird attacks the green dragon, and in an\nastounding flurry gets burnt to a cinder.  The ashes blow away.\n";
const char adv4_string_155[] PROGMEM = "On what?\n";
const char adv4_string_156[] PROGMEM = "Okay, from now on I'll only describe a place in full the\nfirst time you come to it.  To get the full description\nsay \"look\".\n";
const char adv4_string_157[] PROGMEM = "Trolls are close relatives with the rocks and have skin as\ntough as that of a rhinoceros.  The troll fends off your\nblows effortlessly.\n";
const char adv4_string_158[] PROGMEM = "The troll deftly catches the axe, examines it carefully,\nand tosses it back, declaring, \"Good workmanship,\nbut it's not valuable enough.\".\n";
const char adv4_string_159[] PROGMEM = "The troll catches your treasure and scurries away out of sight.\n";
const char adv4_string_160[] PROGMEM = "The troll refuses to let you cross.\n";
const char adv4_string_161[] PROGMEM = "There is no longer any way across the chasm.\n";
const char adv4_string_162[] PROGMEM = "Just as you reach the other side, the bridge buckles beneath\nthe weight of the bear, which was still following you around.\nYou scrabble desperately for support, but as the bridge \ncollapses you stumble back and fall into the chasm.\n";
const char adv4_string_163[] PROGMEM = "The bear lumbers toward the troll, who lets out a\nstartled shriek and scurries away.  The bear soon gives\nup pursuit and wanders back.\n";
const char adv4_string_164[] PROGMEM = "The axe misses and lands near the bear where you can't get\nat it.\n";
const char adv4_string_165[] PROGMEM = "With what?  Your bare hands?  Against HIS bear hands??\n";
const char adv4_string_166[] PROGMEM = "The bear is confused;  he only wants to be your friend.\n";
const char adv4_string_167[] PROGMEM = "For crying out loud, the poor thing is already dead!\n";
const char adv4_string_168[] PROGMEM = "The bear eagerly wolfs down your food, after which he seems\nto calm down considerably, and even becomes rather friendly.\n";
const char adv4_string_169[] PROGMEM = "The bear is still chained to the wall.\n";
const char adv4_string_170[] PROGMEM = "The chain is still locked.\n";
const char adv4_string_171[] PROGMEM = "The chain is now unlocked.\n";
const char adv4_string_172[] PROGMEM = "The chain is now locked.\n";
const char adv4_string_173[] PROGMEM = "There is nothing here to which the chain can be locked.\n";
const char adv4_string_174[] PROGMEM = "There is nothing here to eat.\n";
const char adv4_string_175[] PROGMEM = "Do you want the hint?\n";
const char adv4_string_176[] PROGMEM = "Do you need help getting out of the maze?\n";
const char adv4_string_177[] PROGMEM = "You can make the passages look less alike by dropping things.\n";
const char adv4_string_178[] PROGMEM = "Are you trying to explore beyond the plover room?\n";
const char adv4_string_179[] PROGMEM = "There is a way to explore that region without having to\nworry about falling into a pit.  None of the objects\navailable is immediately useful in descovering the secret.\n";
const char adv4_string_180[] PROGMEM = "Do you need help getting out of here?\n";
const char adv4_string_181[] PROGMEM = "Don't go west.\n";
const char adv4_string_182[] PROGMEM = "Gluttony is not one of the Troll's vices.  Avarice, however, is.\n";
const char adv4_string_183[] PROGMEM = "Your lamp is getting dim.. You'd best start wrapping this up,\nunless you can find some fresh batteries.  I seem to recall\nthere's a vending machine in the maze.  Bring some coins\nwith you.\n";
const char adv4_string_184[] PROGMEM = "Your lamp has run out of power.\n";
const char adv4_string_185[] PROGMEM = "There's not much point in wandering around out here, and you\ncan't explore the cave without a lamp.  So let's just call\nit a day.\n";
const char adv4_string_186[] PROGMEM = "There are faint rustling noises from the darkness behind you.\nAs you turn toward them, the beam of your lamp falls across a\nbearded pirate.  He is carrying a large chest.  \"Shiver me\ntimbers!\"  he cries, \"I've been spotted!  I'd best hide\nmeself off to the maze and hide me chest!\".  With that,\nhe vanished into the gloom.\n";
const char adv4_string_187[] PROGMEM = "Your lamp is getting dim.  You'd best go back for\nthose batteries.\n";
const char adv4_string_188[] PROGMEM = "Your lamp is getting dim.. I'm taking the liberty of replacing\nthe batteries.\n";
const char adv4_string_189[] PROGMEM = "Your lamp is getting dim, and you're out of spare batteries.\nYou'd best start wrapping this up.\n";
const char adv4_string_190[] PROGMEM = "I'm afraid the magazine is written in Dwarvish.\n";
const char adv4_string_191[] PROGMEM = "\"This is not the maze where the pirate leaves his treasure\nchest.\"\n";
const char adv4_string_192[] PROGMEM = "Hmm, this looks like a clue, which means it'll cost you 10\npoints to read it.  Should I go ahead and read it anyway?\n";
const char adv4_string_193[] PROGMEM = "It says, \"There is something strange about this place,\nsuch that one of the words I've always known now has\na new effect.\"\n";
const char adv4_string_194[] PROGMEM = "It says the same thing it did before.\n";
const char adv4_string_195[] PROGMEM = "I'm afraid I don't understand.\n";
const char adv4_string_196[] PROGMEM = "\"Congratulations on bringing light into the dark-room!\"\n";
const char adv4_string_197[] PROGMEM = "You strike the mirror a resounding blow, whereupon it\nshatters into a myriad tiny fragments.\n";
const char adv4_string_198[] PROGMEM = "You have taken the vase and hurled it delicately to the\nground.\n";
const char adv4_string_199[] PROGMEM = "You prod the nearest Dwarf, who wakes up grumpily, takes\none look at you, curses, and grabs for his axe.\n";
const char adv4_string_200[] PROGMEM = "Is this acceptable?\n";
const char adv4_string_201[] PROGMEM = "There's no point in suspending a demonstration game.\n";


//
const char * const adventtxt4[ADVENTTXT4_SIZE] PROGMEM = {adv4_string_1, adv4_string_2, adv4_string_3, adv4_string_4,
                                                  adv4_string_5, adv4_string_6, adv4_string_7, adv4_string_8,
                                                  adv4_string_9, adv4_string_10, adv4_string_11, adv4_string_12,
                                                  adv4_string_13, adv4_string_14, adv4_string_15, adv4_string_16,
                                                  adv4_string_17, adv4_string_18, adv4_string_19, adv4_string_20,
                                                  adv4_string_21, adv4_string_22, adv4_string_23, adv4_string_24,
                                                  adv4_string_25, adv4_string_26, adv4_string_27, adv4_string_28,
                                                  adv4_string_29, adv4_string_30, adv4_string_31, adv4_string_32,
                                                  adv4_string_33, adv4_string_34, adv4_string_35, adv4_string_36,
                                                  adv4_string_37, adv4_string_38, adv4_string_39, adv4_string_40,
                                                  adv4_string_41, adv4_string_42, adv4_string_43, adv4_string_44,
                                                  adv4_string_45, adv4_string_46, adv4_string_47, adv4_string_48,
                                                  adv4_string_49, adv4_string_50, adv4_string_51, adv4_string_52,
                                                  adv4_string_53, adv4_string_54, adv4_string_55, adv4_string_56,
                                                  adv4_string_57, adv4_string_58, adv4_string_59, adv4_string_60,
                                                  adv4_string_61, adv4_string_62, adv4_string_63, adv4_string_64,
                                                  adv4_string_65, adv4_string_66, adv4_string_67, adv4_string_68,
                                                  adv4_string_69, adv4_string_70, adv4_string_71, adv4_string_72,
                                                  adv4_string_73, adv4_string_74, adv4_string_75, adv4_string_76,
                                                  adv4_string_77, adv4_string_78, adv4_string_79, adv4_string_80,
                                                  adv4_string_81, adv4_string_82, adv4_string_83, adv4_string_84,
                                                  adv4_string_85, adv4_string_86, adv4_string_87, adv4_string_88,
                                                  adv4_string_89, adv4_string_90, adv4_string_91, adv4_string_92,
                                                  adv4_string_93, adv4_string_94, adv4_string_95, adv4_string_96,
                                                  adv4_string_97, adv4_string_98, adv4_string_99, adv4_string_100,
                                                  adv4_string_101, adv4_string_102, adv4_string_103, adv4_string_104,
                                                  adv4_string_105, adv4_string_106, adv4_string_107, adv4_string_108,
                                                  adv4_string_109, adv4_string_110, adv4_string_111, adv4_string_112,
                                                  adv4_string_113, adv4_string_114, adv4_string_115, adv4_string_116,
                                                  adv4_string_117, adv4_string_118, adv4_string_119, adv4_string_120,
                                                  adv4_string_121, adv4_string_122, adv4_string_123, adv4_string_124,
                                                  adv4_string_125, adv4_string_126, adv4_string_127, adv4_string_128,
                                                  adv4_string_129, adv4_string_130, adv4_string_131, adv4_string_132,
                                                  adv4_string_133, adv4_string_134, adv4_string_135, adv4_string_136,
                                                  adv4_string_137, adv4_string_138, adv4_string_139, adv4_string_140,
                                                  adv4_string_141, adv4_string_142, adv4_string_143, adv4_string_144,
                                                  adv4_string_145, adv4_string_146, adv4_string_147, adv4_string_148,
                                                  adv4_string_149, adv4_string_150, adv4_string_151, adv4_string_152,
                                                  adv4_string_153, adv4_string_154, adv4_string_155, adv4_string_156,
                                                  adv4_string_157, adv4_string_158, adv4_string_159, adv4_string_160,
                                                  adv4_string_161, adv4_string_162, adv4_string_163, adv4_string_164,
                                                  adv4_string_165, adv4_string_166, adv4_string_167, adv4_string_168,
                                                  adv4_string_169, adv4_string_170, adv4_string_171, adv4_string_172,
                                                  adv4_string_173, adv4_string_174, adv4_string_175, adv4_string_176,
                                                  adv4_string_177, adv4_string_178, adv4_string_179, adv4_string_180,
                                                  adv4_string_181, adv4_string_182, adv4_string_183, adv4_string_184,
                                                  adv4_string_185, adv4_string_186, adv4_string_187, adv4_string_188,
                                                  adv4_string_189, adv4_string_190, adv4_string_191, adv4_string_192,
                                                  adv4_string_193, adv4_string_194, adv4_string_195, adv4_string_196,
                                                  adv4_string_197, adv4_string_198, adv4_string_199, adv4_string_200,
                                                  adv4_string_201};
