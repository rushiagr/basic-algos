#include<iostream>
#include<queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// problem taken from leetcode
// given a complete binary tree, connect all nodes' 'next' pointer to the
// node's right sibling

void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *first = root;
    TreeLinkNode *cur = NULL;
    while(first->left) {
        cur = first;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        first = first->left;
    }
}

// for a generic tree, populate 'next' pointers to the 'right'most node at same
// level
void connect2(TreeLinkNode *root) {
    if (!root)
        return;
    queue<TreeLinkNode *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeLinkNode* first = q.front();
        q.pop();
        if (!first) {
            if (q.empty())
                return;
            q.push(NULL);
            continue;
        }
        first->next = q.front();
        if (first->left)
            q.push(first->left);
        if (first->right)
            q.push(first->right);
    }
    cout<<"done"<<endl;
}

// connect all inorder successor for each node in a tree, using static variable
void connect_inorder_successor(TreeLinkNode* root) {
    static TreeLinkNode *next = NULL;
    if (!root)
        return;
    connect_inorder_successor(root->right);
    root->next = next;
    next = root;
    connect_inorder_successor(root->left);
}

// same without using static variable, but using a helper method
void inorder_successor_helper(TreeLinkNode *root, TreeLinkNode *&next) {
    if (!root)
        return;
    inorder_successor_helper(root->right, next);
    root->next = next;
    next = root;
    inorder_successor_helper(root->left, next);
}

void connect_inorder_successor2(TreeLinkNode* root) {
    TreeLinkNode *next = NULL;
    inorder_successor_helper(root, next);
}


// print 'next' element of each node in the tree rooted at root
void print_treelinknode(TreeLinkNode *root) {
    if (root) {
        if (!root->next)
            cout<<"next of "<<root->val<<" is NULL"<<endl;
        else
            cout<<"next of "<<root->val<<" is "<<root->next->val<<endl;
    } else return;
    print_treelinknode(root->left);
    print_treelinknode(root->right);
}

int main() {
    // TreeLinkNode* root = new TreeLinkNode(10);
    // root->left = new TreeLinkNode(20);
    // root->right = new TreeLinkNode(30);
    // root->left->right = new TreeLinkNode(40);
    // root->right->left = new TreeLinkNode(50);
    // connect2(root);
    // print_treelinknode(root);

    TreeLinkNode* root = new TreeLinkNode(10);
    root->left = new TreeLinkNode(20);
    root->right = new TreeLinkNode(30);
    root->left->right = new TreeLinkNode(40);
    root->right->left = new TreeLinkNode(50);
    connect_inorder_successor2(root);
    print_treelinknode(root);
}

