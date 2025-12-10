//#include <vector>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//int computeMaxS(const vector<int>& B) {
//    vector<vector<int>> result;
//    result.push_back({});
//    int maxS = 0;
//
//    for (int b : B) {
//        int size = result.size();
//        for (int i = 0; i < size; i++) {
//            vector<int> current = result.back();
//            result.pop_back();
//            vector<int> newArray = current;
//            newArray.push_back(b);
//
//            // Compute S for newArray
//            int s = 0;
//            for (size_t k = 1; k < newArray.size(); k++) {
//                int diff = (newArray[k] - newArray[k - 1]);
//                if (diff > 0) {
//                    s += diff;
//                }else s -= diff;
//            }
//            maxS = (maxS > s)? maxS: s;
//
//            result.push_back(newArray);
//        }
//    }
//    return maxS;
//}
//
//// Example usage
//int main() {
//    std::vector<int> B = { 1, 1, 1 };
//    cout << "B = { 1, 1, 1 }  MaxSum = ";
//    int result = computeMaxS(B);
//    cout << result <<"\n";
//    B = { 1, 1, 2 };
//    cout << "B = { 1, 1, 2 }  MaxSum = ";
//    result = computeMaxS(B);
//    cout << result <<"\n";
//    B = { 1, 1, 3 };
//    cout << "B = { 1, 1, 3 }  MaxSum = ";
//    result = computeMaxS(B);
//    cout << result << "\n";
//    B = { 1, 2, 1 };
//    cout << "B = { 1, 2, 1 }  MaxSum = ";
//    result = computeMaxS(B);
//    cout << result << "\n";
//    B = { 1, 2, 2 };
//    cout << "B = { 1, 2, 2 }  MaxSum = ";
//    result = computeMaxS(B);
//    cout << result << "\n";
//    B = { 1, 2, 3 };
//    cout << "B = { 1, 2, 3 }  MaxSum = ";
//    result = computeMaxS(B);
//    cout << result << "\n";
//    return 0;
//}


//O(2^n)