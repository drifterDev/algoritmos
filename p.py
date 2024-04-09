import os

header = """// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio."""

directorio = os.getcwd()

archivos_cpp = [archivo for archivo in os.listdir(directorio) if archivo.endswith('.cpp')]

for archivo in archivos_cpp:
    ruta_completa = os.path.join(directorio, archivo)
    with open(ruta_completa, 'r+') as f:
        contenido_original = f.read()
        f.seek(0, 0)
        f.write(header.strip() + '\n\n' + contenido_original)
