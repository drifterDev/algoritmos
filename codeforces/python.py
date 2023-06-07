for cases in range (int(input())):
    n,k=list(map(int, input().split()))
    p=[0,]
    for i in range(k):
        p.append(2**i)
    print(p)
