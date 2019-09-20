def isPalindrome(x):
    return str(x) == str(x)[::-1]

if __name__ == '__main__':
    x = 121
    print(isPalindrome(x))