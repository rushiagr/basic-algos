#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct HeapNode {
    int val;
    ListNode* node;
    HeapNode(int x, ListNode *node): val(x), node(node) {}
};

struct Comp { // 'greater', because we want a min heap
    bool operator()(const HeapNode &h1, const HeapNode &h2) {
        return h1.val > h2.val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<HeapNode> heap;
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int i=0; i<lists.size(); i++) {
        if (lists[i]) {
            heap.push_back(HeapNode(lists[i]->val, lists[i]));
        }
    }
    make_heap(heap.begin(), heap.end(), Comp());
    while(heap.size()) {
        pop_heap(heap.begin(), heap.end(), Comp());
        tail->next = heap.back().node;
        tail = tail->next;
        heap.pop_back();
        if (tail->next) {
            heap.push_back(HeapNode(tail->next->val, tail->next));
            push_heap(heap.begin(), heap.end(), Comp());
        }
    }
    return dummy.next;
}

ListNode* ll_from_array(int arr[], int length) {
    ListNode dummy = ListNode(0);
    ListNode *l = &dummy;
    for (int i=0; i<length; i++) {
        ListNode *temp = new ListNode(arr[i]);
        l->next = temp;
        l = l->next;
    }
    return dummy.next;
}

int main() {
    int a1[4] = {2, 4, 8, 12};
    int a2[3] = {1, 3, 5};
    int a3[0] = {};
    int a4[1] = {6};
    vector<ListNode* > vec;
    vec.push_back(ll_from_array(a1, 4));
    vec.push_back(ll_from_array(a2, 3));
    vec.push_back(ll_from_array(a3, 0));
    vec.push_back(ll_from_array(a4, 1));
    ListNode *curr = mergeKLists(vec);
    while(curr != NULL) {
        cout<<curr->val<<endl;
        curr = curr->next;
    }
}
