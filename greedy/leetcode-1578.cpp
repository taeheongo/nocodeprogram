// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/submissions/858486166/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0;
        pair<char, int> pre = {'0', 100000};
        
        for(int i=0; i<colors.size(); i++){
            if(pre.first == colors[i]){
                ret += min(pre.second, neededTime[i]);
                pre = {colors[i], max(pre.second, neededTime[i])};
            }else{
                pre = {colors[i], neededTime[i]};
            }
        }

        return ret; 
    }
};