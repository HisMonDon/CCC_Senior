import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)

def bfs(start, dest):
    vis = [False] * (n+1)
    q = deque([start])
    vis[start] = True
    while q:
        cur = q.popleft()
        if cur == dest: return True
        for nxt in adj[cur]:
            if not vis[nxt]:
                q.append(nxt)
                vis[nxt] = True
    return False

p, q = map(int, input().split())
if bfs(p, q):
    print('yes')
elif bfs(q, p):
    print('no')
else:
    print('unknown')
