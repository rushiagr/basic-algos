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
            return true;
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
    
    int peek() {
        if (isempty())
            return -1;
        return stack[top-1];
        
    }
};

class MinStack {
    Stack mainstack(2), minstack(22);

public:
    MinStack(int siz) {
//        mainstack= Stack(3);
//        Stack minstack = Stack(3);
    }
    
/*    bool push(int val) {
        if (!this->mainstack.push(val))
            return false;
        if(this->minstack.isempty())
            this->minstack.push(val);
        else if(this->minstack.peek()>=val)
            this->minstack.push(val);
    }
    
    int pop() {
        if(minstack.peek()==mainstack.peek())
            minstack.pop();
        return mainstack.pop();
    }
    
    int min() {
        if (minstack.isempty())
            return -1;
        else
            return minstack.peek();
    }
    
    bool isempty() {
        return mainstack.isempty();
    }*/
};

int main() {
/*    MinStack ms = MinStack(4);
    ms.push(5);
    ms.push(4);
    ms.push(6);
    ms.push(4);
    ms.push(8);
    for(int i=0; i<5; i++)
        cout<<ms.pop()<<" "<<ms.min()<<" "<<ms.isempty()<<endl;
*/    
    return 0;
}
