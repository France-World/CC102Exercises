#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("color.txt");
    if (!outFile) {
        cout << "Error opening color.txt for writing." << endl;
        return 1;
    }

    outFile << "Red" << endl;
    outFile << "Blue" << endl;
    outFile << "Green" << endl;
    outFile << "Yellow" << endl;
    outFile << "Purple" << endl;
    outFile.close();

    ifstream inFile("color.txt");
    if (!inFile) {
        cout << "Error opening color.txt for reading." << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");
    if (!copyFile) {
        cout << "Error opening color_copy.txt for writing." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "color.txt has been copied to color_copy.txt successfully." << endl;

    return 0;
}
