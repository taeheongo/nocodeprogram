// submission : https://leetcode.com/problems/minimum-path-sum/submissions/863618414/
// time: O(MN), space: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int> (n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) continue;
                else if(i == 0) {grid[i][j] += grid[i][j-1]; }
                else if(j == 0) { grid[i][j] += grid[i-1][j]; }
                else{
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
            }
        }

        return grid[m-1][n-1];
    }
};