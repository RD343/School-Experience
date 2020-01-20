#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

#include "Node.h"
#include "Card.h"

using namespace std;

/******************************************************************
Class LinkedList
This class defines a data structure for a linked list of integers
*******************************************************************/   
template <class Card>
class LinkedList 
{
  private:
   Node<Card>* headNodePtr;
   Node<Card>* midNodePtr;

  public:
   LinkedList ();
   bool isEmpty();
   void insert  (Card);
   void append  (Card);
   int count();
   void printList();
   Card retrieve  (int);
   Card retrieveAtPos (int);
   Card readAtPos(int);
   void clear();
   
   // EXCEPTIONS THROWN
	static const int ItemNotFound = 8001;
	static const int NodeAtPositionNotFound = 8002;
};

/*========================
/*     IMPLEMENTATION
/*========================

/******************************************************************
Class LinkedList
Function:  Constructor
Return: a pointer to the constructed LinkedList object.
*******************************************************************/   
template <class Card>
LinkedList<Card>::LinkedList() 
{
	headNodePtr = NULL;
}

/******************************************************************
Class LinkedList
Function:  isEmpty
Returns a bool that indicates if the linked list is or is not empty
*******************************************************************/   
template <class Card>
bool LinkedList<Card>::isEmpty() 
{	
	if (headNodePtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************
Class LinkedList
Function:  append
    Inserts a new item at the end of the list
    This routing will create a Node object to contain the item to add
Parameters: item to add to the list
Return: void
*******************************************************************/  
template <class Card>
void LinkedList<Card>::append (Card item)
{
   Node<Card> *tempPtr = headNodePtr;
   Node<Card> *tempPtr2 = new Node<Card>(item);
   if (headNodePtr == NULL)
   {
    headNodePtr = tempPtr2;
   }
   else
   {
    while ((tempPtr -> getNext()) != NULL)
    {
        tempPtr = tempPtr -> getNext();
    }
  
   tempPtr -> setNext(tempPtr2);
   }
}

/******************************************************************
Class LinkedList
Function:  count
Returns an integer count of the number of items in the list
*******************************************************************/   
template <class Card>
int LinkedList<Card>::count() 
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

/******************************************************************
Class LinkedList
Function:  printList
Prints the node item and it's position (starting at 1)
*******************************************************************/ 
template <class Card>
void LinkedList<Card>::printList () 
{
	int position;
	Node<Card>* printPtr = headNodePtr;
	if (headNodePtr == NULL)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		position = 1;
		cout << position << ":     " << printPtr -> getItem() << endl;
		while (printPtr -> getNext() != NULL)
		{
			position++;
			printPtr = printPtr->getNext();
			cout << position << ":     " << printPtr -> getItem() << endl;
		}
	}
}

/******************************************************************
Class LinkedList
Function:  readAtPos
Return: item at that position
*******************************************************************/ 
template <class Card>
Card LinkedList<Card>::readAtPos(int pos)
{
	Card error;
	if(pos > count())
	{
		cout << "\nYou must have counted wrong" << endl;
		return error;
	}
	Node<Card>* readPtr = headNodePtr;
	if (headNodePtr == NULL)
	{
		cout<< "No content, you are too cheap, buy the CONTENT!"<<endl;
	}
	else
	{
        	for(int i = 1; i < pos; i++)
		{
			readPtr = readPtr -> getNext();
		}
		return readPtr -> getItem();
	}
}

/******************************************************************
Class LinkedList
Function:  retrieveAtPos
Result:  Node with item is removed from the list.
Return: item at that position
*******************************************************************/ 
template <class Card>
Card LinkedList<Card>::retrieveAtPos(int pos)
{
	Card retItem;
	if(pos > count())
	{
		cout << "\nYou must have counted wrong" <<endl;
		return retItem;
	}
	Node<Card>* previousPtr = headNodePtr;
	Node<Card>* retrievePtr = headNodePtr;
	Node<Card>* tempPtr = headNodePtr;
	if (headNodePtr == NULL)
	{
		cout<< "No content, you are too cheap, buy the CONTENT!"<<endl;
	}
	else
	{
            for (int i = 1; i < pos; i++)
		{
			previousPtr = retrievePtr;
			retrievePtr = retrievePtr -> getNext();
		}
		retItem = retrievePtr -> getItem();
		tempPtr = retrievePtr -> getNext();
		previousPtr = tempPtr;
		delete retrievePtr;
		return retItem;
	}
}

/******************************************************************
Class LinkedList
Function:  delete
Result:  Node with item is removed from the list.
Return: item
*******************************************************************/ 
template <class Card>
Card LinkedList<Card>::retrieve (int item)
{
	Node<Card>* retPtr = headNodePtr;
	Node<Card>* prevPtr = headNodePtr;
	if (headNodePtr == NULL)
	{
		cout << "There is nothing to remove!" << endl;
	}
	else
	{	
		if (retPtr->getItem() == item)
		{       headNodePtr = retPtr->getNext();
			delete retPtr;
		}
		else
		{
			while(retPtr->getNext() != NULL)
			{
				prevPtr = retPtr;
				retPtr = retPtr->getNext();
				if (retPtr->getItem() == item)
				{	prevPtr->setNext(retPtr->getNext());
					delete retPtr;
				}
			}
		}
	}
	return item;			 
}

/******************************************************************
Class LinkedList
Function:  clear
calls function:  isEmpty
*******************************************************************/   
template <class Card>
void LinkedList<Card>::clear()
{
	if(headNodePtr == NULL)
	{
		cout << "The list is already empty" << endl;
	}
	else
	{
		do
		{
			Node<Card> *tempPtr = headNodePtr;

			while ((tempPtr -> getNext()) != NULL)
			{
				tempPtr = tempPtr -> getNext();
			}
			delete tempPtr;
		}
		while(headNodePtr -> getNext() == NULL);
		headNodePtr = NULL;
	}
}

#endif
