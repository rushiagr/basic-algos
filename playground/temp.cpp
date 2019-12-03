#include<iostream>
using namespace std;

// test for branch mispredict vs no branch. There seems to be a slight performance improvement (less than 10%) which can still be useful!

int main() {
    bool val ;
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        if (i%2 == 0){val=true;} else {val=false;}
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        val = (bool)i%2;
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        if (i%2 == 0){val=true;} else {val=false;}
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        val = (bool)i%2;
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        if (i%2 == 0){val=true;} else {val=false;}
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        val = (bool)i%2;
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        if (i%2 == 0){val=true;} else {val=false;}
    }
    cout<<"blah"<<endl;
    for (long long int i=0; i< 1000000000; i++) {
        val = (bool)i%2;
    }
    cout<<"blah"<<endl;
}
