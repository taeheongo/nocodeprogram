// https://leetcode.com/problems/partition-labels/submissions/858988784/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i=s.size()-1; i >= 0; i--){
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = i;
            else continue;
        }

        int start = 0, end = -1; // 구간의 시작 인덱스와 끝 인덱스
        vector<int> ret;
        for(int i=0; i<s.size(); i++){
            end = max(mp[s[i]], end);

            if(end == i){
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ret;
    }
};