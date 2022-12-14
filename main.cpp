// 테스트용 파일

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
        
        for(int i= max[0]; i<=max[1]; i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        return max[2];
    }
};

int main() { 
    Solution s;
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v) << endl;    

    return 0;
}