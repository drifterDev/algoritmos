# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dada una cadena s, se puede transformar cada letra individualmente para que sea minúscula o mayúscula para crear otra cadena. Devuelve una lista de todas las posibles cadenas que podríamos crear. Devuelve la salida en cualquier orden.

# Ejemplo 1:
# Entrada: s = "a1b2"
# Salida: [“a1b2”,“a1B2”,“A1b2”,“A1B2”]

# Ejemplo 2:
# Entrada: s = "3z4"
# Salida: [“3z4”, “3Z4”]


def letterCasePermutation(S: str) -> list[str]:
    res = []

    def dfs(permutacionActual, apuntador):
        if apuntador == len(S):
            res.append("".join(permutacionActual))
            return
        for i in set([S[apuntador].lower(), S[apuntador].upper()]):
            permutacionActual.append(i)
            dfs(permutacionActual, apuntador + 1)
            permutacionActual.pop()

    dfs([], 0)
    return res


print(letterCasePermutation("a1b2"))
print(letterCasePermutation("3z4"))
