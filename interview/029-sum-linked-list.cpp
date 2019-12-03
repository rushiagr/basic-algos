#include<iostream>
using namespace std;

// NOTE: THIS IS INCOMPLETE

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* equalSum(ListNode* l1, ListNode* l2, int carry) {
    // assumption: both lists are of same length
    if (!l1 || !l2)
        return NULL;
    int sum = l1->val + l2->val + carry;
    carry = sum / 10;
    sum = sum % 10;
    ListNode* newNode = new ListNode(sum);
    newNode->next = sumLL(l1->next, l2->next);
    return newNode;
}
