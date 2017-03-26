# Given an array of integers and an integer k, tell if all the elements of the
# array can be grouped into pairs such that sum of each pair is divisible by
# the given integer

import collections

def pairs_divisible(arr, k):
    remainders = collections.defaultdict(list)
    for elem in arr:
        remainders[elem % k].append(elem)

    if len(remainders[0]) % 2 != 0:
        return False

    # If k is even, need to check number of elements with remainder k/2
    if k % 2 == 0 and len(remainders[k/2]) % 2 != 0:
        return False

    for i in range(1, k/2):
        if (len(remainders[i])+len(remainders[k-i])) % 2 != 0:
            return False

    return True

if __name__ == '__main__':
    assert True == pairs_divisible([1, 2, 3, 4], 2)
    assert False == pairs_divisible([1, 2, 3, 4], 4)
    assert True == pairs_divisible([0, 2, 4, 8, 12, 18, 20, 4], 4)
    assert False == pairs_divisible([0, 2, 4, 8, 14, 18, 20, 4], 4)
