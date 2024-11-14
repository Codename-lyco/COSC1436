// This program has the user try to guess a number that the computer randomly generates.

// Ayden Bishop
// 11/11/2024

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void getCorrectGuess(int, int&, int);
void showOutcome(int, int);

int main()
{
    char again;

    // Do-while loop to ask the user if they want to play again.
    do
    {
    srand(time(0));     // To get a fully random number

    int randNum = (rand() % 50) + 1;
    int userGuess;
    int guess = 0;

    // Asks the user to input a number.
    cout << "You have 10 tries" << endl;
    cout << "Guess the number from the range 1-50: ";
    cin >> userGuess;

    /* Input validation to make sure the user inputs a number in
    the correct range */
    while (userGuess < 1 || userGuess > 50)
    {
        cout << "Error: input an integer in the range 1-50: ";
        cin >> userGuess;
    }

    // Functions to get the guesses and outcome of the user.
    getCorrectGuess(randNum, guess, userGuess);
    showOutcome(guess, randNum);

    // Asks the user if they want to play again.
    cout << "Do you want to try again? (y/n): ";
    cin >> again;
    cout << endl;

    } while (again == 'y' || again == 'Y');

    return 0;
}

void getCorrectGuess(int randNum, int& guess, int userGuess)
{
    bool guessCorrect = false;

    // Determines whether the guess is to high, low, or the correct answer
    while (!guessCorrect && guess != (10 - 1))
    {
        if (userGuess > randNum)
        {
            cout << "Try Again! You guessed too high: ";
            cin >> userGuess;
        }
        else if (userGuess < randNum)
        {
            cout << "Try Again! You guessed too low: ";
            cin >> userGuess;
        }
        else
            guessCorrect = true;

        guess++;
    }
}

void showOutcome(int guess, int randNum)
{
    // Determines the outcome of the guesses the user made.
    if (guess == (10 - 1))
        cout << endl << "That's too bad. You did not guess the correct number in time" << endl;
    else
    {
        cout << endl << "Congratulations!" << endl;
        cout << "You got the correct number in " << guess << " time(s)" << endl;
    }
    cout << "The random number was " << randNum << endl;
}
