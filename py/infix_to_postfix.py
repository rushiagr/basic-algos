import pdb

priority = {}
priority['-'] = 1
priority['+'] = 1
priority['*'] = 2
priority['/'] = 2
priority['('] = 3
priority[')'] = 3

def get_token(string):
#    if string == '1':
#        pdb.set_trace()
    if string[0].isdigit():
        token = string[0]
        string = string[1:]
        if len(string) is 0:
            return token, string
        while string[0].isdigit():
            token += string[0]
            string = string[1:]
        return (token, string)
    else:
        return (string[0], string[1:])

def infix_to_postfix(inf_str):
    postf_str = ''
    stack = []
#    pdb.set_trace()
    
            
    print len(inf_str)
    
    while len(inf_str) is not 0:
        print 'aa. stack:', stack, ' poststr: ', postf_str
        token, inf_str = get_token(inf_str)
        if token.isdigit():
            postf_str += token
        elif token == '(':
            stack.append(token)
            print stack
        elif token == ')':
            while stack[-1] != '(':
                print 'wah', stack
                postf_str += stack.pop()
                print 'post2', postf_str
            stack.pop()
        else:
            if len(stack) is 0:
                stack.append(token)
            elif priority[token] > priority[stack[-1]]:
                stack.append(token)
                while len(stack)>0 and priority[stack[-1]] >= priority[token] and \
                        stack[-1] not in [')', '(']:
                    postf_str += stack.pop()
                    print 'post3', postf_str
                stack.append(token)
    
    while len(stack) is not 0:
        postf_str += stack.pop()
    
    return postf_str

expressions = ["1+2*3-(6*5-4)",
               "1+2*7-(8-7*5)+3*1"]



print 'print'
for exp in expressions:
    print infix_to_postfix(exp)
    print '\n'



