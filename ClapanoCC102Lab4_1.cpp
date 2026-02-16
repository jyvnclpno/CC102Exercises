#include <iostream>
using namespace std;

int main() {
    int students, quizzes;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of quizzes per student: ";
    cin >> quizzes;

    int scores[50][50];
    float average[50];


    for (int i = 0; i < students; i++) {
        float sum = 0;
        cout << "Enter scores for Student " << i + 1 << ": ";
        for (int j = 0; j < quizzes; j++) {
            cin >> scores[i][j];
            sum += scores[i][j];
        }
        average[i] = sum / quizzes;
    }

    
    cout << "\n| Student |";
    for (int j = 1; j <= quizzes; j++) {
        cout << " Q" << j << " |";
    }
    cout << " Average |\n";

    for (int i = 0; i < students; i++) {
        cout << "|   " << i + 1 << "     |";
        for (int j = 0; j < quizzes; j++) {
            cout << "  " << scores[i][j] << "  |";
        }
        cout << "   " << average[i] << "   |\n";
    }

    return 0;
}
