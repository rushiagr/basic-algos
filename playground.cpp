#include<iostream>
using namespace std;

#include <unordered_map>    // required for unordered_map
#include <vector>           // required for vectors


// see section 'array'
void array_printer(int arr[], int length) {
    for (int i=0; i<length; i++)
        cout<<arr[i]<<endl;
}

int main() {
    /******** ARRAYS *******/
    int arr1[2] = {};       // empty array
    int arr2[2] = {1, 2};   // filled array
    int arr3[2] = {1};      // half-filled array
    int arr4[] = {1, 2, 0, 4};      // filled array, auto-size-detection

    // pass array to function. See start for function definition
    array_printer(arr4, 2);

    // array of strings
    string arr5[] = {"one", "two", "three"};

    // sorting array
    sort(arr4, arr4 + 4);

    /********** POINTERS ******/
    int *ptr1;           // pointer to an integer
    int myint = 1;
    ptr1 = &myint;       // pointer now points to address of 'myint' integer
    myint = 2;          // *ptr is now 2. Was 1 before this line.
    *ptr1 = 3;           // *ptr, i.e. myint is now 3. Was 2 before this line

    int arr6[] = {1, 2, 3, 4, 5};
    int *ptr = arr6;    // pointer to array
    cout<<*ptr<<endl;   // print first element of array
    cout<<ptr<<endl;    // print address of first element of array
    ptr++;              // now point to second element of array
    cout<<*ptr<<endl;   // print first element of array
    cout<<ptr<<endl;    // print address of first element of array
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(ptr)<<endl;

    // Using 'new', 'delete' with integer
    int *intptr;            // create a pointer (uninitialized)
    intptr = new int;       // allocate memory for integer
    *intptr = 10;           // integer now contains value 10
    delete intptr;          // deallocate memory of integer

    // Using 'new', 'delete' with one-dimensional array
    int *intptr2;           // create pointer. Same as for single int
    intptr2 = new int[3];   // allocate memory for 10 integers
    *intptr2 = 1;           // insert 1 in 0th index
    intptr2[1] = 2;         // insert 2 in 1st index
    cout<<intptr2[2]<<endl; // on 2nd index, 0 is there
    delete [] intptr2;      // deallocate memory

    // Using 'new', 'delete' with 10x10 two-dimensional array
    int **arr2d;
    arr2d = new int*[10];       // allocate rows
    for (int i=0; i<10; i++)
        arr2d[i] = new int[10]; // allocate memory for column
    // now deallocate memory
    for (int i=0; i<10; i++)
        delete [] arr2d[i];     // deallocate memory for column
    delete [] arr2d;            // deallocate rows

    int (*foo)(int, int);// function foo takes two ints and returns an int


    /******** STRINGS *******/
    string s = "one";

    // Length of string
    int len = s.length(); // 3

    // 2 chars starting from 0th index
    string sub = s.substr(0, 2);    // "on"

    // substring starting from 1st position till end
    string sub2 = s.substr(1);      // "ne"
    string sub3 = s.substr(2);      // "e"
    string sub4 = s.substr(3);      // ""
    // string sub4 = s.substr(4);      // throws exception

    // finding substring in string
    int pos = s.find("ne");         // 1
    int pos2 = s.find("xa");         // -1

    cout<<len<<endl<<sub<<endl<<sub2<<endl<<sub3<<endl<<sub4<<endl<<pos<<endl<<pos2<<endl;

    /******** VECTORS *******/
    vector <int> myvec;
    myvec.push_back(1);             // insert
    myvec.push_back(2);             // insert
    int lastval = myvec.back();     // get last value
    myvec.pop_back();               // remove last value
    int size = myvec.size();        // get size, 2 in this case
    bool is_empty = myvec.empty();  // check if empty

    /******** UNORDERED MAP (HASH TABLE) *******/
    unordered_map<string, string> hashmap;

    // insertion
    hashmap["key1"] = "value1";

    // fetch
    string value = hashmap["key1"];

    // finding if key is present
    int count = hashmap.count("key1");  // count = 1
    count = hashmap.count("key2");      // count = 0

    // iterate over all elements
    for (auto it=hashmap.begin(); it!=hashmap.end(); ++it)
        cout<<it->first<<":"<<it->second<<endl;

    // finding if key is present, and get value
    auto t = hashmap.find("key1");
    if (t != hashmap.end()) {
        cout<<t->first<<endl<<t->second;  //present. Printing key and value
    } else {
        ;   // not present
    }

    // erase
    hashmap.erase("key1");


    // alternate way of creation
    unordered_map<string, string> hashmap2;
    hashmap2 = {{"key1", "value1"}, {"key2", "value2"}};




}

