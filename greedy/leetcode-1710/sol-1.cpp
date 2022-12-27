// https://leetcode.com/problems/maximum-units-on-a-truck/submissions/858975958/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        };

        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int i=0, ret =0;
        while(truckSize > 0 && i < boxTypes.size()){
            ret += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= min(truckSize, boxTypes[i][0]);
            i++;
        }

        return ret;
    }
};