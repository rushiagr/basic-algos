#include<iostream>
#include<cmath>
using namespace std;

int reverse(int x) {
    int ans = 0;
    int int_max = pow(2, 32)/2 - 1;
    int int_min = pow(2, 32) * - 1;
    if (x > int_max || x <= int_min)
        return 0;
    bool is_negative = x < 0 ? true : false;
    if (is_negative)
        x = x * -1;
    while (x > 0) {
        int remainder = x%10;
        if (ans > int_max/10)
            return 0;
        else
            ans = ans*10+remainder;
        x = x/10;
    }
    if (is_negative)
        ans = ans * -1;
    return ans;
}


// from leetcode
int reverse2(int x) {
    int int_max = pow(2, 32)/2 - 1;
    int int_min = pow(2, 32) * - 1;
    long long res = 0;
    while(x) {
        res = res*10 + x%10;
        x /= 10;
    }
    return (res<int_min || res>int_max) ? 0 : res;
}

int main() {
    cout<<reverse(1)<<endl;
    cout<<reverse(10)<<endl;
    cout<<reverse(11)<<endl;
    cout<<reverse(-10)<<endl;
    cout<<reverse(-11)<<endl;
    cout<<reverse(1534236469)<<endl;

    cout<<reverse2(-123)<<endl;

}
