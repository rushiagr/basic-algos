#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

class Stack {

    int *stack;
    int top;
    int size;

public:
    Stack(int size) {
        stack = (int *)malloc(sizeof(int) * size);
        top = 0;
        this->size = size;
    }
    
    bool push(int val) {
        if (top==size)
            return false;
        else {
            stack[top] = val;
            top++;
        }
    }

    int pop() {
        if(isempty())
            return -1;
        else {
            top--;
            return stack[top];
        }
    }

    bool isempty() {
        return (top==0);
    }
};

int main() {
    Stack s = Stack(4);
    s.push(1);
    cout<<s.isempty()<<endl;
    s.push(2);
    s.push(5);
    s.push(44);
    for(int i=0; i<5; i++)
        cout<<s.pop()<<" "<<s.isempty()<<endl;
    
    return 0;
}
