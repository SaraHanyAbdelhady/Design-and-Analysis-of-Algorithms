//#include <vector>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//long long mergeCount = 0; // Counter for number of merges
//
//void merge(std::vector<int>& A, int left, int mid, int right) {
//    std::vector<int> leftArray, rightArray;
//    mergeCount++; // Increment counter for each merge operation
//
//    // Copy data to temporary vectors
//    for (int i = left; i <= mid; i++) {
//        leftArray.push_back(A[i]);
//    }
//    for (int i = mid + 1; i <= right; i++) {
//        rightArray.push_back(A[i]);
//    }
//
//    int i = 0, j = 0, k = left;
//    while (i < leftArray.size() && j < rightArray.size()) {
//        if (leftArray[i] <= rightArray[j]) {
//            A[k++] = leftArray[i++];
//        }
//        else {
//            A[k++] = rightArray[j++];
//        }
//    }
//
//    // Copy remaining elements
//    while (i < leftArray.size()) {
//        A[k++] = leftArray[i++];
//    }
//    while (j < rightArray.size()) {
//        A[k++] = rightArray[j++];
//    }
//
//    leftArray.clear();
//    rightArray.clear();
//}
//
//void mergeSort(std::vector<int>& A, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        mergeSort(A, left, mid);
//        mergeSort(A, mid + 1, right);
//        merge(A, left, mid, right);
//    }
//}
//
//int main() {
//    // Example 1
//    std::vector<int> arr1 = { 4, 3, 2, 1 };
//    mergeCount = 0; // Reset counter
//    mergeSort(arr1, 0, arr1.size() - 1);
//    std::cout << "Number of merges for arr1: " << mergeCount << std::endl; // Output: 3
//
//    // Example 2
//    std::vector<int> arr2 = { 2, 1, 3, 1, 2 };
//    mergeCount = 0; // Reset counter
//    mergeSort(arr2, 0, arr2.size() - 1);
//    std::cout << "Number of merges for arr2: " << mergeCount << std::endl; // Output: 4
//
//    return 0;
//}