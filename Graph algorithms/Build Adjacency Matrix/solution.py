import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')
n, m = map(int, input().split())
matrix = [[0] * n for i in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    matrix[u - 1][v - 1] = 1
    matrix[v - 1][u - 1] = 1
for row in matrix:
    print(' '.join(map(str, row)))
