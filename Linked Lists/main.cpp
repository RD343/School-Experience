#include<iostream>
#include <cstdlib>
#include <cstddef>
#include "LinkedList.h"


int readInt(string);
int main()
{

   char choice;
   int item;
   LinkedList a;
   
   cout << "This program demonstrates the linked list. " << endl;
   cout << "Initially, you will be asked to create the list." << endl;
   cout << "You will be later prompted to manipulate the list." <<endl << endl;
   
   
   choice='b';
   
   
      cout << "*******************************************************" << endl;
      cout<<"i: Insert (Insert an element at the beginning of the list)\n";
      cout<<"a: Append (Append an element to the end of the list)\n";
	  cout<<"e: isEmpty (Indicate whether the list is empty)\n";
	  cout<<"n: count (Count the number of items in the list)\n";
      cout<<"p: Print  (Print the content of the current list)\n";
	  cout<<"d: Retrieve (Return and delete a node with the given value)\n";
	  cout<<"x: Retrieve at position (Return and delete a node at a given position)\n";
	  cout<<"r: Read at position (Return a node at a given position)\n";
	  cout<<"c: Clear (Clears or empties the list\n";
      cout<<"q: Quit   (Quit the program)\n";
      cout << "*******************************************************" << endl << endl;
      while(choice != 'q')
   {cout<<"\n   Please enter your choice here:  ";
      cin>>choice;
      
      switch(choice)
      {
	 case 'i':
	    item=readInt("to insert:  ");
	    a.insert(item);
	    break;
	    
	 case 'a':
	    item=readInt("to append to the end:  ");
	    a.append(item);
	    break;

	 case 'd':
	    item=readInt("to remove:  ");
	    cout << "Item removed: " << a.retrieve(item) << endl;
		cout << endl<< endl;
	    break;

	 case 'e':
	    if (a.isEmpty())
			{ cout << "The list is empty" << endl;} 
		else
			{cout << "The list is NOT empty" << endl;} 
		cout << endl<< endl;		
	    break;

	 case 'c':
	    a.clear();
	    break;

	 case 'n':
	     cout << "The number of items in the list is : " << a.count() << endl;
	    break;
	 case 'p':
	    cout << "The content of the current ordered list is:  "<<endl;
	   a.printList();
   		cout << endl<< endl;
	    break;
	  
	 case 'x':
	     item=readInt("for position to remove:  ");
	     cout << "Item removed is: " << a.retrieveAtPos(item)  << endl;
   		cout << endl<< endl;
	    break;

	 case 'r':
	    item=readInt("for position to read:  ");
	    cout << "Item at that postion is: " << a.readAtPos(item)<< endl;
   		cout << endl<< endl;
	    break;		
	 case 'q':
	    break;
	    
	 default:
	    cout<<"\n Invalid choice. Please try again.\n";
	    break;
      }
   }
   cout<<"\n Bye\n";
   return 0;
}	
int readInt(string descr)
{
   int item;
   cout << "\n   Please enter an integer value " << descr; 
   cin >> item;
   
   while (item < 0)
   {
      cout << "\n Please try again:";
      cin >> item;
   }
   return item;
}
