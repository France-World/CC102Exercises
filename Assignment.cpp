#include <iostream>
#include <vector>
using namespace std;

void displayMatrix(vector<vector<int>>* grades, int rows, int columns) {
    cout << "\n============= GRADE MATRIX ==============\n";
    cout << "\t";
    for (int i = 0; i < columns; i++)
        cout << "SUB" << i + 1 << "\t";
    cout << "AVERAGE\n";

    for (int i = 0; i < rows; i++) {
        cout << "S" << i + 1 << "\t";
        int sum = 0;
        for (int j = 0; j < columns; j++) {
            int grade = (*grades)[i][j];
            cout << grade << "\t";
            sum += grade;
        }
        double avg = (double)sum / columns;
        cout << avg << '\n';
    }

    int highestGrade = (*grades)[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            int grade = (*grades)[i][j];
            if (grade > highestGrade) highestGrade = grade;
        }
    cout << "\nHIGHEST GRADE: " << highestGrade << endl;
}

void inputMatrix(vector<vector<int>>* grades, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        cout << "Enter grades for student " << i + 1 << ":" << endl;
        for (int j = 0; j < columns; j++) {
            cout << "Enter grade for subject " << j + 1 << ": ";
            cin >> (*grades)[i][j];
            cout << endl;
        }
    }
}

int main() {
    int students;
    int subjects;
    cout << "Enter how many students: ";
    cin >> students;
    cout << "Enter how many subjects: ";
    cin >> subjects;
    vector<vector<int>> grades(students, vector<int>(subjects));
    inputMatrix(&grades, students, subjects);
    displayMatrix(&grades, students, subjects);
    return 0;
}
