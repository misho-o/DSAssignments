

//TASK 5: GPA DEPT
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int departments;
    const int subjects = 5;

    cout << "Enter number of departments: ";
    cin >> departments;

    // Dynamic array of pointers for departments
    int** studentsInDept = new int*[departments];  // each dept will hold marks of its students
    int* numStudents = new int[departments];       // to store number of students per department

    // Input number of students per department
    for (int i = 0; i < departments; ++i) {
        cout << "Enter number of students in Department " << i + 1 << ": ";
        cin >> numStudents[i];
    }

    // Allocate memory for each department
    for (int i = 0; i < departments; ++i) {
        studentsInDept[i] = new int[numStudents[i] * subjects]; // each student has 5 subjects
    }

    // Input marks
    cout << "\nEnter marks (out of 100) for each student:\n";
    for (int d = 0; d < departments; ++d) {
        cout << "\n--- Department " << d + 1 << " ---\n";
        for (int s = 0; s < numStudents[d]; ++s) {
            cout << "Student " << s + 1 << ":\n";
            for (int sub = 0; sub < subjects; ++sub) {
                cout << "  Subject " << sub + 1 << ": ";
                cin >> studentsInDept[d][s * subjects + sub];
            }
        }
    }

    cout << "\n===========================================\n";

    // Calculate and display stats per department
    for (int d = 0; d < departments; ++d) {
        int highest = 0, lowest = 9999;
        double totalDeptMarks = 0;

        for (int s = 0; s < numStudents[d]; ++s) {
            int totalStudent = 0;
            for (int sub = 0; sub < subjects; ++sub)
                totalStudent += studentsInDept[d][s * subjects + sub];

            if (totalStudent > highest)
                highest = totalStudent;
            if (totalStudent < lowest)
                lowest = totalStudent;

            totalDeptMarks += totalStudent;
        }

        double avgDept = totalDeptMarks / numStudents[d];

        cout << fixed << setprecision(2);
        cout << "\nDepartment " << d + 1 << " Statistics:\n";
        cout << "  Highest Total Marks: " << highest << endl;
        cout << "  Lowest Total Marks : " << lowest << endl;
        cout << "  Average Total Marks: " << avgDept << endl;
    }

    cout << "\n===========================================\n";

    // Free memory
    for (int i = 0; i < departments; ++i)
        delete[] studentsInDept[i];
    delete[] studentsInDept;
    delete[] numStudents;

    return 0;
}
