#include <bits/stdc++.h>
using namespace std;

/*
max heap 풀이.
time: O(N + k*logN)
submission: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/859109080/
*/ 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());

        int ret = 0;
        for(int i=0; i<k-1; i++){
            pop_heap(nums.begin(), nums.end()-i);
        }
        ret = nums[0];

        return ret;
    }
};

/*
min heap을 이용한 풀이.
time: O(N * logk)
submission: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/859118272/
*/ 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min_h;

        int ret = 0;
        for(int n: nums){
            if(min_h.size() <= k){
                min_h.push_back(n);
                push_heap(min_h.begin(), min_h.end(), greater<int>{});
            }

            if(min_h.size() == k+1){
                pop_heap(min_h.begin(), min_h.end(), greater<int>{});
                min_h.pop_back();
            }
        }

        ret = min_h[0];

        return ret;
    }
};