/*
submission : https://leetcode.com/problems/coin-change/submissions/866247813/
Brute Force (Time Limite Exceeded)


     {1,2,3} amount = 6

    1   2   3
    0 - 0 - 6 (o)
      - 2 (x)
      - 4 - (x)
      - 6 (o)
    1 - 1 - (x)
      - 3 - 6 (o)
      - 5 (x)
    2 
    3
    4 
    5
    6

    6/1 * 6/2 * 6/3

    S/c0 * S/c2 * S/c3

    Time: O(S^N)
    Space: O(N)

    + 그리디가 안되는 이유: greedy는 동전이 서로 배수/인수 관계를 가져야 함.
    greedy 반례
    8
    145
*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int _coinChange(vector<int>& coins, int amount, int coin_idx){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(coin_idx == coins.size()) return -1;

        int max_num = amount / coins[coin_idx];
        int tmp = 0, ret = 1e9;
        for(int n=0; n<=max_num; n++){
            tmp = _coinChange(coins, amount - coins[coin_idx] * n, coin_idx + 1);
            if(tmp >= 0){
                ret = min(ret, tmp + n);
            }
        }

        if(ret == 1e9){ return -1; }

        return ret;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        return _coinChange(coins, amount, 0);
    }
};

