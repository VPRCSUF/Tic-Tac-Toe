# Tic-Tac-Toe
A basic player vs. player tic-tac-toe game created in C.

## Getting Started
Clone the repository.

```shell
git clone https://github.com/VPRCSUF/Tic-Tac-Toe.git
```
Compile ttt.c and run.

```shell
cc -o run ttt.c
./run
```

## What to Expect
After executing ttt.c, the game will begin with:

```shell
Welcome to Tic-Tac-Toe
======================
Player 1 turn 'X'
Which Row would you like?

```
Player 1 is prompted to choose a row between 0-2 and then a column between 0-2.
```shell
Welcome to Tic-Tac-Toe
======================
Player 1 turn 'X'
Which Row would you like?
0
Which Col would you like?
0
X| | 
-+-+-
 | | 
-+-+-
 | | 
Player 2 turn 'O'
Which Row would you like?

```
Once Player 1 chose their space, Player 2 will be prompted with the same questions.
```shell
Player 2 turn 'O'
Which Row would you like?
1
Which Col would you like?
1
X| | 
-+-+-
 |O| 
-+-+-
 | | 
Player 1 turn 'X'
Which Row would you like?

```
This will continue until there is a winner or a draw (Cat's game).
```shell
Player 2 turn 'O'
Which Row would you like?
0
Which Col would you like?
1
X|O|X
-+-+-
 |O| 
-+-+-
O| |X
Player 1 turn 'X'
Which Row would you like?
1
Which Col would you like?
2
X|O|X
-+-+-
 |O|X
-+-+-
O| |X
X PLayer Wins!
```
Example of a draw (Cat's game):
```shell
Player 2 turn 'O'
Which Row would you like?
1
Which Col would you like?
2
X|O|X
-+-+-
 |O|O
-+-+-
O|X|X
Player 1 turn 'X'
Which Row would you like?
1
Which Col would you like?
0
X|O|X
-+-+-
X|O|O
-+-+-
O|X|X
Cat's Game!
```
## Have Fun!
Enjoy playing tic-tac-toe with your friends or by yourself!
