def permute(elems):
    ans = []
    backtrack(ans, [], elems, 0)
    return ans

counter = 0

def backtrack(ans_array, curr_arr, elems, idx):
    global counter
    counter += 1
    if len(curr_arr) == len(elems):
        ans_array.append(list(curr_arr))
    for i in range(len(elems)):
        if elems[i] in curr_arr:
            continue
        curr_arr.append(elems[i])
        backtrack(ans_array, curr_arr, elems, i+1)
        curr_arr.pop()

print(permute([1, 2, 3, 4, 5, 6, 7]))
print(counter)

# lessons learnt: when adding list, add after copying list, not directly
