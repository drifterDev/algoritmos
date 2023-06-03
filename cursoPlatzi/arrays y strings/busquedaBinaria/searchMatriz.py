def searchMatriz(matriz, target):
    izq=0
    columns=len(matriz[0])
    der=len(matriz)*columns-1
    while izq<=der:
        mitad=izq+(der-izq)//2
        puntero=matriz[mitad//columns][mitad%columns]
        if puntero==target:
            return True
        elif target<puntero:
            der=mitad-1
        else:
            izq=mitad+1
    return False
            
#Complejidad O(log(n))
if __name__=="__main__":
    n, m, target=list(map(int, input().split()))
    matriz=[]
    for i in range(n):
        matriz.append(list(map(int, input().split())))
    if searchMatriz(matriz, target):
        print("YES")
    else:
        print("NO")