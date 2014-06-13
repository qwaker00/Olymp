
a = [0] * 1000

a[0] = [1, 0, 0]
for i in xrange(1, 100):
    l = 2 * i + 1
    a[i] = [0] * (l + 2)

    a[i][0] = a[i - 1][0]
    a[i][1] = (a[i - 1][0] + a[i - 1][1]) % 3
    for j in xrange(2, l):
        a[i][j] = (a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j - 2]) % 3
    #print ''.join(map(str, a[i][:-2]))

C = [
        [1, 0, 0],
        [1, 1, 0],
        [1, 2, 1]
]

for _i in xrange(10):
    for _j in xrange(2 * _i + 1):
        print a[_i][_j],
        i = _i + 1
        j = _j
        ans = 1
        while i > 0 or j > 0:
            ans = (ans * C[i % 3][j % 3]) % 3
            i /= 3
            j /= 3
        print ans, '   ',
    print
