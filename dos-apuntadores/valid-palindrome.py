# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def isPalindrome(self, s: str) -> bool:
        letras = "qwertyuioplkjhgfdsazxcvbnm0123456789"
        s = s.lower()
        s = s.replace(" ", "")
        word = []
        for letra in s:
            if letra not in letras:
                continue
            word.append(letra)
        s = "".join(word)
        return s[:] == s[::-1]
