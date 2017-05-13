// question: Given an array of integers, find if there are three distinct
// numbers in the array whose sum is 0

// pseudocode
// if array length less than 3, return null
// sort the array
// for all elements i in array
//      mark i as selected
//      for the remaining array need to find if two elements sum to -i
//          left pointer = start element, right pointer = end element
//          if left pointer == mark, increment, vice versa for right ptr
//          while left pointer and right pointer are not at same position:
//              find sum
//              if found, return
//  if we reach here, then return false and abort

#include<iostream>
#include<vector>
using namespace std;

vector<int> find_sum_zero(int array[], int array_length) {
    vector<int> answers;
    if (array_length<3)
        return answers;
    sort(array, array+array_length);
    for (int mark=0; mark<array_length; mark++) {
        int left_ptr = 0, right_ptr = array_length-1;
        while (left_ptr != right_ptr) {
            if (left_ptr==mark)
                left_ptr++;
            if (right_ptr==mark)
                right_ptr--;
            if (left_ptr==right_ptr)
                break;
            int reqd_sum = array[mark] * -1;
            int current_sum = array[left_ptr] + array[right_ptr];
            if (current_sum==reqd_sum) {
                answers.push_back(array[mark]);
                answers.push_back(array[left_ptr]);
                answers.push_back(array[right_ptr]);
                return answers;
            } else if (current_sum>reqd_sum) {
                right_ptr--;
            } else if (current_sum<reqd_sum) {
                left_ptr++;
            }
        }
    }
    return answers;
}


int main() {
    int arr1[] = {6, 2, 1, -8};
    vector<int> ans1 = find_sum_zero(arr1, 4);
    for (int i=0; i<ans1.size(); i++)
        cout<<ans1[i]<<endl;
    int arr2[] = {6, 2, 1, -1, 11, -22};
    vector<int> ans2 = find_sum_zero(arr2, 6);
    for (int i=0; i<ans2.size(); i++)
        cout<<ans2[i]<<endl;
    int arr3[] = {6, 17, 1, -7, -23, 6};
    vector<int> ans3 = find_sum_zero(arr3, 6);
    for (int i=0; i<ans3.size(); i++)
        cout<<ans3[i]<<endl;
}
