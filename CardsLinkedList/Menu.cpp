#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.h"
#include "Card.cpp"
#include "Deck.h"
#include "Deck.cpp"
#include "RPSTools.cpp"
#include "Hand.cpp"

using namespace std;
void draw();
void gameOfWar();
void blackjack(Hand, Hand);
void magicTrick();
void crazyEights(Hand, Hand);

int main()
{
	int pick = 0;
	Hand player;
	Hand house;

	system("clear");
	srand(time(NULL));

	cout << "\nIf the program ever pauses, press Enter to continue";
	cin.ignore();

	do
	{
		cout << endl;
		cout << "***************************************************" << endl;
		cout << "1) Draw cards" << endl;
		cout <<	"2) Play a game of War" << endl;
		cout << "3) Play a game of Blackjack against the House" << endl;
		cout << "4) Magic Trick" << endl;
		cout << "5) Play Rock, Paper, Scissors" << endl;
		cout << "6) Play Crazy Eights" << endl;
		cout << "7) End program" << endl;
		cout << "***************************************************" << endl;

		cout << "Select an action by entering the appropriate number: ";
		cin >> pick;

		system("clear");

		switch(pick)
		{
		case 1:
			draw();
			break;
		case 2:
			gameOfWar();
			break;
		case 3:
			blackjack(player, house);
			break;
		case 4:
			magicTrick();
			break;
		case 5:
			cin.ignore();
			RPS();
			system("clear");
			break;
		case 6:
			crazyEights(player, house);
			break;
		case 7:
			system("clear");
			cout << "\nGoodbye!" << endl;
			cout << "********" << endl;
			break;
		default:
			cout << "You did not enter 1-6: Try again" << endl;
		}
	}while(pick != 7);

	return 0;
}

void draw()
{
	int repeat = 2;
	Deck myDeck;
	myDeck.fillDeck();
	Card temp;

	do
	{
		temp = myDeck.drawCard();
		cout << "\n" << temp << endl;

		cout << "\nTo draw another card, press any number above 0" << endl;
		cout << "To return to menu, press 0: ";
		cin >> repeat;
		cout << endl;
	}while(repeat != 0);
	myDeck.~Deck();
	system("clear");
}

/***********************************************************************
//War function
//This plays 10 rounds of War
//Each round draws one card per player and compares them
//Player with the higher card wins the round
//Impossible for a draw in a round
//Player who wins the most rounds wins the game
//if both players win an equal number of rounds, the game ends in a draw
//fully automated process
************************************************************************/
void gameOfWar()
{
	Deck myDeck;
	myDeck.fillDeck();
	int score = 0;
	Card player1;
	Card player2;

	cout << "\nTwo players will now play a game of War" << endl;
	cout << "The game will last for 10 rounds" << endl;
	cin.ignore();

	for(int i = 0; i < 10; i++)
	{
		player1 = myDeck.drawCard();
		player2 = myDeck.drawCard();

		cout << "\nPlayer 1 drew a card: " << player1 << endl;
		cout << "\nPlayer 2 drew a card: " << player2 << endl;

		if(player1 > player2)
		{
			score++;
			cout << "\nPlayer 1 wins this round!" << endl;
		}
		else
			cout << "\nPlayer 2 wins this round!" << endl;
		cout << "---------------------------------------" << endl;
		cin.ignore();
	}

	cout << "Player 1 score: " << score << endl;
	cout << "Player 2 score: " << 10 - score << endl;

	if(score > 5)
		cout << "\nPlayer 1 is the winner!" << endl;
	else if(score < 5)
		cout << "\nPlayer 2 is the winner!" << endl;
	else// if(score == 5)
		cout << "\nThis game is a draw." << endl;

	myDeck.~Deck();
	cout << "\nPress Enter to return to the main menu" << endl;
	cin.ignore();
	system("clear");
}

