# include <iostream>
using namespace std;
int choose_character() // User Select the Character 'O' , 'X' and return and integer ( 1, 2 , 0)  for 1 -> 'X' and for '2' -> 'O' 
{
	char choice_character  = ' ';
	cout << "\n>>> Wellcome to the game                    " << endl;
	cout << "\n>>> !----player 1 choose the character----! " << endl;
	cout << "\n>>> (available characters are 'O' and 'X')  " << endl;
	cin >> choice_character;
	if (choice_character == 'o' || choice_character == 'O')
	{
		return 2;
	}
	else if (choice_character == 'X' || choice_character == 'x')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void show_game_table(char TicTacToeBoard[3][3]) // Display The Game Board 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << TicTacToeBoard[i][j];
			if (j == 0 || j == 1)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i == 0 || i == 1)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << "--  ";
			}
		}

		cout << endl;
	}
}


int table_check(char poistion, char TicTacToeBoard[3][3], char choice) // on the board at which position character will replace and also this function return a integer (1, 0) 1 for successfully replace the character and 0 for already selected character
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (TicTacToeBoard[i][j] == poistion)
			{
				TicTacToeBoard[i][j] = choice;
				return 1;
			}
		}
	}
  return 0;
}
void player_1(char TicTacToeBoard[3][3])  // Player-1 one will selec the psition in this function 
{
	char select_position = ' ', choice = 'O';

	cin >> select_position;

	if (table_check(select_position, TicTacToeBoard, choice))
	{
		show_game_table(TicTacToeBoard);
	}
	else
	{
		cout << "\n>>> !--------------------already checked--------------------------!\n>>> Enter Again....." << endl;
		player_1(TicTacToeBoard);
	}
	
}
void player_2(char TicTacToeBoard[3][3]) // Player-1 one will selec the psition in this function 
{
	char select_position = ' ', choice = 'X';
	cin >> select_position;

	if (table_check(select_position, TicTacToeBoard, choice))
	{
		show_game_table(TicTacToeBoard);
	}
	else
	{
		cout << "\n>>> !--------------------already checked--------------------------!\n>>> Enter Again....." << endl;
		player_2(TicTacToeBoard);
	}

}


int results(char TicTacToeBoard[3][3]) // return the integer value (1, 2, 0) 1 for 'O' combination and 2 for 'X' combination and 0 for Draw
{
	if ((TicTacToeBoard[0][0] == 'O' && TicTacToeBoard[0][1] == 'O' && TicTacToeBoard[0][2] == 'O') || (TicTacToeBoard[1][0] == 'O' && TicTacToeBoard[1][1] == 'O' && TicTacToeBoard[1][2] == 'O') || (TicTacToeBoard[2][0] == 'O' && TicTacToeBoard[2][1] == 'O' && TicTacToeBoard[2][2] == 'O') || (TicTacToeBoard[0][0] == 'O' && TicTacToeBoard[1][0] == 'O' && TicTacToeBoard[2][0] == 'O') || (TicTacToeBoard[0][1] == 'O' && TicTacToeBoard[1][1] == 'O' && TicTacToeBoard[2][1] == 'O') || (TicTacToeBoard[0][2] == 'O' && TicTacToeBoard[1][2] == 'O' && TicTacToeBoard[2][2] == 'O') || (TicTacToeBoard[0][0] == 'O' && TicTacToeBoard[1][1] == 'O' && TicTacToeBoard[2][2] == 'O') || (TicTacToeBoard[0][2] == 'O' && TicTacToeBoard[1][1] == 'O' && TicTacToeBoard[2][0] == 'O'))
	{
		return 1;
	}
	else if ((TicTacToeBoard[0][0] == 'X' && TicTacToeBoard[0][1] == 'X' && TicTacToeBoard[0][2] == 'X') || (TicTacToeBoard[1][0] == 'X' && TicTacToeBoard[1][1] == 'X' && TicTacToeBoard[1][2] == 'X') || (TicTacToeBoard[2][0] == 'X' && TicTacToeBoard[2][1] == 'X' && TicTacToeBoard[2][2] == 'X') || (TicTacToeBoard[0][0] == 'X' && TicTacToeBoard[1][0] == 'X' && TicTacToeBoard[2][0] == 'X') || (TicTacToeBoard[0][1] == 'X' && TicTacToeBoard[1][1] == 'X' && TicTacToeBoard[2][1] == 'X') || (TicTacToeBoard[0][2] == 'X' && TicTacToeBoard[1][2] == 'X' && TicTacToeBoard[2][2] == 'X') || (TicTacToeBoard[0][0] == 'X' && TicTacToeBoard[1][1] == 'X' && TicTacToeBoard[2][2] == 'X') || (TicTacToeBoard[0][2] == 'X' && TicTacToeBoard[1][1] == 'X' && TicTacToeBoard[2][0] == 'X'))
	{
		return 2;
	}

	return 0;
}

