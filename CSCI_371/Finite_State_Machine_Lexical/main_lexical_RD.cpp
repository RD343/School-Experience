/*Authored By Rankin Dam
CSCI 371 Program 2
  Creates state, action, and ascii arrays
    to recognize characters found in a language
    input comes from file
      (contains commented code for keyboard input)*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
  /***************************************************************************/
  int ascii_Array[256] = {
    //Ascii values 0-31, which we ignore.
      //translated to 0
      //0 column in tables handles characters not in language
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  //32  33  34  35  36  37  38  39 40 41 42 43  44  45  46  47
  //' ' '!'             '%' '&'             '+' ',' '-' '.'
    35,  6,  0,  0, 0,  34,  7, 0, 0, 0, 0,  1, 10,  2, 33, 0,

  //48-57; Numbers 0-9
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,

  //58   59  60  61  62  63  64
  //':' ';' '<' '=' '>' '?'
    11,  9,  3,  5,  4,  12, 0,

  //65  66  67  68  69  70  71  72  73  74  75  76  77  78  79  80  81  82  83
  //A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S
    18, 20, 31, 24, 21, 25, 17, 27, 22, 31, 31, 28, 19, 23, 16, 14, 31, 15, 29,

  //84  85  86  87  88  89  90
  //T   U   V   W   X   Y   Z
    26, 31, 31, 30, 31, 31, 31,

  //91 92 93 94  95  96
  //         '^' '_'
    0, 0, 0, 13, 34, 0,

  //97-122; lower case letters
    31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
    31, 31, 31, 31, 31, 31, 31, 31,

  //123 124 125
  //    '|'
     0,  8,  0,

  //126-255
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  /***************************************************************************/


  /*columns represent next state according to input from ascii conversion
  *****************************************************************************
    0 = unrecognized symbols
    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
   '+' '-' '<' '>' '=' '!' '&' '|' ';' ',' ':' '?' '^' 'P' 'R' 'O' 'G' 'A' 'M'

   20  21  22  23  24  25  26  27  28  29  30
   'B' 'E' 'I' 'N' 'D' 'F' 'T' 'H' 'L' 'S' 'W'

    31 = Other letters
    32 = Numbers 0-9

    33             34             35
    '.'        '_' or '%'         ' '
  *****************************************************************************

  //Construction of next state table
    //Finds next state based on current state and incoming ascii conversion
      //Each cell contains the value of the next state that will be visited*/
  int next_state_return[67][36] = {
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 0, start
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 1, saw '+'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 2, saw '-'
    {66, 1, 2, 3, 4, 9, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 3, saw '<'
    {66, 1, 2, 3, 4, 10, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 4, saw '>'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 5, saw '='
    {66, 1, 2, 3, 4, 11, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 6, saw '!'
    {66, 1, 2, 3, 4, 5, 6, 12, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 7, saw '&'
    {66, 1, 2, 3, 4, 5, 6, 7, 13, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 8, saw '|'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 9, saw '<='
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 10, saw '>='
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 11, saw '!='
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 12, saw '&&'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 13, saw '||'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 14, saw ';'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 15, saw ','
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 19, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 16, saw ':'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 17, saw '?'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 18, saw '^'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 59, 37, 62, 62, 62, 44, 62, 63, 66, 66, 0},//State 19, saw ':='
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 21, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 20, saw 'P'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 22, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 21, saw 'PR'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 23, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 22, saw 'PRO'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 24, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 23, saw 'PROG'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 25, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 24, saw 'PROGR'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 26, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 25, saw 'PROGRA'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 26, saw 'PROGRAM'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 28, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 27, saw 'B'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 29, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 28, saw 'BE'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 30, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 29, saw 'BEG'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 31, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 30, saw 'BEGI'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 31, saw 'BEGIN'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 33, 62, 62, 62, 62, 41, 62, 62, 62, 62, 66, 62, 0},//State 32, saw 'E'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 34, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 33, saw 'EN'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 34, saw 'END'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 49, 62, 36, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 35, saw 'I'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 36, saw 'IF'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 38, 62, 62, 62, 62, 62, 66, 62, 0},//State 37, saw 'T'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 39, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 38, saw 'TH'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 40, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 39, saw 'THE'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 40, saw 'THEN'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 42, 62, 62, 62, 66, 62, 0},//State 41, saw 'EL'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 43, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 42, saw 'ELS'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 43, saw 'ELSE'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 45, 62, 62, 62, 62, 62, 66, 62, 0},//State 44, saw 'W'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 46, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 45, saw 'WH'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 47, 62, 62, 62, 62, 66, 62, 0},//State 46, saw 'WHI'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 48, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 47, saw 'WHIL'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 48, saw 'WHILE'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 50, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 49, saw 'IN'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 51, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 50, saw 'INT'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 52, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 51, saw 'INTE'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 53, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 52, saw 'INTEG'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 54, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 53, saw 'INTEGE'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 54, saw 'INTEGER'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 56, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 55, saw 'R'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 57, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 56, saw 'RE'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 58, 62, 62, 62, 62, 66, 62, 0},//State 57, saw 'REA'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 58, saw 'REAL'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 60, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 59, saw 'F'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 61, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 60, saw 'FO'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 61, saw 'FOR'
  // 0   1  2  3  4  5  6  7  8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
    {66, 1, 2, 3, 4, 5, 6, 62, 8, 14, 15, 16, 17, 18, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 66, 62, 0},//State 62, saw ambiguous letter ('_' and '%' are only recognized here if they appear after letters)
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 62, 37, 62, 62, 62, 44, 62, 63, 64, 62, 0},//State 63, saw a number (if next state is not number nor '.', return 200 and move on)
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 62, 37, 62, 62, 62, 44, 62, 65, 66, 62, 0},//State 64, saw number then '.'
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 62, 37, 62, 62, 62, 44, 62, 65, 66, 62, 0},//State 65, saw number, '.', another number
    {66, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 20, 55, 62, 62, 62, 62, 27, 32, 35, 62, 62, 62, 37, 62, 62, 62, 44, 62, 62, 66, 62, 0}//State 66, saw unrecognized symbols. if this is the start state, action should be 600
  };

  //Construction of action table
    //Coincides with the next state table
    //Returns int code that corresponds to known and unkown character strings
      //Integer is based on current state and the incoming ascii conversion
  int action_table[67][36] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//State 0, start
  //  0    1    2    3    4    5    6    7    8    9    10  11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35
    {301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301, 301},//State 1, saw '+'
    {302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302, 302},//State 2, saw '-'
    {303, 303, 303, 303, 303,  0,  303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303, 303},//State 3, saw '<'
    {304, 304, 304, 304, 304,  0,  304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304, 304},//State 4, saw '>'
    {305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305, 305},//State 5, saw '='
    {600, 600, 600, 600, 600,  0,  600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600},//State 6, saw '!'
    {600, 600, 600, 600, 600, 600, 600,  0,  600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600},//State 7, saw '&'
    {600, 600, 600, 600, 600, 600, 600, 600,  0,  600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600},//State 8, saw '|'
  //  0    1    2    3    4    5    6    7    8    9    10  11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30   31   32   33   34   35
    {307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307, 307},//State 9, saw '<='
    {308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308, 308},//State 10, saw '>='
    {306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306, 306},//State 11, saw '!='
    {309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309, 309},//State 12, saw '&&'
    {310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310},//State 13, saw '||'
    {401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401, 401},//State 14, saw ';'
    {402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402, 402},//State 15, saw ','
    {404, 404, 404, 404, 404,  0,  404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404},//State 16, saw ':'
    {405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405},//State 17, saw '?'
    {406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406, 406},//State 18, saw '^'
    {403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403, 403},//State 19, saw ':='
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 20, saw 'P'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 21, saw 'PR'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 22, saw 'PRO'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 23, saw 'PROG'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 24, saw 'PROGR'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 25, saw 'PROGRA'
    {501, 501, 501, 501, 501, 501, 501, 0, 501, 501, 501, 501, 501, 501,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  501,  0, 501},//State 26, saw 'PROGRAM'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 27, saw 'B'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 28, saw 'BE'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 29, saw 'BEG'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 30, saw 'BEGI'
    {502, 502, 502, 502, 502, 502, 502, 0, 502, 502, 502, 502, 502, 502,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  502,  0, 502},//State 31, saw 'BEGIN'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 32, saw 'E'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 33, saw 'EN'
    {503, 503, 503, 503, 503, 503, 503, 0, 503, 503, 503, 503, 503, 503,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  503,  0, 503},//State 34, saw 'END'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 35, saw 'I'
    {504, 504, 504, 504, 504, 504, 504, 0, 504, 504, 504, 504, 504, 504,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  504,  0, 504},//State 36, saw 'IF'

    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 37, saw 'T'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 38, saw 'TH'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 39, saw 'THE'
    {505, 505, 505, 505, 505, 505, 505, 0, 505, 505, 505, 505, 505, 505,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  505,  0, 505},//State 40, saw 'THEN'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 41, saw 'EL'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 42, saw 'ELS'
    {506, 506, 506, 506, 506, 506, 506, 0, 506, 506, 506, 506, 506, 506,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  506,  0, 506},//State 43, saw 'ELSE'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 44, saw 'W'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 45, saw 'WH'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 46, saw 'WHI'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 47, saw 'WHIL'
    {507, 507, 507, 507, 507, 507, 507, 0, 507, 507, 507, 507, 507, 507,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  507,  0, 507},//State 48, saw 'WHILE'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 49, saw 'IN'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 50, saw 'INT'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 51, saw 'INTE'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 52, saw 'INTEG'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 53, saw 'INTEGE'
    {508, 508, 508, 508, 508, 508, 508, 0, 508, 508, 508, 508, 508, 508,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  508,  0, 508},//State 54, saw 'INTEGER'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 55, saw 'R'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 56, saw 'RE'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 57, saw 'REA'
    {509, 509, 509, 509, 509, 509, 509, 0, 509, 509, 509, 509, 509, 509,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  509,  0, 509},//State 58, saw 'REAL'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 59, saw 'F'
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 60, saw 'FO'
    {510, 510, 510, 510, 510, 510, 510, 0, 510, 510, 510, 510, 510, 510,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  510,  0, 510},//State 61, saw 'FOR'
  //  0    1    2    3    4    5    6   7   8    9    10  11   12   13   14  15  16   17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33   34  35
    {100, 100, 100, 100, 100, 100, 100, 0, 100, 100, 100, 100, 100, 100,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  100,  0, 100},//State 62, saw ambiguous letter ('_' and '%' are only recognized here if they appear after letters)
    {200, 200, 200, 200, 200, 200, 200, 0, 200, 200, 200, 200, 200, 200, 200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200, 0,   0,  200,200},//State 63, saw a number not part of variable (if next state is not number nor '.', return 200 and move on)
    {600, 600, 600, 600, 600, 600, 600,600,600, 600, 600, 600, 600, 600, 600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600, 0,  600, 600,600},//State 64, saw number then '.'
    {200, 200, 200, 200, 200, 200, 200, 0, 200, 200, 200, 200, 200, 200, 200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200, 0,   0,  200,200},//State 65, saw number, then '.', then number*
    {600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600}//State 66, saw unrecognized symbols. if this is the start state, action should be 600
  };

  cout << "\n This program will use a finite state machine to determine";
  cout << "\nif entered character strings are within the language";
  cout << "\n A code will display for recognized character strings";
  cout << "\n-----------------------------------------------------------\n\n";
  cout << " ";

  ifstream infile("Sample_Text.txt"); //<-Replace with name of test file
  string sample;
  string line;
  int count = 0;
  int next_state = 0;
  int current_state = 0;
  int action_output = 0;

  /*getline(cin, sample);  //<- for manual input
  sample += " ";*/

  /*-----------------------------------------------------------------------*/
  while(getline(infile, line)) //reads file line by line, adds to sample
  {
    cout << line << endl;
    sample = sample + line;
    sample += " "; // to account for new lines and lack of end token
  }
  /*------------------------------------------------------------------------*/

  cout << "\n********************************************************\n\n";

  while(count < sample.size())
  {
    //Finds next state based on input ascii and current state
    next_state = next_state_return[current_state][ascii_Array[sample[count]]];
    //action output found the same way as above
    action_output = action_table[current_state][ascii_Array[sample[count]]];

    //This if statement accounts for possible interruptions
      //example
        //if current state saw !, and next state points to 5
        //then the action table returns 600
        //so this if statement displays the action_output
          //BEFORE displaying the next character in the string
      //If this is ignored, program continues printing characters in string
        //until this if statement is called
    if(action_output > 0)
    {
      cout << "    " << action_output << endl; //breaks line for next character
      action_output = 0; //resets action_output for next state analysis
    }
    cout << sample[count]; //displays next (current) character

    current_state = next_state;
    count++;
  }
}
