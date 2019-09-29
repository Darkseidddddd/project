def letterCom(dic, l, digits):
    if not digits:
        return l
    l_ = []
    for s in l:
        for c in dic[digits[0]]:
            l_.append(s+c)
    return letterCom(dic, l_, digits[1:])
def letterCombinations(digits):
    if not digits:
        return []
    dic = {'2': ['a','b','c'], 
           '3': ['d','e','f'], 
           '4': ['g','h','i'], 
           '5': ['j','k','l'], 
           '6': ['m','n','o'],
           '7': ['p','q','r','s'], 
           '8': ['t','u','v'],
           '9': ['w','x','y','z']}
    return letterCom(dic, [''], digits)
    
if __name__ == '__main__':
    digits = '234'
    print(letterCombinations(digits))