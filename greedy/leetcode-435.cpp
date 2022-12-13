// https://leetcode.com/problems/non-overlapping-intervals/submissions/858957807/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){            
            return a[1] < b[1];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);

        int ret = 0; int pre = -1e9;
        for(auto& v:intervals){
            if(v[0] < pre) {
                ret++;
            }else{
                pre = v[1];
            }
        }

        return ret;
    }
};