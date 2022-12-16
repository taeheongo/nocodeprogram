/*
Binary Search(Time exceeded)
    Submission: https://leetcode.com/problems/find-median-from-data-stream/submissions/860454471/
    time: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    vector<int> v;

public:
    void addNum(int num) {
        auto it = lower_bound(v.begin(), v.end(), num); // O(logN)     

        v.insert(it, num); // O(N)
    }
    
    double findMedian() {
        if(v.size() % 2 == 0){
            int idx = v.size() / 2;

            return (v[idx] + v[idx-1]) / 2.0;
        }

        return v[v.size() / 2.0];
    }
};