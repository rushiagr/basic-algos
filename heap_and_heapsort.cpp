#include<iostream>
#include<algorithm>
#include<vector>
#include "utils/cpputils.h"
using namespace std;

int leftChild(int *a, int n, int id) {
    int child_id = 2*id+1;
    if(child_id < n)
        return child_id;
    else return -1;
}

int rightChild(int *a, int n, int id) {
    int child_id = 2*id+2;
    if(child_id < n)
        return child_id;
    else return -1;
}

int parent(int *a, int n, int id) {
    return (id-1)/2;
}

void max_heapify(int *a, int n, int id) {
        int left_id = leftChild(a,n,id);
        int right_id = rightChild(a,n,id);
    if(left_id==-1) {
        return;
    } else if(right_id>=0) {
        if(a[id] < max(a[left_id], a[right_id])) {
            int id_to_change = a[left_id]>a[right_id]?left_id:right_id;
            swap(a[id], a[id_to_change]);
            max_heapify(a,n,id_to_change);
        }
    } else {
        if(a[id] < a[left_id]) {
            swap(a[id], a[left_id]);
            max_heapify(a,n,left_id);
        }
    }

}

void build_max_heap(int *a, int n) {
    // Last element in the array which has atleast one children. Need to call
    // max_heapify() procedure from this element in reverse
    int last_id = (n-2)/2;
    for(int i=last_id; i>=0; i--) {
        max_heapify(a, n, i);
    }
}

void heap_sort(int *a, int n) {
    build_max_heap(a, n);
    for(int i=n-1; i>0; i--) {
        swap(a[0], a[i]);
        max_heapify(a, i, 0);
    }
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    build_max_heap(a,10);
    print_arr(a, 10);

    int b[10] = {10,9,8,7,6,5,4,3,2,1};
    heap_sort(b, 10);
    print_arr(b, 10);

    return 0;
}
