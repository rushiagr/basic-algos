# http://www.programcreek.com/2014/04/leetcode-flip-game-java/

def all_combinations(s):
    res = []
    for i in range(len(s)-1):
        if s[i] == '+' and s[i] == s[i+1]:
            new = list(s)
            new[i] = new[i+1] = '-'
            res.append(''.join(new))
    return res

print(all_combinations('++--++++++--++--'))
