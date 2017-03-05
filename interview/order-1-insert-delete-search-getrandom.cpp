// Write a data structure which provides O(1) insertion, deletion, search and
// getting any element fromt he data structure at random

#include<iostream>
#include<map>
#include<unordered_map>
#include <tr1/unordered_map>

class SuperDS {
    public:
    std::tr1::unordered_map<int, bool> hashmap;
    int *array = new int[1];
    int array_length = 1;
    int array_last_filled_idx = -1;

    void array_insert(int value) {
        if (array_length-1 <= array_last_filled_idx) {
            // not enough space. Double array size before inserting element
            int *old_array = array;
            array = new int[array_length*2];
            for (int i=0; i<array_length; i++) {
                array[i] = old_array[i];
            }
            array_length *= 2;
        }
        array[array_last_filled_idx+1] = value;
        array_last_filled_idx++;
    }

    void insert(int value) {
        int count = hashmap.count(value);
        if (count==1) {
            return;
        }
        hashmap[value] = false;
        array_insert(value);
    }
};

int main() {
    SuperDS myds = SuperDS();
    myds.insert(1);
    myds.insert(2);
    myds.insert(3);
    myds.insert(4);
    myds.insert(4);
    myds.insert(5);
    for (int i=0; i<myds.array_length; i++)
        std::cout<<myds.array[i]<<' ';
    return 0;
}
