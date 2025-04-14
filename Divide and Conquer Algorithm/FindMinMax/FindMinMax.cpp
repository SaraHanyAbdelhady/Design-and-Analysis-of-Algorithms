#include <iostream>
#include <vector>
using namespace std;

// Structure to hold max and min values
struct Pair {
    int max;
    int min;
};

// Divide-and-conquer function to find max and min
Pair findMaxMin(vector<int> arr, int low, int high) {
    Pair result, left, right;

    // Base case: single element
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Base case: two elements
    if (high == low + 1) {
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        return result;
    }

    // Find mid point
    int mid = low + (high - low) / 2;

    // Recursively find max and min in left and right halves
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

    // Combine results
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int n, num;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    // Find max and min
    Pair result = findMaxMin(arr, 0, n - 1);

    // Output results
    cout << "Maximum value: " << result.max << endl;
    cout << "Minimum value: " << result.min << endl;

    return 0;
}