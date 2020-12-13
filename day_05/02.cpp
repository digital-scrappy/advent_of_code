#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string example = "FBFBBFFRLR";
int x = stoi("00011", nullptr, 2);

int row(string first7) {

  for (int i=0; i <7; i++) {
    if (first7[i] == 'F')
      { first7[i] = '0'; }
    else
      { first7[i] = '1'; }
  }
  return stoi(first7, nullptr, 2);
}

int column(string first3) {

  for (int i=0; i <3; i++) {
    if (first3[i] == 'L')
      { first3[i] = '0'; }
    else
      { first3[i] = '1'; }
  }
  return stoi(first3, nullptr, 2);
}


int main() {
  bool seats[1024]= { 0 };
  ifstream file("input.txt");
  string str;
  int biggest = 0;
  int current_pass;
  while (getline(file, str)) {
    current_pass = row(str.substr(0,7)) * 8 + column(str.substr(7,3));
    seats[current_pass] = true;
  }
  for (int i=1; i<1023; i++) {
    if (seats[i-1] == true && seats[i] == false && seats[i+1] == true)
      { cout << i << endl; }
  }

}
