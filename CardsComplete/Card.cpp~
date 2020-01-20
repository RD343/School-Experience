#ifndef CARDIMPLEMENTATION_CPP
#define CARDIMPLEMENTATION_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Card.h"
using namespace std;

/************************************
//Card constructor
//Suit and rank set to zero, or joker
************************************/
Card::Card()
{
	suit = 0;
	rank = 0;
}

/****************************************
//Overloaded Card constructor
//Must take two int arguments when called
*****************************************/
Card::Card(int aSuit, int aRank)
{
	suit = aSuit;
	rank = aRank;

	//If Card() is passed a value outside of the enum parameters, it will throw an error
	//The input error value is 6000
	int input_error = 6000;
	if( (aSuit > 4 || aSuit < 0) || (aRank > 13 || aRank < 0) ) throw input_error;
}

/*************************************
//setSuit
//receives suit values for card object
*************************************/
void Card::setSuit(int aSuit)
{
	suit = aSuit;

	//If setSuit() is passed a value outside of the enum parameters, it will throw an error
	//The input error value is 6000
	int input_error = 6000;
	if(aSuit > 4 || aSuit < 0) throw input_error;
}

/*************************************
//setRank
//receives rank values for card object
*************************************/
void Card::setRank(int aRank)
{
	rank = aRank;

	//If setRank() is passed a value outside of the enum parameters, it will throw an error
	//The input error value is 6000
	int input_error = 6000;
	if(aRank > 13 || aRank < 0) throw input_error;
}

/**************************************************************************
//toString
//Converts integer values of ranks and suits to string values for printing.
***************************************************************************/
string Card::toString() const
{
	string suitString;
	switch(suit)
	{
	case Joker:
		suitString = "Joker";
		break;
	case Hearts:
		suitString = "of Hearts";
		break;
	case Diamonds:
		suitString = "of Diamonds";
		break;
	case Clubs:
		suitString = "of Clubs";
		break;
	case Spades:
		suitString = "of Spades";
		break;
	}

	string rankString;		//Added all numbers for string conversion
	switch(rank)
	{
	case None:
		rankString = "";
		break;
	case Ace:
		rankString = "Ace ";
		break;
	case Two:
		rankString = "2 ";
		break;
	case Three:
		rankString = "3 ";
		break;
	case Four:
		rankString = "4 ";
		break;
	case Five:
		rankString = "5 ";
		break;
	case Six:
		rankString = "6 ";
		break;
	case Seven:
		rankString = "7 ";
		break;
	case Eight:
		rankString = "8 ";
		break;
	case Nine:
		rankString = "9 ";
		break;
	case Ten:
		rankString = "10 ";
		break;
	case Jack:
		rankString = "Jack ";
		break;
	case Queen:
		rankString = "Queen ";
		break;
	case King:
		rankString = "King ";
		break;
	}

	string cardString = rankString + suitString;
	return cardString;
}

/*********************************
//getSuit
//accepts arguments for suit value
*********************************/
int Card::getSuit() const
{
	return suit;
}

/*********************************
//getRank
//accepts arguments for suit value
*********************************/
int Card::getRank() const
{
	return rank;
}

/********************************************************
//Operator < and > Overload
//I set up these functions to compare suits and/or ranks.
********************************************************/
bool operator< (Card& tempCard_A, Card& tempCard_B)
{
	if(tempCard_A.getRank() == tempCard_B.getRank())	//If the ranks are equal, then the operator will compare the suits.
	{	
		return (tempCard_A.getSuit() < tempCard_B.getSuit());
	}
	else
	{
		return (tempCard_A.getRank() < tempCard_B.getRank());
	}
}

bool operator> (Card& tempCard_A, Card& tempCard_B)
{
	if(tempCard_A.getRank() == tempCard_B.getRank())
	{	
		return (tempCard_A.getSuit() > tempCard_B.getSuit());
	}
	else
	{
		return (tempCard_A.getRank() > tempCard_B.getRank());
	}
}

/***************************
//Overloaded the << operator
//Use cout to print cards
****************************/
ostream& operator<< (ostream& os, const Card& argCard)
{
	os << argCard.toString();
	return os;
}

/***************************************************************************
//Overloaded the + operator
//Adds a card object's Rank value to an integer argument and returns integer
//If the card has a rank higher than ten, it will add ten to the integer
	//^specifically for use in Blackjack, where face cards are ten
****************************************************************************/
int operator+ (Card temp, int hand)
{
	if(temp.getRank() > 10)
		hand = hand + 10;
	else
		hand = hand + temp.getRank();
	return hand;
}

int operator+ (int hand, Card temp)
{
	if(temp.getRank() > 10)
		hand = hand + 10;
	else
		hand = hand + temp.getRank();
	return hand;
}
#endif
