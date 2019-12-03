def longest_common_prefix(strs):
    pre = strs[0]
    for s in strs:
        while s.find(pre) != 0:
            pre = pre[:-1]
    return pre

print(longest_common_prefix(['blah', 'blaw', 'blahahah', 'blew']))
