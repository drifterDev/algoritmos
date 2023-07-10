# Dado un array nums de enteros distintos, devuelve todas las permutaciones posibles. Puede devolver la respuesta en cualquier orden.

# Ejemplo 1:
# Entrada: nums = [1,2,3]
# Salida: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

# Ejemplo 2:
# Entrada: nums = [0,1]
# Salida: [[0,1],[1,0]]


def permute(numeros):
    def dfs(listaNumeros, combinaciónActual, permutaciones):
        if not listaNumeros:
            permutaciones.append(combinaciónActual)
        for i in range(len(listaNumeros)):
            dfs(
                listaNumeros[:i] + listaNumeros[i + 1 :],
                combinaciónActual + [listaNumeros[i]],
                permutaciones,
            )

    permutaciones = []
    dfs(numeros, [], permutaciones)
    return permutaciones


print(permute([1, 0]))
print(permute([1, 2, 3]))
