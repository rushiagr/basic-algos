#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/* Binary tree node */
class BTNode {
public:
    int value;
    BTNode *left, *right;
    
    BTNode(int val) {
        value = val;
    }
};

/*TOIMPLEMENT

Will take a string which contains node values appropriately parenthesized.
For example 10(4(3,5),6(11(13,),21(,22))) ## ORDER IMPORTANT!!
4 and 6 are children of 10,
3 and 5 are children of 4,
11 and 21 are children of 6,
13 is left child of 11,
22 is right child of 22.
TODO: Make comma after 13 optional.
TODO: return error when string in improper format
TODO: return error when string is in proper format, but such a tree is not possible*/
BTNode *tree_from_string(string str);

void level_order_traversal(BTNode *root){
    if(!root)
        return;
    queue<BTNode *> q;
    BTNode *curr = root;
    q.push(root);
    while(!q.empty()) {
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        cout<<q.front()->value<<endl;
        q.pop();
    }
}

int main() {
    
    BTNode *tree = new BTNode(1);
    tree->left = new BTNode(2);
    tree->right = new BTNode(3);
    tree->left->right = new BTNode(5);
    tree->left->left = new BTNode(4);
    tree->right->left = new BTNode(6);
    
    level_order_traversal(tree);
    
    return 0;
}