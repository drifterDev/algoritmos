# BrowserHistory(string homepage): inicializa el objeto con la página de inicio del navegador.
# void visit(string url): visita la url de la página actual. Borra todo el historial de avance.
# string back(int steps): mueve los pasos hacia atrás en el historial. Si sólo puede devolver x pasos en el historial y pasos > x, devolverá sólo x pasos. Devuelve la url actual después de retroceder como máximo pasos en el historial.
# string forward(int steps): mover pasos hacia adelante en el historial. Si sólo puede avanzar x pasos en el historial y pasos > x, avanzará sólo x pasos. Devuelve la url actual después de avanzar en el historial como máximo pasos.

# Ejemplo:

# Entrada:

# ["BrowserHistory", "visita", "visita", "visita", "atrás", "atrás", "adelante", "visita", "adelante", "atrás", "atrás"]
# [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
# Salida: [null,null,null, "facebook.com", "google.com", "facebook.com",null, "linkedin.com", "google.com", "leetcode.com"]

# Explicación:

# BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
# browserHistory.visit("google.com"); // Estás en "leetcode.com". Visita "google.com"
# browserHistory.visit("facebook.com"); // Estás en "google.com". Visita "facebook.com"
# browserHistory.visit("youtube.com"); // Estás en "facebook.com". Visita "youtube.com"
# browserHistory.back(1); // Estás en "youtube.com", vuelve a "facebook.com" retornas "facebook.com"
# browserHistory.back(1); // Estás en "facebook.com", vuelve a "google.com" retornas "google.com"
# browserHistory.forward(1); // Estás en "google.com", avanza hasta "facebook.com" return "facebook.com"
# browserHistory.visit("linkedin.com"); // Estás en "facebook.com". Visita "linkedin.com"
# browserHistory.forward(2); // Estás en "linkedin.com", no puedes avanzar ningún paso.
# browserHistory.back(2); // Estás en "linkedin.com", retrocede dos pasos a "facebook.com" y luego a "google.com". devuelve "google.com"
# browserHistory.back(7); // Estás en "google.com", puedes retroceder sólo un paso hasta "leetcode.com". Retornas "leetcode.com"


class BrowserHistory:
    def __init__(self, homepage: str):
        self.home = homepage
        self.main = []
        self.temporal = []

    def visit(self, url: str) -> None:
        self.main.append(url)
        if self.temporal:
            self.temporal.clear()

    def back(self, pasos: int) -> str:
        while self.main and pasos:
            pasos -= 1
            x = self.main.pop()
            self.temporal.append(x)
        if self.main:
            return self.main[-1]
        return self.home

    def forward(self, pasos: int) -> str:
        while self.temporal and pasos:
            pasos -= 1
            x = self.temporal.pop()
            self.main.append(x)
        if self.main:
            return self.main[-1]
        return self.home
