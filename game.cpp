#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "game.h"

Game::Game(vector<string> listInput) {
    vector<int> letterVector;
    this->tries = 0;
    this->computerWord = "none";
    this->wordList = listInput;
    this->correctLetters = letterVector;
}

void Game::PlayGame() {

    bool correctWord = false;
    bool quitCommand = false;

    this->GenerateWord();

    cout << "Computer: I have a 4 letter word in mind. Can you guess it?" << endl;
    cout << "Computer: * means one of the letters is right and in the right place" << endl;
    cout << "Computer: - means one of the letters is right and in the wrong place" << endl;
    cout << "Computer: To get a hint, type 'hint" << endl;
    cout << "Computer: To quit, type 'quit'" << endl;

    while (correctWord == false && quitCommand == false) {

        string guess;

        cout << "Player: ";
        getline(cin, guess);

        if (guess.length() != 4) {
            cout << "Computer: Please enter a 4-letter word!" << endl;
        }
        else if (guess == "quit") {
            quitCommand = true;
        }
        else if (guess == "hint") {
            this->GenerateHint();
        }
        else {
            correctWord = EvaluateInput(guess);
            this->tries += 1;
        }
    }

    if (quitCommand == true) {
        cout << "Computer: good bye!" << endl;
    }
    else {
        cout << "Computer: You got it! " << this->tries << " tries." << endl;
    }

}

void Game::GenerateHint() {
    
    vector<int> diff;
    vector<int> allLetters;

    allLetters.push_back(0);
    allLetters.push_back(1);
    allLetters.push_back(2);
    allLetters.push_back(3);

    for (int i=0; i < allLetters.size(); ++i) {
        if (find(this->correctLetters.begin(), this->correctLetters.end(), allLetters.at(i)) != this->correctLetters.end()) {
            continue;
        }
        else {
            diff.push_back(allLetters.at(i));
        }
    }

    if (this->correctLetters.size() < 3) {
        this->correctLetters.push_back(diff.at(0));
    } 

    cout << "Computer: ";
    for (int i =0; i < allLetters.size(); ++i) {
        if (find(this->correctLetters.begin(), this->correctLetters.end(), allLetters.at(i)) != this->correctLetters.end()) {
            cout << this->computerWord.at(i);
        }
        else {
            cout << "*";
        }
    }        

    cout << endl;

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
                this->correctLetters.push_back(i);
            }
            else {
                letterPresentWrongPosition += 1;
            }
        }

    }

    // output of evaluation

    if (letterNotPresent == 4) {
        cout << "Computer: You got nothing. Sorry!" << endl;
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
    this->computerWord = this->wordList.at(rand() % length);
    return this->computerWord;

}