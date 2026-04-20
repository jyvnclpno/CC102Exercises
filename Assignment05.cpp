#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  
    ofstream outFile("original.txt");
  
    outFile << "One\n";
    outFile << "Two\n";
    outFile << "Three\n";
    outFile << "Four\n";
    outFile << "Five\n";
    outFile << "Six\n";

    outFile.close();

    string words[6];
  
    ifstream inFile("original.txt");
    for (int i = 0; i < 6; i++) {
        inFile >> words[i];
    }
    inFile.close();

    sort(words, words + 6);
  
    ofstream sortedFile("sorted.txt");
  
    for (int i = 0; i < 6; i++) {
        sortedFile << words[i] << endl;
    }
    sortedFile.close();

    cout << "Sorted file created!" << endl;
    return 0;
}
