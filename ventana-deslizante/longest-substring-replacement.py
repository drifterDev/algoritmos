class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        inicio = 0
        maximo = 0
        n = len(s)
        letras = {}
        len_cadena = 0
        res = 0
        for i in range(n):
            try:
                letras[s[i]] += 1
            except:
                letras[s[i]] = 1
            finally:
                for key in letras:
                    maximo = max(letras[key], maximo)
                len_cadena += 1
                if len_cadena - maximo > k:
                    letras[s[inicio]] -= 1
                    len_cadena -= 1
                    inicio += 1
                res = max(len_cadena, res)
        return res
