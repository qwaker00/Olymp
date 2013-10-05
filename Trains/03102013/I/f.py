import sys

t = int(raw_input())
for i in xrange(t):
    s = []
    n = int(raw_input())
    for j in xrange(n):
        s.append(raw_input())

    if i == int(sys.argv[1]):
        print 1
        print n
        print '\n'.join(s)