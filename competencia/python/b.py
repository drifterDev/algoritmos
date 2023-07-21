cases = int(input())
for i in range(cases):
    n = int(input())
    mayor = 0
    index = 0
    for i in range(n):
        a, b = map(int, input().split())
        if a <= 10:
            if b > mayor:
                index = i
                mayor = b
    print(index + 1)
