#include <iostream>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[students][quizzes];
        double avg[students];

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";
            double sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            avg[i] = sum / quizzes;
        }

       
        for (int i = 0; i < quizzes + 3; i++)
            cout << "--------";
        cout << endl;

        
        cout << "| Stud |";
        for (int q = 0; q < quizzes; q++)
            cout << " Q" << q+1 << "   |";
        cout << " Avg   |\n";

       
        for (int i = 0; i < quizzes + 3; i++)
            cout << "--------";
        cout << endl;

     
        for (int i = 0; i < students; i++) {
            cout << "|  " << i+1 << "   |";
            for (int j = 0; j < quizzes; j++)
                cout << " " << scores[i][j] << " |";
            cout << " " << avg[i] << " |\n";
        }

        
        for (int i = 0; i < quizzes + 3; i++)
            cout << "--------";
        cout << endl;

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again=='y'||again=='Y');

    return 0;
}