#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

TreeNode* insert(TreeNode *root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return root;
    }
    if (root->val > val) {
        root->left = insert(root->left, val);
    } else if (root->val < val) {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* highest_node_lower_than_helper(TreeNode *root, TreeNode *curr, int val) {
    if (!root)
        return curr;
    if (!curr) {
        if (root->val < val) {
            curr = root;
        }
    } else if (root->val < val && root->val > curr->val) {
        curr = root;
    }

    if (root->val > val) {
        TreeNode* temp = highest_node_lower_than_helper(root->left, curr, val);
        return temp;
    } else if (root->val < val) {
        TreeNode* temp = highest_node_lower_than_helper(root->right, curr, val);
        return temp;
    } else {
        return root;
    }
}

// for given value, find node with larges value lower than or equal to given
// value
TreeNode* highest_node_lower_than(TreeNode *root, int val) {
    if (root->val <= val)
        return highest_node_lower_than_helper(root, root, val);
    return highest_node_lower_than_helper(root, NULL, val);
}

void kth_smallest_in_bst_helper(TreeNode *root, int k, int &i) {
    if (!root)
        return;
    kth_smallest_in_bst_helper(root->left, k, i);
    i++;
    if (i==k)
        cout<<root->val<<endl;
    kth_smallest_in_bst_helper(root->right, k, i);
}

void kth_smallest_in_bst(TreeNode *root, int k) {
    int i = 0;
    kth_smallest_in_bst_helper(root, k, i);
}


// int min_dist_to_leaf(TreeNode *root, int val) {
//     if (!root)
//         return 0;
//     return min(min_dist_to_leaf(root->right), min_dist_to_leaf(root->left));
// }


int main() {
    // tree nodes in inorder: 20 30 40 50 60 70 80
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right = new TreeNode(70);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    TreeNode *curr = highest_node_lower_than(root, 91);
    if (!curr)
        cout<<"no such element found"<<endl;
    else
        cout<<curr->val<<endl;
    kth_smallest_in_bst(root, 3);
    kth_smallest_in_bst(root, 1);
    kth_smallest_in_bst(root, 2);
    kth_smallest_in_bst(root, 4);
}
