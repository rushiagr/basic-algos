#include<iostream>
#include<unordered_map>
using namespace std;

// https://leetcode.com/problems/decode-ways/#/description
// Note: my solution uses a hashmap. Instead of storing strings, we can also
// store index in the string from where the substring starts. That actually
// means, instead of hashmap, we can actually just use an integer array. There
// is a concise solution in leetcode solutions which doesn't even use an array,
// but just two variables.

unordered_map<string, int> hashmap;

int numDecodings(string s) {
    if (s.empty()) {
        return 0;
    }
    if (hashmap.find(s) != hashmap.end()) {
        return hashmap[s];
    }
    if (s.length() == 1 ) {
        if (stoi(s) != 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (s.length() == 2) {
        int first = stoi(s.substr(0, 1));
        int second = stoi(s.substr(1, 1));
        int both = stoi(s.substr(0, 2));
        int ans = 0;
        if (first != 0 && second != 0)
            ans += 1;
        if (both >=10 && both <=26)
            ans += 1;
        hashmap[s] = ans;
        return ans;
    } else {
        int ans = 0;
        int first_num_decodings = numDecodings(s.substr(1));
        int first = stoi(s.substr(0, 1));
        if (first != 0)
            ans += first_num_decodings;
        int second_num_decodings = numDecodings(s.substr(2));
        int both = stoi(s.substr(0, 2));
        if (both >= 10 && both <=26)
            ans += second_num_decodings;
        hashmap[s] = ans;
        return ans;
    }
}

// My solution, after looking at leetcode solution. Assumption: each char is only from 0-9
// Explanation: in 'dp', at ith position, store all possible ways the string of
// length 0-i can be decoded.
// Complexity: Time O(n). Space: O(n).
int numDecodings2(string s) {
    if (s.length() == 0)
        return 0;
    if (s.length() == 1) {
        if (s[0] > '0') {
            return 1;
        } else {
            return 0;
        }
    }
    int dp[s.length()+1];
    dp[0] = 1;
    if (s[0] > '0') {
        dp[1] = 1;
    } else {
        dp[1] = 0;
    }
    for (int i=1; i<s.length(); i++) {
        if (s[i] > '0') {
            dp[i+1] = dp[i];
        } else {
            dp[i+1] = 0;
        }
        if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            dp[i+1] += dp[i-1];
        }
    }
    return dp[s.length()];
}


int main() {
    cout<<numDecodings("112")<<endl;
    cout<<numDecodings("1099")<<endl;
    cout<<numDecodings("122222222")<<endl;
    cout<<numDecodings("123422222")<<endl;
    cout<<numDecodings("1230422222")<<endl;
    cout<<numDecodings2("112")<<endl;
    cout<<numDecodings2("1099")<<endl;
    cout<<numDecodings2("122222222")<<endl;
    cout<<numDecodings2("123422222")<<endl;
    cout<<numDecodings2("1230422222")<<endl;
}
