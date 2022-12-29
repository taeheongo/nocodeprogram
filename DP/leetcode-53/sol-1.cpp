// submission: https://leetcode.com/problems/maximum-subarray/submissions/867346544/
// time: O(N)
// space: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max[3] = {0, 0, nums[0]};
        int l = 1, r = 1, sum = nums[0];

        for(; r<nums.size(); r++){
            if(sum < 0){
                l = r;
                sum = nums[r];
            }else{
                sum += nums[r];
            }
            
            if(max[2] < sum){
                max[0] = l;
                max[1] = r;
                max[2] = sum;
            }
        }
        
        return max[2];
    }
};