/*
submisson: https://leetcode.com/problems/coin-change/submissions/866258204/
DP(bottom up)

time: O(S*N)
space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount+1, -1);
        v[0] = 0;

        int tmp = 0;
        for(int s=1; s<=amount; s++){
            tmp = 1e9;
            for(int c: coins){
                if(s-c >= 0 && v[s-c] >= 0)
                    tmp = min(tmp, v[s-c] + 1);
            }
            if(tmp == 1e9) v[s] = -1;
            else v[s] = tmp;
        }

        return v[amount];
    }
};