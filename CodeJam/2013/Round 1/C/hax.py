import sys, os, random, string

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline


d = [s.strip() for s in open('dict.txt')]
s = ''
while len(s) < 4000:
    s += random.choice(d)

for i in xrange(4000):
    if random.randint(0, 10) == 0:
        s = s[:i] + 'a' + s[i + 1:]
print s[:4000]