#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;

// Function to check if the arrangement is valid
bool isValid(const vector<int>& queens) {
    int n = queens.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(queens[i] - queens[j]) == abs(i - j)) { // Diagonal conflict
                return false;
            }
        }
    }
    return true;
}

void solveNQueens(int n) {
    vector<int> queens(n);
    for (int i = 0; i < n; i++) {
        queens[i] = i; 
    }

    int count = 0;
    do {
        if (isValid(queens)) {
            count++;
            // Print the arrangement
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == queens[i]) {
                        cout << "Q ";
                    }
                    else {
                        cout << ". ";
                    }
                }
                cout << endl;
            }
            cout << "=================================\n";
        }
    } while (next_permutation(queens.begin(), queens.end()));

    cout << "Total solutions: " << count << endl;
}

int main() {
    int n;
    cout << "Enter the number of queens to place (>=4): \n";
    cin >> n;

    if (n < 4) {
        cout << "The board size must be at least 4x4.\n Please, Enter a number greater than 3: \n" << endl;
        return 0;
    }

    solveNQueens(n);

    return 0;
}
