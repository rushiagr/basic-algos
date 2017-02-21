# Given a number, find out the minimum numbers whose sum of squares is this
# number

def calc(n):
    if n<=0:
        return 0
    if n==1:
        return 1
    minval = 999999999999
    for i in range(1, int(math.floor(math.sqrt(n))+1)):
        minval = min(minval, 1+calc(n-i**2))
    return minval
