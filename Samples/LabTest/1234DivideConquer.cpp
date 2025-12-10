//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int compareDigits(char digit1, char digit2) {
//    string order = "3124";
//    int index1 = 0, index2 = 0;
//    for (int i = 0; i < order.size(); i++) {
//        if (digit1 == order[i]) {
//            index1 = i;
//        }
//        if (digit2 == order[i]) {
//            index2 = i;
//        }
//    }
//    return index1 - index2;
//}
//
//void merge(vector<char>& digits, int start, int mid, int end) {
//    vector<char> merged;
//
//    int leftIndex = start;
//    int rightIndex = mid + 1;
//
//    while (leftIndex <= mid && rightIndex <= end) {
//        char leftDigit = digits[leftIndex];
//        char rightDigit = digits[rightIndex];
//        if (compareDigits(leftDigit, rightDigit) <= 0) {
//            merged.push_back(leftDigit);
//            leftIndex++;
//        }
//        else {
//            merged.push_back(rightDigit);
//            rightIndex++;
//        }
//    }
//    while (leftIndex <= mid) {
//        merged.push_back(digits[leftIndex]);
//        leftIndex++;
//    }
//    while (rightIndex <= end) {
//        merged.push_back(digits[rightIndex]);
//        rightIndex++;
//    }
//
//    // Copy merged elements back to digits in the range [start, end]
//    for (int i = 0; i < merged.size(); i++) {
//        digits[start + i] = merged[i];
//    }
//}
//
//void rearrange(vector<char>& digits, int start, int end) { // Pass digits by reference
//    if (start >= end) {
//        return;
//    }
//    int mid = start + (end - start) / 2;
//    rearrange(digits, start, mid);
//    rearrange(digits, mid + 1, end);
//    merge(digits, start, mid, end);
//}
//
//string rearrangeDigits(string digits) {
//    vector<char> digitList;
//
//    for (int i = 0; i < digits.size(); i++) {
//        digitList.push_back(digits[i]);
//    }
//
//    rearrange(digitList, 0, digitList.size() - 1);
//
//    string result;
//    for (char c : digitList) {
//        result.push_back(c);
//    }
//
//    return result;
//}
//
//int main() {
//    string lin;
//    cout << "Enter a string of digits (1, 2, 3, 4): ";
//    cin >> lin;
//    string rearrangedDigits = rearrangeDigits(lin);
//    cout << "Rearranged digits: " << rearrangedDigits;
//    return 0;
//}


//T(n) = 2T(n/2)+n   O(nlogn)