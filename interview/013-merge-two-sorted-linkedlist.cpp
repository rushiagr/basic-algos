#include<iostream>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/#/description

struct ListNode {
    int val;
    ListNode next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* merge_two_ll(ListNode *l1, ListNode *l2) {
    ListNode dummy = ListNode(0);
    ListNode *tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
