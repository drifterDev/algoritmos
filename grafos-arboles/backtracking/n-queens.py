# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#     El rompecabezas de n reinas es el problema de colocar n reinas en un tablero de ajedrez de n x n de manera que ninguna de ellas se ataque mutuamente.
# Dado un número entero n, devuelva todas las soluciones distintas del rompecabezas de n reinas. Puede devolver la respuesta en cualquier orden. Cada solución contiene una configuración del tablero distinta de la colocación de n reinas, donde “Q” y “.” indican una reina y un espacio vacío, respectivamente.

# Ejemplo 1:
# queens.png

# Entrada: n = 4
# Salida: [[".Q…","…Q",“Q…”,"…Q."],["…Q.",“Q…”,"…Q",".Q…"]]
# Explicación: Existen dos soluciones distintas al rompecabezas de las 4 reinas como se muestra arriba


class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        res = []
        self.dfs([-1] * n, 0, [], res)
        return res

    def dfs(self, numeros, apuntador, construccionActual, res):
        if apuntador == len(numeros):
            res.append(construccionActual)
            return
        for i in range(len(numeros)):
            numeros[apuntador] = i
            if self.valid(numeros, apuntador):
                tmp = "." * len(numeros)
                self.dfs(
                    numeros.copy(),
                    apuntador + 1,
                    construccionActual + [tmp[:i] + "Q" + tmp[i + 1 :]],
                    res,
                )

    def valid(self, numeros, apuntador):
        for i in range(apuntador):
            if (
                abs(numeros[i] - numeros[apuntador]) == abs(apuntador - i)
                or numeros[i] == numeros[apuntador]
            ):
                return False
        return True
