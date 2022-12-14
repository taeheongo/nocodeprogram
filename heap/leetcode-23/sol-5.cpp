/*
Merge with Divide And Conquer

    submission: https://leetcode.com/problems/merge-k-sorted-lists/submissions/859512927/
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
        if(lists.size() == 0) return nullptr;

        return merge(0, lists.size()-1, lists);
    }

    ListNode* merge(int left_idx, int right_idx, vector<ListNode*>& lists){
        if(left_idx == right_idx){
            return lists[left_idx];
        }

        ListNode* L = lists[left_idx];
        ListNode* R = lists[right_idx];
        if(right_idx - left_idx > 1){
            int mid = (left_idx + right_idx) / 2;
            L = merge(left_idx, mid, lists);
            R = merge(mid + 1, right_idx, lists);
        }

        ListNode head{0};
        ListNode* cur = &head;

        while(L && R){
            if(L->val < R->val){
                cur->next = new ListNode{L->val};
                L = L->next;
            }else{
                cur->next = new ListNode{R->val};
                R = R->next;
            }
            cur = cur->next;
        }

        while(L){
            cur->next = new ListNode{L->val};
            cur = cur->next;
            L = L->next;
        }

        while(R){
            cur->next = new ListNode{R->val};
            cur = cur->next;
            R = R->next;
        }

        return head.next;
    }
};