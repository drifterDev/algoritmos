# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

def searchMatriz(matriz: list[list[int]], target:int)->bool:
    izq=0
    der=len(matriz)-1
    while izq<der:
        mitad=izq+(der-izq)//2 +1
        if matriz[mitad][0]==target:
            return True
        if matriz[mitad][0]<target:
            izq=mitad
        else:
            der=mitad-1
    fila=matriz[izq]
    izq=0
    der=len(fila)-1
    while izq<=der:
        mitad=izq+(der-izq)//2
        if fila[mitad]==target:
            return True
        if fila[mitad]<target:
            izq=mitad+1
        else:
            der=mitad-1
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