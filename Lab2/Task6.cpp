#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows in the conference hall: ";
    cin >> rows;

    // Create jagged array (array of string pointers)
    string** seats = new string*[rows];
    int* seatsPerRow = new int[rows]; // to keep track of each row's size

    // Input seat capacities for each row
    for (int i = 0; i < rows; ++i) {
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seatsPerRow[i];
        seats[i] = new string[seatsPerRow[i]];  // allocate memory for each row
    }

    cout << "\n--- Enter attendee names ---\n";
    for (int i = 0; i < rows; ++i) {
        cout << "\nRow " << i + 1 << ":\n";
        for (int j = 0; j < seatsPerRow[i]; ++j) {
            cout << "  Seat " << j + 1 << ": ";
            cin >> seats[i][j];
        }
    }

    // Display seating chart
    cout << "\n=========== Conference Seating Chart ===========\n";
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seatsPerRow[i]; ++j) {
            cout << seats[i][j] << "\t";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i)
        delete[] seats[i];
    delete[] seats;
    delete[] seatsPerRow;

    return 0;
}

