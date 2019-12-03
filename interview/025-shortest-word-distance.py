# http://www.programcreek.com/2014/08/leetcode-shortest-word-distance-java/

def swd(l, w1, w2):
    pos_w1 = pos_w2 = -1
    min_dist = len(l) + 1
    for i in range(len(l)):
        if l[i] == w1:
            if pos_w2 > -1:
                min_dist = min(min_dist, i-pos_w2)
                pos_w1 = i
        elif l[i] == w2:
            if pos_w1 > -1:
                min_dist = min(min_dist, i-pos_w1)
    if min_dist == len(l) + 1:
        return -1
    return min_dist
