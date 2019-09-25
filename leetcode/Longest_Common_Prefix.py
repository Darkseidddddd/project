def longestCommonPrefix(s):
    i = 0
    if len(s) == 0:
        return ''
    if len(s[0]) == 0:
        return ''
    while True:
        if i == len(s[0]):
            return s[0][0:i]
        c = s[0][i]
        for s_ in s:
            if i == len(s_):
                return s[0][0:i]
            if s_[i] != c:
                return s[0][0:i]
        i += 1
    return ''


def longestCommonPrefix_(s):
    if not s:
        return ''
    res = s[0]
    i = 1
    while i < len(s):
        while s[i].find(res) != 0:
            res = res[:len(res)-1]
        i += 1
    return res

if __name__ == '__main__':
    s = ['flow', 'flower', 'flew']
    print(longestCommonPrefix(s))