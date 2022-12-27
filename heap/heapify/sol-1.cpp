/*
    heapify, heappop 구현.
*/

#include <bits/stdc++.h>
using namespace std;

void _heapify(vector<int>& v, int idx){
    int left_child_idx = idx * 2 + 1;
    int right_child_idx = idx * 2 + 2;

    int small_idx = idx;
    if(left_child_idx < v.size() && v[left_child_idx] < v[small_idx]){
        small_idx = left_child_idx;
    }
    if(right_child_idx < v.size() && v[right_child_idx] < v[small_idx]){
        small_idx = right_child_idx;
    }
    if(small_idx != idx){
        swap(v[idx], v[small_idx]);
        _heapify(v, small_idx);
    }
}

// time : O(N)
void heapify(vector<int>& v){
    int i = (v.size() - 2) / 2;

    for(; i >= 0; i--){
        _heapify(v, i);
    }
}

// O(logN)
int heap_pop(vector<int>& v){
    if(v.size() < 0){
        cout << "vector size less than 0\n";
        exit(1);
    }
    int ret = v[0];
    v[0] = v[v.size() - 1];
    int i = 0, left_child_idx = 0, right_child_idx = 0, small_idx = 0;
    while(i < v.size()){
        left_child_idx = i * 2 + 1;
        right_child_idx = i * 2 + 2;

        small_idx = i;
        if(left_child_idx < v.size() && v[left_child_idx] < v[small_idx]){
            small_idx = left_child_idx;
        }

        if(right_child_idx < v.size() && v[right_child_idx] < v[small_idx]){
            small_idx = right_child_idx;
        }

        if(small_idx == i){
            break;
        }
           
        swap(v[small_idx], v[i]);
        i = small_idx;
    }

    return ret;
}

void print_v(vector<int> v){
    for(auto &e: v){
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> v = {7, 5, 3, 1, 9};

    heapify(v);

    print_v(v);

    for(int i=0; i<v.size(); i++){
        cout << heap_pop(v) << "\n";
    }

    return 0;    
}