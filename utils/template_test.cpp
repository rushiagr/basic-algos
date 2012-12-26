#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 


#define fo(a,b,c) for( int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define co(a,b,c) fi(a)cout<< b i c<<" "
#define NL cout<<endl;

// fills 2d vector m with n*n integers from input
#define fvvi(m,n) fi(n){int k;vi t;fj(n){cin>>k;t.pb(k);}m.pb(t);}

// prints elements of nxn vector m
#define fvvip(m,n) fi(n){fj(n)cout<<m[i][j]<<" ";cout<<endl;}

vvi dp;

int main() {
    int num;
    cin>>num;
    vvi inp;
    fvvi(inp,num);
    fvvip(inp, num);
    
    dp = 
    return 0;
}
