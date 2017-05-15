#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// question: given an array of integers, and a length of sliding window 'k',
// find maximum elements in each sliding window

// complexity: O(n) comparisons. O(n) auxiliary space.

// solution: as soon as we move forward, add the element to the heap. Also,
// maintain a hashmap where key is the element, and value is a vector of
// positions where that element has occurred. Whenever we move sliding window,
// insert element to heap and hashmap, and then find max from heap. If the max
// number is outside of sliding window, then remove that element from heap and
// the corresponding index from hashamp successively, and find first instance
// of that max number inside the sliding window.

vector<int> find_sliding_windows(int array[], int length, int window_size) {
    vector<int> answers;
    if (array == NULL || length == 0 )
        return answers;
    if (window_size > length)
        window_size = length;
    unordered_map<int, vector<int> > hashmap;
    vector<int> heap;   // max heap

    for (int i=0; i<window_size; i++) {
        // push to hashmap
        if (hashmap.find(array[i]) != hashmap.end()) {
            hashmap[array[i]].push_back(i);
        } else {
            vector<int> temp;
            temp.push_back(i);
            hashmap[array[i]] = temp;
        }
        // push to heap
        heap.push_back(array[i]);
        push_heap(heap.begin(), heap.end());
    }

    int max_in_window = heap[0];
    answers.push_back(max_in_window);

    for (int start=1, end=window_size+1; end<=length; start++, end++) {
        // push to hashmap
        if (hashmap.find(array[end-1]) != hashmap.end()) {
            hashmap[array[end-1]].push_back(end-1);
        } else {
            vector<int> temp;
            temp.push_back(end-1);
            hashmap[array[end-1]] = temp;
        }
        // push to heap
        heap.push_back(array[end-1]);
        push_heap(heap.begin(), heap.end());
        while (true) {
            int max_from_heap = heap[0];
            int max_from_heap_idx = hashmap[max_from_heap][0];
            if (max_from_heap_idx < start) {
                hashmap[max_from_heap].erase(hashmap[max_from_heap].begin());
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            } else {
                answers.push_back(max_from_heap);
                break;
            }
        }
    }
    return answers;
}

int main() {
    int a[] = {5, 4, 3, 2, 1, 2, 3, 5, 11, 2, 1, -1, 44, 234, -222};
    vector<int> ans = find_sliding_windows(a, 15, 5);
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    int b[] = {5, 4, 3, 2, 1, 2, 3, 5, 11, 2, 1, -1, 44, 234, -222};
    ans = find_sliding_windows(b, 15, 1);
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
