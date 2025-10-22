#include <iostream>
#include <vector>
using namespace std;

int sumJagged(const vector<vector<int>>& arr, int row = 0) {

    if (row == arr.size())
        return 0;

    int rowSum = 0;
    for (int val : arr[row])
        rowSum += val;

    return rowSum + sumJagged(arr, row + 1);
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };

    cout << "Sum of all elements: " << sumJagged(arr) << endl;

    return 0;
}

