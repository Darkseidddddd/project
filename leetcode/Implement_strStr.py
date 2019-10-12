import re
def strStr(haystack, needle):
    if not needle:
        return 0
    m = re.search(needle,haystack)
    if m:
        return m.span()[0]
    return -1

def strStr1(haystack, needle):
    if not needle or haystack == needle:
        return 0
    if len(needle) > len(haystack):
        return -1
    i,j,k = 0,0,0
    length1 = len(haystack)
    length2 = len(needle)
    while i < length1 and j < length1:
        if haystack[j] == needle[k]:
            j += 1
            k += 1
            if k == length2:
                return j-k
        else:
            i += 1
            j = i
            k = 0
    return -1
        
def strStr2(haystack, needle):
    return haystack.find(needle)

def strStr3(haystack, needle):
    new = []
    length1 = len(haystack)
    length2 = len(needle)
    for i in range(length1-length2+1):
        new.append(haystack[i:i+length2])
    for i in new:
        if i == needle:
            return new.index(i)
    return -1

if __name__ == '__main__':
    haystack = 'qwerasdwwsw'
    needle = 'sdww'
    print(strStr3(haystack, needle))