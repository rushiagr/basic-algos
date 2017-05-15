#include<iostream>
using namespace std;

// Question: given an array and a number x, remove all instances of that number
// from the given array, and return the new length.

// Solution complexity: O(n)

// TODO: also think of passing int array[] vs int* array. I guess pbr pbv jhol.

int remove_instances(int array[], int length, int x) {
    if (array == NULL || length <= 0)
        return 0;
    int curr = 0, end = length;
    while (curr < end && curr < length) {
        if (array[curr] == x) {
            array[curr] = array[end-1];
            end--;
        }
        if (array[curr] != x)
            curr++;
    }
    return end;
}

int main() {
    int a[] = {1, 2, 3};
    cout<<remove_instances(a, 3, 99)<<endl;
    int b[] = {1, 2, 3};
    cout<<remove_instances(b, 3, 1)<<endl;
    int c[] = {1, 2, 3};
    cout<<remove_instances(c, 3, 2)<<endl;
    int d[] = {1, 1, 1};
    cout<<remove_instances(d, 3, 1)<<endl;
    int e[] = {};
    cout<<remove_instances(e, 0, 1)<<endl;
    cout<<remove_instances(NULL, 3, 1)<<endl;
}
