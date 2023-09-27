# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []
        self.back(res, n, n, "")
        return res

    def back(self, res: list, up: int, down: int, act: str) -> None:
        if up == 0 and down == 0:
            res.append(act)
        elif up > 0 and up == down:
            self.back(res, up - 1, down, act + "(")
        elif up > 0 and down > up:
            self.back(res, up - 1, down, act + "(")
            self.back(res, up, down - 1, act + ")")
        elif up == 0:
            self.back(res, up, down - 1, act + ")")
