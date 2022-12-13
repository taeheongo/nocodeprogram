// https://leetcode.com/problems/gas-station/submissions/859021800/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int sum = 0, ret = -1, start = 0;
        
        for(int start = 0; start < N; start++){
            sum = 0;
            for(int i=start; i<start + N; i++){
                sum += gas[i % N];
                sum -= cost[i % N];
                if(sum < 0){
                    start = i;
                    break;
                }
            }
            if(sum >= 0){
                ret = start;
                break;
            }
        }

        return ret;
    }
};