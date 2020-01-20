/*Authored By Rankin Dam
CSCI 371 Program 1
  A finite state machine that checks that entered Roman Numerals are valid
  If valid, returns the base ten value of the entered numeral*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

//Function takes in a character and outputs an Integer
  //Integer stems from Roman Numerals contained within language
  //Return 5 if not a character in the language
int Rome_Array(char r)
{
  switch(r)
  {
  case 'I':
    return 0;
  case 'V':
    return 1;
  case 'X':
    return 2;
  case 'L':
    return 3;
  case 'C':
    return 4;
  default:
    return 5;
  }
}

int main()
{
  //Construction of next state table
    //Finds next state based on current state and incoming Roman Numeral
      //Each cell contains the value of the next state that will be visited
  int next_state[19][6] = {
    {1, 6, 10, 13, 14, -1},//State 0, start
    {2, 4, 5, -1, -1, -1},//State 1 saw first I
    {3, -1, -1, -1, -1, -1},//State 2 saw second I
    {-1, -1, -1, -1, -1, -1},//State 3 saw third I
    {-1, -1, -1, -1, -1, -1},//State 4 saw V after first I
    {-1, -1, -1, -1, -1, -1},//State 5 saw X after first I
    {7, -1, -1, -1, -1, -1},//State 6 saw V
    {8, -1, -1, -1, -1, -1},//State 7 saw I after V
    {9, -1, -1, -1, -1, -1},//State 8 saw second I after V
    {-1, -1, -1, -1, -1, -1},//State 9 saw third I after V
    {1, 6, 11, 13, 15, -1},//State 10 saw first X
    {1, 6, 12, -1, -1, -1},//State 11 saw second X
    {1, 6, -1, -1, -1, -1},//State 12 saw third X
    {1, 6, 10, -1, -1, -1},//State 13 saw L
    {1, 6, 10, 13, 16, -1},//State 14 saw first C
    {1, 6, -1, -1, -1, -1},//State 15 saw C after X
    {1, 6, 10, 13, 17, -1},//State 16 saw second C
    {18, 18, 18, 18, 18, -1},//State 17 saw third C
    {18, 18, 18, 18, 18, -1}//State 18 saw any valid numeral after third C
  // I   V   X   L   C    !
  };

  //Construction of action table
    //Coincides with the next state table
    //Returns integer that can be added to a running total
      //Integer is based on current state and the incoming Roman Numeral
  int action_table[19][6] = {
    {1, 5, 10, 50, 100, 0},//State 0, start
    {1, 3, 8, 0, 0, 0},//State 1 saw first I
    {1, 0, 0, 0, 0, 0},//State 2 saw second I
    {0, 0, 0, 0, 0, 0},//State 3 saw third I
    {0, 0, 0, 0, 0, 0},//State 4 saw V after first I
    {0, 0, 0, 0, 0, 0},//State 5 saw X after first I
    {1, 0, 0, 0, 0, 0},//State 6 saw V
    {1, 0, 0, 0, 0, 0},//State 7 saw I after V
    {1, 0, 0, 0, 0, 0},//State 8 saw second I after V
    {0, 0, 0, 0, 0, 0},//State 9 saw third I after V
    {1, 5, 10, 30, 80, 0},//State 10 saw first X
    {1, 5, 10, 0, 0, 0},//State 11 saw second X
    {1, 5, 10, 0, 0, 0},//State 12 saw third X
    {1, 5, 10, 0, 0, 0},//State 13 saw L
    {1, 5, 10, 50, 100, 0},//State 14 saw first C
    {1, 5, 0, 0, 0, 0},//State 15 saw C after X
    {1, 5, 10, 50, 100, 0},//State 16 saw second C
    {0, 0, 0, 0, 0, 0},//State 17 saw third C
    {0, 0, 0, 0, 0, 0},//State 18 Saw any valid numeral after third C
  // I  V  X  L  C  !
  };

  string sample; //string that will take user input
  cout << "\nEnter a Roman Numeral valued 300 (CCC) or lower" << endl;
  cout << "This program will use a finite state machine";
  cout << " to determine if the input is a valid Roman Numeral";
  cout << "\nIf the numeral is valid, it's base ten equivalent will display";
  cout << "\nNOTE: Capitalize all letters, no spaces" << endl;
  cout << "Input Q to quit" << endl;
  cout << "-----------------------------------------------------------\n\n";

  //Do/while statement for user input until Q is entered
  do {
    cout << " ";
    cin >> sample;

    if(sample != "Q") //Input Q quits program
    {
      int current = 0;
      int base_ten = 0;
      int count = 0;

      //Loop that goes through each position of the input string
      //While loop more efficient than for loop.
        //Does not have to go through whole string if dead state detected early
      while(count < sample.size() && current != -1)
      {
        //accesses the action table for integer addition
        base_ten = base_ten + action_table[current][Rome_Array(sample[count])];
        //accesses the next state table and sets current to next state
        current = next_state[current][Rome_Array(sample[count])];
        count++;
      }

      if(current == -1)
        cout << " ^ is NOT a valid Roman Numeral" << endl;
      else if(current == 18)
        cout << "Program does not go beyond Numeral CCC (300)" << endl;
      else
        cout << " ^ is a valid Roman Numeral equal to " << base_ten << endl;
      cout << "-----------------------------------------------------------\n\n";
    }

  } while(sample != "Q");
}
