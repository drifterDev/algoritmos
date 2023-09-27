# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


def longest(string):
    sub=1
    maximo=0
    lon=0
    dic={}
    n=len(string)
    for i in range(n):
      for j in range (i, n):
        try:
            if dic[string[j]]!=sub:
              dic[string[j]]=sub
              lon+=1
            else:
              sub+=1
              break
        except:
            dic[string[j]]=sub
            lon+=1
      maximo=max(lon, maximo)
      lon=0
    return maximo

if __name__=="__main__":
    string=input()
    print(longest(string))