#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream outFile("color.txt");
    if (!outFile) {
        cout << "Could not open color.txt for writing." << endl;
        return 1;
    }

    outFile << "Black\n";
    outFile << "Orange\n";
    outFile << "Blue\n";
    outFile << "Green\n";
    outFile << "Red\n";
    outFile.close();


    ifstream inFile("color.txt");
    if (!inFile) {
        cout << "Could not open color.txt for reading." << endl;
        return 1;
    }

    ofstream copyFile("colorCopy.txt");
    if (!copyFile) {
        cout << "Could not open colorCopy.txt for writing." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "File copied successfully!" << endl;
    return 0;
}
