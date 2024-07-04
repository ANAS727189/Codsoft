#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    cout << "Welcome to the best Random Game in the World!" << endl;
    cout << "Now to explain the rules:" << endl;
    cout << "The Game will start from Level 1 and the final level is 100" << endl;
    cout << "You have to complete each level to enter the next level" << endl;
    cout << "In each level, you have to guess a number in a range and as you move forward, the range keeps increasing." << endl;
    cout << "You have 5 chances of guessing the number at 1st level then 10 on 2nd level and so on, If the guesses are finished then you are OUT!" << endl;
    cout << "I believe you understood all the rules, So Let's Begin the Game" << endl;
    cout << "DING DONG DING, LET THE GAME BEGIN" << endl;

    cout << endl;
    cout << endl;

    int level = 1;
    while (level <= 100) {
        cout << "Level " << level << " Loading ....." << endl;

        int max_range = level * 10;
        int random_number = rand() % max_range;

        bool level_won = false;
        for (int chance = 1; chance <= (level*5); chance++) {
            cout << "Guess the number between 0 to " << max_range - 1 << ": ";
            int guess;
            cin >> guess;

            if (guess == random_number) {
                cout << "Congrats! Yo YO Yo you have found the number." << endl;
                level_won = true;
                break;
            } else if (abs(guess - random_number) >= 20) {
                cout << "No No, It is very high, you are very far from the number" << endl;
            } else if (guess > random_number) {
                cout << "No, It is very close but still high from the number" << endl;
            } else {
                cout << "No No you are still low to reach the number" << endl;
            }
        }

        if (!level_won) {
            cout << "BOOOOO ! YOU LOST THE GAME ...TRY AGAIN !" << endl;
            cout << "The correct number was: " << random_number << endl;
            cout << "Press 1 to try again and 0 to quit: ";
            int check;
            cin >> check;
            if (check == 1) {
                level = 1;
            } else {
                break; 
            }
        } else {
            level++; 
        }
    }

    return 0;
}
