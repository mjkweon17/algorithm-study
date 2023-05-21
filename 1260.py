# https://www.acmicpc.net/source/61088456
# https://www.acmicpc.net/source/61089342

# https://www.acmicpc.net/source/61089678
import sys
from collections import deque

read = sys.stdin.readline

def dfs(graph, v, visited):
    print()


N, M, V = map(int, read().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, read().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N + 1):
    graph[i].sort()
visited = [False] * (N + 1)