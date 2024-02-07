def is_tree(n, adjacency_matrix):
    visited = [False] * n
    stack = [0]  
    visited[0] = True

    while stack:
        current_vertex = stack.pop()
        for neighbor in range(n):
            if adjacency_matrix[current_vertex][neighbor] == 1 and not visited[neighbor]:
                stack.append(neighbor)
                visited[neighbor] = True

    if False in visited:
        return "No"  

    edges_count = sum(sum(row) for row in adjacency_matrix) // 2
    if edges_count != n - 1:
        return "No"  

    return "Yes"

with open("input.txt", "r") as file:
    n = int(file.readline().strip())
    adjacency_matrix = [list(map(int, file.readline().split())) for _ in range(n)]

result = is_tree(n, adjacency_matrix)

with open("output.txt", "w") as file:
    file.write(result + "\n")
