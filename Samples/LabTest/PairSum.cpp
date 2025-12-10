//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int count(vector<int> arr, int n) {
//    int count = 0;
//    for (int i = 0; i < arr.size(); i++) {
//        if (n == arr[i]) {
//            count++;
//        }
//    }
//    return count;
//}
//
//vector<int> index(vector<int> arr, int n) {
//    vector<int> b;
//    for (int i = 0; i < arr.size(); i++) {
//        if (n == arr[i]) {
//            b.push_back(i);
//        }
//    }
//    return b;
//}
//
//void print(vector<int> a1, vector<int> a2, vector<int> a3) {
//    cout << "Sum\tCount\tPairs\n";
//    int min_sum = a1[0];
//    int max_sum = a1[0];
//    for (int i = 1; i < a1.size(); i++) {
//        if (a1[i] < min_sum) min_sum = a1[i];
//        if (a1[i] > max_sum) max_sum = a1[i];
//    }
//    for (int m = min_sum; m <= max_sum; m++) {
//        vector<int> a = index(a1, m);
//        int c = count(a1, m);
//        if (a.size() == 0) {
//            cout << m << "\t0\tno result\n";
//        }
//        else {
//            cout << m << "\t" << c << "\t";
//            for (int j = 0; j < c; j++) {
//                cout << "(" << a2[a[j]] << "," << a3[a[j]] << ")";
//                if (j < c - 1) {
//                    cout << ",";
//                }
//            }
//            cout << "\n";
//        }
//    }
//}
//
//void PairSums(vector<int> arr) {
//    int n = arr.size();
//    vector<int> a1;
//    vector<int> a2;
//    vector<int> a3;
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            a1.push_back(arr[i] + arr[j]);
//            a2.push_back(arr[i]);
//            a3.push_back(arr[j]);
//        }
//    }
//    print(a1, a2, a3);
//}
//
//int main() {
//    vector<int> arr;
//    int x;
//    char n;
//	cout<<"Enter a array size else if you dont want to enter an array Enter any char: ";	
//	cin>>n;
//    if (isdigit(n)) {
//        for (int i = 0; i < atoi(&n);i++) {
//            cout << "Enter: ";
//            cin >> x;
//            arr.push_back(x);
//        }
//    } 
//    else
//    {
//        arr = { 3, 4, 5, 7, 9, 10, 10 };
//        cout << "arr = { 3, 4, 5, 7, 9, 10, 10 }\n";
//    }
//    PairSums(arr);
//    return 0;
//}



/*O(N^4)*/