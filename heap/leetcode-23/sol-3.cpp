/*
Optimize Approach 2 by Priority Queue

    submission: https://leetcode.com/problems/merge-k-sorted-lists/submissions/859569886/
    time: O(Nlogk)
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
        vector<ListNode*> lv;
        for(auto& l: lists){
            if(l){ lv.push_back(l); }
        }

        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        make_heap(lv.begin(), lv.end(), cmp);

        ListNode head{0};
        ListNode* cur = &head;
        ListNode* tmp = nullptr;
        while(lv.size()){
            pop_heap(lv.begin(), lv.end(), cmp);
            tmp = lv[lv.size() - 1];
            lv.pop_back();
            cur->next = tmp;
            cur = cur->next;

            if(tmp->next){
                lv.push_back(tmp->next);
                push_heap(lv.begin(), lv.end(), cmp);
            }
        }

        return head.next;
    }
};