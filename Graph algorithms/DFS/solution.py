def dfs(graph, vertex, labels, current_label):
    labels[vertex] = current_label
    current_label += 1
    for i in range(len(graph)):
        if graph[vertex][i] == 1 and labels[i] == 0:
            current_label = dfs(graph, i, labels, current_label)
    return current_label

def depth_first_search(graph):
    n = len(graph)
    labels = [0] * n
    current_label = 1

    for i in range(n):
        if labels[i] == 0:
            current_label = dfs(graph, i, labels, current_label)

    return labels

with open("input.txt", "r") as file:
    n = int(file.readline())
    adjacency_matrix = [list(map(int, file.readline().split())) for _ in range(n)]
result = depth_first_search(adjacency_matrix)
with open("output.txt", "w") as file:
    file.write(" ".join(map(str, result)))
