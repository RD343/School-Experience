#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"

class Hand: public LinkedList<Card>
{
private:
	Node<Card>* headNodePtr;
public:
	int clubsCount, diamondsCount, heartsCount, spadesCount, rankSum;
	Card temp;
	Hand();
	void addCard(Card draw);
	void removeCardSuit(Card play);
	int getRankSum();
	void getSuitCounts();
	bool suitsMatch(Card toMatch);
	bool ranksMatch(Card toMatch);
	bool hasEights();
	int searchSuits(Card toMatch);
	int searchRanks(Card toMatch);
	int findEight();
	int highestSuitCount();
};
#endif
