def isPalindrome(s):
    if s == s[::-1]:
        return len(s)
    return 0
def longestPalindrome(s):
    i, j = 0, len(s)-1
    l, max_l = 0, 0
    if j <= 0:
        return s
    max_s = s[0]
    while j > 0:
        while i < j:
            l = isPalindrome(s[i:j+1])
            if l > max_l:
                max_l = l
                max_s = s[i:j+1]
                break
            i += 1
        j -= 1
        i = 0
    return max_s

def longestPalindrome_(s):
    if (len(s) <= 1) or s == s[::-1]:
        return s
    start = 0
    maxlen = 0
    for i in range(len(s)):
        str1 = s[i - maxlen: i + 1]
        str2 = s[i - maxlen - 1: i + 1]
        
        if (i - maxlen) >= 0 and (str1 == str1[::-1]):
            start, maxlen = i - maxlen, len(str1)
        if (i - maxlen - 1) >= 0 and (str2 == str2[::-1]):
            start, maxlen = i - maxlen - 1, len(str2)
    return s[start: start + maxlen]

if __name__ == '__main__':
    s = 'aaaaa'
    print(longestPalindrome_(s))