T = int(raw_input())
while T:
	T -= 1
	n, p = map(int, raw_input().split())
	nn, prod = n, 1
	while nn > 0:
		prod *= nn % p + 1
		nn /= p
	print n + 1 - prod
