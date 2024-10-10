#include<bits/stdc++.h>
using namespace std;
 
int main() {
    cout << "\n                               ****Welcome to the Number Guessing Game!****" << endl;
    int largestNumber;
    cout << "\nEnter the largest number you want to play with: ";
    cin>>largestNumber;
    int secretNumber = rand() % largestNumber + 1; // rand() is used for guessing any number
    int userGuess = 0;
    cout << "I'm thinking of a number between 1 and "<<largestNumber<<" ." << endl;
 
    while (userGuess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        if (userGuess < secretNumber) {
            cout << "Too low. Try again." << endl;
        }
        else if (userGuess > secretNumber) {
            cout << "Too high. Try again." << endl;
        }
        else {
            cout << "\n            *********Congratulations! You guessed the number!********" << endl;
        }
    }
    return 0;
}