with open('input.txt', 'r') as fin:
    
    line=fin.readline()
    n=int(line)
    d= [0] * int(n)
    with open('output.txt', 'w') as fout:   
        for line in fin:
            a, b = line.split()
            a=int(a)
            b=int(b)
            d[b-1]=a

        for k in range(n):
            fout.write(str(d[k])+' ')
