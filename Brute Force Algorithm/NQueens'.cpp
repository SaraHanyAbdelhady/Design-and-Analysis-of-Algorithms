#include <iostream>
#include <vector>
#include <cmath> // For abs function

using namespace std;

bool isValid(const vector<int>& column) {
    int row = column.size() - 1;
    for (int i = 0; i < row; i++) {
        int diff = abs(column[i] - column[row]);
        if (diff == 0 || diff == row - i) return false;
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& column, vector<vector<string>>& answer) {
    if (row == n) {
        // Convert the column positions into an n x n board
        vector<string> board(n, string(n, '-')); // Initialize an empty board
        for (int i = 0; i < n; i++) {
            board[i][column[i]] = 'Q'; // Place a queen
        }
        answer.push_back(board); // Add the board to the answer
        return;
    }
    for (int col = 0; col < n; col++) {
        column.push_back(col); // Place queen
        if (isValid(column)) {
            solveNQueens(n, row + 1, column, answer); // Explore next row
        }
        column.pop_back(); // Backtrack
    }
}

vector<vector<string>> nQueens(int n) {
    vector<vector<string>> answer;
    vector<int> column;
    solveNQueens(n, 0, column, answer);
    return answer;
}

void printSolution(const vector<vector<string>>& Queens) {
    for (int i = 0; i < Queens.size(); i++) {
        for (int j = 0; j < Queens[i].size(); j++) {
            cout << Queens[i][j] << "\n";
        }
        cout << "\n===================================\n";
    }
}

int main() {
    int n;
    cout << "Enter the Number of Queens to place (>=4): \n";
    cin >> n;
    while (n < 4) {
        cout << "Invalid input. Please enter an integer greater than or equal to 4: ";
        cin >> n;
    }

    vector<vector<string>> Queens = nQueens(n);
    cout << "Solutions:\n";
    printSolution(Queens);

    return 0;
}

