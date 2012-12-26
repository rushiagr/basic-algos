#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// Returns -1 if element not found, else return the index
int binary_search(vector<int> &arr, int val) {
    int i, j, mid;
    i = 0;
    j = int(arr.size()-1);
    while(i!=j) {
        mid = (i+j)/2;
        if(arr[mid] < val) {
            i = mid + 1;
        }
        else {
            if(arr[j]==val)
                return j;
            j = mid;
        }
    }
    if (arr[i] == val)
        return i;
    else return -1;
}

int main() {
    int a[10] = {1,2,3,5,5,7,7,8,9,9};
    vector<int>b (a, a+10);
    cout<<binary_search(b, 5)<<endl;
    cout<<binary_search(b, 10)<<endl;
    cout<<binary_search(b, 0)<<endl;
    cout<<binary_search(b, 3)<<endl;
    cout<<binary_search(b, 4)<<endl;
    return 0;
}
