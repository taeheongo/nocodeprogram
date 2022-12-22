#include <bits/stdc++.h>
using namespace std;

/* 
time: O(2^n)

                               f(6)
                   f(5)                           f(4)
          f(4)               f(3)           f(3)         f(2)
     f(3)      f(2)      f(2)    f(1)    f(2)  f(1)    f(1) f(0)
  f(2) f(0) f(1) f(0)  f(1)  f(0)      f(1) f(0)
f(1) f(0)
*/
int fib(int n){
    if (n == 1 || n == 2) { return n-1; }

    return fib(n - 1) + fib(n - 2);
}

int main(){
    // 0 1 1 2 3 5
    cout << fib(6) << endl;

    return 0;
}

