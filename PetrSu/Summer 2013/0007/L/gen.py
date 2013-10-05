import random

n = 60
k = 5000000 / n

st = ''
fin = ''

print n, k
for i in xrange(n):
	st += random.choice(['0', '1'])
	fin += random.choice(['0', '1'])
print st, fin

for i in xrange(k):
	a = ''
	for i in xrange(n):
		a += random.choice(['0', '1'])
	print a
