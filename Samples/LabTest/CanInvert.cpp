//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void printInversions(const std::vector<int>& A) {
//    int n = A.size();
//    vector<int> pair1;
//    vector<int> pair2;
//
//    // Generate all pairs (i, j) where i < j
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            pair1.push_back(i);
//            pair1.push_back(j);
//        }
//    }
//
//    // Print table header
//    std::cout << "Index Pairs\tValues\tInversion\n";
//
//    // Process each pair and print
//    for (int x = 0;x < pair1.size();x++) {
//        int i = pair1[x];
//        int j = pair2[x];
//        cout << i << "," << j << "\t\t" << A[i] << "," << A[j] << "\t";
//        if (A[i] > A[j]) {
//            cout << "Yes\n";
//        }
//        else {
//            cout << "No\n";
//        }
//    }
//}
//
//int main() {
//    int n;
//    cout << "Enter size of array: ";
//    cin >> n;
//    vector<int> A(n);
//    for (int i = 0; i < n; i++) {
//        cout << "Enter Number:";
//        cin >> A[i];
//    }
//
//    printInversions(A);
//    return 0;
//}
//
////O(n^2)