// https://leetcode.com/problems/two-city-scheduling/submissions/858974037/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0;
        int n = costs.size() / 2;
        vector<pair<int, int>> difs;
        for(int i=0; i<costs.size(); i++){
            difs.push_back({i, costs[i][0] - costs[i][1]});
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        };
        sort(difs.begin(), difs.end(), cmp);
        
        int idx = 0;
        for(int i=0; i<2*n; i++){
            idx = difs[i].first;
            if(i<n){
                ret += costs[idx][0];
            }else{
                ret += costs[idx][1];
            }
        }

        return ret;
    }
};