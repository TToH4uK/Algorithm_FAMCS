import sys
from bisect import bisect_left

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

n = int(input())
a = list(map(int, input().split()))

cat = []
for i in range(n):
    j = bisect_left(cat, a[i])
    if j < len(cat):
        cat[j] = a[i]
    else:
       cat.append(a[i])

print(len(cat))
