
# uses the python 'gotcha' of mutable default arguments
def generateParenthesis(n):
    def generate(p, left, right, parens=[]):
            parens))
        if left:
            generate(p + '(', left-1, right)
        if right > left:
            generate(p + ')', left, right-1)
        if not right:
            parens += p,
            parens, parens))
        return parens
    return generate('', n, n)

print(generateParenthesis(3))
