#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** matrix;
    int rows, cols;

public:
    DynamicMatrix(int r, int c) {
        rows = r;
        cols = c;
        allocateMatrix();
    }

    void allocateMatrix(int initValue = 0) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = initValue;
        }
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                if (i < rows && j < cols)
                    newMatrix[i][j] = matrix[i][j]; // keep old value
                else
                    newMatrix[i][j] = fillValue;    // initialize new
            }
        }

        // Free old memory
        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;

        // Update pointers and dimensions
        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    // Transpose matrix
    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; ++j)
                transposed[i][j] = matrix[j][i];
        }

        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;

        // Update
        matrix = transposed;
        swap(rows, cols);
    }

    void addTwoToOddIndices() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if ((i + j) % 2 != 0)  // if index sum is odd
                    matrix[i][j] += 2;
    }

    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    
    ~DynamicMatrix() {
        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
};

//  to test
int main() {
    int r = 3, c = 3;
    DynamicMatrix mat(r, c);

    cout << "Initial 3x3 Matrix:\n";
    mat.printMatrix();

    cout << "\nAfter Resizing to 4x4 (fill with 5):\n";
    mat.resize(4, 4, 5);
    mat.printMatrix();

    cout << "\nAfter Transpose:\n";
    mat.transpose();
    mat.printMatrix();

    cout << "\nAfter Adding 2 to Odd Indices:\n";
    mat.addTwoToOddIndices();
    mat.printMatrix();

    return 0;
}

