import sys
import wx
from Queue import Queue

SCALE = 1

def LoadMap(mapFile):
	mapData = ''.join(map(lambda x: '\n' if x == '\r' else x, open(mapFile, 'r').read())).split('\n') + ['']
	n, m = 0, 0
	M = []
	end = False
	params = {}
	for s in mapData:
		if s == '': end = True
		if not end:
			n += 1
			M.append([])
		else:
			if s.startswith('Water '):
				params['Water'] = int(s[6:])
			if s.startswith('Flooding '):
				params['Flooding'] = int(s[9:])
			if s.startswith('Waterproof '):
				params['Waterproof'] = int(s[11:])
			if s.startswith('Trampoline '):
				params[s[11]] = s[21]

	M += [[], []]
	for i in xrange(n):
		M[n - i] = ['#'] + [c for c in mapData[i]] + ['#']
		m = max(m, len(M[n - i]) - 2)
	for i in xrange(1, n + 1):
		if len(M[i]) < m + 2:
			M[i] = M[i][:-1] + ['.'] * (m + 2 - len(M[i])) + ['#']
	M[0] = '#' * (m + 2)
	M[n+1] = '#' * (m + 2)
	return n, m, M, params

class Interpret:
	def __init__(self, cmd):
		self.cmd = cmd
		self.p = 0

	def InputKey(self, q):
		pass

	def Next(self):
		ret = None if self.p == len(self.cmd) else self.cmd[self.p]
		self.p += 1
		return ret

class KBDInput:
	def __init__(self):
		self.q = Queue()

	def InputKey(self, k):
		if k == wx.WXK_DOWN:
			self.q.put('D')
		elif k == wx.WXK_RIGHT:
			self.q.put('R')
		elif k == wx.WXK_UP:
			self.q.put('U')
		elif k == wx.WXK_LEFT:
			self.q.put('L')
		elif k == 87:
			self.q.put('W')
		elif k == 65:
			self.q.put('A')
		elif k == wx.WXK_ESCAPE:
			self.q.put(None)

	def Next(self):
		if self.q.empty():
			return '!'
		return self.q.get()


if len(sys.argv) >= 3:
	cmd = Interpret(sys.argv[2])
else:
	cmd = KBDInput()
n, m, M, params = LoadMap('map.txt' if len(sys.argv) == 1 else sys.argv[1])
print n, m

DIR = {'U':0, 'R':1, 'D':2, 'L':3}
DX = (0, 1, 0, -1)
DY = (1, 0, -1, 0)


class Frame(wx.Frame):
	def __init__(self, parent, title, n, m, M, cmd, params):
		self.n = n
		self.m = m
		self.M = M
		wx.Frame.__init__(self, parent, id = -1, title = title, size = (32 * m * SCALE + 5, 32 * n * SCALE + 28), style = wx.CAPTION + wx.CLOSE_BOX)
		self.Width, self.Height = 32 * m , 32 * n
		self.cmd = cmd
		self.Lambda = 0
		self.MaxLambda = 0
		self.Score = 0

		self.waterlevel = params['Water'] if 'Water' in params else 0
		self.waterproof = params['Waterproof'] if 'Waterproof' in params else 10
		self.flooding = params['Flooding'] if 'Flooding' in params else 10**9
		self.target = {}
		for c in 'ABCDEFGHI':
			if c in params:
				self.target[c] = params[c]
		self.watertick = 0
		self.underwater = -1
	
		self.timer = wx.Timer(self)
		self.timer.Start(milliseconds = 50)
		self.lifeInterval = 100
		self.paintInterval = 25
		self.paintTime = 0
		self.lifeTime  = 0
		self.iterations = 0

		self.Bind(wx.EVT_TIMER, self.OnTimer)
		self.Bind(wx.EVT_PAINT, self.OnPaint)
		self.Bind(wx.EVT_KEY_DOWN, self.OnKeyDown)

		M = self.M
		for i in xrange(1, n + 1):
			for j in xrange(1, m + 1):
				if M[i][j] == 'R':
					self.rx = j
					self.ry = i
				elif M[i][j] == '\\':
					self.MaxLambda += 1
		self.U = [[0 for j in range(0, m + 2)] for i in range(0, n + 2)]

		self.Sprites = {}
		LoadList = (
			('R', 'pic/robot.png'),
			('\\', 'pic/lambda.png'),
			('#', 'pic/brick.png'),
			('*', 'pic/stone.png'),
			('L', 'pic/lift_closed.png'),
			('O', 'pic/lift_opened.png'),
			('.', 'pic/ground.png'),
		)
		LoadList += tuple([(chr(c), 'pic/portal_in.png') for c in xrange(65, 75)])
		LoadList += tuple([(chr(c), 'pic/portal_out.png') for c in xrange(49, 59)])

		for p in LoadList:
			pic = wx.Bitmap(p[1])
