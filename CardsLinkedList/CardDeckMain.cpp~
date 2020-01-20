#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.h"
#include "Card.cpp"
#include "Deck.h"
#include "Deck.cpp"
using namespace std;

int main()
{
	/*****************************************************
	//temporary cards to take card arguments from the deck
	*****************************************************/
	Card temp1;
	Card temp2;
	Card temp3;
	int totalCards;			//totalCards is for building dynamic deck
	srand(time(NULL));

	cout << "How many cards are in the deck?" << endl;
	cout << "Enter 2 to test the drawCard function on an empty deck: ";
	cin >> totalCards;

	if(totalCards < 0)
	{
		do
		{
			cout << "\n\nError! Enter a positive number or zero: ";
			cin >> totalCards;
		}while(totalCards < 0);
	}

	Deck myDeck;		//Calls Deck constructor, makes object myDeck
	myDeck.buildDynamic(totalCards);
	myDeck.fillDeck(totalCards);

	cout << "\nThree cards will now be randomly pulled from the deck." << endl;
	temp1 = myDeck.drawCard(totalCards);
	temp1.printCard();
	temp2 = myDeck.drawCard(totalCards);
	temp2.printCard();
	temp3 = myDeck.drawCard(totalCards);
	temp3.printCard();

	cout << "\n";

	return 0;
}
