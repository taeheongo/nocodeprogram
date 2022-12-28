/*
submission : https://leetcode.com/problems/coin-change/submissions/866199128/
DP(top-down)
    exponential time -> polynomial time

    f(S) = min(f(S-c0), f(S-c1), ... f(S-Cn-1)) + 1 

                        f(6)
            f(5)          f(4)        f(3)
        f(4)  (3) (f2)
    ...    
    f(2)
f(1)   f(0)

    Time: O(S*N)
    Space: O(S) 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp(vector<int>& coins, int amount, vector<int>& v){
        if(amount < 0){ return -1; }
        if(amount == 0) { return 0; }
        if(v[amount]) return v[amount];

        int ret = 1e9;
        int tmp = 0;
        for(int e: coins){
            tmp = dp(coins, amount - e, v);
            if(tmp >= 0)
                ret = min(ret, tmp + 1);
        }

        if(ret == 1e9) return v[amount] = -1;

        return v[amount] = ret;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount+1, 0);

        return dp(coins, amount, v);
    }
};

