// submission : https://leetcode.com/problems/climbing-stairs/submissions/863595789/

#include <bits/stdc++.h>
using namespace std;

// time: O(N), space:O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }

        int prev_1 = 1;
        int prev_2 = 2;
        int ret = 0;

        for(int i=3; i<=n; i++){
            ret = prev_1 + prev_2;
            prev_1 = prev_2;
            prev_2 = ret;
        }     

        return ret;
    }
};
