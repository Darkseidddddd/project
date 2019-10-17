def longestValidParentheses(s):
    stack, b = [], [0]*len(s)
    for i, val in enumerate(s):
        if val == '(':
            stack.append(i)
        elif stack:
            b[stack.pop()] = 1
            b[i] = 1
    num, max_num = 0, 0
    for i in b:
        if i:
            num+= 1
        else:
            max_num = max(max_num, num)
            num = 0
    
    return max(max_num, num)

if __name__ == '__main__':
    s = '((())))(())'
    print(longestValidParentheses(s))