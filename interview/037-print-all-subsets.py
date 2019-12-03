def get_all_subsets(elems):
    elems = sorted(elems)
    ans = []
    backtrack(ans, [], elems, 0)
    return ans

def backtrack(ans_array, curr_arr, elems, idx):
    print('called with {} {}'.format(curr_arr, idx))
    ans_array.append(list(curr_arr))
    for i in range(idx, len(elems)):
        curr_arr.append(elems[i])
        backtrack(ans_array, curr_arr, elems, i+1)
        curr_arr.pop()

print(get_all_subsets([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))

# lessons learnt: when adding list, add after copying list, not directly
