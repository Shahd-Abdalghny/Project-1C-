

#include <iostream>
using namespace std;
int RandomNumber(int From, int To) { 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
int combuter_turn() {
	int t = RandomNumber(1, 3);
	return t;
}
int read_round(string massage) {
	int n;
	cout << massage;
	cin >> n;
	return n;
}
int read_chose_user(string massage) {
	int n;
	cout << massage;
	cin >> n;
	return n;
}
string winner(int user, int com) {
	string winner;
	if (user == com) {
		winner = "[NO Winner]";
	}
	else {
		if (user == 1) {
			if (com == 2) {
				winner = "Combuter";
			}
			else {
				winner = "Player1";
			}
		}
		else if (user == 2) {
			if (com == 3) {
				winner = "Combuter";
			}
			else {
				winner = "Player1";
			}
		}
		else  {
			if (com == 1) {
				winner = "Combuter";
			}
			else {
				winner = "Player1";
			}
		
		}
	}
	return winner;

}
string enumGameChoiceToString(int n) {
	switch (n) {
	case 1:
		return "Stone";
	case 2:
		return "Paper";
	case 3:
		return "Scissor";
	default:
		return "Unknown";
	}
}
void round_result(int user, int com,int rou, string win) {
	cout << "----------------Round [" << rou << "] ----------------\n";
	cout << "Player1 Choice: " << enumGameChoiceToString(user)<<"\n";
	cout << "Computer Choice: " << enumGameChoiceToString(com) << "\n";
	cout << "Round Winner   : " << win << "\n";
	cout << "-------------------------------------------\n";

}
void game_over(int round, int use, int com, int draw) {

	cout << "\t\t\t--------------------------------------------------------\n";
	cout << "\t\t\t\t\t +++ G a m e  O v e r +++ \t\t\n";
	cout << "\t\t\t--------------------------------------------------------\n";
	cout << "\t\t\t----------------[Game Results ]-------------------------\n";
	cout << "\t\t\tGame Rounds       : " << round << "\n";
	cout << "\t\t\tPlayer1 won times : " << use << "\n";
	cout << "\t\t\tcomputer won times: " << com << "\n";
	cout << "\t\t\tDraw times        : " << draw << "\n";
	if (use > com) {
		cout << "\t\t\tFinel Winner   : " << "player1\n";
	}
	else if (com > use) {
		cout << "\t\t\tFinel Winner   : " << "Computer\n";

	}
	else {
		cout << "\t\t\tFinel Winner   : " << "No Winner\n";
	}
	cout << "\t\t\t--------------------------------------------------------\n";

}
void game_begin(int& number_of_round) {
	int fin_user = 0, fin_com = 0,draw=0;
	for (int i = 1; i <= number_of_round; i++) {
		cout << "Round " << "[" << i << "] " << "Begin: \n";
		int user = read_chose_user("Your Choice: [1]:stone, [2]:Paper, [3]:Scissors ?");
		int combuter = combuter_turn();
		string winner_round = winner(user, combuter);
		
		round_result(user, combuter, i, winner_round);

		if (winner_round == "Player1") {
			fin_user++;
			system("color 2f");
		}
		else if (winner_round == "Combuter") {
			fin_com++;
			system("color 4f");
			cout << "\a";
		}
		else {
			draw++;
			system("color 6f");
		}


	}
	game_over(number_of_round, fin_user, fin_com, draw);
}
void ResetScreen() {
	system("cls");
	system("color 0f");
}
int main()
{

	  srand((unsigned)time(NULL)); 
	  char playAgain = 'Y';
	  do {
		  ResetScreen();
      
	int number_of_round = read_round("How Many Rounds 1 to 10 ? ");
	game_begin(number_of_round);
	cout << endl << '\t' << '\t' << "Do you want to play again ? Y/N?";
	cin >> playAgain;

	  } while (playAgain == 'Y' || playAgain == 'y');


	return 0;
}

