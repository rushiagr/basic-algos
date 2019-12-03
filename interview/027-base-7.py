# https://leetcode.com/problems/base-7/#/description

def base_7(n):
    rem = 0
    ans = []
    while(n):
        rem = n%7
        ans.append(str(rem))
        n = n - rem
        n = int(n/7)
    ans.reverse()
    return int(''.join(ans))

print(base_7(100))
print(base_7(101))
print(base_7(102))
