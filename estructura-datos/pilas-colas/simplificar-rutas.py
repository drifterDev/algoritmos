# Dada una cadena que representa una ruta absoluta, es decir que representa la ruta de archivo o directorio en un sistema de archivos estilo Unix (comienza con un slash ‘/’), conviértala en la ruta canónica simplificada.

# En un sistema de archivos de estilo Unix, un punto ‘.’ se refiere al directorio actual, un doble punto ‘…’ se refiere al directorio de un nivel superior, y cualquier barra múltiple consecutiva (es decir, ‘//’) se trata como una sola barra ‘/’. Para este problema, cualquier otro formato de puntos como ‘…’ se tratan como nombres de archivo/directorio.

# La ruta canónica debe tener el siguiente formato:
# La ruta comienza con una sola barra ‘/’.
# Dos directorios cualesquiera se separan con una sola barra ‘/’.
# La ruta no termina con un “/” al final.
# La ruta sólo contiene los directorios de la ruta desde el directorio raíz hasta el archivo o directorio de destino (es decir, sin punto ‘.’ o doble punto ‘…’)
# Devuelve la ruta canónica simplificada.

# Ejemplo 1:
#     Entrada: ruta = "/home/"
#     Salida: "/home"
# Explicación: Observe que no hay una barra al final del nombre del último directorio.


# Ejemplo 2:
#     Entrada: ruta = "/../"
#     Salida: "/"
# Explicación: Subir un nivel desde el directorio raíz es un no-op, ya que el nivel raíz es el nivel más alto al que se puede ir.


# Ejemplo 3:
#     Entrada: path = "/home//foo/"
#     Salida: "/home/foo"
# Explicación: En la ruta canónica, varias barras inclinadas consecutivas se sustituyen por una sola.


def simplificar(self, ruta: str) -> str:
    pila = []
    lista_rutas = ruta.split("/")
    for fragmento in lista_rutas:
        if fragmento == "..":
            if pila:
                pila.pop()
        elif fragmento == "." or fragmento == "":
            continue
        else:
            pila.append(fragmento)

    nueva_ruta = "/"
    for i in range(len(pila)):
        nueva_ruta += pila[i]
        if i < len(pila) - 1:
            nueva_ruta += "/"
    return nueva_ruta
