// submission : https://leetcode.com/problems/top-k-frequent-elements/submissions/859127054/


#include <bits/stdc++.h>
using namespace std;

// time : O(NlogN)
// O(N + Mlogk) M은 서로 다른 숫자의 수. M <= N
// 1 <= k <= M -> 1 <= k <= N
// O(N + NlogN) -> O(NlogN)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        for(int n: nums){ // O(N)
            mp[n]++;
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        };

        vector<pair<int, int>> v;
        for(auto e: mp){ // O(MlogK)
            if(v.size() <= k){
                v.push_back({e.first, e.second});
                push_heap(v.begin(), v.end(), cmp);
            }

            if(v.size() == k+1){
                pop_heap(v.begin(), v.end(), cmp);
                v.pop_back();
            }
        }
        vector<int> ret;
        for(auto& e: v){
            ret.push_back(e.first);
        }

        return ret;
    }
};