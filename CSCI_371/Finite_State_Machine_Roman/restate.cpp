#include <iostream>

using namespace std;

int main() {
int next_state[20][6] = {
  {1,7,11,14,15,4},//State 0, start
  {2,5,6,4,4,4},//State 1 saw I
  {3,4,4,4,4,4},//State 2
  {4,4,4,4,4,4},//State 3
  {4,4,4,4,4,4},//State 4 dead state
  {4,4,4,4,4,4},//State 5
  {4,4,4,4,4,4},//State 6
  {8,4,4,4,4,4},//State 7 saw V
  {9,4,4,4,4,4},//State 8
  {10,4,4,4,4,4},//State 9
  {4,4,4,4,4,4},//State 10
  {1,7,12,14,16,4},//State 11 saw X
  {1,7,13,4,4,4},//State 12
  {1,7,4,4,4,4},//State 13
  {1,7,11,4,4,4},//State 14 saw L
  {1,7,11,14,17,4},//State 15 saw C
  {1,7,4,4,4,4},//State 16
  {1,7,11,14,18,4},//State 17 saw second C
  {19,19,19,19,19,4},//State 18 saw third C
  {19,19,19,19,19,4},//State 19 Special case for capping input >= 300
// I  V  X  L  C  !
};

for (int i = 0; i < 20; i++) {
if (i == 4) continue;
cout << '{';
for (int j = 0; j < 6; j++) {
 if (next_state[i][j] > 4) {
  cout << next_state[i][j] - 1;
} else if (next_state[i][j] == 4) {
  cout << -1;
} else {
  cout << next_state[i][j];
}

 if (j != 5) cout << ", ";
}
cout << '}';

if (i != 19) {
cout << ",\n";
}
}

}
