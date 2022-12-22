// submission : https://leetcode.com/problems/minimum-path-sum/submissions/863615097/
// time:O(MN), space:O(MN)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int> (n, 0));

        return f(m-1, n-1, cost, grid);
    }

    int f(int y, int x, vector<vector<int>>& cost, vector<vector<int>>& grid){
        if(y == 0 && x == 0) return grid[0][0];

        if(y < 0 || y >=grid.size() || x < 0 || x >= grid[0].size()) return 1e9;

        if(cost[y][x]) return cost[y][x];

        return cost[y][x] = min(f(y-1, x, cost, grid), f(y, x-1, cost, grid)) + grid[y][x];
    }
};