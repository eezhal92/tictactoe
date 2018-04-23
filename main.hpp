#include "Board.cpp"

void getPlayerNames();
void promptPosition(Board &, string, char);

void getPlayerNames(string &player_x, string &player_o)
{
  std::cout << "Name of user to be 'x' : ";
  std::cin >> player_x;
  std::cout << "Name of user to be 'o' : ";
  std::cin >> player_o;
}

void promptPosition(Board &board, string player_name, char letter)
{
  int position = -1;
  cout << "\n";
  cout << player_name << ", where would you like to place an " << letter << " ?" << endl;
  cout << "\n";

  do
  {
    board.drawLegenda();

    cout << "\n";
    cout << "Enter an integer between 0 and 15: ";

    cin.clear();
    cin >> position;

    bool is_valid_position = position <= 15 || position >= 0;

    if (!is_valid_position)
    {
      cout << "That is not a valid position" << endl;
      position = -1;
    }

    int grid_taken;

    grid_taken = board.setPosition(position, letter);

    if (grid_taken == -1)
    {
      cout << "Position: " << position << " is already taken. \n";

      position = grid_taken;
    }

    cout << "\n";
  } while (position == -1);

  board.drawPosition();
}