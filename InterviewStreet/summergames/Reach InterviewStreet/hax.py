

DXY = ((2, 1), (2, -1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2))
Intersect = {}

def IsIntersect(p1, p2, p3, p4):
	if p1 == p3 and p2 == p4 or p1 == p4 and p2 == p3:
		return True
	if p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4:
		return False

	a = p2[1] - p1[1]
	b = p1[0] - p2[0]
	c = -p1[0] * a - p1[1] * b
	if (a * p3[0] + b * p3[1] + c) * (a * p4[0] + b * p4[1] + c) > 0:
		return False

	a = p4[1] - p3[1]
	b = p3[0] - p4[0]
	c = -p3[0] * a - p3[1] * b
	if (a * p1[0] + b * p1[1] + c) * (a * p2[0] + b * p2[1] + c) > 0:
		return False
	
	return True

def RecWay(f, x, y, pt, ans):
	ans.append( f[x][y] )
	pt.append( (x, y) )

	f[x][y] = '#'
	moves = 0

	for dx, dy in DXY:
		xx = dx + x
		yy = dy + y

		if xx < 0 or xx > 5: continue
		if yy < 0 or yy > 5: continue
		if f[xx][yy] == '#': continue

		bad = False
		for p1, p2 in zip(pt[:-2], pt[1:-1]):
			if Intersect[ (p1, p2, pt[-1], pt[-2]) ]:
				bad = True
				break
		if bad: continue

		moves = 1
		RecWay(f, x + dx, y + dy, pt, ans)

	if moves == 0:
		print ''.join(ans)

	f[x][y] = ans[-1]
	del ans[-1]
	del pt[-1]
		

f = [	list('A..5PD')
	  , list('TVDASO')
	  , list('C.AM.4')
	  , list('3S..N.')
	  , list('WI5.7E')
	  , list('1.F429')
	]

for i in xrange(6):
	for j in xrange(6):
		for dx, dy in DXY:
			xx, yy = i + dx, j + dy
			if xx < 0 or xx > 5: continue
			if yy < 0 or yy > 5: continue
			for ii in xrange(6):
				for jj in xrange(6):
					if ii == i and jj == j: continue
					if ii == xx and jj == yy: continue
					for dxx, dyy in DXY:
						xxx, yyy = ii + dxx, jj + dyy
						if xxx < 0 or xxx > 5: continue
						if yyy < 0 or yyy > 5: continue
						Intersect[((i, j), (xx, yy), (ii, jj), (xxx, yyy))] = IsIntersect((i, j), (xx, yy), (ii, jj), (xxx, yyy))

RecWay(f, 5, 0, [], [])
