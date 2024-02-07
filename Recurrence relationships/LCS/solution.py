n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

DP = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if a[i-1] == b[j-1]:
            DP[i][j] = DP[i - 1][j - 1] + 1
        else:
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1])

print(DP[n][n])

i, j = n, n
FirstStr, SecondStr = [], []
while i > 0 and j > 0:
    if a[i-1] == b[j-1] and DP[i][j] == DP[i - 1][j - 1] + 1:
        FirstStr.append(i-1)
        SecondStr.append(j-1)
        i -= 1
        j -= 1
    elif DP[i - 1][j] > DP[i][j - 1]:
        i -= 1
    else:
        j -= 1

FirstStr.reverse()
SecondStr.reverse()
print(*FirstStr)
print(*SecondStr)
