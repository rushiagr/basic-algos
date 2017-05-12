// Write a data structure which provides O(1) insertion, deletion, search and
// getting any element from the data structure at random.
//
// Run as: g++ <filename>.cpp -std=gnu++11
//
// Solution: keep incoming integer in a hashmap and also in an
// auto-expanding-array, where key is the integer, and value is it's position
// in the array. Double the size of array as soon as it becomes full.

#include<iostream>
#include <tr1/unordered_map>

class SuperDS {
    public:
    std::tr1::unordered_map<int, int> hashmap;
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
            delete [] old_array;
            array_length *= 2;
        }
        array[array_last_filled_idx+1] = value;
    }

    void insert(int value) {
        int count = hashmap.count(value);
        if (count==1) {
            return;
        }
        array_insert(value);
        array_last_filled_idx++;
        hashmap[value] = array_last_filled_idx;
    }

    bool search(int value) {
        int count = hashmap.count(value);
        if (count==1) {
            return true;
        }
        return false;
    }

    // if element is not present, delete() does nothing
    void del(int value) {
        int count = hashmap.count(value);
        if (count==0)
            return;
        int array_idx = hashmap[value];
        array[array_idx] = array[array_last_filled_idx];
        array[array_last_filled_idx] = 0;
        hashmap.erase(value);
        array_last_filled_idx -= 1;

        // shrink array if it can be shrunk
        if (array_last_filled_idx < array_length/2 && array_length > 1) {
            int *old_array = array;
            array = new int[array_length/2];
            for (int i=0; i<=array_last_filled_idx; i++) {
                array[i] = old_array[i];
            }
            delete [] old_array;
            array_length /= 2;
        }
    }

    int get_random() {
        return array[rand() % (array_last_filled_idx+1)];
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
    myds.insert(6);
    std::cout<<"Inserted 1, 2, 3, 4, 5, 6"<<'\n';
    myds.search(1);
    myds.search(2);
    myds.search(3);
    myds.search(4);
    myds.search(5);
    myds.search(6);
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    myds.del(4);
    myds.del(5);
    myds.del(2);
    std::cout<<"Deleted 4, 5, 2"<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Random element from array: "<<myds.get_random()<<'\n';
    std::cout<<"Elements in DS now:"<<'\n';
    for (int i=0; i<=myds.array_last_filled_idx; i++)
        std::cout<<myds.array[i]<<' ';
    std::cout<<'\n';
    return 0;
}
