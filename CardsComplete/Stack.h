#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>

#include "Node.h"

using namespace std;

//Class Declaration
//-----------------
template <class Card>
class Stack
{
private:
	Node<Card> * headNodePtr;
	Card temp;
public:
	Stack();
	bool isEmpty();
	bool push(Card Item);
	Card pop();
	void printList();
	int getCount();
};

/*************
//Constructor
*************/
template <class Card>
Stack<Card>::Stack()
{
	headNodePtr = NULL;
}

/****************************
//isEmpty
//Determines if stack is empty
****************************/
template <class Card>
bool Stack<Card>::isEmpty()
{
	if ( headNodePtr == NULL )
		return true;
	else
		return false;
}

/*******************************
//Push
//Places a node on top of stack
*******************************/
template <class Card>
bool Stack<Card>::push(Card Item)
{
	Node<Card> * newNodePtr = new Node<Card>(Item, headNodePtr);
	headNodePtr = newNodePtr;
}

/*************************************
//Removes top item, prints, and delete
//This may not be fully functional yet
**************************************/
template <class Card>
Card Stack<Card>::pop()
{
	if ( headNodePtr == NULL )
	{
		Card card;
		cout << "Error: Stack is empty";
		temp = card;
	}
	else
	{
		temp = headNodePtr -> getItem();
		headNodePtr = headNodePtr -> getNext();
	}
	return temp;
}

/******************************************************************
//Class LinkedList
//Function:  printList
//For testing purposes
*******************************************************************/ 
template <class Card>
void Stack<Card>::printList()
{
	Node<Card>* printPtr = headNodePtr;
	if (headNodePtr == NULL)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{	cout << printPtr->getItem() << endl;
		while (printPtr->getNext() != NULL)
		{
			printPtr = printPtr->getNext();
			cout << printPtr->getItem() << endl;
		}
	}
}

/*****************************************************
//Get Count function
//Counts the number of cards within the specified Deck
*****************************************************/
template <class Card>
int Stack<Card>::getCount()
{
	int count;
	Node<Card>* countPtr = headNodePtr;

	if (headNodePtr == NULL)
	{
		return count = 0;
	}
	else
	{
		count = 1;
		while (countPtr->getNext() != NULL)
		{
			count++;
			countPtr = countPtr->getNext();
		}
  		return count;
	}
}
#endif
