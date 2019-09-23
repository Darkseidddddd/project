def intToRoman(num):
    dic = {0: '', 1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC', 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
    index = [1,4,5,9]
    res = ''
    s = str(num)
    for i in range(len(s)):
        j = len(s) - int(i) - 1
        m = 0
        for k in index:
            if int(s[i]) >= k:
                m = k
        n = int(s[i])-m
        m = m * 10**j
        res = res + dic[m] + dic[10**j]*n
            
    return res

def intToRoman_(num):
    res = ''
    if num >= 1000:
        res += 'M'*(num//1000)
        num %= 1000
    if num >= 900:
        res += 'CM'
        num %= 900
    if num >= 500:
        res += 'D'
        #res += 'C'*(num//100-5)
        num %= 500
    if num >= 400:
        res += 'CD'
        num %= 400
    if num >= 100:
        res += 'C'*(num//100)
        num %= 100
    if num >= 90:
        res += 'XC'
        num %= 90
    if num >= 50:
        res += 'L'
        #res += 'X'*(num//10-5)
        num %= 50
    if num >= 40:
        res += 'XL'
        num %= 40
    if num >= 10:
        res += 'X'*(num//10)
        num %= 10
    if num >= 9:
        res += 'IX'
        num %= 9
    if num >= 5:
        res += 'V'
        #res += 'I'*(num-5)
        num %= 5
    if num >= 4:
        res += 'IV'
        num %= 4
    if num >= 1:
        res += 'I'*num
    return res

if __name__ == '__main__':
    num = 40
    print(intToRoman_(num))