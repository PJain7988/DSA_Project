#include <iostream>
#include <random>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    cout << "\n==========================================================" << endl;
    cout << "          **** Welcome to the Number Guessing Game! ****" << endl;
    cout << "==========================================================" << endl;
    
    int largestNumber;
    cout << "\nEnter the largest number you want to play with: ";
    
    // Input validation for largestNumber
    while (!(cin >> largestNumber) || largestNumber <= 1) {
        cout << "Invalid input. Please enter a number greater than 1: ";
        clearInputBuffer();
    }

    // Modern random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, largestNumber);

    int secretNumber = distrib(gen);
    int userGuess = 0;
    int attempts = 0;

    cout << "\nI'm thinking of a number between 1 and " << largestNumber << "." << endl;
 
    while (userGuess != secretNumber) {
        cout << "\nEnter your guess: ";
        
        // Input validation for userGuess
        if (!(cin >> userGuess)) {
            cout << "Invalid input. Please enter an integer." << endl;
            clearInputBuffer();
            continue;
        }
        
        attempts++;

        if (userGuess < 1 || userGuess > largestNumber) {
            cout << "Please guess a number within the range (1 to " << largestNumber << ")." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Too low. Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high. Try again." << endl;
        } else {
            cout << "\n**********************************************************" << endl;
            cout << "   Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
            cout << "**********************************************************\n" << endl;
        }
    }
    
    return 0;
}