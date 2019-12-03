#include<iostream>
using namespace std;

class DLL {
    public:
    int val;
    DLL *next, *prev;
    DLL(int x): val(x), next(NULL), prev(NULL) {};
};

DLL* dll_insert(DLL *dll_head, DLL* node) {
    if (!dll_head)
        return node;
    node->next = dll_head;
    dll_head->prev = node;
    node->prev = NULL;
    return node;
}

DLL* dll_delete(DLL *dll_head, DLL* node) {
    if (!node)
        return dll_head;
    if (node == dll_head) {
        DLL *ret = node->next;
        delete node;
        return ret;
    }
    if (node->next)
        node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    return dll_head;
}

void dll_print(DLL *dll_head) {
    DLL* curr = dll_head;
    while (curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main() {
    DLL* dll = NULL;
    DLL* one = new DLL(10);
    DLL* two = new DLL(20);
    DLL* three = new DLL(30);
    DLL* four = new DLL(40);
    dll = dll_insert(dll, four);
    dll_print(dll);
    dll = dll_insert(dll, three);
    dll_print(dll);
    dll = dll_insert(dll, two);
    dll_print(dll);
    dll = dll_insert(dll, one);
    dll_print(dll);
    dll = dll_delete(dll, three); // inner element
    dll_print(dll);
    dll = dll_delete(dll, four); // last element
    dll_print(dll);
    dll = dll_delete(dll, one); // first element
    dll_print(dll);
    dll = dll_delete(dll, two); // only element
    dll_print(dll);
}
