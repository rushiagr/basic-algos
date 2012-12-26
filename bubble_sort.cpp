#include<iostream>
#include<algorithm>
using namespace std;

int* bubble_sort(int* arr, int len) {
    for(int i=len-2; i>=0; i--) {
        for(int j=0; j<=i; j++) {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    return arr;
}

int main() {
    int a[10] = {9,8,7,6,5,4,3,2,1,1};
    bubble_sort(a, 10);
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
        
    return 0;
}
