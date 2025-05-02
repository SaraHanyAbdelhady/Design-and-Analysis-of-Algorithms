#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Modified function to return both the max sum and the path
pair<int, vector<int>> findMaxPathSum(vector<vector<int>>& triangle, int levels) {
    int rows = levels;
    vector<vector<int>> dp(rows, vector<int>(rows, 0));
    vector<vector<int>> path(rows, vector<int>(rows, 0)); // To track the path

    // Initialize the last row with the triangle's base values
    for (int j = 0; j < triangle[rows - 1].size(); j++) {
        dp[rows - 1][j] = triangle[rows - 1][j];
    }

    // Compute maximum sum from bottom up and track the path
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (dp[i + 1][j] >= dp[i + 1][j + 1]) {
                dp[i][j] = triangle[i][j] + dp[i + 1][j];
                path[i][j] = j; // Choose left child
            }
            else {
                dp[i][j] = triangle[i][j] + dp[i + 1][j + 1];
                path[i][j] = j + 1; // Choose right child
            }
        }
    }

    // Reconstruct the path
    vector<int> maxPath;
    int j = 0;
    for (int i = 0; i < rows; i++) {
        maxPath.push_back(triangle[i][j]);
        j = path[i][j];
    }

    return { dp[0][0], maxPath };
}

// Function to display the triangle
void displayTriangle(const vector<vector<int>>& triangle, int levels) {
    cout << "Triangle:" << endl;
    for (int i = 0; i < levels; i++) {
        // Add spaces before each row to center the triangle
        for (int s = 0; s < levels - i - 1; s++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << setw(4) << triangle[i][j];
        }
        cout << endl;
    }
}

int main() {
    int levels;
    cout << "Enter the number of levels in the triangle: ";
    cin >> levels;

    int totalNumbers = (levels * (levels + 1)) / 2;
    vector<vector<int>> triangle(levels);

    cout << "Enter " << totalNumbers << " numbers for the triangle:" << endl;
    for (int i = 0; i < levels; i++) {
        for (int j = 0; j <= i; j++) {
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }

    // Display the triangle
    displayTriangle(triangle, levels);

    // Find the maximum path sum and the path
    auto result = findMaxPathSum(triangle, levels);
    int maxSum = result.first;
    vector<int> maxPath = result.second;

    cout << "Maximum path sum from top to bottom: " << maxSum << endl;
    cout << "Path of numbers contributing to the maximum sum: ";
    for (int i = 0; i < maxPath.size(); i++) {
        cout << maxPath[i];
        if (i < maxPath.size() - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
}