n, p, k = map(int, raw_input().split())

res = 1
for i in xrange(n):
	res *= (i + 1)

cnt = 0
while res % p == 0:
	cnt += 1
	res /= p
print res % (p ** k), cnt