mem = {}
def solve(n, k):
    if k == 0 or n == k: return 1
    if (n, k) in mem: return mem[(n, k)]
    t = solve(n + 1, k) - solve(n, k - 1)
    mem[(n, k)] = t
    return t
