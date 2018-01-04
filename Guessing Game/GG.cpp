#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  // initialize rand seed
  srand(time(NULL));
  // set initial values but make sure to reset when new game started
  int guess = 0, counter = 0, rnd = rand() % 101;
  // runs until user says to discontinue
  while (true) {
    if (counter == 0) cout << "Take a guess: ";
    else cout << "Take another guess: ";
    cin >> guess;
    counter++;
    if (guess < rnd) {
      cout << "Guess is too low. ";
    } else if (guess > rnd) {
      cout << "Guess is too high. ";
    } else { // if not higher or lower then guess is correct, ask if user wants to play again
      cout << "Guess is correct! Number of guesses: " << counter << ". Play again? (Y/N): ";
      char cont;
      cin >> cont;
      if (cont == 'N') { // break out of the loop
	cout << "Game terminated." << endl;
	break;
      } else { // otherwise reset variables
	cout << "New game initiated. ";
	counter = 0;
	rnd = rand() % 101;
      }
    }
  }
}
