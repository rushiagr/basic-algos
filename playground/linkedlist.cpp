#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;         // seems like we can also append 'struct' before ListNode
    ListNode(int x) {       // constructor
        val = x;
        next = NULL;
    }
    // constructor with initializer list. Shorthand for above constructor
    // ListNode(int x): val(x), next(NULL) {}
};

// function to convert array to linkedlist
ListNode* ll_from_array(int arr[], int length) {
    ListNode dummy = ListNode(0);
    ListNode *l = &dummy;
    for (int i=0; i<length; i++) {
        ListNode *temp = new ListNode(arr[i]);
        l->next = temp;
        l = l->next;
    }
    return dummy.next;
}

int main() {
    ListNode* n1 = new ListNode(10);
    ListNode* n2 = new ListNode(20);
    n1->next = n2;
    ListNode* curr = n1;
    while(curr != NULL) {
        cout<<curr->val<<endl;
        curr = curr->next;
    }
}
