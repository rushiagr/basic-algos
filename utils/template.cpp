#include<iostream>
#include<algorithm>
using namespace std;

// Useful macros


/** 
All of a container.
example: you can write:
    sort(all(X));
instead of 
    sort(X.begin(), X.end());
*/
#define all(c) c.begin(), c.end() 


/* traverse a container
Note: additional brackets required

example:
int r = 0; 
      tr(v, it) { 
           r += (*it)*(*it); 
      } 
      
       */

//#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 


// important shortcuts copied from topcoder tutorials
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

