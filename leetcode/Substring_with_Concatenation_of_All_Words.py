def findSubstring(s, words):
    if not s or not words:
        return []
    words.sort()
    res = []
    one_word = len(words[0])
    n = len(s)
    total_len = one_word*len(words)
    for i in range(0, n-total_len+1):
        s_ = s[i:i+total_len]
        temp = []
        while s_:
            temp.append(s_[0:one_word])
            s_ = s_[one_word:]  
        temp.sort()
        #print(temp)
        if temp == words:
            res.append(i)
    return res
        
if __name__ == '__main__':
    s = "lingmindraboofooowingdingbarrwingmonkeypoundcake"
    words = ["fooo","barr","wing","ding","wing"]
    print(findSubstring(s, words))        