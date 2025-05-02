#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flipCoins(vector<char>& coins, int start, int& moves) {
    int n = coins.size();
    int firstTail = -1;

    // Find the first 'T' starting from 'start'
    for (int i = start; i < n; ++i) {
        if (coins[i] == 'T' || coins[i] == 't') {
            firstTail = i;
            break;
        }
    }

    // If no 'T' found, all are 'H', return
    if (firstTail == -1) {
        return;
    }

    int firstHeadAfterTail = -1;
    // Find the first 'H' after firstTail
    for (int i = firstTail + 1; i < n; ++i) {
        if (coins[i] == 'H' || coins[i] == 'h') {
            firstHeadAfterTail = i;
            break;
        }
    }

    // Determine the range to flip: from firstTail to (firstHeadAfterTail - 1) or end
    int endFlip;
    if (firstHeadAfterTail == -1) {
        endFlip = n - 1;
    }
    else {
        endFlip = firstHeadAfterTail - 1;
    }

    // Flip the coins in the range [firstTail, endFlip]
    for (int i = firstTail; i <= endFlip; i++) {
        coins[i] = (coins[i] == 'H') ? 'T' : 'H';
    }
    moves++;

    // Recursive call starting from firstHeadAfterTail if it exists, else return
    if (firstHeadAfterTail != -1) {
        flipCoins(coins, firstHeadAfterTail, moves);
    }
    else {
        return;
    }
}

int minMovesToHeads(vector<char>& coins) {
    int moves = 0;
    flipCoins(coins, 0, moves);
    return moves;
}
int main()
{
    int n;
    std::cout << "Hello, Enter the size of coins array: ";
    cin >> n;
    vector<char> coins;
    char coin;
    for (int i = 1;i < n+1;i++) {
        cout << "Please enter coin number "<<i<<" : ";
        cin >> coin;
        if (coin == 'H' || coin == 'h' || coin == 'T' || coin == 't') {
            coins.push_back(coin);
        }
        else {
            cout << "Enter Head or Tail (H/T) : \n";
            i--;
        }
    }
    cout<<"Minimum number of moves to flip all coins to head is "<<minMovesToHeads(coins);
}
