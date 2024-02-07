with open('input.txt', 'r') as infile:
    n = int(infile.readline())
    label_count = 1
    labels = [[0] * n for _ in range(n)]
    visited= [False] * n
    vertex = [0] * n

    for i in range(n):
        labels[i] = list(map(int, infile.readline().split()))

for i in range(n):
    if not visited[i]:
        queue = [i]
        visited[i] = True
        vertex[i] = label_count
        label_count += 1

        while queue:
            p = queue[0]
            queue = queue[1:]
            for j in range(n):
                if labels[p][j] == 1 and not visited[j]:
                    visited[j] = True
                    queue.append(j)
                    vertex[j] = label_count
                    label_count += 1

with open('output.txt', 'w') as outfile:
    for i in range(n):
        outfile.write(str(vertex[i]) + ' ')
