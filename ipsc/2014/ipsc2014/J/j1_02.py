

def solve(n, k):
    dx = [ 1, 0, -1, 0]
    dy = [ 0,-1,  0, 1]

    mem = {}

    def move(x, y, d):
        if x == k and y == n - k: return 1
        if d == 0: return 0

        if (x, y, d) in mem:
            return mem[(x, y, d)]

        sol = 0
        for i in range(4):
            sol += move(x + dx[i], y + dy[i], d - 1)

        mem[(x, y, d)] = sol
        return sol

    return move(0, 0, n)
