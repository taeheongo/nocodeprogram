/*
2 heap (max_heap, min_heap)
    submission: https://leetcode.com/problems/find-median-from-data-stream/submissions/860475599/
    time: O(logN)    
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    vector<int> max_h;
    vector<int> min_h;

public:    
    void addNum(int num) {
        if(max_h.empty() && min_h.empty()){
            max_h.push_back(num);
            return;
        }

        auto min_h_cmp = [](int a, int b){
            return a > b;
        };

        if(max_h[0] < num){
            min_h.push_back(num);
            push_heap(min_h.begin(), min_h.end(), min_h_cmp);
        }else{
            max_h.push_back(num);
            push_heap(max_h.begin(), max_h.end());
        }

        int tmp = 0;
        if(max_h.size() - min_h.size() == 2){
            pop_heap(max_h.begin(), max_h.end());
            tmp = max_h[max_h.size() - 1];
            max_h.pop_back();
            min_h.push_back(tmp);
            push_heap(min_h.begin(), min_h.end(), min_h_cmp);
        }else if(min_h.size() - max_h.size() == 2){
            pop_heap(min_h.begin(), min_h.end(), min_h_cmp);
            tmp = min_h[min_h.size() - 1];
            min_h.pop_back();
            max_h.push_back(tmp);
            push_heap(max_h.begin(), max_h.end());
        }
    }
    
    double findMedian() {
        if(max_h.size() == min_h.size()){
            return (max_h[0] + min_h[0]) / 2.0;
        }

        return max_h.size() < min_h.size() ? min_h[0] : max_h[0];
    }
};