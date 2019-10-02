def isValid(s):
    res = ''
    dic = {')': '(', ']': '[', '}': '{'}
    for ch in s:
        if ch in ['(', '[', '{']:
            res += ch
        elif len(res) != 0 and ch in dic and res[-1] == dic[ch]:
            res = res[0:-1]
        else:
            return False
    return res == ''

def isValid_(s):
    dic = {'{': '}',  '[': ']', '(': ')', '?': '?'}
    stack = ['?']
    for ch in s:
        if ch in dic:
            stack.append(ch)
        elif dic[stack.pop()] != ch:
            return False
    return stack == ['?']

if __name__ == '__main__':
    s = '[{()}]'
    print(isValid_(s))