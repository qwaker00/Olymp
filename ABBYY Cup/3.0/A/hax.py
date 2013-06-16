import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

s = raw_input()
l = len(s)
was = [False] * 256

ans = 1
let = 0
letstart = 0
for i in xrange(l):
    if s[i] == '?':
        if i > 0:
            ans *= 10
        else:
            ans *= 9
    if s[i] in 'ABCDEFGHIJ':
        if was[ord(s[i])]: continue
        was[ord(s[i])] = 1
        let += 1
        if i == 0:
            letstart = 1

if letstart == 1:
    ans *= 9
    d = 9
    for i in xrange(let - 1):
        ans *= d
        d -= 1
else:
    d = 10
    for i in xrange(let):
        ans *= d
        d -= 1

print ans
    