#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "game.h"

using namespace std;

int main() {
	ifstream inFile; //Input file
    string str;
    vector<string> words; //Vector holding student names
    string strFile = "./four_letter_words.txt";
    
    inFile.open(strFile.c_str());

    while (getline(inFile, str)) {
        words.push_back(str);
    }

    Game* game = new Game(words);
    game->PlayGame();

    return 0;
}