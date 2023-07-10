# Dada una matriz de enteros distintos candidatos y un entero objetivo, devuelve una lista de todas las combinaciones únicas de candidatos en las que los números elegidos suman el objetivo. Puede devolver las combinaciones en cualquier orden. El mismo número puede ser elegido entre los candidatos un número ilimitado de veces. Dos combinaciones son únicas si la frecuencia de al menos uno de los números elegidos es diferente. Los casos de prueba se generan de forma que el número de combinaciones únicas que suman el objetivo sea inferior a 150 combinaciones para la entrada dada.

# Ejemplo 1:
# Entrada: candidatos = [2,3,6,7], objetivo = 7
# Salida: [[2,2,3],[7]]
# Explicación: 2 y 3 son candidatos, y 2 + 2 + 3 = 7. Nótese que 2 puede usarse varias veces. 7 es un candidato, y 7 = 7. Estas son las dos únicas combinaciones.


def combinationSum(candidatos: list[int], target: int) -> list[list[int]]:
    def dfs(sobrante, pila, resultado):
        if sobrante == 0:
            resultado.append(pila.copy())
            return
        for numero in candidatos:
            if numero > sobrante:
                return
            if not pila or pila[-1] <= numero:
                dfs(sobrante - numero, pila + [numero], resultado)

    resultado = []
    candidatos.sort()
    dfs(target, [], resultado)
    return resultado


nums = list(map(int, input().split()))
target = int(input())
print(combinationSum(nums, target))
