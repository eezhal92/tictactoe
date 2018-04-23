#include "main.hpp"

int main()
{
  Board board;
  string player_x_name, player_o_name;
  char winner = 'z';
  int number_of_turns = 0;

  getPlayerNames(player_x_name, player_o_name);

  while (number_of_turns < 8)
  {
    int position;

    promptPosition(board, player_x_name, 'x');

    winner = board.determineWinner();

    if (winner != 'z')
    {
      cout << "\n";
      cout << "Winner is ";

      if (winner == 'x')
        cout << player_x_name << endl;
      if (winner == 'o')
        cout << player_o_name << endl;

      cout << "\n";
      board.drawPosition();

      break;
    }

    promptPosition(board, player_o_name, 'o');

    winner = board.determineWinner();

    if (winner != 'z')
    {
      cout << "\n";
      cout << "Winner is ";

      if (winner == 'x')
        cout << player_x_name << endl;
      if (winner == 'o')
        cout << player_o_name << endl;

      cout << "\n";
      board.drawPosition();

      break;
    }

    number_of_turns++;
  }

  return 0;
}