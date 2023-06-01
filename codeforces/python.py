# def espiral(n):
#   espiral=[]
#   for i in range (n):
#     filaAdd=[]
#     for j in range (n):
#       filaAdd.append(0)
#     espiral.append(filaAdd)
#   orientacion="derecha"
#   fila=0
#   topeIzq=0
#   topeDer=n-1
#   topeAbajo=n-1
#   topeArr=1
#   columna=0
#   while True:
#     hizo=False
#     if orientacion=="derecha":
#       if espiral[fila][columna]==0 and topeDer>columna:
#         espiral[fila][columna]="═"
#         columna+=1
#         hizo=True
#       elif espiral[fila][columna]==0:
#         espiral[fila][columna]="╗"
#         fila+=1
#         orientacion="abajo"
#         topeDer-=1
#         hizo=True
#     elif orientacion=="abajo":
#       if espiral[fila][columna]==0 and topeAbajo>fila:
#         espiral[fila][columna]="║"
#         fila+=1
#         hizo=True
#       elif espiral[fila][columna]==0:
#         espiral[fila][columna]="╝"
#         columna-=1
#         orientacion="izquierda"
#         topeAbajo-=1
#         hizo=True
#     elif orientacion=="izquierda":
#       if espiral[fila][columna]==0 and topeIzq<columna:
#         espiral[fila][columna]="═"
#         columna-=1
#         hizo=True
#       elif espiral[fila][columna]==0:
#         espiral[fila][columna]="╚"
#         fila-=1
#         orientacion="arriba"
#         topeIzq+=1
#         hizo=True
#     elif orientacion=="arriba":
#       if espiral[fila][columna]==0 and topeArr<fila:
#         espiral[fila][columna]="║"
#         fila-=1
#         hizo=True
#       elif espiral[fila][columna]==0:
#         espiral[fila][columna]="╔"
#         columna+=1
#         orientacion="derecha"
#         topeArr+=1
#         hizo=True
#     if not hizo:
#       break
#   for m in espiral:
#     print("".join(m))


# def main():
#   n=int(input("Ingresa el tamano de la espiral: "))
#   while True:
#     if n>1:
#       break
#     n=int(input("Ingresa un numero valido (Mayor que 1): "))
#   espiral(n)

# if __name__ == "__main__":
#   main()

# Crea una función que dibuje una espiral como la del ejemplo.
# - Únicamente se indica de forma dinámica el tamaño del lado.
# - Símbolos permitidos: ═ ║ ╗ ╔ ╝ ╚
# Ejemplo espiral de lado 5 (5 filas y 5 columnas):
# ════╗
# ╔══╗║
# ║╔╗║║
# ║╚═╝║
# ╚═══╝

import math


def espiral(lado):
    superior = (math.ceil(lado / 2))
    
    for i in range(superior):
        if (i == 0):
            print(("═"*(lado-1)) + "╗")
        else:
            print(("║"*(i-1)+ "╔" + "═"*(lado - (2*i)-1)) + "╗" + "║"*i)
    
    for i in range(superior, lado):
        print("║"*(lado-i-1)+ "╚" + "═"*((2*i)-lado) + "╝" + "║"*(lado-i-1))
    
espiral(3)
espiral(5)
espiral(10)
espiral(30)