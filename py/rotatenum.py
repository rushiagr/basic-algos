# If rotating the number upside down results in the same number
def canrotate(num):
    num_list = [int(i) for i in list(str(num))]
    noncompatible = [2, 3, 4, 5, 7]
    mirrors = {1:1, 0:0, 6:9, 9:6, 8:8}
    for i in num_list:
        if i in noncompatible:
            return False
    for i in range(len(num_list)/2+1):
        if num_list[i] != mirrors[num_list[0-i-1]]:
            return False
    return True
