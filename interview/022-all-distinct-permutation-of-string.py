# http://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/

# All 'distinct' permutation of a string

# Input is a string
def all_perm(s):
    if len(s) <= 1:
        return [s]
    s = list(s)
    d = {}
    perms = []
    for i, char in enumerate(s):
        if not d.get(char):
            d[char] = i
    for char, i in d.items():
        s[0], s[i] = s[i], s[0]
        for ans in all_perm(s[1:]):
            temp = [s[0]]
            temp.extend(ans)
            perms.append(''.join(temp))
        s[0], s[i] = s[i], s[0]
    return perms

# input is list of ints
def all_int_perms(l, start_idx=0):
    if len(l) <= 1 or start_idx == len(l) - 1:
        print(l)
        return
    intmap = {}
    for i in range(start_idx, len(l)):
        if intmap.get(l[i]) is None:
            l[i], l[start_idx] = l[start_idx], l[i]
            all_int_perms(l, start_idx+1)
            l[i], l[start_idx] = l[start_idx], l[i]
            intmap[l[i]] = True



# print(all_perm('abc'))
# print(all_perm('aac'))
# print(all_perm('a'))
# print(all_perm(''))
all_int_perms([1, 2, 3])
all_int_perms([1, 1, 3])
