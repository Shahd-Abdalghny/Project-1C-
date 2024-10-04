#include<iostream>
using namespace std;
enum enGameChoice {stone = 1, paper = 2, scissors =3 };
enum enWinner {player1 = 1, Computer = 2 , Draw =3};
struct stRoundInfo {
	short RoundNumber = 0; 
	enGameChoice PlayChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};
struct stGameResult {
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrowTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};
int RandomNumber(int from, int to) {
	int randNum = rand() % (to - from + 1) + from;
	return randNum;

}
string WinnerName(enWinner Winner) {

	string arrWinnerName[3] = { "Player1" , "Computer" , "No Winner" };
	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
	if (RoundInfo.PlayChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayChoice)
	{
	case enGameChoice::stone:
		if (RoundInfo.ComputerChoice == enGameChoice::paper) {
			return enWinner::Computer;
		}
		break;
	case enGameChoice::paper:
		if (RoundInfo.ComputerChoice == enGameChoice::scissors) {
			return enWinner::Computer;
		}
		break;
	case enGameChoice::scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::stone) {
			return enWinner::Computer;
		}
		break;

	}
	return enWinner::player1;

}
string ChoiceName(enGameChoice Choice) {
	string arrChoice[3] = { "Stone", "Paper", "Scissors" };
	return arrChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner) {
	switch (Winner) {
		case enWinner::Player1:        
		system("color 2F");//turn screen to Greenbreak;
		case enWinner::Computer:        
			system("color 4F"); //turn screen to Red      
		cout << "\a"; break;  // جرس
		default:      
			system("color 6F"); //turn screen to Yellowbreak;    
	} 
}

void PrintRoundResults(stRoundInfo RoundInfo) {
	cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";   
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;  
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;    
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";    
	cout << "__________________________________\n" << endl;     
	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {
	if (Player1WinTimes > ComputerWinTimes) 
		returnenWinner::Player1;
	else if(ComputerWinTimes > Player1WinTimes) 
		returnenWinner::Computer;
	else 
		returnenWinner::Draw;

}

stGameResult FillGameResults(int GameRounds, short PlayWinTimes, short ComputerWinTimes, short DrawTimes) {
 
	stGameResult GameResult;
	GameResult.GameRounds = GameRounds;
	GameResult.PlayerWinTimes = PlayWinTimes;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrowTimes = DrawTimes;
	GameResult.GameWinner = WhoWonTheGame(PlayWinTimes,ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.GameWinner);
	return GameResult;
}

enGameChoice GetComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}
enGameChoice ReadPlayerChoice () {
	short choice = 1;
	do {
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissoes ? ";
		cin >> choice;
	} while (choice < 1 || choice>3);
	return (enGameChoice)choice;
}
stGameResult playGame(short HowManyRounds) {
	stRoundInfo RoundInfo;
	short Play1Wintimes = 0, computerWintimes = 0, Drewtimes = 0;
	for (int gameRound = 1; gameRound <= HowManyRounds; gameRound++) {

		cout << "\nRound [" << gameRound << "] begins:\n";
		RoundInfo.RoundNumber = gameRound;
		RoundInfo.PlayChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		if (RoundInfo.Winner == enWinner::player1)
			Play1Wintimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			computerWintimes++;
		else
			Drewtimes++;
		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, Play1Wintimes, computerWintimes, Drewtimes);


}
string  Tabs(short NumberOfTabs) {
	string t = "";
	for (int i = 1; i < NumberOfTabs; i++) 
	{
		t = t + "\t";       
	cout << t; 
	}
	return t;
}

short ReadHowManyRound() {
	short GameRounds = 1;
	do {
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);
}

void ShowGameOverScreen() 
{
	cout << Tabs(2) << "__________________________________________________________\n\n";     
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";    
	cout << Tabs(2) << "__________________________________________________________\n\n";
} 
void ShowFinalGameResults(stGameResult GameResults) { 
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";     
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;     
	cout << Tabs(2) << "Player1 won times  : " << GameResults.PlayerWinTimes << endl;    
	cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;     
	cout << Tabs(2) << "Draw times         : " << GameResults.DrowTimes << endl;    
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;     
	cout << Tabs(2) << "___________________________________________________________\n";     
	SetWinnerScreenColor(GameResults.GameWinner);

}
void ResetScreen() {
	system("cls"); // clear befor data in screen
	system("color 0f"); // normal color of consol screen
}
void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		stGameResult GameResults = playGame(ReadHowManyRound());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);
		cout << "Do you want to play again? Y/N?";
		cin >> PlayAgain;

	} while (PlayAgain== 'Y' || PlayAgain == 'y');

}




int main ()
{
	srand((unsigned)time(NULL));
	StartGame();

}