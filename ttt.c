// Vincent P. Rodriguez CPSC223C-01

#include <stdio.h>
#define ROWS 3
#define COLUMNS 3

// Print the tic tac toe board and the characters in the spaces.
void Print(char board[ROWS][COLUMNS])
{
  // loops through the rows
  for (int i = 0; i < ROWS; i++)
  {
    // Prints "-+-+-" after rows 1 and 2.
    if (i == 1 || i == 2)
    {
      printf("\n-+-+-\n");
    }
    // Loops through the columns.
    for (int j = 0; j < COLUMNS; j++)
    {
      // Prints "|" after columns 1 and 2.
      if (j == 1 || j == 2)
      {
        printf("|");
      }
      printf("%c", board[i][j]);
    }
  }
  printf("\n");
}

//------------------------------------------------------------------------------

// Sets the player's piece into the space they chose.
void SetPlayerMove(char game_board[ROWS][COLUMNS], int player_num)
{
  char player_piece;

  int row_choice,
      column_choice;

  int input;

  // Determines whether to place an X or O based off of the player number.
  // Player 1 = X
  // Player 2 = O
  if (player_num == 1)
  {
    player_piece = 'X';
  }
  else
  {
    player_piece = 'O';
  }

  // Loops until the player provides a valid space.
  do
  {
    // Prompts player to choose their space (row column).
    printf("Which Row would you like?\n");
    scanf("%d", &row_choice);
    printf("Which Col would you like?\n");
    scanf("%d", &column_choice);

    // Checks if the row choice is a valid row on the board.
    if (row_choice < 0 || row_choice > 2)
    {
      printf("Please choose a row between 0 and 2.\n");
      input = 0;

    // Checks if the column choice is a valid column on the board.
    }
    else if (column_choice < 0 || column_choice > 2)
    {
      printf("Please choose a column between 0 and 2.\n");
      input = 0;

    // Checks if the space is filled.
    }
    else if (game_board[row_choice][column_choice] != ' ')
    {
      printf("That space is filled. Please choose another space.\n");
      input = 0;

    // If the space is empty, fills that space with the player's piece.
    }
    else if (game_board[row_choice][column_choice] == ' ')
    {
      game_board[row_choice][column_choice] = player_piece;
      input = 1;
    }

  // Will loop through the do-while loop until input is 1. That is, until the
  // user puts a piece in a valid, empty space.
  } while (input == 0);
}

//------------------------------------------------------------------------------

// Checks the Rows for a TicTacToe.
int CheckRows(char board[ROWS][COLUMNS], char piece)
{

  //Loops through each row.
  for (int i = 0; i < ROWS; i++)
  {

    //Checks each column in that particular row to see if they all have the
    //same piece.
    if (board[i][0] == piece &&
        board[i][1] == piece &&
        board[i][2] == piece)
    {

    //If all columns in the row contain the same piece, returns true(1).
      return 1;
    }
  }

  //At this point, it is assumed that no rows have the same piece in all three
  //of its columns.
  return 0;
}

//------------------------------------------------------------------------------

// Checks the Columns for a TicTacToe.
int CheckColumns(char board[ROWS][COLUMNS], char piece)
{

  //Loops through each column.
  for (int i = 0; i < COLUMNS; i++)
  {

    //Checks each row in that particular column to see if they all have the
    //same piece.
    if (board[0][i] == piece &&
        board[1][i] == piece &&
        board[2][i] == piece)
    {

    //If all rows in that column contain the same piece, returns true(1).
      return 1;
    }
  }

  //At this point, it is assumed that no columns have the same piece in all
  //three of its rows.
  return 0;
}

//------------------------------------------------------------------------------

// Checks for a diagonal TicTacToe.
int CheckDiagonals(char board[ROWS][COLUMNS], char piece)
{

  /*If all spaces in the diagonal going from top left to bottom right or in the
    diagonal going from bottom left to top right contain the same piece, returns
    true(1).*/
  if (( //DIAGONAL FROM TOP LEFT TO BOTTOM RIGHT.
        board[0][0] == piece &&
        board[1][1] == piece &&
        board[2][2] == piece ) ||
        //DIAGONAL FROM BOTTOM LEFT TO TOP RIGHT.
      ( board[0][2] == piece &&
        board[1][1] == piece &&
        board[2][0] == piece ))
  {
    return 1;
  }

  //At this point, assumes none of the diagonals contain the same piece.
  return 0;
}

//------------------------------------------------------------------------------

// Checks if there is a winner.
int IsWinner(char board[ROWS][COLUMNS], char piece)
{

  //Checks to see if the same piece is in each spot of any row, column, or
  //diagonal. Returns true(1) if any of those is the case.
  if (CheckRows(board, piece) == 1 ||
      CheckColumns(board, piece) == 1 ||
      CheckDiagonals(board, piece) == 1)
  {
    return 1;
  }

  //If there is no winner, returns false(0) until the function detects a winning
  //pattern.
  return 0;
}

//------------------------------------------------------------------------------

//Loops through the 2D array and checks all of the spaces to see if they are
//empty or if there is a piece occupying the space.
int IsBoardFull(char board[ROWS][COLUMNS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLUMNS; j++)
    {

      //If there is a space that is empty, immediately returns false(0) since if
      //there is at least one space that is empty, it is highly unlikely that
      //the board is full.
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }

  //Returns true(1) if all the spaces on the board are full.
  return 1;
}

// Check on the board.
// If X Player has tictactoe, return 1.
// If O Player has tictactoe, return 2.
// If Draw, return 3.
// Game can still be played, return 0.
int DetermineBoardState(char board[ROWS][COLUMNS]) {
  if (IsWinner(board, 'X') == 1) {
    printf("X PLayer Wins!\n");
    return 1;
  } else if (IsWinner(board, 'O') == 1) {
    printf("O Player Wins!\n");
    return 2;
  } else if (IsBoardFull(board) == 1) {
    printf("Cat's Game!\n");
    return 3;
  }

  return 0;
}

int main()
{
  // Initializes the tic tac toe board with empty spaces.
  char game_board[ROWS][COLUMNS];
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLUMNS; j++)
    {
      game_board[i][j] = ' ';
    }
  }

  printf("Welcome to Tic-Tac-Toe\n");
  printf("======================\n");

  // Since there are only 9 spaces, only 9 turns will be taking place.
  for (int i = 0; i < 9; i++)
  {
    // Player1 turn.
    // Checks to see if there is a winner or a draw, then exits the loop.
    if ((DetermineBoardState(game_board) != 0) ||
         IsBoardFull(game_board) == 1)
    {
      break;
    }
    else
    {
      printf("Player 1 turn 'X'\n");
      SetPlayerMove(game_board, 1);
      Print(game_board);
    }

    // Player2 turn.
    if ((DetermineBoardState(game_board) != 0) ||
         IsBoardFull(game_board) == 1)
    {
      break;
    }
    else
    {
      printf("Player 2 turn 'O'\n");
      SetPlayerMove(game_board, 2);
      Print(game_board);
    }
  }
  return 0;
}
