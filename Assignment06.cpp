#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int num) {

    if(num <= 1) return false;

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}


int countPrimes() {

    ifstream inFile("NUMS.TXT");

    if(!inFile) {
        cout << "File not found!" << endl;
        return 0;
    }

    int number, primeCount = 0;

    while(inFile >> number) {
        if(isPrime(number)) {
            primeCount++;
        }
    }

    inFile.close();

    return primeCount;
}

int main() {

    int result = countPrimes();

    cout << "Number of prime numbers: " << result << endl;

    return 0;
}
