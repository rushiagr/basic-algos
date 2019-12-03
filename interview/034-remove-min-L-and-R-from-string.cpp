// problem: given a string, e.g. LLRLLRRLRR, find out minimum number of
// characters you have to remove such that the remaining strings has all Ls to
// left and Rs to right. There can be 0 or more L and 0 or more Rs in the
// string

#include<iostream>
using namespace std;

int min_LR_removals(string s) {
    int l = s.length();
    int dp[l][l];
    bool left[l][l];
    bool right[l][l];
    for (int gap=0; gap<l; gap++) {
        for (int i = 0; i < l - gap; i++) {
            int j = i+gap;
            if (gap == 0) {
                dp[i][j] = 0;
                left[i][j] = s[i] == 'L' ? true: false;
                right[i][j] = s[i] == 'R' ? true: false;
                continue;
            } else {
                // part 1 last elem + remaining
                int dp1 = dp[i][j-1];
                int left1 = left[i][j-1], right1 = right[i][j-1];
                int currdp;
                bool currleft, currright;
                if (s[j] == 'R') {
                    currdp = dp1;
                    currleft = false;
                    currright = right1;
                } else {
                    if (left1 == true) {
                        currdp = dp1;
                        currleft = left1;
                        currright = false;
                    } else {
                        currdp = dp1 + 1;
                        currleft = left1;
                        currright = right1;
                    }
                }

                // part 2, first elem + remaining
                int dp2 = dp[i+1][j];
                int left2 = left[i+1][j], right2 = right[i+1][j];
                int currdp2;
                bool currleft2, currright2;
                if (s[i] == 'L') {
                    currdp2 = dp2;
                    currleft2 = left2;
                    currright2 = false;
                } else {
                    if (right2 == true) {
                        currdp2 = dp2;
                        currleft2 = false;
                        currright2 = right2;
                    } else {
                        currdp2 = dp2 + 1;
                        currleft2 = left2;
                        currright2 = right2;
                    }
                }
                if (currdp < currdp2) {
                    dp[i][j] = currdp;
                    left[i][j] = currleft;
                    right[i][j] = currright;
                } else if (currdp > currdp2) {
                    dp[i][j] = currdp2;
                    left[i][j] = currleft2;
                    right[i][j] = currright2;
                } else {
                    dp[i][j] = currdp;
                    left[i][j] = currleft  | currleft2;
                    right[i][j] = currright | currright2;
                }
            }
        }
    }
    return dp[0][l-1];
}

int min_LR_removals2(string s) {
    int l = s.length();
    int dp[l][l];
    for (int i=0; i<l; i++)
            dp[i][i] = 0;
    for (int gap=1; gap<l; gap++) {
        for (int i = 0; i < l - gap; i++) {
            int j = i+gap;
            int val1, val2;
            if (s[i] == 'L')
                val1 = dp[i+1][j];
            else
                val1 = 1 + dp[i+1][j];
            if (s[j] == 'R')
                val2 = dp[i][j-1];
            else
                val2 = 1 + dp[i][j-1];
            dp[i][j] = min(val1, val2);
        }
    }
    return dp[0][l-1];
}

int main() {
    cout<<min_LR_removals("LRLR")<<endl;
    cout<<min_LR_removals("RLRRLLLRRRLRRR")<<endl;
    cout<<min_LR_removals("LRLLLRRLLLLRRRLLLRLRRRRLRLRRRR")<<endl;
    cout<<min_LR_removals("RRRRLL")<<endl;
    cout<<min_LR_removals2("LRLR")<<endl;
    cout<<min_LR_removals2("RLRRLLLRRRLRRR")<<endl;
    cout<<min_LR_removals2("LRLLLRRLLLLRRRLLLRLRRRRLRLRRRR")<<endl;
    cout<<min_LR_removals2("RRRRLL")<<endl;
}
