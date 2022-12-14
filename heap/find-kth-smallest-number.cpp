/*
    Find kth smallest number

    Heap algorithms in c++ : https://en.cppreference.com/w/cpp/algorithm/make_heap
*/ 

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v){
    for(auto &e: v){
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> v{7, 5, 3, 1, 9};
    int k = 4;

    // min_heap
    std::make_heap(v.begin(), v.end(), std::greater<int>{}); // O(N)

    int ret;
    for(int i=0; i<k-1; i++){
        std::pop_heap(v.begin(), v.end()-i, std::greater<int>{}); // O(logN)
    }
    ret = v[0];
    
    cout << ret << "\n";

    return 0;
}