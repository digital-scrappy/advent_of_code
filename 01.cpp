#include <string>
#include <fstream>
#include <iostream>
#include <istream>
using namespace std;



int main () {
  ifstream infile("01_input.txt");
  int arr[200];
  int indx = 0;
  int x;
  bool flag = false;

  while (infile >> x) {
    arr[indx] = x;
    indx++;
  }
  for (int a = 0; a < 200; a++) {
    if (flag) {break;}
    for(int b = 0; b < 200; b++) {
      if (flag) {break;}
      for(int c = 0; c < 200; c++) {
      if (arr[b]+arr[a]+arr[c] == 2020) {
        cout << arr[a]*arr[b]*arr[c] << endl;
        flag = true;
        break;
      }
      }
    }

  }


  return 0;
}
