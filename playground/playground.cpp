#include<iostream>
using namespace std;

#include<unordered_map>     // required for unordered_map
#include<vector>            // required for vectors
#include<limits>            // required to find out integer and other max and min values
#include<cmath>             // required for 'pow' function
#include<list>              // required for creating 'list' (doubly LL)
#include<queue>             // required for queue
#include<set>               // required for set



// see section 'array'
void array_printer(int arr[], int length) {
    for (int i=0; i<length; i++)
        cout<<arr[i]<<endl;
}
void array_printer2(int* arr, int length) { // works exactly same as above
    for (int i=0; i<length; i++)
        cout<<arr[i]<<endl;
}

void increment_by_reference(int &a) {
    a++;
}
int increment_by_value(int a) {
    a++;
    return a;
}
int & increment_by_reference_and_return(int &a) {
    a++;
    return a;
}

int main() {
    /******** ARRAYS *******/
    int arr1[2] = {};       // empty array
    int arr2[2] = {1, 2};   // filled array
    int arr3[2] = {1};      // half-filled array
    int arr4[] = {1, 2, 0, 4};      // filled array, auto-size-detection

    // pass array to function. See start for function definition
    array_printer(arr4, 2);
    array_printer2(arr4, 2);

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

    // check if string is empty
    bool is_empty = s.empty();  // false

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
    myvec.push_back(3);             // insert
    myvec.push_back(4);             // insert
    int lastval = myvec.back();     // get last value
    myvec.pop_back();               // remove last value
    int size = myvec.size();        // get size, 2 in this case
    is_empty = myvec.empty();       // check if empty
    myvec.erase(myvec.begin()+1);   // delete second value

    // iteration using iterators
    for (auto it = myvec.begin(); it != myvec.end(); ++it)
        cout<<"from iterator "<<*it<<endl;

    // initialize vector named myvec2 with 128 elements, all equal to 0
    vector<int> myvec2(128,0);

    // create a vector as a slice of another vector
    vector<int> myvec3(myvec.begin()+1, myvec.begin()+2);   //myvec[1:2+1]



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
    cout<<endl;

    // erase
    hashmap.erase("key1");


    // alternate way of creation
    unordered_map<string, string> hashmap2;
    hashmap2 = {{"key1", "value1"}, {"key2", "value2"}};

    /******** HEAPS *********/
    // create a MAX heap
    vector<int> heap;
    make_heap(heap.begin(), heap.end());
    heap.push_back(1);
    push_heap(heap.begin(), heap.end());     // insert 1
    heap.push_back(2);
    push_heap(heap.begin(), heap.end());     // insert 2
    heap.push_back(3);
    push_heap(heap.begin(), heap.end());     // insert 3
    heap.push_back(4);
    push_heap(heap.begin(), heap.end());     // insert 4
    for (int i=0; i<heap.size(); i++)
        cout<<heap[i]<<endl;

    // Create a MIN heap
    // Note that for ALL heap operations, you need to specify 'greater<int>()'
    vector<int> minheap;
    make_heap(minheap.begin(), minheap.end(), greater<int>()); // don't forget '()'
    minheap.push_back(4);
    push_heap(minheap.begin(), minheap.end(), greater<int>());     // insert 1
    minheap.push_back(3);
    push_heap(minheap.begin(), minheap.end(), greater<int>());     // insert 2
    minheap.push_back(2);
    push_heap(minheap.begin(), minheap.end(), greater<int>());     // insert 3
    minheap.push_back(1);
    push_heap(minheap.begin(), minheap.end(), greater<int>());     // insert 4

    for (int i=0; i<minheap.size(); i++)
        cout<<minheap[i]<<endl;

    // pop top element. Actually, it just places it at the end of underlying vector
    pop_heap(minheap.begin(), minheap.end(), greater<int>());
    minheap.pop_back();     // now actually pop

    for (int i=0; i<minheap.size(); i++)
        cout<<minheap[i]<<endl;

    // Heap with additional data
    struct HeapNode {       // also an example of creating and using struct
        int data, extra;
    };

    // comparator function for heap with additional data
    struct Comp {
        bool operator()(const HeapNode& hn1, const HeapNode& hn2) {
            return hn1.data < hn2.data;
        }
    };
    vector<HeapNode> heap2;
    HeapNode hn1, hn2;
    hn1.data = 10; hn1.extra = 12345;
    hn2.data = 20; hn2.extra = 54321;
    heap2.push_back(hn1);
    heap2.push_back(hn2);
    make_heap(heap2.begin(), heap2.end(), Comp());  // don't forget '()' for Comp

    for (int i=0; i<heap2.size(); i++)  // should print 20 first and then 10
        cout<<heap2[i].data<<" "<<endl;


    /************ PRIORITY QUEUE *********/
    priority_queue<int> pq;     // note: only max heap possible. Part of 'std'.
    pq.push(1);
    pq.push(3);
    pq.push(2);
    int maxval = pq.top();      // access top element
    pq.pop();                   // remove top element

    // example of complex priority queue, which will be arranged on first int
    priority_queue<pair<int, pair<int, int> > > pq2;

    /*********** SETS *********************/
    set<int> myset;
    myset.insert(1);
    myset.insert(2);
    myset.insert(3);
    if (myset.find(4) == myset.end())
        cout<<"4 not found in set"<<endl;
    myset.erase(3);

    /**************** STL LINKED LISTS **************/
    list<int> mylist;           // create linked list of integers
    mylist.push_back(10);       // push 10 to list
    mylist.push_back(20);       // push 20 to list, front(head) is 10, back(rear) is 20
    mylist.push_front(30);      // list: 30 10 20
    list<int>::iterator it;     // iterator to list
    it = mylist.begin();        // points to 30
    it++;                       // points to 10
    mylist.erase(it);           // list: 30 20 (erases element)
    for (auto it2 = mylist.begin(); it2 != mylist.end(); it2++)
        cout<<*it2<<endl;
    mylist.empty();             // removes all elements from list

    /*************** STL QUEUE *******************/
    queue<int> myq;
    myq.push(1);                  // push 1
    myq.push(2);                  // push 2
    cout<<myq.front()<<endl;      // print '1'
    myq.pop();                    // removes '1'
    if (myq.empty()) return 0;    // example to check if queue is empty

    /************ OTHERS ***********/
    int imin = numeric_limits<int>::min(); // min int, in this case (2**32)/2-1
    int imax = numeric_limits<int>::max(); // max int
    int int_max = pow(2, 32)/2 - 1;         // one more way to write the same
    int int_min = pow(2, 32) * - 1;

    int a = 11, b = -11;
    int c = a % 10;     // c becomes 1
    int d = b % 10;     // d becomes -1

    cout<<imin<<" "<<imax<<" "<<c<<" "<<d<<" "<<endl;

    // convert string to integer and vice versa
    string int_str = "562";
    int int_int = stoi(int_str);
    string str_int = to_string(1234);

    // Array empty-initialization
    int arr7[10] = {0};  // initializes all elem of array to zero
    int arr8[10];        // initializes all elem of array to zero
    int random=10;
    int arr9[random];    // DOES NOT initializes all elem of array to zero
    // int arr10[random] = {0}; // DOES NOT WORK THIS WAY. Variable can't be
                                // specified while initializing. Use 'for' loop
                                // or memset() to zero out

    // call by value, call by reference etc primer
    int e = 10, f = 20, g = 30;
    int h = increment_by_value(e);
    increment_by_reference(f);
    int i = increment_by_reference_and_return(g);
    // at this point:
    // e = 10 -- unchanged
    // f = 21 -- incremented
    // g = 31 -- incremented
    // and return values h = 11, i = 31
    cout<<e<<endl;
    cout<<f<<endl;
    cout<<g<<endl;
    cout<<h<<endl;
    cout<<i<<endl;

    /*********** BIT MANIPULATION *************/
    int j = 1, k = 5;
    int m = j & k;      // AND. 1 AND 101 = 1 i.e. 1
    int n = j | k;      // OR. 1 OR 101 = 101 i.e. 5
    int l = j ^ k;      // XOR. 1 XOR 101 = 100 i.e. 4
    int o = ~-4;// ^ k;      // NOT. NOT 1 is (1*-1)-1 i.e. -2 (only for +ve integers)
    bool p = false;
    p = !p;             // flip value of boolean. It'll now become 'true'
    cout<<l<<" "<<m<<" "<<n<<" "<<o<<endl;
    int q = 12;      // binary 1100
    q = log2(q & -q); // position of rightmost set bit. value 2 means 3rd position from right
    cout<<"q "<<q<<endl;

    vector<int> tempvec(10, 0);
    int somelen = tempvec.size()-1;
    while (somelen-->=0)
        cout<<tempvec[somelen]<<" ";

    cout<<"--"<<endl;

    // value of variables
    i = 0;
    int end = 10;
    for (; i<end; ++i) {
        cout<<i<<endl;
        // if (i==9)
        //     break;
    }
    // if we break the above loop at last iteration like we're doing, i after
    // loop will be 9, else if we don't break, it'll be 10 after the loop.
    cout<<i<<endl;

    i = 0, end = 10; for (; i<end; ++i) {cout<<i<<endl;} cout<<i<<endl;
    i = 0, end = 10; for (; i<end; i++) {cout<<i<<endl;} cout<<i<<endl;

    // cout<<"allocation started"<<endl;
    // int *arrx = new int[1000000000];
    // cout<<"allocation ended"<<endl;
    // for (int i = 0; i<1000000000; i++) arrx[i] = 0;
    // cout<<"allocation ended"<<endl;
    // list<int> xyzz;
    // for (int i = 0; i<100000000; i++) xyzz.push_front(i);
    // cin>>i;

}
