#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include "utils/cpputils.h"

// Ineffecient, full recursive. Roughly O(2^n) time.
int lcsl(string s1, string s2) {
    if(s1.length()==0 || s2.length()==0) {
        return 0;
    }
    if(s1[s1.length()-1] == s2[s2.length()-1]) {
        return lcsl(s1.substr(0, s1.length()-1), s2.substr(0, s2.length()-1)) + 1;
    } else {
        return max(
            lcsl(s1.substr(0, s1.length()-1), s2),
            lcsl(s1, s2.substr(0, s2.length()-1))
            );
    }
}

// O(n^2) space. Much faster. More space can be saved.
int lcsl2(string s1, string s2) {
    int x = s1.length();
    int y = s2.length();
    int mat[100][100];
    
    for(int i=1; i<=x; i++) {
        for(int j=1; j<=y; j++) {
            if(s1[i-1]==s2[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    return mat[x][y];
}

// O(n) space, O(n^2) time. Returns not only length, but the string.
// Incomplete/wrong.
string lcs(string s1, string s2) {
    if(s1.length() > s2.length()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    cout<<s1<<" "<<s2<<endl;
    vector<int> mat(s1.length(), -1);
    
    for(int i=mat.size()-1; i>=0; i--) {
        // find the last occurence IN S2 of same char in the current string
        int last_occurence_index = s2.length();
        for(int j=i; j<mat.size(); j++) {
            if(s1[j]==s1[i] && j!=i){
                last_occurence_index = mat[j];
                cout<<"BR "<<i<<" "<<j<<endl;
                break;
            }
        }
        print_vi(mat);
        
        if (last_occurence_index <= 0) {
            cout<<"last"<<last_occurence_index<<endl;    
            continue;
        }
        
        for(int j=last_occurence_index-1; j>=0; j--) {
                cout<<"ij:"<<i<<" "<<j<<endl;
            if (s1[i]==s2[j]) {
                mat[i] = j;
                break;
//                length_remaining = j;
            }
        }
    }
    
    
    string ans = "";
    
    for(int i=0; i<mat.size(); i++) {
        if(mat[i]>-1) {
            ans += s1[i];
        }
    }
    return ans;
}




int main() {
    cout<<lcsl("rushiagrawal", "russhia")<<endl;
    cout<<lcsl("agrmujahiddeen", "muddinmuhammad")<<endl;
    cout<<lcsl2("rushiagrawal", "russhia")<<endl;
    cout<<lcsl2("agrmujahiddeen", "muddinmuhammad")<<endl;
    cout<<lcs("rushiagrawal", "russhia")<<endl;
    cout<<lcs("agrmujahiddeen", "muddinmuhammad")<<endl;
    return 0;
}
