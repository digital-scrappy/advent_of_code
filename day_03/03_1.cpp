#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  bool tundra[323][31];
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
  indx = 0;
  for (i = 0; i < 323; i++) {

    if ( tundra[i][indx] )
      { treecount++; }

    indx += 3;
    if (indx > 30)
      { indx -= 31; }

  }
  cout << treecount << endl;
}
