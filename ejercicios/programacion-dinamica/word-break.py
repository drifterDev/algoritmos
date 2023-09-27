# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        dp = {}
        n = len(s)
        primera_vez = True
        for i in range(n):
            if primera_vez:
                for word in wordDict:
                    if s[: i + 1] == word:
                        dp[i + 1] = True
                        dp[0] = True
                        primera_vez = False
                        break
            else:
                for key in dp:
                    for word in wordDict:
                        if s[key : i + 1] == word:
                            dp[i + 1] = True
                            break
                    if i + 1 in dp:
                        break
        return True if n in dp else False


solucion = Solution()
print(solucion.wordBreak("leetcode", ["leet", "code"]))
print(solucion.wordBreak("applepenapple", ["apple", "pen"]))
print(solucion.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))
print(solucion.wordBreak("aaaaaaa", ["aaaa", "aa"]))
