n = int(input())
for case in range(n):
    n, m = list(map(int, input().split()))
    libros = list(map(int, input().split()))
    librosGratis = libros.count(0)
    if librosGratis > m:
        print("Impossible")
    elif n == m:
        print("Richman")
    else:
        money = 0
        libros.sort()
        minimo = sum(libros[:m])
        libros.reverse()
        for i in range(n - m - 1):
            maximo = sum(libros[i : i + m])
            if minimo > maximo:
                print(maximo)
