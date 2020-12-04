#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> fields;
string requirements[7] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};

void reset_map() {
fields["byr"] = false;
fields["iyr"] = false;
fields["eyr"] = false;
fields["hgt"] = false;
fields["hcl"] = false;
fields["ecl"] = false;
fields["pid"] = false;
fields["cid" ] = false;
}

bool is_valid() {
  bool valid = true;

  for (int i =0; i < 7; i++) {
    if (!fields[requirements[i]])
      { valid = false; }
  }
  return valid;
}


void string_parser(string passport) {
  int token_indx;
  string field;

  token_indx = passport.find(' ');
  field = passport.substr(0,3);
  fields[field] = true;

  if (token_indx != string::npos ) {

    passport = passport.substr(token_indx +1 , passport.length() - token_indx -1);

    if (passport.length() > 2)
      { string_parser(passport); }
  }
}

int main() {
  ifstream file("04_input.txt");
  string str;
  int valid_ones = 0;

  reset_map();

  while (getline(file, str)) {

    if (str.length() > 2)
      { string_parser(str); }

    if (str.length() <= 1) {
        if (is_valid())
          { valid_ones++; }

        reset_map();
    }

  }
  if (is_valid())
    { valid_ones++; }

  cout << valid_ones << endl;
}
