import sys

sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')


x = int(input())
y = int(input())
z = int(input())

A = input()
B = input()


dp = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]


for i in range(1, len(A) + 1):
    dp[i][0] = i * x
  
for j in range(1, len(B) + 1):
    dp[0][j] = j * y
  
for i in range(1, len(A) + 1):
    for j in range(1, len(B) + 1):
        if A[i-1] == B[j-1]:
            dp[i][j] = dp[i - 1][j - 1]
        else:
            dp[i][j] = min(dp[i - 1][j] + x, dp[i][j - 1] + y, dp[i - 1][j - 1] + z)


print(dp[len(A)][len(B)])
