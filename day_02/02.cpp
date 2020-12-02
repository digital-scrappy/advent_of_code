#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main () {

  ifstream file("02_input.txt");
  string str;
  string password;
  char letter;
  int max;
  int min;
  string delim_1 = ":";
  string delim_2 = "-";
  int minus;
  int colon;
  int indx = 0;
  int letter_count;
  int correct_password_count;
  int i =0;


  while (getline(file, str)) {

    colon = str.find(delim_1);
    minus = str.find(delim_2);
    letter_count = 0;

    min = stoi(str.substr(0, minus));
    max = stoi(str.substr(minus+1, minus - colon -1));
    letter = str.substr(colon-1, 1)[0];
    password = str.substr(colon+2 , str.size() - colon -2);

    for (i = 0; i < password.length(); i++) {

      if (password[i] == letter)
        { letter_count++; }

    }
    if (letter_count >= min && letter_count <= max)
      { correct_password_count++; }

    indx++;
  }

  cout << correct_password_count<< endl;

}
