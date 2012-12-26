#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

void putAtDepth(stack<int>* s, int e, int depth) {

  if(depth == 1) {
    int holder = s->top();
    s->pop(); 
    s->push(e);
    s->push(holder);
  }
  
  else {
    int holder = s->top();
    s->pop();
    putAtDepth(s,e,depth-1);
    s->push(holder);
  }
  
}

void reverse(stack<int>*s) {
  for(int i=0;i<s->size()-1;i++){
    int holder = s->top();
    s->pop();
    putAtDepth(s,holder,s->size()-i);
  }
}

void printStack(stack<int>* s){
    stack<int> temp;
    while(!s->empty()) {
        cout<<s->top()<<" ";
        temp.push(s->top());
        s->pop();
    }
    while(!temp.empty()) {
        s->push(temp.top());
        temp.pop();
    }
    
    cout<<endl;
}

int main() {

  stack<int> s;
  int elems, val;
  cin>>elems;
  while(elems--) {
    cin>>val;
    s.push(val);
  }
  cout<<"==== before ==="<<endl;
  printStack(&s);
  reverse(&s);
  cout<<"==== after ==="<<endl;
  printStack(&s);
}
