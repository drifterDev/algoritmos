#Busqueda binaria
#Algoritmo para hacer una busqueda en una lista ordenada en O(Log n)

def busqueda_binaria(array, target):
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = (low + high) // 2
        # Verificar si el valor medio es igual al objetivo
        if array[mid] == target:
            return mid
        # Si el valor medio es mayor que el objetivo, buscar en la mitad izquierda
        elif array[mid] > target:
            high = mid - 1
        # Si el valor medio es menor que el objetivo, buscar en la mitad derecha
        else:
            low = mid + 1
    # Si no se encuentra el objetivo, devolver -1
    return -1

# Ejemplo de uso
array = list(map(int, input().split()))
target =int(input("Objetivo: "))

result = busqueda_binaria(array, target)
if result != -1:
    print("El objetivo",target,"se encontró en el índice",result)
else:
    print("El objetivo",target,"no se encontró en el arreglo")
