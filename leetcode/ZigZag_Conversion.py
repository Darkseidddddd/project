def convert(s, numRows):
    if numRows == 1:
        return s
    a = 2*(numRows-1)
    b = a
    res_s = ''
    for i in range(numRows):
        j = i
        while j < len(s):
            if b == 0:
                b = a - b
                continue
            res_s += s[j]
            j += b
            b = a - b
        b = a - 2*(i+1)
    return res_s

if __name__ == '__main__':
    s = 'ABCDEFGHIJKLMNOPQRST'
    numRows = 5
    print(convert(s, numRows))