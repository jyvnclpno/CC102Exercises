#include <iostream>
#include <iomanip>

using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    float gpa;
};

void input(student s[], int number) {
    for (int i = 0; i < number; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        bool taken;
        do {
            taken = false;
            cout << "Student ID : ";
            cin >> s[i].studentID;
            cin.ignore();
            for (int j = 0; j < i; j++) {
                if (s[j].studentID == s[i].studentID) {
                    taken = true;
                    cout << "ID already exists! Try again.\n";
                    break;
                }
            }
        } while (taken);

        cout << "Name : ";
        getline(cin, s[i].name);
        cout << "Course : ";
        getline(cin, s[i].course);
        cout << "GPA (0-100): ";
        cin >> s[i].gpa;
        cin.ignore();
    }
}

void display(student s[], int number) {
    cout << "\n";
    cout << left
         << setw(12) << "Student ID"
         << setw(22) << "Name"
         << setw(18) << "Course"
         << setw(8)  << "GPA"
         << "Academic Standing" << "\n";
    cout << "---------------------------------------------------------------------------" << "\n";

    for (int i = 0; i < number; i++) {
        string standing;
        if      (s[i].gpa >= 90) standing = "Excellent";
        else if (s[i].gpa >= 80) standing = "Very Good";
        else if (s[i].gpa >= 70) standing = "Good";
        else if (s[i].gpa >= 60) standing = "Passing";
        else                     standing = "Failed";

        cout << left
             << setw(12) << s[i].studentID
             << setw(22) << s[i].name
             << setw(18) << s[i].course
             << setw(8)  << s[i].gpa
             << standing << "\n";
    }
}

int main() {
    int number;
    char choice;

    do {
        cout << "Enter number of students: ";
        cin >> number;
        cin.ignore();

        student s[number];

        input(s, number);
        display(s, number);

        cout << "\nRun again? (y/n): ";
        cin >> choice;
        cin.ignore();
        cout << "\n";
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
