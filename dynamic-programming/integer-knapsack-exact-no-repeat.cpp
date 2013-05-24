#include<iostream>
using namespace std;

/*
 *Note this is not full knapsack. It only checks the optimal value if the capacity is 'exactly' the capacity variable. In practice,
 *you should run this algorithm for i = 1 to capacity
 */

int maxknapsack(int *value, int* size, int items, int capacity) {
    static int dp[10000][10000] = {0};
    
    if(dp[items][capacity]!=0)
        return dp[items][capacity];


    if(items==0 || capacity<=0)
        return -1;
    
    if(items==1) {
        if(capacity==size[0]) {
            dp[items][capacity] = value[0];
            return value[0];
        } else {
            dp[items][capacity] = -1;
            return -1;
        }
    }
    
/*
 *ATTENTION: You cannot do like this! what if the second call to maxknapsack returns -1, and value[items-1] is 2?
 *Answer: max_val will be max of (-1 and (-1+2)) = 1!!! but the answer should be -1
 *  int max_val = max(
        maxknapsack(value, size, items-1, capacity),
        (maxknapsack(value, size, items-1, capacity-size[items-1]) + value[items-1])
    );
*/

    int val1 =         maxknapsack(value, size, items-1, capacity);
    int val2 =         maxknapsack(value, size, items-1, capacity-size[items-1]);// + value[items-1];
    
    if(val1==val2==-1) {
        dp[items][capacity] = -1;
        return -1;
    }
    if(val2==-1) {
        dp[items][capacity] = val1;
        return val1;
    } else {
        dp[items][capacity] = val2+value[items-1];
        return val2+value[items-1];
    }
}

int main() {
    int val[] = {4, 2, 1, 10, 2};
    int siz[] = {12, 2, 1, 4, 1};
    cout<<maxknapsack(val, siz, 5, 11)<<endl;
    cout<<maxknapsack(val, siz, 5, 12)<<endl;
    cout<<maxknapsack(val, siz, 5, 15)<<endl;
    cout<<maxknapsack(val, siz, 5, 21)<<endl;
    
    return 0;
}