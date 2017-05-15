# Validate if a given string (e.g. '{{}{}}') has proper matching pair of braces
# or not

def check_matching_braces(inp):
    stack = []
    for char in list(inp):
        if char == '{':
            stack.append(char)
        elif char == '}':
            if len(stack) == 0:
                return False
            else:
                stack.pop()
    if len(stack) == 0:
        return True
    else:
        return False

if __name__ == '__main__':
    assert True == check_matching_braces('{{}}')
    assert False == check_matching_braces('{}}')
    assert False == check_matching_braces('{{{}')
    assert True == check_matching_braces('{{}{}{{{}}}}')
    assert True == check_matching_braces('')
    assert False == check_matching_braces('{')
    assert False == check_matching_braces('}')
