#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Game {

    public:
        Game(vector<string> listInput);
        void PlayGame();
        string GenerateWord();
        bool EvaluateInput(string wordInput);
        void GenerateHint();

    private: 
        int tries;
        string computerWord;
        vector<string> wordList;
        vector<int> correctLetters;
};

#endif