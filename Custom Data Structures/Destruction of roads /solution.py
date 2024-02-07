with open("input.txt") as input_file, open("output.txt", "w") as output_file:
    n, m, q = map(int, input_file.readline().split())
    arr = [-1] * (n + 1)
    arrM = [[0, 0] for _ in range(m + 1)]
    arrQ = [0] * q
    arrE = [1] * (m + 1)
    for i in range(1, m + 1):
        arrM[i][0], arrM[i][1] = map(int, input_file.readline().split())
    for i in range(q - 1, -1, -1):
        arrQ[i] = int(input_file.readline())
        arrE[arrQ[i]] = 0
    ind = 0
    if q != m:
        for i in range(1, m + 1):
            if arrE[i]:
                temp_1 = arrM[i][0]
                temp_2 = arrM[i][1]
                while arr[temp_1] >= 0:
                    temp_1 = arr[temp_1]
                while arr[temp_2] >= 0:
                    temp_2 = arr[temp_2]
                if temp_1 != temp_2:
                    n -= 1
                    if abs(arr[temp_1]) >= abs(arr[temp_2]):
                        arr[temp_1] += arr[temp_2]
                        arr[temp_2] = temp_1
                    else:
                        arr[temp_2] += arr[temp_1]
                        arr[temp_1] = temp_2
    for index in range(q):
        temp_1 = arrM[arrQ[index]][0]
        temp_2 = arrM[arrQ[index]][1]
        while arr[temp_1] >= 0:
            temp_1 = arr[temp_1]
        while arr[temp_2] >= 0:
            temp_2 = arr[temp_2]
        if temp_1 != temp_2:
            n -= 1
            if n == 1:
                ind = index + 1
                break
            if abs(arr[temp_1]) >= abs(arr[temp_2]):
                arr[temp_1] += arr[temp_2]
                arr[temp_2] = temp_1
            else:
                arr[temp_2] += arr[temp_1]
                arr[temp_1] = temp_2
    for index in range(q):
        temp_1 = arrM[arrQ[index]][0]
        temp_2 = arrM[arrQ[index]][1]
        while arr[temp_1] >= 0:
            temp_1 = arr[temp_1]
        while arr[temp_2] >= 0:
            temp_2 = arr[temp_2]
        if temp_1 != temp_2:
            n -= 1
            if n == 1:
                ind = index + 1
                break
            if abs(arr[temp_1]) >= abs(arr[temp_2]):
                arr[temp_1] += arr[temp_2]
                arr[temp_2] = temp_1

    for i in range(q - ind):
        output_file.write('1')

    for i in range(ind):
        output_file.write('0')
