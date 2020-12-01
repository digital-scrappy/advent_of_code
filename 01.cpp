#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <vector>
using namespace std;



// int main () {
//   ifstream infile("01_input.txt");
//   vector<int> arr;
//   int indx = 0;
//   int x;
//   int d = 0;

//   while (infile >> x) {
//     arr.push_back(x);
//   }
//   for (int a = 0; a < arr.size(); a++) {
//     for(int b = 0; b < arr.size(); b++) {
//       for(int c = 0; c < arr.size(); c++) {
//         d = arr[b]+arr[a]+arr[c];
//       if (d == 2020) {
//         cout << arr[a]*arr[b]*arr[c] << endl;
//       }
//       }
//     }
//   }
//   return 0;
// }

int main () {
  ifstream infile("01_input.txt");
  vector<int> arr;
  int indx = 0;
  int x;
  int d = 0;
  int crazy = 0;
  while (infile >> x) {
    arr.push_back(x);
  }
  for (crazy; crazy < 1000001; crazy++){
  for (int a = 0; a < arr.size(); a++) {
    for(int b = 0; b < arr.size(); b++) {
      d = arr[b]+arr[a];
      if (d == 2020) {
        cout << arr[a]*arr[b] << endl;

      }
    }
  }
  }
  return 0;
}
