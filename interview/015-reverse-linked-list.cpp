#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x): val(x), next(NULL) {}
};

Node* ll_from_array(int arr[], int length) {
    Node dummy = Node(0);
    Node *l = &dummy;
    for (int i=0; i<length; i++) {
        Node *temp = new Node(arr[i]);
        l->next = temp;
        l = l->next;
    }
    return dummy.next;
}

// recursive
Node* reverse(Node *head) {
    if (!head || !head->next)
        return head;
    Node* reversed = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversed;
}

// iterative
Node* reverse2(Node *head) {
    if (!head || !head->next)
        return head;
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Node* ll1 = ll_from_array(arr, 5);
    Node* ll2 = reverse(ll1);
    Node* curr = ll2;
    while(curr) {
        cout<<curr->val;
        curr = curr->next;
    }
}