void  restart(char TicTacToeBoard[3][3]) // reset the board after the game complete and also return the choice whether the player want to play again or not
{
	int value = 49; // value for 1 to 9 
	char choice = ' ';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			TicTacToeBoard[i][j] = char(value) ;
			value++;
		}
	}
}


int main()
{
	char TicTacToeBoard[3][3] = { '1','2','3','4','5','6','7','8','9' };

	int  result = 0;

	char restart_game = ' ', choice = ' ';

	show_game_table(TicTacToeBoard);
	do
	{
		switch (choose_character())
		{
		case 0:
		{
			cout << "\n>>> Not Found!\n>>> Invalid character..." << endl;
			break;
		}
		case 1:
		{
			cout << "\n>>> Player 1's character is 'X' and player 2's character is 'O'.\n>>> Best of luck...        " << endl;
			cout << "\n>>> Enter any number from 1 - 9\n>>> Thank you...\n\n>>> player-1 Turn...                    " << endl;
			player_2(TicTacToeBoard);
			cout << "\n>>> Player-2 Turn" << endl;
			player_1(TicTacToeBoard);
			cout << "\n>>> Player-1 Turn" << endl;
			player_2(TicTacToeBoard);
			cout << "\n>>> Player-2 Turn" << endl;
			player_1(TicTacToeBoard);
			cout << "\n>>> Player-1 Turn" << endl;
			player_2(TicTacToeBoard);

			result = results(TicTacToeBoard);
			if (result == 2)
			{
				cout << "\n>>> The winner of the game is .............." << " Player-1 Turn" << endl;
				restart(TicTacToeBoard);
				break;
			}
			else
			{
				cout << "\n>>> Player-2 Turn" << endl;

				player_1(TicTacToeBoard);

				result = results(TicTacToeBoard);

				if (result == 1)
				{
					cout << "\n>>> The winner of the game is.............." << " Player-2" << endl;
					restart(TicTacToeBoard);
					break;
				}
				else
				{
					cout << "\n>>> Player-1 Turn" << endl;

					player_2(TicTacToeBoard);

					result = results(TicTacToeBoard);
					if (result == 2)
					{
						cout << "\n>>> Tthe winner of the game is.............." << " Player-1" << endl;
						restart(TicTacToeBoard);
						break;
					}
					else
					{
						cout << "\n>>> Player-2 Turn" << endl;
						player_1(TicTacToeBoard);
						result = results(TicTacToeBoard);
						if (result == 1)
						{
							cout << "\n>>> The winner of the game is.............." << " Player-2" << endl;
							restart(TicTacToeBoard);
							break;
						}
						else
						{
							cout << "\n>>> Your match against 2nd player is drawn" << "\n>>> Thank You..." << endl;
							restart(TicTacToeBoard);
							break;
						}
					}
				}
			}
			break;
		}
		case 2:
		{
			cout << "\n>>> Player 1's character is 'O' and player 2's character is 'X'.\n>>> Best of luck...        " << endl;
			cout << "\n>>> Enter any number from 1 - 9\n>>> Thank you...\n\n>>> player-1 Turn...                    " << endl;
			player_1(TicTacToeBoard);
			cout << "\n>>> Player-2 Turn" << endl;
			player_2(TicTacToeBoard);
			cout << "\n>>> Player-1 Turn" << endl;
			player_1(TicTacToeBoard);
			cout << "\n>>> Player-2 Turn" << endl;
			player_2(TicTacToeBoard);
			cout << "\n>>> Player-1 Turn" << endl;
			player_1(TicTacToeBoard);
			result = results(TicTacToeBoard);
			if (result == 1)
			{
				cout << "\n>>> Tthe winner of the game is.............." << " Player-1" << endl;
				restart(TicTacToeBoard);
				break;
			}
			else
			{
				cout << "\n>>> Player-2 Turn" << endl;
				player_2(TicTacToeBoard);

				result = results(TicTacToeBoard);
				if (result == 2)
				{
					cout << "\n>>> The winner of the game is.............." << " Player-2" << endl;
					restart(TicTacToeBoard);

					break;
				}
				else
				{
					cout << "\n>>> Player-1 Turn" << endl;
					player_2(TicTacToeBoard);
					result = results(TicTacToeBoard);
					if (result == 1)
					{
						cout << "\n>>> Tthe winner of the game is.............." << " Player-1" << endl;
						restart(TicTacToeBoard);
						break;
					}
					else
					{
						cout << "\n>>> Player-2 Turn" << endl;
						player_1(TicTacToeBoard);
						result = results(TicTacToeBoard);
						if (result == 2)
						{
							cout << "\n>>> The winner of the game is.............." << " Player-2" << endl;
							restart(TicTacToeBoard);
							break;
						}
						else
						{
							cout << "\n>>> Your match against 2nd player is drawn" << "\n>>> Thank You..." << endl;
							restart(TicTacToeBoard);
							break;
						}
					}
				}
			}
			break;
		}
		}
		cout << "\n>>> If you want to restart the game press 'y', Otherwise press any key..." << endl;
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	return 0;
}