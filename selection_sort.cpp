#include<iostream>
#include<algorithm>
using namespace std;

int* bubble_sort(int* arr, int len) {
    for(int i=0; i<len; i++) {
        int min = i;
        for(int j=i; j<len; j++) {
            min=arr[j]<arr[min]?j:min;
        }
        swap(arr[i], arr[min]);
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
