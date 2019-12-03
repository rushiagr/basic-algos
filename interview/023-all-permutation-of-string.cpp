#include<iostream>
using namespace std;

// http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

// prints with duplicates

void all_perms(string s, int start) {
    if (start == s.length()-1) {
        cout<<s<<endl;
        return;
    }
    char temp;
    for (int i=start; i<s.length(); i++) {
        temp = s[i];
        s[i] = s[start];
        s[start] = temp;
        all_perms(s, start+1);
        s[start] = s[i];
        s[i] = temp;
    }
}

int main() {
    all_perms("abc", 0);
    all_perms("aab", 0);
}
