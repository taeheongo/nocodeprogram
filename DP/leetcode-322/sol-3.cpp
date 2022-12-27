/*
submission : https://leetcode.com/problems/coin-change/submissions/866199128/
DP(top-down)
    exponential time -> polynomial time

    f(S) = min(f(S-c0), f(S-c1), ... f(S-Cn-1)) + 1 

                        f(6)
            f(5)          f(4)        f(3)
        f(4)  (3) (f2)
    ...    
    f(2)
f(1)   f(0)

    Time: O(S*N)
    Space: O(S) 
*/

