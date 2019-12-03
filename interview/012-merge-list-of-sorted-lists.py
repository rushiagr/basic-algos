from heapq import heappush, heappop

# https://leetcode.com/problems/merge-k-sorted-lists/#/description

def merge_lists(lol):
    # assumption: all lists of same, non-zero length
    pointers = [0] * len(lol)
    heap = []
    answers = []
    pointers_at_end = 0
    for i in range(len(lol)):
        heappush(heap, (lol[i][0], i))
    # for i in range(len(lol)*(len(lol[0]-1))):
    while pointers_at_end < len(lol):
        elem, list_idx = heappop(heap)
        answers.append(elem)
        pointers[list_idx] += 1
        if pointers[list_idx] < len(lol[0]):
            heappush(heap, (lol[list_idx][pointers[list_idx]], list_idx))
        else:
            pointers_at_end += 1
    while len(heap) > 0:
        elem, list_idx = heappop(heap)
        answers.append(elem)
    return answers

if __name__ == '__main__':
    print(merge_lists([[1, 2], [3, 4]]))
    print(merge_lists([[1, 4], [3, 5]]))
