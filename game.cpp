#include <iostream>
#include "game.h"

Game::Game(vector<string> listInput) {
    this->tries = 0;
    this->computerWord = "none";
    this->wordList = listInput;
}



void Game::PlayGame() {

    bool correctWord = false;

    this->GenerateWord();

    cout << "WORD: " << this->computerWord << endl; 
    cout << "Computer: I have a 4 letter word in mind. Can you guess it?" << endl;

    cout << "Computer: * means one of the letters is right and in the right place" << endl;
    cout << "Computer: - means one of the letters is right and in the wrong place" << endl;

    while (correctWord == false) {

        string guess;

        cout << "What's your guess?" << endl;
        getline(cin, guess);
        cout << "Player: " << guess << endl;

        correctWord = EvaluateInput(guess);

        this->tries += 1;
    }

    cout << "Computer: You got it! " << this->tries << " tries." << endl;

}

bool Game::EvaluateInput(string wordInput) {

    bool evaluation = false;
    
    int letterNotPresent = 0;
    int letterPresentWrongPosition = 0;
    int rightLetterRightPosition = 0;

    for (int i = 0; i < wordInput.length(); ++i) {
        int place;
        string inputCastString(1, wordInput.at(i));
        place = this->computerWord.find(inputCastString);

        if (place == -1) {
            letterNotPresent += 1;
        }
        else {
            if (place == i) {
                rightLetterRightPosition += 1;
            }
            else {
                letterPresentWrongPosition += 1;
            }
        }

    }

    cout << "A: " <<  letterNotPresent << endl;
    cout << "B: " <<  letterPresentWrongPosition << endl;
    cout << "C: " << rightLetterRightPosition << endl;

    // output of evaluation

    if (letterNotPresent == 4) {
        cout << "Computer: You got nothing. Sorry!";
    }
    else {
        cout << "Computer: " << string(rightLetterRightPosition, '*') << string(letterPresentWrongPosition, '-') << endl; 
    }

    // evaluate whether player got the right answer
    if (rightLetterRightPosition == 4) {
        evaluation = true;
    }

    return evaluation;

}

string Game::GenerateWord() {

    int length = this->wordList.size();
    srand (time(NULL));
    cout << "RANDOM: " << rand() % length << endl;
    this->computerWord = this->wordList.at(rand() % length);
    return this->computerWord;

}