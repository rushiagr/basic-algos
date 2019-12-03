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

// simple binary search tree TWO
//              10
//             /  \
//            11   -20
//           / \   /\
//          15 12  0 9
//                /\
//               16 18
struct tnode *simpleBST3() {
  struct tnode *root = newtnode(10);
  root->left = newtnode(11);
  root->right = newtnode(-20);
  root->left->left = newtnode(15);
  root->left->right = newtnode(12);
  root->right->left = newtnode(0);
  root->right->right = newtnode(9);
  root->right->left->left = newtnode(16);
  root->right->left->right = newtnode(18);
  return root;
}

struct tnode *simpleBST2() {
  struct tnode *root = newtnode(10);
  root->left = newtnode(5);
  root->right = newtnode(19);
  root->left->left = newtnode(2);
  root->left->right = newtnode(11);
  root->left->left->right = newtnode(8);
  root->right->left = newtnode(-2);
  root->right->right = newtnode(6);
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

// correct and working solution
void postorderit2(struct tnode *t){
    vector<tnode*> stack;
    struct tnode *curr = t;
    while (curr || !stack.empty()) {
        if (curr) {
            stack.push_back(curr);
            curr = curr->left;
        } else {
            struct tnode *temp = stack.back()->right;
            if (temp) {
                curr = temp;
            } else {
                temp = stack.back();
                stack.pop_back();
                cout<<temp->val<<" ";
                while (!stack.empty() && temp == stack.back()->right) {
                    temp = stack.back();
                    stack.pop_back();
                    cout<<temp->val<<" ";
                }
            }
        }
    }
}

/* POST ORDER TRAVERSAL
Method 1: Use two stacks.
Algo
    Put root in stack1
    While stack1 is not empty:
        pop stack1 top element
        add it to stack2
        if it has left child, push it to stack1
        if it has right child, push it to stack1
    pop out elements from stack2 and print as you are popping




 */

//Iterative post order traversal code, copied from below now-defunct link
// see http://leetcode.com/2010/10/binary-tree-post-order-traversal.html
/*
SHORT SUMMARY
Normal postorder logic. Note that curr is initialized to top of the stack each time, and prev becomes curr at the end of the while loop

ANOTHER WAY FOR POSTORDER(not implemented here): Do a mirrored pre-order (right is evaluated first,
then left), and then print all the elements in reverse! Done!! :)
*/

void postOrderTraversalIterative(struct tnode *root) {
  if (!root)
      return;
  vector<tnode*> s;
  s.push_back(root);
  tnode *prev = NULL;
  while (!s.empty()) {
    struct tnode *curr = s.back();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push_back(curr->left);
      } else if (curr->right) {
        s.push_back(curr->right);
      } else {
        cout << curr->val << " ";
        s.pop_back();
      }
    }
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push_back(curr->right);
      } else {
        cout << curr->val << " ";
        s.pop_back();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->val << " ";
      s.pop_back();
    }
    prev = curr;  // record previously traversed node
  }
}




int main() {

  struct tnode *tree = simpleBST();
  struct tnode *tree2 = simpleBST2();
  struct tnode *tree3 = simpleBST3();
  inorder(tree);
  cout<<endl;
  inorderit(tree);
  cout<<endl;
  preorderit(tree);
  cout<<endl;
  preorderit(tree3);
  cout<<endl;
  postorderit2(tree);
  cout<<endl;
  postOrderTraversalIterative(tree);
  cout<<endl;

  return 0;
}
