#include<iostream>
#include<algorithm>
using namespace std;

int* bubble_sort(int* arr, int len) {
    for(int i=1; i<len; i++) {
        for(int j=i; j>=1; j--) {
            if(arr[j-1] > arr[j])
                swap(arr[j-1], arr[j]);
        }
    }
    return arr;
}

int main() {
    int a[10] = {9,8,7,6,5,4,3,2,1,1};
    bubble_sort(a, 10);
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
