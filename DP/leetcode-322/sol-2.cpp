/*
Brute Force (Time Limite Exceeded)

 위의 Solution과 시간 복잡도가 동일하나 구조가 다르다.
 구조를 다르게 한 이유는 subproblem으로 나눌 수 있기 때문.(아직 memoization하지 않은 상태)
 submissoin : https://leetcode.com/problems/coin-change/submissions/866193026/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp(vector<int>& coins, int amount){
        if(amount < 0){ return -1; }
        if(amount == 0) { return 0; }

        int ret = 1e9;
        int tmp = 0;
        for(int e: coins){
            tmp = dp(coins, amount - e);
            if(tmp >= 0)
                ret = min(ret, tmp + 1);
        }

        if(ret == 1e9) return -1;

        return ret;  
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }
};

