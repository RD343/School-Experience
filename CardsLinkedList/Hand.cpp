#include <iostream>
#include <cstdlib>
#include <string>

#include "LinkedList.h"

using namespace std;

class Hand: public LinkedList<Card>
{
private:
	Node<Card>* headNodePtr;

public:
	int rankSum;
	Hand()
	{
		rankSum = 0;
		headNodePtr = NULL;
	}

/**********************************************************************************
//This function adds a card to (what is meant to be) a blank or partial deck object
//The Deck object this is meant for should be a player's hand
//This function also keeps a tally of the rank sum in the deck object
**********************************************************************************/
	void addCard(Card draw)
	{
		append(draw);
		rankSum = rankSum + draw;
	}

/***********************************************************
//getRankSum
//Returns a deck's ranksum
//Unless otherwise changed, rankSum should be zero
//BlackJack function will change the rankSum of player decks
***********************************************************/
	int getRankSum()
	{
		return rankSum;
	}
};
