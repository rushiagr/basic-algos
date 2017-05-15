#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// question: given an array of integers and a number, find out if there is a
// contiguous subarray in the given array which sums to given number.

// complexity: O(n)

// References:
// http://www.geeksforgeeks.org/find-subarray-with-given-sum/
// http://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

/* This solution assumes array contains only nonnegative integers
 * Complexity: O(n) */
vector<int> find_subarray_sum(int array[], int length, int num) {
    vector<int> answers;
    if (length<1)
        return answers;
    int start = 0, end = 0, sum = array[0];
    while (end < length) {
        if (sum == num) {
            answers.push_back(start);
            answers.push_back(end);
            return answers;
        } else if (sum > num) {
            start++;
            if (start < length) {
                sum = sum - array[start];
            }
        } else if (sum < num) {
            end++;
            if (end < length) {
                sum = sum + array[end];
            }
        }
        if (start > end) {
            end = start;
            if (end < length) {
                sum = sum + array[end];
            }
        }
    }
    return answers;
}

/* General, best solution.
 * Complexity: time: O(n), Space: O(n) */
vector<int> find_subarray_sum_general(int array[], int length, int num) {
    vector<int> answers;
    if (length < 1)
        return answers;
    unordered_map<int, int> hashmap;    // keys are sums, values are index
    int sum_till_here = 0;
    for (int i=0; i<length; i++) {
        sum_till_here = sum_till_here + array[i];
        if (sum_till_here == num) {
            answers.push_back(0);
            answers.push_back(i);
            return answers;
        }
        int sum_to_subtract = sum_till_here - num;
        auto t = hashmap.find(sum_to_subtract);
        if (t != hashmap.end()) {
            answers.push_back((t->second)+1);
            answers.push_back(i);
            return answers;
        }
        hashmap[sum_till_here] = i;
    }
    return answers;
}

int main() {
    // Solution 1
    int arr1[] = {10, 20, 30, 40};
    vector<int> ans1 = find_subarray_sum(arr1, 4, 10);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    ans1 = find_subarray_sum(arr1, 4, 100);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    ans1 = find_subarray_sum(arr1, 4, 5);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;

    cout<<"soln"<<endl;
    // Solution 2
    ans1 = find_subarray_sum_general(arr1, 4, 10);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    ans1 = find_subarray_sum_general(arr1, 4, 100);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    ans1 = find_subarray_sum_general(arr1, 4, 5);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    int arr2[] = {-15, 20, -30, 40};
    ans1 = find_subarray_sum_general(arr2, 4, -10);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
}