/*****************************************
//Blackjack function
//Plays a game of blackjack
//Now incorporates linked lists for hands
*****************************************/
void blackjack(Hand player, Hand house)
{
	Deck myDeck;
	myDeck.fillDeck();

	char hitStay = ' ';

	Card playerCard;
	Card houseCard;

	//Basic Rules
	cout << "\nJack, Queen, and King cards all have a value of 10" << endl;
	cout << "Ace has a value of 1" << endl;
	cout << "Get as close to 21 without exceeding it as you can" << endl;
	cout << "Hit to draw another card" << endl;
	cout << "Stay to stop drawing cards" << endl;
	cout << "This game will be played against the dealer" << endl;
	cin.ignore();
	cout << "\nEach player will now be dealt 2 cards" << endl;
	cin.ignore();
	for(int d = 0; d < 2; d++)	//Initial two card deal
	{
		playerCard = myDeck.drawCard();
		player.addCard(playerCard);

		houseCard = myDeck.drawCard();
		house.addCard(houseCard);
	}

	cout << "\n*Your hand*" << endl;
	player.printList();
	cout << "\n*Dealer's hand*" << endl;
	house.printList();
	cin.ignore();

	do
	{
		//Player's turn
		cout << "\nYou may hit or stay (h for hit/s for stay): ";
		cin >> hitStay;
		cin.ignore();
		while(hitStay != 'h' && hitStay != 's')
		{
			cout << "\nYou must enter either h or s: ";
			cin >> hitStay;
			cin.ignore();
		}

		switch(hitStay)
		{
		case 'h':
			playerCard = myDeck.drawCard();
			player.addCard(playerCard);;
			cout << "\nYou drew: " << playerCard << endl;
			cout << "\n*Your hand*" << endl;
			player.printList();
			cin.ignore();
			break;
		case 's':
			//do nothing
			break;
		default:
			cout << "error" << endl;
		}

		//House's turn
		if(hitStay == 'h' && player.getRankSum() <= 21 && 
		player.getRankSum() > house.getRankSum())
		{
			houseCard = myDeck.drawCard();
			cout << "\nDealer drew: " << houseCard << endl;
			house.addCard(houseCard);
			cout << "\n*Dealer's hand*" << endl;
			house.printList();
			cin.ignore();
		}
	}while(hitStay == 'h' && player.getRankSum() < 21 && house.getRankSum() < 21);

	//House's turn if player stays
	while(house.getRankSum() < 21 && player.getRankSum() <= 21 && 
	player.getRankSum() > house.getRankSum())
	{
		if(player.getRankSum() > house.getRankSum())
		{
			houseCard = myDeck.drawCard();
			cout << "\nDealer drew: " << houseCard << endl;
			house.addCard(houseCard);
			cout << "\n*Dealer's hand*" << endl;
			house.printList();
			cin.ignore();
		}
	}

	//win/lose conditions	(multiple if/else statements for code readability) 
	if(player.getRankSum() == 21)
	{
		cout << "\nYou won!" << endl;
		cout << "********" << endl;
	}
	else if(player.getRankSum() < 21 && house.getRankSum() > 21)
	{
		cout << "\nYou won!" << endl;
		cout << "********" << endl;
	}
	else if(player.getRankSum() < 21 && player.getRankSum() > house.getRankSum())
	{
		cout << "\nYou won!" << endl;
		cout << "********" << endl;
	}
	else
	{
		cout << "\nThe House wins" << endl;
		cout << "--------------" << endl;
	}

	player.clear();
	house.clear();
	myDeck.~Deck();
	cout << "\nPress Enter to return to the main menu" << endl;
	cin.ignore();
	system("clear");
}

/*******************************************************************
//Magic Trick function
//Draws a card from the deck and changes it into the Queen of Hearts
********************************************************************/
void magicTrick()
{
	cin.ignore();
	Deck myDeck;
	myDeck.fillDeck();
	Card magic = myDeck.drawCard();
	cout << "\nThis function will transform any drawn card into the Queen of Hearts" << endl;
	cin.ignore();
	cout << "\nYou drew the " << magic << endl;
	cout << "\n**ALAKAZAM**" << endl;
	magic.setRank(12);
	magic.setSuit(3);
	cout << "\nBehold! The card is now the " << magic << endl;
	cout << "-------------------------------------------" << endl;
	myDeck.~Deck();
	cout << "\nPress Enter to return to the main menu" << endl;
	cin.ignore();
	system("clear");
}

/*****************************************************************
//Crazy Eights Function
//Currently only draws hands to demonstrate inherited linked lists
//Each hand only has 8 cards
******************************************************************/
void crazyEights(Hand player, Hand house)
{
	cin.ignore();
	Deck myDeck;
	myDeck.fillDeck();
   
	cout << "This function demonstrates the linked list card hands." << endl;   
	cin.ignore();

	cout << "Drawing 8 cards to player and computer hands" << endl;
	for(int i = 0; i < 8; i++)
	{
		player.append(myDeck.drawCard());
		house.append(myDeck.drawCard());
	}

	cin.ignore();

	cout << "\nThe content of the player hand is:"<< endl;
	player.printList();

	cout << "\nThe content of the computer hand is:"<< endl;
	house.printList();

	myDeck.~Deck();
	player.clear();
	house.clear();

	cout << "\nPress Enter to return to the main menu" << endl;
	cin.ignore();
	system("clear");
}
