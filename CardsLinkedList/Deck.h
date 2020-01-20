#ifndef DECK_H
#define DECK_H

class Deck : public Card
{
//friend class Card;
public:
	Card** cardPlace;
	Deck();
	void fillDeck();
	Card drawCard();
	~Deck();
};
#endif
