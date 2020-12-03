#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool tundra[323][31];


int ride_yo_sled(int horizontal, int vertical) {
  int indx = 0;
  int treecount = 0;
  for (int i = 0; i < 323; i+=vertical) {

    if (tundra[i][indx] )
      { treecount++; }

    indx += horizontal;

    if (indx > 30)
      { indx -= 31; }
  }
  return treecount;
}

void sled_testing(int directions[5][2]) {
  int lenght = 5;
  int trees= 1;
  for (int i = 0; i < lenght; i++) {
    trees *= ride_yo_sled(directions[i][0], directions[i][1]);
      }
  cout << trees << endl;
}
int main() {

  int directions[5][2] = {{1,1},
                          {3,1},
                          {5,1},
                          {7,1},
                          {1,2}};
  string str;
  int indx = 0;
  int i = 0;
  int treecount = 0;
  ifstream file("03_input.txt");

  while (getline(file, str)) {
    for (i = 0; i < 31; i++) {

      if (str[i] == '.')
        { tundra[indx][i] = false; }

      else if (str[i] == '#')
        { tundra[indx][i] = true;}
    }
    indx++;
  }
  sled_testing(directions);
}
