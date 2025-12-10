//#include <vector>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//struct Result {
//    std::vector<int> sequence;
//    int score;
//};
//
//// Compute the score S(a) for a sequence
//int computeScore(const std::vector<int>& a) {
//    int score = 0;
//    for (size_t i = 1; i < a.size(); i++) {
//        int diff = a[i] - a[i - 1];
//        if(diff>0) score += diff;
//        else score -= diff;
//    }
//    return score;
//}
//
//Result minimizeScore(std::vector<int>& initial, int n, int x) {
//    vector<int> current = initial;
//    vector<bool> used(x + 1, false);
//    int remaining = x;
//
//    while (remaining > 0) {
//        int minScore = INT_MAX;
//        vector<int> bestSequence;
//        int bestPos = -1;
//        int bestVal = -1;
//
//        // Try inserting at each position
//        for (int pos = 0; pos <= current.size(); pos++) {
//            // Try each number from 1 to x that hasn't been used
//            for (int val = 1; val <= x; val++) {
//                if (!used[val]) {
//                    vector<int> temp = current;
//                    // Insert val at position pos
//                    vector<int> newSeq;
//                    for (int i = 0; i < pos; i++) {
//                        newSeq.push_back(temp[i]);
//                    }
//                    newSeq.push_back(val);
//                    for (int i = pos; i < temp.size(); i++) {
//                        newSeq.push_back(temp[i]);
//                    }
//                    int score = computeScore(newSeq);
//                    if (score < minScore) {
//                        minScore = score;
//                        bestSequence = newSeq;
//                        bestPos = pos;
//                        bestVal = val;
//                    }
//                }
//            }
//        }
//
//        // Update current sequence with the best insertion
//        current = bestSequence;
//        used[bestVal] = true;
//        remaining--;
//    }
//
//    return { current, computeScore(current) };
//}
//
//int main() {
//    int x, n;
//    cout << "Enter the x to insert numbers from 1 to x in the array n: ";
//    cin >> x;
//    cout << "Enter the size of array n: ";
//    cin >> n;
//    vector<int> initial(n);
//    for (int i = 0; i < n; i++) {
//        cout << "Enter Element Number "<<i<<" of array n: ";
//        cin >> initial[i];
//    }
//
//    Result res = minimizeScore(initial, n, x);
//    cout << res.score << '\n';
//    for (int num : res.sequence) {
//        cout << num << ' ';
//    }
//    cout << '\n';
//    return 0;
//}
////O(x^2n)