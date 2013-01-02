#include<iostream>
#include<vector>
using namespace std;

// Print all elements of vector<int>
void print_vi(vector<int> vect) {
    for(int i=0; i<vect.size(); i++)
        cout<<vect[i]<<" ";
    cout<<endl;
}

// Print all elements of vector<vector<int> >
void print_vii(vector<vector<int> > vect) {
    for(int i=0; i<vect.size(); i++) {
        for(int j=0; j<vect[0].size(); j++) {
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
}


// Prints a 1 dimensional int array
void print_arr(int* a, int len) {
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

// Prints a 2 dimentional int array a[m][n]
void print_arr(int**a, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

#define fo(a,b,c) for( int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define co(a,b,c) fi(a)cout<< b i c<<" "
#define NL cout<<endl;

