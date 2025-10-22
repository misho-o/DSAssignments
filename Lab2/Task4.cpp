#include <iostream>
#include <string>
using namespace std;

int main() {
    // Departments and number of courses
    string departments[] = {"Software Engineering", "Artificial Intelligence", "Computer Science", "Data Science"};
    int numDepartments = 4;
    int coursesPerDept[] = {3, 4, 2, 1};

    // Create jagged dynamic array
    float** GPA = new float*[numDepartments];

    // Allocate memory for each department’s courses
    for (int i = 0; i < numDepartments; ++i) {
        GPA[i] = new float[coursesPerDept[i]];
    }

    // Input GPA for each department
    cout << "Enter GPAs for each department:\n";
    for (int i = 0; i < numDepartments; ++i) {
        cout << "\n" << departments[i] << " (" << coursesPerDept[i] << " courses):\n";
        for (int j = 0; j < coursesPerDept[i]; ++j) {
            cout << "  Course " << j + 1 << " GPA: ";
            cin >> GPA[i][j];
        }
    }

    // Display GPAs
    cout << "\n------------------------------------------\n";
    cout << "GPAs of Core Courses by Department:\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < numDepartments; ++i) {
        cout << departments[i] << ":\n";
        for (int j = 0; j < coursesPerDept[i]; ++j) {
            cout << "  Course " << j + 1 << " GPA = " << GPA[i][j] << endl;
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < numDepartments; ++i)
        delete[] GPA[i];
    delete[] GPA;

    return 0;
}

