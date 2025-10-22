
//TASK 2:SCHOOL MANAGEMNT
#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    
    int** marks = new int*[students];
    for (int i = 0; i < students; ++i)
        marks[i] = new int[subjects];

    
    cout << "Enter marks for " << students << " students in " << subjects << " subjects:\n";
    for (int i = 0; i < students; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        for (int j = 0; j < subjects; ++j) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n-------------------------------\n";

    // Calculate total marks per student
    int* totalMarks = new int[students];
    int topperIndex = 0;
    int highestTotal = 0;

    for (int i = 0; i < students; ++i) {
        totalMarks[i] = 0;
        for (int j = 0; j < subjects; ++j)
            totalMarks[i] += marks[i][j];

        cout << "Total marks of Student " << i + 1 << " = " << totalMarks[i] << endl;

        // Find topper
        if (totalMarks[i] > highestTotal) {
            highestTotal = totalMarks[i];
            topperIndex = i;
        }
    }

    cout << "\n-------------------------------\n";

   
    cout << "Average marks per subject:\n";
    for (int j = 0; j < subjects; ++j) {
        double subjectTotal = 0;
        for (int i = 0; i < students; ++i)
            subjectTotal += marks[i][j];
        cout << "Subject " << j + 1 << " average = " << subjectTotal / students << endl;
    }

    cout << "\n-------------------------------\n";


    cout << "Topper Student: Student " << topperIndex + 1
         << " with total marks = " << highestTotal << endl;

    cout << "-------------------------------\n";

    // Free dynamically allocated memory
    for (int i = 0; i < students; ++i)
        delete[] marks[i];
    delete[] marks;
    delete[] totalMarks;

    return 0;
}
