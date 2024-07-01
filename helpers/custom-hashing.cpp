#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static long long splitmix64(long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(long long x) const {
        static const long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(const pair<int,int>& x) const {
        return (size_t) x.first * 37U + (size_t) x.second;
    }

    size_t operator()(const vector<int>& v) const {
        size_t s = 0;
        for(auto &e : v)
            s^=hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
        return s;
    }
};

unordered_map<long long, int, custom_hash> safe_map;
gp_hash_table<int, int, custom_hash> table;
safe_map.reserve(1024); // potencias de 2 para reducir la cantidad de realocaciones de memoria (escoger bien pow 2, tle)
safe_map.max_load_factor(0.25); 
// Al establecer una carga máxima de 0.25
// se asegura que la tabla se redimensione (aumente su tamaño) cuando esté al 25% de su capacidad total. 
// Esto reduce el numero de colisiones, lo que mejora el rendimiento de las operaciones de busqueda y actualizacion
