#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(NULL));
  int guess = 0, counter = 0, rnd = rand() % 101;
  while (true) {
    if (counter == 0) cout << "Take a guess: ";
    else cout << "Take another guess: ";
    cin >> guess;
    counter++;
    if (guess < rnd) {
      cout << "Guess is too low. ";
    } else if (guess > rnd) {
      cout << "Guess is too high. ";
    } else {
      cout << "Guess is correct! Number of guesses: " << counter << ". Play again? (Y/N): ";
      char cont;
      cin >> cont;
      if (cont == 'N') {
	cout << "Game terminated." << endl;
	break;
      } else {
	cout << "New game initiated. ";
	counter = 0;
	rnd = rand() % 101;
      }
    }
  }
}
