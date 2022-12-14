/* 
Brute force
 
 submission : https://leetcode.com/problems/merge-k-sorted-lists/submissions/859454136/
 time: O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head{0};
        ListNode* cur = &head;

        vector<int> v;
        for(auto& l: lists){
            while(l){
                v.push_back(l->val);
                l = l->next;
            }
        }

        sort(v.begin(), v.end());

        for(auto e: v){
            cur->next = new ListNode{e};
            cur = cur->next;
        }

        return head.next;
    }
};