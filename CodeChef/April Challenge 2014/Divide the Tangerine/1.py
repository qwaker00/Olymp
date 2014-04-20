def gcd(x, y):
    if y == 0: return x
    return gcd(y, x % y)


a = 1
for i in xrange(1, 101):
    a = a * i / gcd(a, i)
    print a