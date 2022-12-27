// submission : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/863602700/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev_1 = cost[0];
        int prev_2 = cost[1];
        int ret = 0;

        for(int i=2; i<cost.size(); i++){
            ret = min(prev_1, prev_2) + cost[i];
            prev_1 = prev_2;
            prev_2 = ret;
        }
        ret = min(prev_1, prev_2);        

        return ret;
    }
};