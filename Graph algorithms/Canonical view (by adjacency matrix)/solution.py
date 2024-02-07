def build_canonical_representation(n, adjacency_matrix):
    parent = [0] * (n + 1)

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if adjacency_matrix[i - 1][j - 1] == 1:
                parent[j] = i
                
    return parent[1:]
  
with open("input.txt", "r") as file:
    n = int(file.readline().strip())
    adjacency_matrix = [list(map(int, file.readline().split())) for _ in range(n)]

result = build_canonical_representation(n, adjacency_matrix)

with open("output.txt", "w") as file:
    file.write(" ".join(map(str, result)))
