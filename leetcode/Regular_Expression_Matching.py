import re
def isMatch(s,p):
    return s in re.findall(p,s)

def isMatch_(s,p):
    if not p:
        return not s
    first_match = p[0] in [s[0], '.']
    if len(p) > 1 and p[1] == '*':
        return first_match and isMatch(s[1:], p) or isMatch(s,p[2:])
    else:
        return first_match and isMatch(s[1:], p[1:])

if __name__ == '__main__':
    s = 'assssdfv'
    p = 'as*df.'
    print(isMatch_(s,p))