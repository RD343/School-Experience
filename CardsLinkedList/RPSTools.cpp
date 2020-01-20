#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

class Tool
{
public:
	string type;
	Tool()
	{
		type = "";
	}
	string getType()
	{
		return type;	
	}
	virtual int fight(Tool *argType)=0;
	~Tool(){}
};

class Rock: public Tool
{
public:
	Rock()
	{
		type = "Rock";
	}
	int fight(Tool *argType)
	{
		string type = argType -> getType();
		if(type == "Rock")		//Tie
			return 0;
		else if(type == "Scissors")	//Player win
			return 1;
		else if(type == "Paper")	//Computer win
			return 2;
	}
	~Rock(){}
};

class Scissors: public Tool
{
public:
	Scissors()
	{
		type = "Scissors";
	};
	int fight(Tool *argType)
	{
		string type = argType -> getType();
		if(type == "Scissors")		//tie
			return 0;
		else if(type == "Paper")	//player win
			return 1;
		else if(type == "Rock")		//computer win
			return 2;
	}
	~Scissors(){}
};

class Paper: public Tool
{
public:
	Paper()
	{
		type = "Paper";
	}
	int fight(Tool *argType)
	{
		string type = argType -> getType();
		if(type == "Paper")		//tie
			return 0;
		else if(type == "Rock")		//player win
			return 1;
		else if(type == "Scissors")	//computer win
			return 2;
	}
	~Paper(){}
};

void RPS()
{
	srand(time(NULL));
	int ctc;
	int score = 0;
	char toolChoice = ' ';

	//Tool constructors
	Tool *computerTool;
	Tool *playerTool;
	Rock Rock;
	Paper Paper;
	Scissors Scissors;

	cout << "\nUser will play three rounds of Rock, Paper, Scissors against the computer" << endl;
	cout << "Whoever wins the most rounds wins the game" << endl;
	cin.ignore();
	for(int i = 0; i < 3; i++)
	{
		cout << "\nEnter the letter of the tool you wish to choose" << endl;
		cout << "(r) Rock" << endl;
		cout << "(p) Paper" << endl;
		cout << "(s) Scissors" << endl;
		cin >> toolChoice;

		while( (toolChoice != 'r') && (toolChoice != 'p') && (toolChoice != 's') )
		{
			cout << "\nIncorrect choice" << endl;
			cout << "Enter the letter of the tool you wish to choose" << endl;
			cout << "(r) Rock" << endl;
			cout << "(p) Paper" << endl;
			cout << "(s) Scissors" << endl;
			cin >> toolChoice;
		}

		//Assigns playerTool the player's chosen tool type
		cout << "\nYou chose ";
		switch(toolChoice)
		{
		case 'r':
			cout << "Rock" << endl;
			playerTool = &Rock;
			break;
		case 'p':
			cout << "Paper" << endl;
			playerTool = &Paper;
			break;
		case 's':
			cout << "Scissors" << endl;
			playerTool = &Scissors;
			break;
		default:
			cout << "\nError in toolChoice switch statement" << endl;
		}

		//Assigns computerTool the computer's randomly chosen tool type
		ctc = rand() % 3;
		cout << "Computer chose ";
		switch(ctc)
		{
		case 0:
			cout << "Rock" << endl;
			computerTool = &Rock;
			break;
		case 1:
			cout << "Paper" << endl;
			computerTool = &Paper;
			break;
		case 2:
			cout << "Scissors" << endl;
			computerTool = &Scissors;
			break;
		default:
			cout << "\nUnknown error in computerToolChoice function" << endl;
		};

		//Fight function usage
		if(playerTool -> fight(computerTool) == 1)
		{
			cout << "\nYou won this round" << endl;
			score++;
		}
		else if(playerTool -> fight(computerTool) == 0)
		{
			cout << "\nTie" << endl;
		}
		else if(playerTool -> fight(computerTool) == 2)
		{
			cout << "\nComputer won this round" << endl;
			score--;
		}
		cout << "---------------------------" << endl;
		cin.ignore();
	}

	if(score > 0)		//Math
		cout << "\nYou are the winner" << endl;
	else if(score < 0)
		cout << "\nComputer is the winner" << endl;
	else if(score == 0)
		cout << "\nThis game is a draw" << endl;

	cout << "\nPress Enter to return to the main menu" << endl;
	cin.ignore();
}
