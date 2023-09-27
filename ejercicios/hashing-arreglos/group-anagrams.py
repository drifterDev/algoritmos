# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagrams = {}
        for string in strs:
            actual = "".join(sorted(list(string)))
            try:
                anagrams[actual].append(string)
            except:
                anagrams[actual] = [string]
        return anagrams.values()
