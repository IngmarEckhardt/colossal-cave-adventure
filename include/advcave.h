#include <avr/pgmspace.h>

#define CAVETXT_SIZE 140

const char cave_string_1[] PROGMEM = "2002000,2044000,2029000,3003000,3012000,3019000,3043000,4005000,4013000,4014000,4046000,4030000,5006000,5045000,5043000,8063000,";
const char cave_string_2[] PROGMEM = "1002000,1012000,1007000,1043000,1045000,1030000,5006000,5045000,5046000,";
const char cave_string_3[] PROGMEM = "1003000,1011000,1032000,1044000,11062000,33065000,79005000,79014000,";
const char cave_string_4[] PROGMEM = "1004000,1012000,1045000,5006000,5043000,5044000,5029000,7005000,7046000,7030000,8063000,";
const char cave_string_5[] PROGMEM = "4009000,4043000,4030000,5006050,5007050,5045050,6006000,5044000,5046000,";
const char cave_string_6[] PROGMEM = "1002000,1045000,4009000,4043000,4044000,4030000,5006000,5046000,";
const char cave_string_7[] PROGMEM = "1012000,4004000,4045000,5006000,5043000,5044000,8005000,8015000,8016000,8046000,595060000,595014000,595030000,";
const char cave_string_8[] PROGMEM = "5006000,5043000,5046000,5044000,1012000,7004000,7013000,7045000,9003303,9019303,9030303,593003000,";
const char cave_string_9[] PROGMEM = "8011303,8029303,593011000,10017000,10018000,10019000,10044000,14031000,11051000,";
const char cave_string_10[] PROGMEM = "9011000,9020000,9021000,9043000,11019000,11022000,11044000,11051000,14031000,";
const char cave_string_11[] PROGMEM = "8063303,9064000,10017000,10018000,10023000,10024000,10043000,12025000,12019000,12029000,12044000,3062000,14031000,";
const char cave_string_12[] PROGMEM = "8063303,9064000,11030000,11043000,11051000,13019000,13029000,13044000,14031000,";
const char cave_string_13[] PROGMEM = "8063303,9064000,11051000,12025000,12043000,14023000,14031000,14044000,";
const char cave_string_14[] PROGMEM = "8063303,9064000,11051000,13023000,13043000,20030150,20031150,20034150,15030000,16033000,16044000,";
const char cave_string_15[] PROGMEM = "18036000,18046000,17007000,17038000,17044000,19010000,19030000,19045000,22029150,22031150,22034150,22035150,22023150,22043150,14029000,34055000,";
const char cave_string_16[] PROGMEM = "14001000,";
const char cave_string_17[] PROGMEM = "15038000,15043000,596039312,21007412,597041412,597042412,597044412,597069412,27041000,";
const char cave_string_18[] PROGMEM = "15038000,15011000,15045000,";
const char cave_string_19[] PROGMEM = "15010000,15029000,15043000,28045311,28036311,29046311,29037311,30044311,30007311,32045000,74049035,32049211,74066000,";
const char cave_string_20[] PROGMEM = "001000,";
const char cave_string_21[] PROGMEM = "001000,";
const char cave_string_22[] PROGMEM = "15001000,";
const char cave_string_23[] PROGMEM = "67043000,67042000,68044000,68061000,25030000,25031000,648052000,";
const char cave_string_24[] PROGMEM = "67029000,67011000,";
const char cave_string_25[] PROGMEM = "23029000,23011000,31056724,26056000,";
const char cave_string_26[] PROGMEM = "88001000,";
const char cave_string_27[] PROGMEM = "596039312,21007412,597041412,597042412,597043412,597069412,17041000,40045000,41044000,";
const char cave_string_28[] PROGMEM = "19038000,19011000,19046000,33045000,33055000,36030000,36052000,";
const char cave_string_29[] PROGMEM = "19038000,19011000,19045000,";
const char cave_string_30[] PROGMEM = "19038000,19011000,19043000,62044000,62029000,";
const char cave_string_31[] PROGMEM = "89001524,90001000,";
const char cave_string_32[] PROGMEM = "19001000,";
const char cave_string_33[] PROGMEM = "3065000,28046000,34043000,34053000,34054000,35044000,302071159,100071000,";
const char cave_string_34[] PROGMEM = "33030000,33055000,15029000,";
const char cave_string_35[] PROGMEM = "33043000,33055000,20039000,";
const char cave_string_36[] PROGMEM = "37043000,37017000,28029000,28052000,39044000,65070000,";
const char cave_string_37[] PROGMEM = "36044000,36017000,38030000,38031000,38056000,";
const char cave_string_38[] PROGMEM = "37056000,37029000,37011000,595060000,595014000,595030000,595004000,595005000,";
const char cave_string_39[] PROGMEM = "36043000,36023000,64030000,64052000,64058000,65070000,";
const char cave_string_40[] PROGMEM = "41001000,";
const char cave_string_41[] PROGMEM = "42046000,42029000,42023000,42056000,27043000,59045000,60044000,60017000,";
const char cave_string_42[] PROGMEM = "41029000,42045000,43043000,45046000,80044000,";
const char cave_string_43[] PROGMEM = "42044000,44046000,45043000,";
const char cave_string_44[] PROGMEM = "43043000,48030000,50046000,82045000,";
const char cave_string_45[] PROGMEM = "42044000,43045000,46043000,47046000,87029000,87030000,";
const char cave_string_46[] PROGMEM = "45044000,45011000,";
const char cave_string_47[] PROGMEM = "45043000,45011000,";
const char cave_string_48[] PROGMEM = "44029000,44011000,";
const char cave_string_49[] PROGMEM = "50043000,51044000,";
const char cave_string_50[] PROGMEM = "44043000,49044000,51030000,52046000,";
const char cave_string_51[] PROGMEM = "49044000,50029000,52043000,53046000,";
const char cave_string_52[] PROGMEM = "50044000,51043000,52046000,53029000,55045000,86030000,";
const char cave_string_53[] PROGMEM = "51044000,52045000,54046000,";
const char cave_string_54[] PROGMEM = "53044000,53011000,";
const char cave_string_55[] PROGMEM = "52044000,55045000,56030000,57043000,";
const char cave_string_56[] PROGMEM = "55029000,55011000,";
const char cave_string_57[] PROGMEM = "13030000,13056000,55044000,58046000,83045000,84043000,";
const char cave_string_58[] PROGMEM = "57043000,57011000,";
const char cave_string_59[] PROGMEM = "27001000,";
const char cave_string_60[] PROGMEM = "41043000,41029000,41017000,61044000,62045000,62030000,62052000,";
const char cave_string_61[] PROGMEM = "60043000,62045000,107046100,";
const char cave_string_62[] PROGMEM = "60044000,63045000,30043000,61046000,";
const char cave_string_63[] PROGMEM = "62046000,62011000,";
const char cave_string_64[] PROGMEM = "39029000,39056000,39059000,65044000,65070000,103045000,103074000,106043000,";
const char cave_string_65[] PROGMEM = "64043000,66044000,556046080,68061000,556029080,70029050,39029000,556045060,72045075,71045000,556030080,106030000,";
const char cave_string_66[] PROGMEM = "65047000,67044000,556046080,77025000,96043000,556050050,97072000,";
const char cave_string_67[] PROGMEM = "66043000,23044000,23042000,24030000,24031000,";
const char cave_string_68[] PROGMEM = "23046000,69029000,69056000,65045000,";
const char cave_string_69[] PROGMEM = "68030000,68061000,120046331,119046000,109045000,113075000,";
const char cave_string_70[] PROGMEM = "71045000,65030000,65023000,111046000,";
const char cave_string_71[] PROGMEM = "65048000,70046000,110045000,";
const char cave_string_72[] PROGMEM = "65070000,118049000,73045000,97048000,97072000,";
const char cave_string_73[] PROGMEM = "72046000,72017000,72011000,";
const char cave_string_74[] PROGMEM = "19043000,120044331,121044000,75030000,";
const char cave_string_75[] PROGMEM = "76046000,77045000,";
const char cave_string_76[] PROGMEM = "75045000,";
const char cave_string_77[] PROGMEM = "75043000,78044000,66045000,66017000,";
const char cave_string_78[] PROGMEM = "77046000,";
const char cave_string_79[] PROGMEM = "3001000,";
const char cave_string_80[] PROGMEM = "42045000,80044000,80046000,81043000,";
const char cave_string_81[] PROGMEM = "80044000,80011000,";
const char cave_string_82[] PROGMEM = "44046000,44011000,";
const char cave_string_83[] PROGMEM = "57046000,84043000,85044000,";
const char cave_string_84[] PROGMEM = "57045000,83044000,114050000,";
const char cave_string_85[] PROGMEM = "83043000,83011000,";
const char cave_string_86[] PROGMEM = "52029000,52011000,";
const char cave_string_87[] PROGMEM = "45029000,45030000,";
const char cave_string_88[] PROGMEM = "25030000,25056000,25043000,20039000,92044000,92027000,";
const char cave_string_89[] PROGMEM = "25001000,";
const char cave_string_90[] PROGMEM = "23001000,";
const char cave_string_91[] PROGMEM = "95045000,95073000,95023000,72030000,72056000,";
const char cave_string_92[] PROGMEM = "88046000,93043000,94045000,";
const char cave_string_93[] PROGMEM = "92046000,92027000,92011000,";
const char cave_string_94[] PROGMEM = "92046000,92027000,92023000,95045309,95003309,95073309,611045000,";
const char cave_string_95[] PROGMEM = "94046000,94011000,92027000,91044000,";
const char cave_string_96[] PROGMEM = "66044000,66011000,";
const char cave_string_97[] PROGMEM = "66048000,72044000,72017000,98029000,98045000,98073000,";
const char cave_string_98[] PROGMEM = "97046000,97072000,99044000,";
const char cave_string_99[] PROGMEM = "98050000,98073000,301043000,301023000,100043000,";
const char cave_string_100[] PROGMEM = "301044000,301023000,301011000,99044000,302071159,33071000,101047000,101022000,";
const char cave_string_101[] PROGMEM = "100046000,100071000,100011000,";
const char cave_string_102[] PROGMEM = "103030000,103074000,103011000,";
const char cave_string_103[] PROGMEM = "102029000,102038000,104030000,618046114,619046115,64046000,";
const char cave_string_104[] PROGMEM = "103029000,103074000,105030000,";
const char cave_string_105[] PROGMEM = "104029000,104011000,103074000,";
const char cave_string_106[] PROGMEM = "64029000,65044000,108043000,";
const char cave_string_107[] PROGMEM = "131046000,132049000,133047000,134048000,135029000,136050000,137043000,138044000,139045000,61030000,";
const char cave_string_108[] PROGMEM = "556043095,556045095,556046095,556047095,556048095,556049095,556050095,556029095,556030095,106043000,626044000,";
const char cave_string_109[] PROGMEM = "69046000,113045000,113075000,";
const char cave_string_110[] PROGMEM = "71044000,20039000,";
const char cave_string_111[] PROGMEM = "70045000,50030040,50039040,50056040,53030050,45030000,";
const char cave_string_112[] PROGMEM = "131049000,132045000,133043000,134050000,135048000,136047000,137044000,138030000,139029000,140046000,";
const char cave_string_113[] PROGMEM = "109046000,109011000,109109000,";
const char cave_string_114[] PROGMEM = "84048000,";
const char cave_string_115[] PROGMEM = "116049000,";
const char cave_string_116[] PROGMEM = "115047000,593030000,";
const char cave_string_117[] PROGMEM = "118049000,660041233,660042233,660069233,660047233,661041332,303041000,21039332,596039000,";
const char cave_string_118[] PROGMEM = "72030000,117029000,";
const char cave_string_119[] PROGMEM = "69045000,69011000,653043000,65307000,";
const char cave_string_120[] PROGMEM = "69045000,74043000,";
const char cave_string_121[] PROGMEM = "74043000,74011000,653045000,653007000,";
const char cave_string_122[] PROGMEM = "123047000,660041233,660042233,660069233,660049233,303041000,596039000,124077000,126028000,129040000,";
const char cave_string_123[] PROGMEM = "122044000,124043000,124077000,126028000,129040000,";
const char cave_string_124[] PROGMEM = "123044000,125047000,125036000,128048000,128037000,128030000,126028000,129040000,";
const char cave_string_125[] PROGMEM = "124046000,124077000,126045000,126028000,127043000,127017000,";
const char cave_string_126[] PROGMEM = "125046000,125023000,125011000,124077000,610030000,610039000,";
const char cave_string_127[] PROGMEM = "125044000,125011000,125017000,124077000,126028000,";
const char cave_string_128[] PROGMEM = "124045000,124029000,124077000,129046000,129030000,129040000,126028000,";
const char cave_string_129[] PROGMEM = "128044000,128029000,124077000,130043000,130019000,130040000,130003000,126028000,";
const char cave_string_130[] PROGMEM = "129044000,124077000,126028000,";
const char cave_string_131[] PROGMEM = "107044000,132048000,133050000,134049000,135047000,136029000,137030000,138045000,139046000,112043000,";
const char cave_string_132[] PROGMEM = "107050000,131029000,133045000,134046000,135044000,136049000,137047000,138043000,139030000,112048000,";
const char cave_string_133[] PROGMEM = "107029000,131030000,132044000,134047000,135049000,136043000,137045000,138050000,139048000,112046000,";
const char cave_string_134[] PROGMEM = "107047000,131045000,132050000,133048000,135043000,136030000,137046000,138029000,139044000,112049000,";
const char cave_string_135[] PROGMEM = "107045000,131048000,132030000,133046000,134043000,136044000,137049000,138047000,139050000,112029000,";
const char cave_string_136[] PROGMEM = "107043000,131044000,132029000,133049000,134030000,135046000,137050000,138048000,139047000,112045000,";
const char cave_string_137[] PROGMEM = "107048000,131047000,132046000,133030000,134029000,135050000,136045000,138049000,139043000,112044000,";
const char cave_string_138[] PROGMEM = "107030000,131043000,132047000,133029000,134044000,135045000,136046000,137048000,139049000,112050000,";
const char cave_string_139[] PROGMEM = "107049000,131050000,132043000,133044000,134045000,135030000,136048000,137029000,138046000,112047000,";
const char cave_string_140[] PROGMEM = "112045000,112011000,";
const char * const cave[CAVETXT_SIZE] = {cave_string_1, cave_string_2, cave_string_3, cave_string_4, cave_string_5,
                                 cave_string_6, cave_string_7, cave_string_8, cave_string_9, cave_string_10,
                                 cave_string_11, cave_string_12, cave_string_13, cave_string_14, cave_string_15,
                                 cave_string_16, cave_string_17, cave_string_18, cave_string_19, cave_string_20,
                                 cave_string_21, cave_string_22, cave_string_23, cave_string_24, cave_string_25,
                                 cave_string_26, cave_string_27, cave_string_28, cave_string_29, cave_string_30,
                                 cave_string_31, cave_string_32, cave_string_33, cave_string_34, cave_string_35,
                                 cave_string_36, cave_string_37, cave_string_38, cave_string_39, cave_string_40,
                                 cave_string_41, cave_string_42, cave_string_43, cave_string_44, cave_string_45,
                                 cave_string_46, cave_string_47, cave_string_48, cave_string_49, cave_string_50,
                                 cave_string_51, cave_string_52, cave_string_53, cave_string_54, cave_string_55,
                                 cave_string_56, cave_string_57, cave_string_58, cave_string_59, cave_string_60,
                                 cave_string_61, cave_string_62, cave_string_63, cave_string_64, cave_string_65,
                                 cave_string_66, cave_string_67, cave_string_68, cave_string_69, cave_string_70,
                                 cave_string_71, cave_string_72, cave_string_73, cave_string_74, cave_string_75,
                                 cave_string_76, cave_string_77, cave_string_78, cave_string_79, cave_string_80,
                                 cave_string_81, cave_string_82, cave_string_83, cave_string_84, cave_string_85,
                                 cave_string_86, cave_string_87, cave_string_88, cave_string_89, cave_string_90,
                                 cave_string_91, cave_string_92, cave_string_93, cave_string_94, cave_string_95,
                                 cave_string_96, cave_string_97, cave_string_98, cave_string_99, cave_string_100,
                                 cave_string_101, cave_string_102, cave_string_103, cave_string_104, cave_string_105,
                                 cave_string_106, cave_string_107, cave_string_108, cave_string_109, cave_string_110,
                                 cave_string_111, cave_string_112, cave_string_113, cave_string_114, cave_string_115,
                                 cave_string_116, cave_string_117, cave_string_118, cave_string_119, cave_string_120,
                                 cave_string_121, cave_string_122, cave_string_123, cave_string_124, cave_string_125,
                                 cave_string_126, cave_string_127, cave_string_128, cave_string_129, cave_string_130,
                                 cave_string_131, cave_string_132, cave_string_133, cave_string_134, cave_string_135,
                                 cave_string_136, cave_string_137, cave_string_138, cave_string_139, cave_string_140};
size_t cavesz = sizeof(cave) / sizeof(cave[0]);