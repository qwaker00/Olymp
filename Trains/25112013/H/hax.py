import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

out = open('ans', 'w')
print 100
for t in xrange(100):
    n = rand(1, 100000)
    print n, 10 * n
    l = 1
    ans = []
    for i in xrange(n):
        if l == 0:
            ans.append('F')
        else:
            ans.append('B')
        t = rand(0, 1)
        if t == 0:
            if l == 0:
                print 9, 200, 200, 1, 200
            else:
                print 9, 1, 200, 200, 200
            l = 0      
        else:
            if l == 0:
                print 9, 200, 200, 200, 1
            else:
                print 9, 200, 1, 200, 200
            l = 1
    if t == 1:
        print >>out, ''.join(ans)
    else:
        print >>out, 'IMPOSSIBLE'
