print 300, 20000
it = 0
for i in xrange(1, 301):
    for j in xrange(i + 1, 301):
        it += 1
        if it > 20000: break
        print i, j, 10**9

