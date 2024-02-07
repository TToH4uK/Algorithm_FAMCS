def position(first, second, matrix):
    return matrix[first][second]

def is_reacts(first, second, matrix):
    return matrix[first][second] != 0

def main():
    with open("in.txt", "r") as infile:
        n, m = map(int, infile.readline().split())
        matrix = [list(map(int, infile.readline().split())) for _ in range(n)]
        stack = list(map(int, infile.readline().split()))

    answer = []

    for elem in stack:
        answer.append(elem)

        while len(answer) > 1 and is_reacts(answer[-1] - 1, answer[-2] - 1, matrix):
            answer[-2] = position(answer[-1] - 1, answer[-2] - 1, matrix)
            answer.pop()

    with open("out.txt", "w") as outfile:
        outfile.write(" ".join(map(str, answer[::-1])))


main()
