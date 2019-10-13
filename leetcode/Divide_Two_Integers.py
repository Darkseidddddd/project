def divide(dividend, divisor):
    dividend_ = abs(dividend)
    divisor_ = abs(divisor)
    quotient = 0
    for i in range(32)[::-1]:
        if (dividend_ >> i) >= divisor_:
            quotient += (1 << i)
            dividend_ -= (divisor_ << i)
    if dividend ^ divisor < 0:
        return -quotient
    return quotient

def divide_(dividend, divisor):
    dividend_ = abs(dividend)
    divisor_ = abs(divisor)
    quotient = 0
    i = 0
    while divisor_ <= dividend_:
        divisor_ <<= 1
        i += 1
    while i > 0:
        i -= 1
        divisor_ >>= 1
        if divisor_ <= dividend_:
            quotient += (1 << i)
            dividend_ -= divisor_
    if dividend ^ divisor < 0:
        quotient = -quotient
    if quotient >= 2**31:
        quotient -= 1
    return quotient
        

if __name__ == '__main__':
    dividend = 7
    divisor = -3
    print(divide_(dividend, divisor))