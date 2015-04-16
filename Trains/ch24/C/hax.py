import decimal
from decimal import Decimal
decimal.setcontext(decimal.Context(prec=30))

inf = open("C1.in");
ouf = open("C1.out", "w");

eps = Decimal(1)
for i in xrange(10):
	eps /= 10

T = int(inf.readline())
while T > 0:
	T -= 1

	n = int(inf.readline())

	a = map(Decimal, inf.readline().split())
	b = map(Decimal, inf.readline().split())

	fnd = False
	for i in xrange(n):
		for j in xrange(n): 
			if i != j:
				for k in xrange(n): 
					if k != i and k != j:
						A1 = a[1] - a[0];
						B1 = b[j] - b[i];
						C1 = -A1 * (a[0] + a[1]) / 2 - B1 * (b[i] + b[j]) / 2;


						A2 = a[2] - a[0];
						B2 = b[k] - b[i];
						C2 = -A2 * (a[0] + a[2]) / 2 - B2 * (b[i] + b[k]) / 2;

						d = A1 * B2 - A2 * B1;
						if abs(d) < eps:
							continue

						dx = -C1 * B2 + B1 * C2;
						dy = -A1 * C2 + A2 * C1;


						cx = dx / d;
						cy = dy / d;
						rr = (cx - a[0]) ** 2 + (cy - b[i]) ** 2;

						if rr < eps:
							continue

						assert abs((cx - a[1])**2 + (cy - b[j])**2 - rr) < eps
						assert abs((cx - a[2])**2 + (cy - b[k])**2 - rr) < eps

						was = [False] * n
						for it in xrange(3, n):
							was[i] = was[j] = was[k] = True;
							for it2 in xrange(n):
								if was[it2]: continue
								if abs((cx - a[it])**2 + (cy - b[it2])**2 - rr) < eps:
									was[it2] = True
									break
							else:
								break
						else:
							fnd = True

						if fnd:
							break
			if fnd:
				break			
		if fnd:
			break			
	if fnd:
		print >>ouf, 'YES'
	else:
		print >>ouf, 'NO'
