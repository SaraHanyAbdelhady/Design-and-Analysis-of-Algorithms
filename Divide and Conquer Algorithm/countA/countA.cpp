#include <iostream>
#include <string>
using namespace std;

// Divide-and-conquer function to count 'A's
int countA(char find, bool Case, const string& str, int low, int high) {
    // Base case: single character
    if (low == high) {
        if (Case) {
            if (str[low] == toupper(find)) return 1;
            if (str[low] == tolower(find)) return 1;
            return 0;
        }
        return (str[low] == find) ? 1 : 0;
    }

    // Base case: empty range
    if (low > high) {
        return 0;
    }

    // Find midpoint
    int mid = low + (high - low) / 2;

    // Recursively count 'A's in left and right halves
    int leftCount = countA(find, Case, str, low, mid);
    int rightCount = countA(find, Case, str, mid + 1, high);

    // Return total count
    return leftCount + rightCount;
}

int main() {
    char find;
    cout << "Choose a letter to search for: ";
    cin >> find;
    char how;
    bool Case = false;
    cout << "Do you want Upper-case and Lower-case or as you entered only ?? (if both enter b else enter any letter) ";
    cin >> how;
    if (how == 'b') {
        Case = true;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int n = str.length();

    // Count occurrences of 'A'
    int result = countA(find, Case, str, 0, n - 1);

    // Output result
    cout << "Number of '";
    if (Case) cout << char(toupper(find)) << "/" << char(tolower(find));
    else cout << char(find);
    cout << "'s in the string: " << result << endl;

    return 0;
}