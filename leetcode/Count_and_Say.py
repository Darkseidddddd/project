def countAndSay(n):
    res = '1'
    for i in range(n-1):
        res_ = ''
        k = 0
        temp = res[0]
        for j in range(len(res)):
            if res[j] == temp:
                k += 1
            else:
                res_ += str(k)+temp 
                temp = res[j]
                k = 1
        res = res_ + str(k) + temp
    return res

if __name__ == '__main__':
    print(countAndSay(5))