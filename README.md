# Colossal Cave Adventure

This is the real, full-blown Colossal Cave Adventure game, written by
Will Crowther and Don Woods at Stanford AI Lab in the early '70s.  It is
the first interactive fiction game where the computer simulates and
describes a situation, and the user types in what to do next, in simple
English.

## Port to MCU

The game shall be ported to run on an AtMega2560 (as used in some Arduino clones).

The original code can be found at 'https://github.com/troglobit/adventure' and is licensed under the Unlicense.

Most of the groundwork has been completed, and the game now utilizes a stdin/out interface, allowing it to be played over a serial connection. Much effort has been dedicated to storing strings in Program Memory to accommodate the limited 8kB RAM. Currently, the game utilizes less than 1.5kB RAM, leaving room for minor improvements such as better separation of debug and release code. With approximately 6kB of free RAM available, the next steps involve caching certain strings to optimize performance. Additionally, this should allow for the direct execution of Unity and testing of components within a simavr session.

An early bug has been identified and documented in the issues section. You are encouraged to investigate and submit a pull request if you discover a solution. Feel free to contribute to this exciting project!
