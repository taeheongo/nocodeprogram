/*
Brute Force(Time exceeded)
    submission: https://leetcode.com/problems/find-median-from-data-stream/submissions/860449100/
    time: O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    vector<int> v;

public:    
    void addNum(int num) {
        v.push_back(num); 
        sort(v.begin(), v.end()); // O(NlogN)
    }
    
    double findMedian() {
        if(v.size() % 2 == 0){
            int idx = v.size() / 2;

            return (v[idx] + v[idx-1]) / 2.0;
        }

        return v[v.size() / 2.0];
    }
};