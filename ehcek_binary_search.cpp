#include<iostream>
using namespace std;

void f(int y[10], int x) {
    int i,j,k;
    i=0; j=9;
    do {
        k = (i+j)/2;
        if(y[k] < x)
            i=k;
        else j=k;
    } while ( (y[k] != x) && (i<j) );
    
    if(y[k] = x )
        cout<<" x in array"<<endl;
    else cout<<" X NOT IN ARRAY"<<endl;
}

int main() {
    int aa[10] = {1,2,3,4,5,6,7,8,9,10};
    int bb[10] = {1,3,5,7,9,11,13,15,17,19};
    int cc[10] = {2,2,2,2,2,2,2,2,2,2};
    int dd[10] = {2,4,6,8,10,12,14,16,18,20};
    
    f(aa, 9);    f(bb, 0);    f(cc, 3);    f(dd, 11);
    
    return 0;
}
