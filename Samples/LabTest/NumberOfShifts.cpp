//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int countShifts(vector<int>& arr) {
//    int totalShifts = 0;
//    int n = arr.size();
//
//    for (int i = 1; i < n; i++) {
//        int key = arr[i];
//        int j = i - 1;
//        int shifts = 0;
//
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j--;
//            shifts++;
//        }
//        arr[j + 1] = key;
//        totalShifts += shifts;
//    }
//    return totalShifts;
//}
//
//int main() {
//    vector<int> A;
//    char n;
//    int x;
//    cout << "Enter a array size else if you dont want to enter an array Enter any char: ";
//    cin >> n;
//    if (isdigit(n)) {
//        for (int i = 0; i < atoi(&n);i++) {
//            cout << "Enter Number : ";
//            cin >> x;
//            A.push_back(x);
//        }
//    }
//    else
//    {
//        A = { 4, 3, 2, 1 };
//        cout << " A = { 4, 3, 2, 1 };\n";
//    }
//    int shifts = countShifts(A);
//    // Output result (e.g., 4 inversions for the example)
//    cout << "Number of Shifts is " << shifts;
//    return 0;
//}