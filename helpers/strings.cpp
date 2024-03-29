// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define PB push_back

// Función para convertir un caracter a un entero
int conv(char ch) { 
    return ((ch>='a' && ch<='z') ? ch-'a' : ch-'A'+26); 
}

vector<string> split(string& s, char c=' '){
    vector<string> res;
    stringstream ss(s);
    string sub;
    while(getline(ss, sub, c))res.PB(sub);
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s="abc";
    cout<<s.substr(1)<<"\n";
    cout<<s.substr(0,1)<<"\n";

    s.insert(3, "def"); // El primer parametro es la posicion inicial 
    cout<<s<<"\n";

    s.erase(3,3); // El primer parametro es la posicion y el segundo es la cantidad de caracteres a borrar
    cout<<s<<"\n";
    
    s.replace(0,2,"def"); // El primer parametro es la posicion y el segundo es la cantidad de caracteres a reemplazar
    cout<<s<<"\n";
    
    for(char& c:s)c=toupper(c);
    cout<<s<<"\n";

    for(char& c:s)c=tolower(c);
    cout<<s<<"\n";

    s="123";
    int n=stoi(s); // De string a entero

    s="010101101";
    n = stoi(s, nullptr, 2);

    n=456;
    s=to_string(n); // De entero a string
    cout<<s<<"\n";

    s="123.456";
    double d=stod(s); // De string a double
    return 0;
}