#			pic.SetMask(wx.Mask(pic, '#000000'))
			self.Sprites[p[0]] = pic

		self.BufferBMP = wx.EmptyBitmap(self.Width * SCALE, self.Height * SCALE)
		self.SetBackgroundStyle(wx.BG_STYLE_CUSTOM)
		self.Centre()
		self.RePaint()
		self.Show()

	def OnPaint(self, event):
		dc = wx.BufferedPaintDC(self, self.BufferBMP, wx.BUFFER_VIRTUAL_AREA)
		event.Skip()


	def RePaint(self):
		dc = wx.BufferedDC(None, self.BufferBMP)
		self.Draw(dc)
		del dc
		self.Refresh()
		self.Update()

	def Draw(self, dc):
		dc.BeginDrawing()
		dc.SetUserScale(SCALE, SCALE)
		dc.SetLogicalFunction(wx.COPY)
#		dc.SetBackground(wx.Brush('#000000'))
		dc.SetBrush(wx.Brush('#000000'))
#		dc.Clear()

		 
		curit = self.iterations
		M, U = self.M, self.U
		for i in range(1, n + 1):
			for j in range(1, m + 1):
				if U[i][j] < curit: continue
				if M[i][j] == ' ':
					dc.DrawRectangle(j * 32 - 32, self.Height - i * 32, 32, 32)
				else: 
					dc.DrawBitmap(self.Sprites[M[i][j]], x = j * 32 - 32, y = self.Height - i * 32, useMask = True)
				
		dc.SetLogicalFunction(wx.OR)
		dc.SetBrush(wx.Brush('#0000FF'))
		dc.DrawRectangle(0, self.Height - self.waterlevel * 32, self.Width, 400)

		dc.EndDrawing()

	def Move(self, c):
		M, U = self.M, self.U
		print c, 
		self.Score -= 1
		if c == 'A': return self.Stop()
		if c == 'W': return
		dirId = DIR[c]
		newx = self.rx + DX[dirId]
		newy = self.ry + DY[dirId]
		if M[newy][newx] in ' .\\O':
			if M[newy][newx] == '\\':
				self.Lambda += 1
				self.Score += 25
			if M[newy][newx] == 'O':
				self.Score += self.Lambda * 50
				print 'Win'
				self.Stop()
			M[newy][newx] = 'R'
			U[newy][newx] = self.iterations
			M[self.ry][self.rx] = ' '
			U[self.ry][self.rx] = self.iterations
			self.rx = newx
			self.ry = newy
			return
		if c == 'R' and M[newy][newx] == '*' and M[self.ry][self.rx + 2] == ' ':
			M[self.ry][self.rx + 2] = '*'
			U[self.ry][self.rx + 2] = self.iterations
			M[newy][newx] = 'R'
			U[newy][newx] = self.iterations
			M[self.ry][self.rx] = ' '
			U[self.ry][self.rx] = self.iterations
			self.rx = newx
			self.ry = newy
			return
		if c == 'L' and M[newy][newx] == '*' and M[self.ry][self.rx - 2] == ' ':
			U[self.ry][self.rx - 2] = self.iterations
			M[self.ry][self.rx - 2] = '*'
			M[newy][newx] = 'R'
			U[newy][newx] = self.iterations
			M[self.ry][self.rx] = ' '
			U[self.ry][self.rx] = self.iterations
			self.rx = newx
			self.ry = newy
			return
		if M[newy][newx] in 'ABCDEFGHI':
			target = self.target[M[newy][newx]]
			for i in xrange(1, n + 1):
				for j in xrange(1, m + 1):
					if M[i][j] == target:
						U[self.ry][self.rx] = self.iterations
						M[self.ry][self.rx] = ' '
						M[i][j] = 'R'
						U[i][j] = self.iterations
						self.rx = j
						self.ry = i
					elif M[i][j] in 'ABCDEFGHI' and self.target[M[i][j]] == target:
						M[i][j] = ' '
						U[i][j] = self.iterations
			return


	def UpdateGame(self):
		M, U = self.M, self.U
		for y in range(1, n + 1):
			for x in xrange(1, m + 1):
				if M[y][x] == '*' and M[y - 1][x] == ' ':
					M[y][x] = ' '
					M[y - 1][x] = '*'
					U[y][x] = self.iterations
					U[y - 1][x] = self.iterations
				elif M[y][x] == '*' and M[y - 1][x] == '*' and M[y][x + 1] == ' ' and M[y - 1][x + 1] == ' ':
					M[y][x] = ' '
					M[y - 1][x + 1] = '*'
					U[y][x] = self.iterations
					U[y - 1][x + 1] = self.iterations
				elif M[y][x] == '*' and M[y - 1][x] == '*' and M[y][x - 1] == ' ' and M[y - 1][x - 1] == ' ':
					M[y][x] = ' '
					M[y - 1][x - 1] = '*'
					U[y][x] = self.iterations
					U[y - 1][x - 1] = self.iterations
				elif M[y][x] == '*' and M[y - 1][x] == '\\' and M[y][x + 1] == ' ' and M[y - 1][x + 1] == ' ':
					M[y][x] = ' '
					M[y - 1][x + 1] = '*'
					U[y][x] = self.iterations
					U[y - 1][x + 1] = self.iterations
				elif M[y][x] == 'L' and self.Lambda == self.MaxLambda:
					M[y][x] = 'O'					
					U[y][x] = self.iterations
		self.watertick += 1
		if self.watertick == self.flooding:
			self.watertick = 0
			self.waterlevel += 1

	def LifeTick(self):
		c = self.cmd.Next()
		if c == None or c == '':
			self.Score += self.Lambda * 25
			return self.Stop()
		if c == '!': return

		M, U = self.M, self.U
		self.iterations += 1
		self.Move(c)
		self.UpdateGame()

		if self.ry <= self.waterlevel:
			self.underwater += 1
			if self.underwater > self.waterproof:
				print 'WaterLose'
				self.Stop()
		else:
			self.underwater = -1
		if M[self.ry + 1][self.rx] == '*' and U[self.ry + 1][self.rx] == self.iterations:
			print 'Lose'
			self.Stop()

	def Stop(self):
		self.timer.Stop()
		wx.MessageBox('Modeling finished\nIterations: %d\nScore: %d' % (self.iterations, self.Score), 'Finished', wx.OK | wx.ICON_INFORMATION)

	def OnKeyDown(self, event):
		if event.GetKeyCode() == wx.WXK_SPACE:
			if self.timer.IsRunning():
				self.timer.Stop()
			else:
				self.timer.Start()
		else:
			cmd.InputKey(event.GetKeyCode())
		event.Skip()


	def OnTimer(self, event):
		self.lifeTime += 50
		self.paintTime += 50

		while self.lifeTime >= self.lifeInterval:
			self.lifeTime -= self.lifeInterval
			self.LifeTick()

		while self.paintTime >= self.paintInterval:
			self.paintTime -= self.paintInterval
			self.RePaint()
			event.Skip()


app = wx.App(False)
frame = Frame(None, 'ICFP', n, m, M, cmd, params)
app.MainLoop()
