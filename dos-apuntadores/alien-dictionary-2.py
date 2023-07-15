# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

def is_alien_sorted(words, orden):
    dic={}
    for i in range(26):
        dic[words[i]]=i
    n=len(words) 
    for j in range(n-1): #O(n*m)
      if not comparar(words[j], words[j+1]):
          return False
    return True
      
def comparar(dic, word1, word2):
    n=min(len(word1), len(word2)) 
    for k in range(n): #O(m)
        if dic[word1[k]]<dic[word2[k]]:
            return True
        elif dic[word1[k]]>dic[word2[k]]:
            return False
    return len(word1)<=len(word2)

#La complejidad es O(n) porque las constantes se desprecian
if __name__=="__main__":
    words=input().split()
    orden=input()
    print(is_alien_sorted(words, orden))