#include <bits/stdc++.h>
using namespace std;

int n;

// time: O(N), space: O(N)
int fib(int n, vector<int>& v){
    if(n == 1 || n == 2) return n-1;
    if(v[n-1]) return v[n-1];
    
    return v[n-1] = fib(n-1, v) + fib(n-2, v);
}

int main(){
    cin >> n;

    vector<int> v(n, 0);

    cout << fib(n, v) << endl;

    return 0;
}