#include<iostream>
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description
//
struct tn {
    int val;
    tn* left, right;
    tn(int x): val(x), left(NULL), right(NULL) {}
};


int maxDepth(tn* root) {
    if (!root)
        return 0;
    else {
        int left_depth = 1 + maxDepth(root->left);
        int right_depth = 1 + maxDepth(root->right);
        return left_depth > right_depth ? left_depth : right_depth;
    }
}
