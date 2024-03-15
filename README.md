# Colossal Cave Adventure

This is the real, full-blown Colossal Cave Adventure game, written by
Will Crowther and Don Woods at Stanford AI Lab in the early '70s.  It is
the first interactive fiction game where the computer simulates and
describes a situation, and the user types in what to do next, in simple
English.

## Port to MCU

The game is ported to run on a AtMega2560 (such as used in some arduino clones).

The original code is from 'https://github.com/troglobit/adventure' and under unlicense.

The most of the work is done and the game uses stdin/out Interface and can be played over 
a serial connection. Most of the work until now was placing the strings into Program Memory, 
to deal with 8kB Ram. The game uses now less then 1.5kB Ram and has space for small improvement
with better seperation of debug and release code. The 6kB free Ram should be used in the next
steps to cache some strings, and also should allow to run unity directly and test the components
in a simavr session. There is a early coming bug, described in issues. Feel free to investigate
and open a pull request if you found the solution.
