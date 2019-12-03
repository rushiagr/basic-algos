#include<iostream>
using namespace std;

int log_2(int x) {
    // assumption: x is not zero
    int ans = 0;
    while (x >>= 1)
        ans++;
    return ans;
}

int main() {
    cout<<log_2(1)<<endl;
    cout<<log_2(2)<<endl;
    cout<<log_2(3)<<endl;
    cout<<log_2(4)<<endl;
    cout<<log_2(5)<<endl;
    cout<<log_2(6)<<endl;
    cout<<log_2(7)<<endl;
    cout<<log_2(8)<<endl;
}
