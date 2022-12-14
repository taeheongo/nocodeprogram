/*
Approcah one by one

 submission : https://leetcode.com/problems/merge-k-sorted-lists/submissions/859572316/
 time: O(k*N)
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
        vector<ListNode *> lh{lists};

        int idx = 0;
        ListNode* min_node = nullptr;
        ListNode head{0};
        ListNode* cur = &head;
        while(true){
            min_node = nullptr;
            for(int i=0; i<lh.size(); i++){
                if(lh[i] == nullptr) continue;
                if(min_node == nullptr) {
                    min_node = lh[i];
                    idx = i;
                }
                else {
                    if(lh[i]->val < min_node->val){
                        min_node = lh[i];
                        idx = i;
                    }
                }
            }

            if(!min_node) break;

            lh[idx] = lh[idx]->next;

            min_node->next = nullptr;
            cur->next = min_node;
            cur = cur->next;
        }

        return head.next;
    }
};