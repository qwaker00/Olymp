import sys

f = open('.in')
t = int(f.readline())
s = []
n = int(f.readline())
for j in xrange(n):
    s.append(f.readline())

d = set()
for i in open(sys.argv[1]):
    d.add(i)

for i in open(sys.argv[2]):
    if i not in d:
        for c in i.split():
            print s[int(c)],
        print
