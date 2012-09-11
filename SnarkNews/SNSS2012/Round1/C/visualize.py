from PIL import Image, ImageDraw

d = []
f = open('.in').readlines()
for i in xrange(7):
	for j in xrange(7):
		if f[i][j] != '.':
			d.append([i + 1, j + 1, f[i][j]])

#need = 'skctebzdujqr'
need = 'sbckdeuqrjtz'

for i in xrange(len(d)):
	if d[i][2] != need[i]:
		for j in xrange(len(d)):
			if d[j][2]== need[i]:
				d[i], d[j] = d[j], d[i]
				break	

d = map(lambda x: [x[1], x[0], x[2]], d)

i = Image.new('RGB', (800, 800), 0)
c = ImageDraw.Draw(i)
c.line((0, 0, 800, 800), (0, 100, 0))
c.line((0, 800, 800, 0), (0, 100, 0))
last = d[0][:2]
for p in d:
	q = map(lambda x: x * 100, last + p[:2])
	c.line( q, fill=(255, 0, 0), width = 3)
	last = p[:2]

for p in d:
	c.text(map(lambda x: x * 100 + 5, p[:2]), p[2], fill = (255, 255, 255))

i.save('res.png')
