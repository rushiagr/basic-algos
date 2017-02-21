#include<iostream>
using namespace std;


/*
 * Given a set of coins (each coin can be used multiple times), and a change
 * amount, return the minimum number of coins required to make the change.
 * Return -1 if not possible to make change.  To make the problem non-dp, just
 * remove the lines which are concerned with the array 'dp'
 */
int mincoins(int *arr, int n, int sum) {

    static int dp[10000] = {0};
    
    if(dp[sum]!=0)
        return dp[sum];    
    if(sum==0)
        return 0;
    if(sum<0)
        return -1;
    
    int when_1_consumed = sum+1;

    for(int i=0; i<n; i++) {
        int result = mincoins(arr, n, sum-arr[i]);
        // the below if loop can be removed as it is taken care in the second if loop
        if(result==0) {
            dp[sum] = 1;
            return 1;
        }
        if(result!=-1 && result<when_1_consumed) {
            when_1_consumed = result;
        }
    }
    
    if (when_1_consumed==sum+1) {
        dp[sum] = -1;
        return -1;
    }
    dp[sum] = when_1_consumed+1;
    return when_1_consumed + 1;
}

int main() {
    int a[] = {2,4};
//    int b[] = {2,5,5};
    cout<<mincoins(a, 2, 3001)<<endl;
    cout<<mincoins(a, 2, 3000)<<endl;
//    cout<<mincoins(b, 3, 11);
    
    return 0;
}
