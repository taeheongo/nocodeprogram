/* 
submission : https://leetcode.com/problems/decode-ways/submissions/866797058/
    time: O(N)
    space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp(string& s, vector<int>& v, int idx){
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(v[idx] != -1) return v[idx];

        v[idx] = dp(s, v, idx + 1);
        if(idx + 1 < s.size()){
            string tmp_s = s.substr(idx, 2);
            if(atoi(tmp_s.c_str()) <= 26){
                v[idx] += dp(s, v, idx + 2);
            }
        }

        if(v[idx] == -1) v[idx] = 0;

        return v[idx];
    }
public:
    int numDecodings(string s) {
        vector<int> v(s.size(), -1);

        return dp(s, v, 0);
    }
};