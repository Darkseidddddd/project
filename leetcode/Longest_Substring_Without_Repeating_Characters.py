def lengthOfLongestSubstring(s):
    length, res_len = 0,0
    s_ = {}
    i = 0
    head = 0
    while i < len(s):
        if s[i] in s_:
            j = s_[s[i]]
            while head <= j:
                s_.pop(s[head])
                length -= 1
                head += 1 
        else:
            length += 1
            s_[s[i]] = i
            i += 1
        if length > res_len:
            res_len = length
        #print(s_)
        #print(res_len, ' ', length)
    return res_len

def lengthOfLongestSubstring_(s):
    length = 0
    s_ = {}
    start = 0
    for i, char in enumerate(s):
        if char in s_ and s_[char] >= start:
            start = s_[char] + 1
        else:
            length = max(length, i-start+1)
        s_[char] = i
    return length

def lengthOfLongestSubstring__(s):
    length = 0
    max_length = 0
    s_ = ''
    for char in s:
        if char in s_:
            max_length = max(length, max_length)
            i = s_.index(char) + 1
            s_ = s_[i:] + char
            length = len(s_)
        else:
            s_ += char
            length += 1
        max_length = max(length, max_length)
    return max_length

if __name__ == '__main__':
    s = 'abcabcacdbaddcefa'
    print(lengthOfLongestSubstring__(s))