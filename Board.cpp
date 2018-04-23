#include <iostream>

using namespace std;

class Board
{
  char positions_taken[16];

public:
  Board();
  void drawPosition();
  void drawLegenda();
  int setPosition(int grid, char letter);
  char determineWinner();

private:
  char getRowWinner();
  char getColumnWinner();
  char getDiagonalWinner();
};

Board::Board()
{
  for (int i = 0; i < 16; i++)
  {
    positions_taken[i] = '_';
  }
}

char Board::getRowWinner()
{
  int x_in_row_count = 0;
  int o_in_row_count = 0;

  for (int first_grid_row = 0; first_grid_row < 16; first_grid_row = first_grid_row + 4)
  {
    for (int i = 0; i < 4; i++)
    {
      if (positions_taken[i + first_grid_row] == 'x')
        x_in_row_count++;
      if (positions_taken[i + first_grid_row] == 'o')
        o_in_row_count++;
    }

    if (x_in_row_count == 4)
    {
      return 'x';
    }

    if (o_in_row_count == 4)
    {
      return 'o';
    }

    // reset
    x_in_row_count = 0;
    o_in_row_count = 0;
  }

  return 'z';
}

char Board::getColumnWinner()
{
  int x_in_row_count = 0;
  int o_in_row_count = 0;

  for (int first_grid_column = 0; first_grid_column < 4; first_grid_column++)
  {
    for (int i = 0; i < 16; i = i + 4)
    {
      if (positions_taken[i + first_grid_column] == 'x')
        x_in_row_count++;
      if (positions_taken[i + first_grid_column] == 'o')
        o_in_row_count++;
    }

    if (x_in_row_count == 4)
    {
      return 'x';
    }

    if (o_in_row_count == 4)
    {
      return 'o';
    }

    // reset
    x_in_row_count = 0;
    o_in_row_count = 0;
  }

  return 'z';
}

char Board::getDiagonalWinner()
{
  int x_in_row_count = 0;
  int o_in_row_count = 0;

  for (int i = 0; i < 16; i = i + 5)
  {
    if (positions_taken[i] == 'x')
      x_in_row_count++;
    if (positions_taken[i] == 'o')
      o_in_row_count++;
  }

  if (x_in_row_count != 4 && o_in_row_count != 4)
  {
    // reset
    x_in_row_count = 0;
    o_in_row_count = 0;

    for (int i = 3; i < 15; i = i + 3)
    {
      if (positions_taken[i] == 'x')
        x_in_row_count++;
      if (positions_taken[i] == 'o')
        o_in_row_count++;
    }
  }

  if (x_in_row_count == 4)
  {
    return 'x';
  }

  if (o_in_row_count == 4)
  {
    return 'o';
  }

  return 'z';
}

char Board::determineWinner()
{
  char winner = getRowWinner();

  if (winner == 'z')
  {
    winner = getColumnWinner();
  }

  if (winner == 'z')
  {
    winner = getDiagonalWinner();
  }

  return winner;
}

void Board::drawPosition()
{
  for (int i = 0; i < 16; i++)
  {
    bool is_first_item_in_row = i % 4 == 0;

    if (is_first_item_in_row)
    {
      cout << "| ";
    }
    else
    {
      cout << " | ";
    }

    cout << positions_taken[i];
    if (i % 4 == 3)
    {
      cout << " |\n";
    }
  }
}

void Board::drawLegenda()
{
  for (int i = 0; i < 16; i++)
  {
    bool is_first_item_in_row = i % 4 == 0;

    if (is_first_item_in_row)
    {
      cout << "| ";
    }
    else
    {
      cout << " | ";
    }

    // Padding
    if (i < 10)
    {
      cout << " ";
    }

    cout << i;

    if (i % 4 == 3)
    {
      cout << " |\n";
    }
  }
}

int Board::setPosition(int grid, char letter)
{
  bool is_valid_grid = grid >= 0 && grid <= 15;

  if (!is_valid_grid)
  {
    return -1;
  }

  if (positions_taken[grid] == '_')
  {
    positions_taken[grid] = letter;

    return grid;
  }

  return -1;
}