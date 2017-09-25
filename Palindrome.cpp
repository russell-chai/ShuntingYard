/*
 * Palindrome - by Eric Fan on 9/25/17
 * Enter a string and this program will
 * tell you if it is a palindrome.
 */

#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char str[80], strcopy[80], str2[80]; // create strings with length 80 given cap length
  cin.getline(str, 79); // read in string from input stream
  int count = 0; // copy all alphanumeric characters into a separate cstring
  for (int i = 0; i <= strlen(str); i++) {
    if (isalnum(str[i])) strcopy[count++] = toupper(str[i]);
    else if (str[i] == '\0') strcopy[count++] = str[i];
  } // reverse strcopy
  for (int i = 0; i <= strlen(strcopy); i++) str2[i] = (i == strlen(strcopy)) ? '\0' : strcopy[strlen(strcopy) - 1 - i];
  cout << ((strcmp(strcopy, str2) == 0) ? "Palindrome" : "Not a palindrome") << endl; // print out palindrome or not
}
