// https://leetcode.com/problems/intersection-of-two-arrays/#/description

#include<iostream>
using namespace std;

// Given two sorted arrays, print elements which are common to both arrays.
// Print a number only once.
// Modification of https://leetcode.com/problems/intersection-of-two-arrays/#/description

void print_intersection(int arr1[], int arr2[], int len1, int len2) {
    int last_printed = -1;
    int i=0, j=0;
    while (i<len1 && j<len2) {
        if (arr1[i] == arr2[j]) {
            if (last_printed != arr1[i]) {
                cout<<arr1[i]<<endl;
            }
            last_printed = arr1[i];
            i++; j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        }
    }
}

int main() {
    int a[] = {1, 2, 2, 2, 3, 3, 4};
    int b[] = {2, 2, 3};
    print_intersection(a, b, 7, 3);
}
