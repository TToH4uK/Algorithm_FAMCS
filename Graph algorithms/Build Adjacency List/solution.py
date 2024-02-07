with open("input.txt", "r") as input_file:
    n, m = map(int, input_file.readline().split())

    adjacency_list = {i: set() for i in range(1, n + 1)}

    for _ in range(m):
        u, v = map(int, input_file.readline().split())
        adjacency_list[u].add(v)
        adjacency_list[v].add(u)

with open("output.txt", "w") as output_file:
    for i in range(1, n + 1):
        output_file.write(f"{len(adjacency_list[i])} {' '.join(map(str, adjacency_list[i]))}\n")
