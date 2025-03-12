#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMagicSquare(const vector<int>& grid) {
    int magicSum = 15; 

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i * 3] + grid[i * 3 + 1] + grid[i * 3 + 2] != magicSum) {
            return false;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[i] + grid[i + 3] + grid[i + 6] != magicSum) {
            return false;
        }
    }

    // Check diagonals
    if (grid[0] + grid[4] + grid[8] != magicSum || grid[2] + grid[4] + grid[6] != magicSum) {
        return false;
    }

    return true;
}

int main() {
    vector<int> grid = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Initialize the grid with numbers 1 to 9
    int count = 0; // Counter for the number of valid magic squares

    // Generate all permutations of the grid
    do {
        if (isMagicSquare(grid)) {
            count++;
            // Print the magic square
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[i * 3 + j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    } while (next_permutation(grid.begin(), grid.end()));

    // Print the total number of solutions
    cout << "Total number of magic squares: " << count << endl;

    return 0;
}
