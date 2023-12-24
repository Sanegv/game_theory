# game_theory

tournaments of different game theory strategies

--- 

## Files

- ### strategies

These files (.h and .c) contain a few different strategies. 
In order to be used with function pointers, all have the same prototype :
```c
int strategy(Score** values, int lastOpponentChoice, char player);
```

the files also contain the struct Score, that is simply a collection of two ints, 
as well as a function that returns the sum of the integers in a score struct, 
and one that prints the values of these integers.

- ### game

These files contain the necessary functions to simplify the creation of a game,
or several games in a row. It can also print and free the grids.

In term, I might decide to create a struct that stores all the data used during a game
(the grid of scores, the function pointers for strategies, the last results, etc).

- ### main

This file contains a few methods to show how the functions interact.

--- 

## TODO

- **implement threads**
