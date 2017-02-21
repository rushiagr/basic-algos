#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "utils/cpputils.h"

void quick_sort(int *a, int start, int end) {
    if((end-start) <= 1) {
        return;
    }

    //Remove following 5 lines for normal (and not randomized) quicksort
    srand(time(NULL));
    int m, r;        // mid and right indexes
    m=r=start;
    int random_id = (rand()%(end-start))+start;
    swap(a[random_id], a[end-1]);

    int pivot = a[end-1];
    while(r < end-1) {
        if(a[r]<pivot) {
            if(r!=start)
                swap(a[m], a[r]);
            m++;
        }
        r++;
    }

    swap(a[m], a[end-1]);

    quick_sort(a, start, m);
    quick_sort(a, m+1, end);
}

int main() {
    int a[11] = {10,9,8,7,6,5,4,3,2,1,0};
    int b[15] = {0,1,2,3,4,5,6,6,7,8,-1,-1,-2,9,6};
    quick_sort(a, 0, 11);
    quick_sort(b, 0, 15);
    print_arr(a, 11);
    print_arr(b, 15);

    return 0;
}
