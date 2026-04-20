#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ofstream outFile("original.txt");
    if (!outFile) {
        cout << "Error opening original.txt for writing." << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;
    outFile.close();

    ifstream inFile("original.txt");
    if (!inFile) {
        cout << "Error opening original.txt for reading." << endl;
        return 1;
    }

    vector<string> words;
    string line;
    while (getline(inFile, line)) {
        words.push_back(line);
    }
    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");
    if (!sortedFile) {
        cout << "Error opening sorted.txt for writing." << endl;
        return 1;
    }

    for (int i = 0; i < words.size(); i++) {
        sortedFile << words[i] << endl;
    }
    sortedFile.close();

    cout << "original.txt has been sorted and saved to sorted.txt successfully." << endl;

    return 0;
}
