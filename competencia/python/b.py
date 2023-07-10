def formarCombates(string):
    reto = ""
    lens = len(string)
    for i in range(lens):
        reto = string[0] + " " + string[1]
        combates.append(reto)
        formarCombates(string[1:])
        formarCombates(string[:1])


cases = int(input())
for case in range(cases):
    n, k = list(map(int, input().split()))
    if n % 2 != 0:
        print("Impossible")
        continue
    caballeros = []
    for i in range(1, n + 1):
        caballeros.append(str(i))
    combates = []
    formarCombates("".join(caballeros))
    combates.sort()
    for combate in combates:
        print(combate)
