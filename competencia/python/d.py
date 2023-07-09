# Escribe un script para que haga una peticion a la API de github y devuelva el numero de repositorios que tiene un usuario
# Ejemplo de uso: python d.py <drifterDev>
# Ejemplo de salida: drifterDev tiene 10 repositorios
import requests
import sys

if len(sys.argv) != 2:
    print("Usage: python d.py <username>")
    sys.exit()

username = sys.argv[1]
url = "https://api.github.com/users/" + username + "/repos"
response = requests.get(url)
if response.status_code != 200:
    print("Error: ", response.status_code)
    sys.exit()
repos = response.json()
print(username, "has", len(repos), "repositories")
