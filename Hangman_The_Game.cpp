#include <iostream>
#include <string>
#include "Words.h"
#include "Player.h"
#include "Scoreboard.h"

using namespace std;

void drawHangman(int errors) {
    cout << "  -------" << endl;
    cout << "  |     |" << endl;

    if (errors == 0) {
        cout << "  |" << endl; cout << "  |" << endl; cout << "  |" << endl;
    }
    else if (errors == 1) {
        cout << "  |     O" << endl; cout << "  |" << endl; cout << "  |" << endl;
    }
    else if (errors == 2) {
        cout << "  |     O" << endl; cout << "  |     |" << endl; cout << "  |" << endl;
    }
    else if (errors == 3) {
        cout << "  |     O" << endl; cout << "  |    /|" << endl; cout << "  |" << endl;
    }
    else if (errors == 4) {
        cout << "  |     O" << endl; cout << "  |    /|\\" << endl; cout << "  |" << endl;
    }
    else if (errors == 5) {
        cout << "  |     O" << endl; cout << "  |    /|\\" << endl; cout << "  |    /" << endl;
    }
    else if (errors == 6) {
        cout << "  |     O" << endl; cout << "  |    /|\\" << endl; cout << "  |    / \\" << endl;
    }

    cout << "  |" << endl;
    cout << "  |" << endl;
}

int main() {
    Words wordManager;
    Scoreboard scoreboard;

    //exception
    try {
        wordManager.loadWords("words.txt");
    }
    catch (runtime_error& e) {
        cout << "ERROR: " << e.what() << endl;
        cout << "Please make sure 'words.txt' is in the correct folder." << endl;
        return 1; //exit and return safely
    }

    int choice = 0;

    //main menu loop
    while (choice != 4) {
        cout << "\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
        cout << "S                   Welcome to Hangman!                    S" << endl;
        cout << "S                    1 - Instructions                      S" << endl;
        cout << "S                    2 - Play the Game                     S" << endl;
        cout << "S                    3 - Leaderboard                       S" << endl;
        cout << "S                    4 - Exit                              S" << endl;
        cout << "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            //instructions
            cout << "You need to guess the word one letter at a time..." << endl;
            cout << "Categories: Fruits, Colors, Animals" << endl;
        }
        
        else if (choice == 2) {
            cout << "Enter your name: ";
            string playerName;
            cin >> playerName;

            Player currentPlayer(playerName);
            string secretWord = wordManager.getRandomWord();
            string guessedWord(secretWord.length(), '_');

            //vector to store guesses
            vector<char> guessedLetters;

            int attemptsLeft = 6;
            int errorsMade = 0;
            bool wordGuessed = false;

            while (attemptsLeft > 0 && !wordGuessed) {
                drawHangman(errorsMade);

                cout << "\nWord: " << guessedWord << endl;
                cout << "Attempts left: " << attemptsLeft << endl;

                cout << "Guessed letters: ";
                for (int i = 0; i < guessedLetters.size(); i++) {
                    cout << guessedLetters[i] << " ";
                }
                cout << "\nGuess a letter: ";

                char guess;
                cin >> guess;

                //put the guessed letter innside the vector
                guessedLetters.push_back(guess);

                bool found = false;
                for (int i = 0; i < secretWord.length(); i++) {
                    if (secretWord[i] == guess) {
                        guessedWord[i] = guess;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "\nIncorrect guess!" << endl;
                    attemptsLeft--;
                    errorsMade++;
                }
                else {
                    cout << "\nCorrect guess!" << endl;
                }

                if (guessedWord == secretWord) {
                    wordGuessed = true;
                }
            }

            //final draw
            drawHangman(errorsMade);

            if (wordGuessed) {
                cout << "\nCongratulations! You guessed the word: " << secretWord << endl;

                int pointsWon = 0;
                if (errorsMade == 0) pointsWon = 10;
                else if (errorsMade == 1) pointsWon = 8;
                else if (errorsMade == 2) pointsWon = 6;
                else if (errorsMade == 3) pointsWon = 4;
                else if (errorsMade == 4) pointsWon = 2;
                else if (errorsMade == 5) pointsWon = 1;

                cout << "You won " << pointsWon << " points!" << endl;

                currentPlayer.addPoints(pointsWon);
                scoreboard.addPlayer(currentPlayer);

                try {
                    scoreboard.saveToFile("leaderboard.txt");
                }
                catch (runtime_error& e) {
                    cout << "WARNING: " << e.what() << endl;
                }
            }
            else {
                cout << "\nYou lost! The word was: " << secretWord << endl;
            }
        }
        else if (choice == 3) {
            scoreboard.displayLeaderboard();
        }
        else if (choice == 4) {
            cout << "Thanks for playing!" << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
