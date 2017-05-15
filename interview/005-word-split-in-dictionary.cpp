#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

// Given a string and a word dictionary, tell if that string is composed of
// words found in the dictionary. E.g. string is 'listlinkedlistarray' and
// dictionary contains words 'linked', 'linkedlist' and 'array'. The answer is
// 'no' in this case.

unordered_map<string, bool> dict;
unordered_map<string, bool> memtable;

/* Working code. Note that some edge cases can be merged into the main 'for'
 * loop, which is exactly what is being done in the next function */
bool can_split(string str) {
    auto t = dict.find(str);
    if (t != dict.end()) {
        return true;
    }
    auto t2 = memtable.find(str);
    if (t2 != memtable.end()) {
        return true;
    }
    if (str.length() == 0) {
        return false;
    }
    if (str.length() == 1) {
        auto t3 = dict.find(str);
        if (t3 == dict.end()) {
            return false;
        }
    }
    for (int i=1; i<str.length()-1; i++) {
        string first = str.substr(0, i);
        string rest = str.substr(i);
        auto t4 = dict.find(first);
        if (t4 != dict.end()) {
            bool is_rest_splittable = can_split(rest);
            if (is_rest_splittable) {
                memtable[str] = true;
                return true;
            }
        }
    }
    return false;
}

/* The best, crispest solution. */
bool can_split2(string str) {
    if (str.length() == 0) {
        return false;
    }
    auto t = dict.find(str);
    if (t != dict.end()) {
        return true;
    }
    auto t2 = memtable.find(str);
    if (t2 != memtable.end()) {
        return true;
    }

    for (int i=1; i<str.length(); i++) {
        string first = str.substr(0, i);
        string rest = str.substr(i);
        auto t3 = dict.find(first);
        if (t3 != dict.end()) {
            bool is_rest_splittable = can_split(rest);
            if (is_rest_splittable) {
                memtable[str] = true;
                return true;
            }
        }
    }
    return false;
}

unordered_map<string, bool> dict2;
unordered_map<string, string> memtable2;
/* This solution returns not boolean value, but the string split as words,
 * separated by spaces. So if dictionary contains "one" and "two", and the word
 * is "onetwo", then the return value will be "one two". */
string get_splits(string str) {
    if (str.length() == 0) {
        return "";
    }
    auto t = dict2.find(str);
    if (t != dict2.end()) {
        return str;
    }
    auto t2 = memtable2.find(str);
    if (t2 != memtable2.end()) {
        return t2->second;
    }

    for (int i=1; i<str.length(); i++) {
        string first = str.substr(0, i);
        string rest = str.substr(i);
        auto t3 = dict2.find(first);
        if (t3 != dict2.end()) {
            string splits = get_splits(rest);
            if (splits != "") {
                string new_entry = first + " " + splits;
                memtable2[str] = new_entry;
                return new_entry;
            }
        }
    }
    return "";
}

// TODO: if there are more than one possibilities, return all the
// possibilities. We need to return vector of strings from our function

int main() {
    dict["one"] = true;
    dict["onetwo"] = true;
    dict["three"] = true;
    dict["four"] = true;
    dict["five"] = true;
    dict["rushi"] = true;
    dict["a"] = true;
    dict["ab"] = true;
    dict["c"] = true;
    cout<<can_split("rushi")<<'\n';
    cout<<can_split("oneonetwo")<<'\n';
    cout<<can_split("twoonetwo")<<'\n';
    cout<<can_split("oneone")<<'\n';
    cout<<can_split("fourfourfive")<<'\n';
    cout<<can_split("onetwothreefourfivefourfive")<<'\n';


    cout<<can_split2("rushi")<<'\n';
    cout<<can_split2("oneonetwo")<<'\n';
    cout<<can_split2("twoonetwo")<<'\n';
    cout<<can_split2("oneone")<<'\n';
    cout<<can_split2("fourfourfive")<<'\n';
    cout<<can_split2("onetwothreefourfivefourfive")<<'\n';
    cout<<can_split2("abc")<<'\n';

    dict2["one"] = true;
    dict2["onetwo"] = true;
    dict2["three"] = true;
    dict2["four"] = true;
    dict2["five"] = true;
    dict2["rushi"] = true;
    dict2["a"] = true;
    dict2["ab"] = true;
    dict2["c"] = true;
    cout<<get_splits("rushi")<<'\n';
    cout<<get_splits("oneonetwo")<<'\n';
    cout<<get_splits("twoonetwo")<<'\n';
    cout<<get_splits("oneone")<<'\n';
    cout<<get_splits("fourfourfive")<<'\n';
    cout<<get_splits("onetwothreefourfivefourfive")<<'\n';
    cout<<get_splits("abc")<<'\n';
}
