def reverse(x):
    sum = 0
    symbol = x//abs(x)
    x = abs(x)
    while x != 0:
        sum = sum*10 + x%10
        x //= 10
    return symbol*sum

def reverse_(x):
    MAX_VALUE=2147483647
    MIN_VALUE=-2147483648
    s = str(x)
    s = s[::-1]
    if s[-1] == '-':
        s = -int(s[:-1])
    else:
        s = int(s)
    if s > MAX_VALUE or s < MIN_VALUE:
        return 0
    return s

if __name__ == '__main__':
    x = 99909090
    print(reverse_(x))