/* Question: Given an array of integers and a number, you have to find out if
 * the array contains a pair of numbers whose sum is equal to the given number.
 * The array can have repeat numbers. */

// questions:
// What if no such pair exists? return some 'null'
// What if the given number exists in array, and no pair of numbers exists?
// return some 'null'
// What if the array contains negative integers? It should still work


// pseudocode for find_pair_sum (order: nlogn)
// if array length is less than 2, return null
// sort array
// first pointer at start, last pointer at last
// do this while the pointers are not at same location
//      current sum = sum fo elements below pointers
//      if current sum > provided number, move right pointer one place left, else move left pointer one place right
//      else if current sum = provided number:
//          return the two numbers
//  return null if we reach here

// pseudocode for find_pair_sum_hash (order: n)
// for each element in array
//      see if hashtable contains (given number - current element)
//      if yes, return answer
//      if no, insert current number in hash and go to next element
// if we reach here, return null

// TODO: extensions: 1. return all pairs.

#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

vector<int> find_pair_sum(int array[], int array_length, int sum) {
    vector<int> answers;
    if (array_length<2)
        return answers;
    sort(array, array + array_length);
    if (sum<2*array[0] || sum>2*array[array_length-1])
        return answers;
    int left_ptr = 0, right_ptr = array_length-1;
    while(left_ptr != right_ptr) {
        int current_sum = array[left_ptr] + array[right_ptr];
        if (current_sum == sum) {
            answers.push_back(array[left_ptr]);
            answers.push_back(array[right_ptr]);
            return answers;
        } else if (current_sum > sum) {
            right_ptr--;
        } else if (current_sum < sum) {
            left_ptr++;
        }
    }
    return answers;
}

vector<int> find_pair_sum_hash(int array[], int array_length, int sum) {
    unordered_map<int, bool> hashmap;
    vector<int> answers;
    for (int i=0; i<array_length; i++) {
        int current_num = array[i];
        auto t = hashmap.find(sum-current_num);
        if (t != hashmap.end()) {
            answers.push_back(current_num);
            answers.push_back(sum-current_num);
            return answers;
        } else {
            hashmap[current_num] = true;
        }
    }
    return answers;
}

// leetcode answer
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> hashmap;
    for (int i=0; i<nums.size(); i++) {
        if (hashmap.find(target-nums[i]) != hashmap.end()) {
            ans.push_back(hashmap[target-nums[i]]);
            ans.push_back(i);
            return ans;
        } else {
            hashmap[nums[i]] = i;
        }
    }
    return ans;
}


int main() {
    // First implementation
    int arr1[] = {6, 2, 1};
    vector<int> ans1 = find_pair_sum(arr1, 3, 8);
    vector<int> ans2 = find_pair_sum(arr1, 3, 9);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    for (int i=0; i<ans2.size(); i++)
        cout<<ans2[i]<<endl;

    // Second implementation
    ans1 = find_pair_sum_hash(arr1, 3, 8);
    ans2 = find_pair_sum_hash(arr1, 3, 9);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    for (int i=0; i<ans2.size(); i++)
        cout<<ans2[i]<<endl;
}
