def palindrome_partitioning(s):
    ans = []
    backtrack(ans, [], s, 0)
    return ans

def backtrack(ans, curr_arr, s, start_idx):
    if start_idx == len(s):
        ans.append(list(curr_arr))
    else:
        for i in range(start_idx, len(s)):
            subs = s[start_idx:i+1]
            if is_palindrome(subs):
                curr_arr.append(subs)
                backtrack(ans, curr_arr, s, i+1)
                curr_arr.pop()

def is_palindrome(s):
    for i in range(len(s)/2):
        if s[i] != s[len(s)-1-i]:
            return False
    return True

print(palindrome_partitioning('geegfofgeeg'))
