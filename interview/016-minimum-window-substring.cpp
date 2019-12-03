#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/#/description
// amazing description of three similar problems given in solutions:
// https://leetcode.com/problems/minimum-window-substring/#/solutions

string minWindow(string s, string t) {
    vector<int> mmap(128, 0);
    int begin = 0, end = 0;
    int min_i = 0, min_j = 1000000;//s.length();
    int counter = t.length();
    for (auto chr: t)
        mmap[chr]++;
    while (end<s.size()) {
        if(mmap[s[end]] > 0) {
            cout<<"decreasing counter at "<<s[end]<<endl;
            counter--;
        }
        mmap[s[end]]--;
        end++;
        while (counter == 0) {
            if(end - begin < min_j - min_i) {
                min_j = end;
                min_i = begin;
            }
            if (mmap[s[begin]] == 0) {
                counter++;
                cout<<"increasing counter at "<<s[begin]<<endl;
            }
            mmap[s[begin]]++;
            begin++;
        }
    }
    if (min_i == 0 && min_j == 1000000)
        return "";
    else
        return s.substr(min_i, min_j-min_i);
}

int main() {
    cout<<minWindow("ab", "b")<<endl;
    cout<<minWindow("FFADOBECODEBANC", "ABC")<<endl;
}
