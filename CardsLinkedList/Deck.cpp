#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.h"
#include "Card.cpp"
#include "Deck.h"
using namespace std;

/******************************************
//Base Constructor
//Includes pointer reference initialization
******************************************/
Deck::Deck()
{	
	Card **cardPlace;
}

/******************************************************************
//fillDeck
//takes totalCards as an argument
//uses the size of the deck to create card objects for the pointers
//DO NOT USE WITH NULLPOINTER() OR PLAYER HANDS
*******************************************************************/
void Deck::fillDeck()
{
	cardPlace = new Card*[52];
	for(int i = 0; i < 52; i++)
		cardPlace[i] = NULL;

	int suitCount = 1;
	int rankCount = 1;
	for(int i = 0; i < 52; i++)
	{
		if(suitCount >= 1 && suitCount <=4)
			cardPlace[i] = new Card(suitCount, rankCount);
		else
		{
			suitCount = 1;
			rankCount++;
			cardPlace[i] = new Card(suitCount, rankCount);
		}
		suitCount++;
	}
}

/********************************************************************************************
//drawCard
//takes totalCards as an argument
//uses rand function to pull an initial random card object from the deck
//if/else, do/while, and try functions go through deck to a pointer not null
//once the counter == totalCards, then the deck is declared empty, breaking the do/while loop
********************************************************************************************/
Card Deck::drawCard()
{
	Card temp;
	int l = rand() % 52;
	int nullCount = 0;		//nullcount moderates the while loop.

	try
	{
		if(cardPlace[l] == NULL)
		{
			do		//the do/while function goes through the pointer array,
			{		//checking for NULL pointers
					//the starting point is whatever pointer is returned by
					//the random number function above
				if(l < 52)
				{
					l = l++;
					nullCount = nullCount++;
				}
				else
				{
					l = 0;
					nullCount = nullCount++;
				}
			}while(cardPlace[l] == NULL && nullCount != 52);
		}
		if(nullCount == 52 && cardPlace[l] == NULL) throw temp;

		temp = *cardPlace[l];
		cardPlace[l] = NULL;
		return temp;
	}

	catch(Card temp)
	{
		Card blank;
		cout << "\nThe deck is empty~ ";
		return blank;
	}
}

/***************
//Deconstructor
***************/
Deck::~Deck()
{}
