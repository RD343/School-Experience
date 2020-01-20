#ifndef DECK_H
#define DECK_H

#include "Stack.h"

class Deck : public Stack<Card>
{
private:
	Node<Card>* headNodePtr;
public:
	Deck();
	void fillDeck();
	void shuffle();
	~Deck();
};
#endif
