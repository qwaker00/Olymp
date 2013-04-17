import sys, os, random

rand = random.randint
out = sys.stdout.write
inp = sys.stdin.readline

a = rand(1, 10**20)
b = rand(1, 10**20)
c = rand(1, 10**6)

def PowMod(x, y, c):
	res = 1
	while y > 0:
		if y & 1:
			res = (res * x) % c
		x = (x * x) % c
		y >>= 1
	return res

print a
print b
print c
print PowMod(a, b, c)
