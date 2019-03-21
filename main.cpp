#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    for (int i =0; i < 10; ++i) {
        cout << words.at(i) << endl;
    }

    return 0;
}