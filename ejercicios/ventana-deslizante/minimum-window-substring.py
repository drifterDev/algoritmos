# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(s)
        m = len(t)
        if m > n:
            return ""
        elif m == n:
            return s if sorted(list(s)) == sorted(list(t)) else ""
        else:
            minimo = 10**5
            res = ""
            letras = {}
            for j in range(m):
                try:
                    letras[t[j]] += 1
                except:
                    letras[t[j]] = 1
            tiene = {}
            comienza = 0
            for i in range(n):
                if s[i] in letras:
                    if s[i] in tiene:
                        tiene[s[i]] += 1
                    else:
                        tiene[s[i]] = 1
                correcto = len(letras) == len(tiene)
                if correcto:
                    vamos = True
                    for key in letras:
                        if letras[key] > tiene[key]:
                            vamos = False
                            break
                    if vamos:
                        while vamos:
                            comienza += 1
                            if s[comienza - 1] in tiene:
                                tiene[s[comienza - 1]] -= 1
                            vamos = True
                            for key in letras:
                                if letras[key] > tiene[key]:
                                    vamos = False
                                    break
                            if not vamos:
                                if res == "" or len(res) > len(s[comienza - 1 : i + 1]):
                                    res = s[comienza - 1 : i + 1]
            return res
