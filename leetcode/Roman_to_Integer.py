def romanToInt(s):
    s = s[::-1]
    dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M':1000}
    last = 1
    sum = 0
    for i in range(len(s)):
        if dic[s[i]] < last:
            sum -= dic[s[i]]
        else:
            sum += dic[s[i]]
        last = dic[s[i]]
    return sum

if __name__ == '__main__':
    s = 'XVIII'
    print(romanToInt(s))