# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


# Fuerza bruta
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        maximo = 0
        n = len(s)
        for i in range(n):
            for j in range(i, n):
                string = s[i : j + 1]
                if string == string[::-1]:
                    if maximo < len(string):
                        maximo = len(string)
                        res = string
        return res


# Otra solución
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        maximo = 0
        n = len(s)
        for i in range(n):
            actual1 = s[i]
            actual2 = s[i]
            l = i - 1
            r = i + 1
            while l > -1 and r < n:
                if s[l] == s[r]:
                    actual1 = s[l : r + 1]
                else:
                    break
                l -= 1
                r += 1
            l = i
            r = i + 1
            while l > -1 and r < n:
                if s[l] == s[r]:
                    actual2 = s[l : r + 1]
                else:
                    break
                l -= 1
                r += 1
            if len(actual2) > maximo:
                res = actual2
                maximo = len(actual2)
            elif len(actual1) > maximo:
                res = actual1
                maximo = len(actual1)
        return res


# s = Solution()
# s.longestPalindrome("babad")
# print("////////////////")
# s.longestPalindrome("cbbd")
