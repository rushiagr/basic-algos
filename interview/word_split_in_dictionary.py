# Given a string and a word dictionary, tell if that string is composed of
# words found in the dictionary. E.g. string is 'listlinkedlistarray' and
# dictionary contains words 'linked', 'linkedlist' and 'array'. The answer is
# 'no' in this case.

def string_in_dict(string, dictionary):
    # split each string into two parts, and recurse on both parts
    # worst case complexity: 2^n (exponential!)
    if string in dictionary:
        return True
    for i in range(1, len(string)):
        first = string[:i]
        rest = string[i:]
        if string_in_dict(first, dictionary) and \
                string_in_dict(rest, dictionary):
            return True
    return False


def string_in_dict2(string, dictionary):
    # split each string into two parts, and check if first part is in the
    # dictionary, and recurse only on second part
    # worst case complexity: 2^n (still exponential!)
    if string in dictionary:
        return True
    for i in range(1, len(string)):
        first = string[:i]
        rest = string[i:]
        if first in dictionary and \
                string_in_dict2(rest, dictionary):
            return True
    return False

dp = {}

# NOTE: THIS SOLUTION IS WRONG!!!! Last ASSERTION FAILS
def string_in_dict3(string, dictionary):
    # split each string into two parts, and check if first part is in the
    # dictionary, and recurse only on second part. Also maintain a memoization
    # table where you store if the string is splittable or not.
    # worst case complexity: n^2
    global dp
    if string in dictionary or dp.get(string):
        return True
    for i in range(1, len(string)):
        first = string[:i]
        rest = string[i:]
        if first in dictionary:
            if rest in dp.keys():
                val = dp[rest]
                if val:
                    return True
            else:
                val = string_in_dict3(rest, dictionary)
                dp[rest] = val
                return val
    return False

if __name__ == '__main__':
    d = ['list', 'linked']
    s = 'linkedlist'
    assert True == string_in_dict(s, d)
    d = ['list', 'linkedlist']
    s = 'linkedlistlinked'
    assert False == string_in_dict(s, d)
    d = ['list', 'linked', 'my']
    s = 'linkedmylist'
    assert True == string_in_dict(s, d)
    d = ['list', 'linkedlist', 'my']
    s = 'linkedmylist'
    assert False == string_in_dict(s, d)

    d = ['list', 'linked']
    s = 'linkedlist'
    assert True == string_in_dict2(s, d)
    d = ['list', 'linkedlist']
    s = 'linkedlistlinked'
    assert False == string_in_dict2(s, d)
    d = ['list', 'linked', 'my']
    s = 'linkedmylist'
    assert True == string_in_dict2(s, d)
    d = ['list', 'linkedlist', 'my']
    s = 'linkedmylist'
    assert False == string_in_dict2(s, d)
    d = ['list', 'linkedlist', 'my', 'linked']
    s = 'linkedmylist'*200
    assert True == string_in_dict2(s, d)
    d = ['list', 'linkedlist', 'my', 'linked']
    s = 'abcdefghij'*200
    assert False == string_in_dict2(s, d)

    d = ['a', 'aa', 'aaa', 'aaaa', 'aaaaa', 'aaaaaa', 'aaaaaaa', 'aaaaaaaa',
    'aaaaaaaaa', 'aaaaaaaaaa', 'aaaaaaaaaaa', 'aaaaaaaaaaaa']
    s = 'aaaaaaaaaaaab'
    assert False == string_in_dict2(s, d)

    d = ['list', 'linked']
    s = 'linkedlist'
    assert True == string_in_dict3(s, d)
    d = ['list', 'linkedlist']
    s = 'linkedlistlinked'
    assert False == string_in_dict3(s, d)
    d = ['list', 'linked', 'my']
    s = 'linkedmylist'
    assert True == string_in_dict3(s, d)
    d = ['list', 'linkedlist', 'my']
    s = 'linkedmylist'
    assert False == string_in_dict3(s, d)
    d = ['list', 'linkedlist', 'my', 'linked']
    s = 'linkedmylist'*200
    assert True == string_in_dict3(s, d)
    d = ['list', 'linkedlist', 'my', 'linked']
    s = 'abcdefghij'*200
    assert False == string_in_dict3(s, d)

    dp = {}
    d = ['a', 'aa', 'aaa', 'aaaa', 'aaaaa', 'aaaaaa', 'aaaaaaa', 'aaaaaaaa',
    'aaaaaaaaa', 'aaaaaaaaaa', 'aaaaaaaaaaa', 'aaaaaaaaaaaa']
    s = 'aaaaaaaaaaaab'
    assert False == string_in_dict3(s, d)

    dp = {}
    d = ['one', 'onetwo', 'three', 'four', 'five']
    s = 'onetwothreefourfivefourfive'
    assert True == string_in_dict3(s, d)
