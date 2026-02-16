#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main() {
    system("cls");
    const int salespeople = 4;
    const int products = 5;
    double sales[products][salespeople] = {0};

    char more;
    do {
        int sp, prod;
        double amount;

        cout << "Salesperson (1-4): ";
        cin >> sp;
        cout << "Product (1-5): ";
        cin >> prod;
        cout << "Amount: ";
        cin >> amount;

        sales[prod - 1][sp - 1] += amount;

        cout << "Add another slip? (Y/N): ";
        cin >> more;
    } while (more == 'Y' || more == 'y');

    cout << "\n| Product |";
    for (int sp = 1; sp <= salespeople; sp++) {
        cout << " Salesperson " << sp << " |";
    }
    cout << " Total |\n";

    double grandTotal = 0;
    double colTotals[salespeople] = {0};

    for (int prod = 0; prod < products; prod++) {
        double rowTotal = 0;
        cout << "|   " << setw(3) << prod + 1 << "   |";
        for (int sp = 0; sp < salespeople; sp++) {
            cout << setw(12) << fixed << setprecision(2) << sales[prod][sp] << " |";
            rowTotal += sales[prod][sp];
            colTotals[sp] += sales[prod][sp];
        }
        cout << setw(7) << rowTotal << " |\n";
        grandTotal += rowTotal;
    }


    cout << "| Total   |";
    for (int sp = 0; sp < salespeople; sp++) {
        cout << setw(12) << fixed << setprecision(2) << colTotals[sp] << " |";
    }
    cout << setw(7) << grandTotal << " |\n";

    return 0;
}