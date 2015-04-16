n, k, m = map(int, raw_input().split())

res = 1
for i in xrange(n):
	res *= (i + 1)
for i in xrange(k):
	res /= (i + 1)
for i in xrange(n - k):
	res /= (i + 1)

print res % m	