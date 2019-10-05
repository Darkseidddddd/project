def generatePar(res, n, l, r, s):
    if l+r == 2*n and l == r:
        res.append(s)
        return
    if l < n:
        generatePar(res, n, l+1, r, s+'(')
    if l-r > 0:
        generatePar(res, n, l, r+1, s+')')
def generateParenthesis(n):
    res = []
    generatePar(res, n, 0, 0, '')
    return res

def generateParenthesis_(n):
    res = ['(']
    while res:
        temp = []
        if len(res[0]) == 2*n:
            return res
        for s in res:
            if s.count('(') < n:
                temp.append(s+'(')
            if s.count(')') < s.count('('):
                temp.append(s+')')
            res = temp
    return res

if __name__ == '__main__':
    n = 4
    print(generateParenthesis_(n))