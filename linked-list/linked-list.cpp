#include<iostream>
#include<vector>
using namespace std;

// All code using C++ and minimal C

class Node {
public:
    Node *next;
    int data;
};

// Function to create a linked list
// ATTENTION: if vector is [1,2,3], linked list will be 3->2->1

Node* linked_list_from_vector(vector<int> input) {
    Node *head = NULL;

    for(int i=0; i<input.size(); i++) {
        Node *node = new Node;
        node->data = input[i];
        node->next = head;
        head = node;
    }
    
    return head;
}


void print_linked_list(Node *head) {
    Node *current_node = head;
    while(current_node) {
        cout<<current_node->data<<" ";
        current_node = current_node->next;
    }
    cout<<endl;
}

// Reverse a linked list (iterative)
Node* reverse_linked_list(Node *head) {
    Node *current = head;
    Node *new_head = NULL;
    
    while(current) {
        Node *temp = current;
        current = current->next;
        temp->next = new_head;
        new_head = temp;
    }
    
    return new_head;
}

// pssp pssp very interesting and important
// Reverse a linked list (recursive)
// Understand from here http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/
Node* reverse_linked_list_recursive(Node *head) {
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
    Node *remaining_list = head->next;
    remaining_list = reverse_linked_list(remaining_list);
    head->next->next=head;
    head->next=NULL;
    
    return remaining_list;
}


int main() {
    vector<int> inp;
    inp.push_back(10);
    inp.push_back(9);
    inp.push_back(11);
    inp.push_back(8);
    
    Node *ll = linked_list_from_vector(inp);
    print_linked_list(ll);
    
    ll = reverse_linked_list(ll);
    
    print_linked_list(ll);

    ll = reverse_linked_list_recursive(ll);
    
    print_linked_list(ll);
}