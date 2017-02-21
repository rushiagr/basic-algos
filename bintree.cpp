#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

// simple tree node
struct tnode {
  int val;
  struct tnode *left, *right;
};

struct tnode* newtnode(int value) {
  struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->val = value;
  return newnode;
}

// simple binary search tree
//              20
//             /  \
//            8   22
//           / \
//          4  12
//            /  \
//           10  14
struct tnode *simpleBST() {
  struct tnode *root = newtnode(20);
  root->left = newtnode(8);
  root->right = newtnode(22);
  root->left->left = newtnode(4);
  root->left->right = newtnode(12);
  root->left->right->left = newtnode(10);
  root->left->right->right = newtnode(14);
  return root;
}


// recursive inorder traversal of the tree
void inorder(struct tnode *t) {
  if(t->left)
    inorder(t->left);
  printf("%d ", t->val);
  if(t->right)
    inorder(t->right);
}

// iterative inorder traversal of the tree.
/*
SHORT SUMMARY
Temporary pointer curr will point to not only proper nodes (having data), but also NULLs.
If curr is not null, DO NOT print it, push it onto the stack (so that we can later access the right subtree),
and then go to the left child
If curr is null, and the stack is not empty,
take the top value of the stack, print it, and then make its right child curr, and then pop out the top value from stack
if stack becomes empty, done = 1!
*/
void inorderit(struct tnode *t){
  vector<tnode*> stack;
  struct tnode *curr = t;
  bool done = 0;

  while(!done) {
    if(curr) {
      stack.push_back(curr);
      curr = curr->left;
    } else {
      if(!stack.empty()) {
        cout<<stack.back()->val<<" ";
        curr = stack.back()->right;
        stack.pop_back();
      } else done = 1;
    }
  }
}


// iterative preorder traversal of the tree.
// Same as above, just print it very early (PRE!), instead of in the else part
void preorderit(struct tnode *t){
  vector<tnode*> stack;
  struct tnode *curr = t;
  bool done = 0;

  while(!done) {
    if(curr) {
      cout<<curr->val<<" ";
      stack.push_back(curr);
      curr = curr->left;
    } else {
      if(!stack.empty()) {
        //cout<<stack.back()->val<<" ";
        curr = stack.back()->right;
        stack.pop_back();
      } else done = 1;
    }
  }
}

// iterative postorder traversal of the tree.
// incorrect
void postorderit(struct tnode *t){
  vector<tnode*> stack;
  struct tnode *curr = t;
  bool done = 0;

  while(!done) {
    if(curr) {
      //cout<<curr->val<<" ";
      stack.push_back(curr);
      curr = curr->left;
    } else {
      if(!stack.empty()) {
        //cout<<stack.back()->val<<" ";
        curr = stack.back()->right;
        cout<<stack.back()->  val<<" ";
        stack.pop_back();
      } else done = 1;
    }
  }
}



//Iterative post order traversal code
// see http://leetcode.com/2010/10/binary-tree-post-order-traversal.html
/*
SHORT SUMMARY
Normal postorder logic. Note that curr is initialized to top of the stack each time, and prev becomes curr at the end of the while loop

ANOTHER WAY FOR POSTORDER(not implemented here): Do a mirrored pre-order (right is evaluated first,
then left), and then print all the elements in reverse! Done!! :)
*/
void postOrderTraversalIterative(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  s.push(root);
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;  // record previously traversed node
  }
}




int main() {

  struct tnode *tree = simpleBST();
  inorder(tree);
  cout<<endl;
  inorderit(tree);
  cout<<endl;
  preorderit(tree);
  cout<<endl;
  postorderit(tree);
  cout<<endl;

  return 0;
}
