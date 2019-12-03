#include<iostream>
#include<vector>
using namespace std;

vector<int> next_palindrome2(vector<int> a) {
    int l = a.size();
    bool is_odd = (bool)l%2;
    bool is_all_nines = true, is_smaller = false, override_increment = false;
    int left = (l-1)/2;
    int right = l/2;
    int carry = 0;
    while (left >= 0) {
        if (a[left] != 9 || a[right] != 9) {
            is_all_nines = false;
        }
        if ((a[left] > a[right]) || (a[left] < a[right] && is_smaller)) {
            a[right] = a[left];
            is_smaller = true;
        }
        if (override_increment) {
            int temp = a[left] + carry;
            carry = temp / 10;
            temp = temp % 10;
            a[left] = temp;
            a[right] = temp;
        } else if ((a[left] < a[right] && !is_smaller) || (left == 0 && !is_smaller)) {
            override_increment = true;
            left = (l-1)/2;
            right = l/2;
            carry = 1;
            continue;
        }
        left--;
        right++;
    }

    if (is_all_nines) {
        a[0] = 1;
        for (int i=1; i<a.size(); i++)
            a[i] = 0;
        a.push_back(1);
    }

    return a;
}

vector<int> next_palindrome(vector<int> a) {
    int l = a.size();
    bool is_odd = (bool)l%2;
    bool is_all_nines = true, is_smaller = false, is_larger = false;
    int left = (l-1)/2;
    int right = l/2;
    while (left >= 0) {
        if (a[left] != 9 || a[right] != 9) {
            is_all_nines = false;
        }
        if ((a[left] > a[right]) || (a[left] < a[right] && is_smaller)) {
            a[right] = a[left];
            is_smaller = true;
        } else if (a[left] < a[right] && !is_smaller) {
            is_larger = true;
            break;
        }
        if (left == 0 && !is_smaller) {
            is_larger = true;
        }
        left--;
        right++;
    }

    if (is_larger) {
        int carry = 1;
        left = (l-1)/2;
        right = l/2;
        while (left >= 0) {
            int temp = a[left] + carry;
            carry = temp / 10;
            temp = temp % 10;
            a[left] = temp;
            a[right] = temp;
            left--;
            right++;
        }
    }

    if (is_all_nines) {
        a[0] = 1;
        for (int i=1; i<a.size(); i++)
            a[i] = 0;
        a.push_back(1);
    }

    return a;
}

vector<int> str_to_int_vec(string s) {
    cout<<endl<<s<<endl;
    vector<int> ans;
    for (int i=0; i<s.length(); i++) {
        ans.push_back(s[i] - '0');
    }
    return ans;
}

void print_vec(vector<int> v) {
    for (int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<endl;
}

int main() {
    print_vec(next_palindrome2(str_to_int_vec("1")));
    print_vec(next_palindrome2(str_to_int_vec("11")));
    print_vec(next_palindrome2(str_to_int_vec("9")));
    print_vec(next_palindrome2(str_to_int_vec("99")));
    print_vec(next_palindrome2(str_to_int_vec("12345")));
    print_vec(next_palindrome2(str_to_int_vec("99999")));
    print_vec(next_palindrome2(str_to_int_vec("12321")));
    print_vec(next_palindrome2(str_to_int_vec("55555499")));
    print_vec(next_palindrome2(str_to_int_vec("55555949")));
    print_vec(next_palindrome2(str_to_int_vec("12344321")));
    print_vec(next_palindrome2(str_to_int_vec("12344320")));
    print_vec(next_palindrome2(str_to_int_vec("12344324")));
    print_vec(next_palindrome2(str_to_int_vec("55555949")));
    print_vec(next_palindrome2(str_to_int_vec("19999999")));
}
