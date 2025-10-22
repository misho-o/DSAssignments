#include <iostream>
using namespace std;

// Function to check if two people have a common friend
bool haveCommonFriend(bool friends[5][5], int a, int b) {
    for (int k = 0; k < 5; ++k) {
        if (friends[a][k] && friends[b][k]) {
            return true;  // Found a common friend
        }
    }
    return false;  // No common friend found
}

int main() {
    // 5x5 Boolean matrix representing friendships
    bool friends[5][5] = {
        //  0    1    2    3    4
        {false, true, false, true, false},  // person 0
        {true, false, true, false, false},  // person 1
        {false, true, false, false, false}, // person 2
        {true, false, false, false, true},  // person 3
        {false, false, false, true, false}  // person 4
    };

    cout << "Friendship Matrix (1 = friends, 0 = not friends):\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << friends[i][j] << " ";
        cout << endl;
    }

    cout << "\nChecking common friends:\n";
    cout << "Do 0 and 4 have a common friend? ";
    cout << (haveCommonFriend(friends, 0, 4) ? "Yes" : "No") << endl;

    cout << "Do 1 and 2 have a common friend? ";
    cout << (haveCommonFriend(friends, 1, 2) ? "Yes" : "No") << endl;

    cout << "Do 0 and 1 have a common friend? ";
    cout << (haveCommonFriend(friends, 0, 1) ? "Yes" : "No") << endl;

    return 0;
}

