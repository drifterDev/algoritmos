# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Forma corta


class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(n):
            res += 1
            res += self.palindomos(s, i - 1, i + 1)
            res += self.palindomos(s, i, i + 1)
        return res

    def palindromos(self, s: str, l: int, r: int) -> int:
        res = 0
        n = len(s)
        while l > -1 and r < n:
            if s[l] == s[r]:
                res += 1
            else:
                break
            l -= 1
            r += 1
        return res


# Forma larga


class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(n):
            res += 1
            l = i - 1
            r = i + 1
            while l > -1 and r < n:
                if s[l] == s[r]:
                    res += 1
                else:
                    break
                l -= 1
                r += 1
            l = i
            r = i + 1
            while l > -1 and r < n:
                if s[l] == s[r]:
                    res += 1
                else:
                    break
                l -= 1
                r += 1
        return res
