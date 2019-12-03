def is_subsequence(bigstr, smallstr, biglen, smalllen):
    if smalllen == 0:
        return True
    if biglen == 0:
        return False
    if bigstr[biglen-1] == smallstr[smalllen-1]:
        return is_subsequence(bigstr, smallstr, biglen-1, smalllen-1)
    else:
        return is_subsequence(bigstr, smallstr, biglen-1, smalllen)

print(is_subsequence('abracadabra', 'abcd', 11, 4))
print(is_subsequence('abracadabra', 'abrz', 11, 4))
