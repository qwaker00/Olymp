import random

print 100, 100
for i in range(100):
	print random.randint(1, 5000), 
print
for i in range(100):
	print random.randint(1, 5000), 
print
for i in range(100):
	a = []
	for j in range(100):
		if random.randint(0, 5) == 0:
			a.append(j + 1)
	print len(a), ' '.join(map(str, a))