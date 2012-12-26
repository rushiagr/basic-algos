#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void revStack(stack<int> *s) {
    stack<int> temp;
    int holder;

    for(int i=0; i<s->size()-1; i++) {
        holder = s->top();
        s->pop();
        int totransfer = s->size()-i;
        for(int j=0; j<totransfer; j++) {
            temp.push(s->top());
            s->pop();
        }
        s->push(holder);
        for(int j=0; j<totransfer; j++) {
            s->push(temp.top());
            temp.pop();
        }
    }
}

void printStack(stack<int> *s) {
    cout<<s->size()<<endl;
    while(!s->empty()) {
        cout<<s->top()<<" ";
        s->pop();
    }
    cout<<endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(44);
    
//    printStack(&s);
    revStack(&s);
    printStack(&s);
    
    return 0;
}
