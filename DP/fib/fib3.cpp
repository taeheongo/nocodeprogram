#include <bits/stdc++.h>
using namespace std;

int prev_1, prev_2, n, ret;

// time: O(N), space: O(1)
int main(){
    cin >> n;

    prev_1 = 0; prev_2 = 1; 
    for(int i=3; i <= n; i++){
        ret = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = ret;
    }

    // 0 1 1 2 3 5
    cout << ret << endl;

    return 0;
}