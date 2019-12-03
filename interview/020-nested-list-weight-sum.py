# http://www.programcreek.com/2014/05/leetcode-nested-list-weight-sum-java/
def nested_weight(l):
    return helper(l, 1)

def helper(l, weight):
    ans = 0
    for i in l:
        if type(i) == int:
            ans += i*weight
        elif type(i) == list:
            ans += helper(i, weight+1)
    return ans

print(nested_weight([[1, 1], 2, [1, 1]]))
print(nested_weight([[1, 1, [[[[[[[1]]]]]]]], 2, [1, 1]]))
