# Teoria

## Inclusión-Exclusión

* |A ∪ B| = |A| + |B| - |A ∩ B|
* Se puede hacer con los subconjuntos, sumando los subconjuntos impares y restando los pares

## Bitwise

* a | b = a ^ b + a & b 
* a ^ (a & b) = (a | b) ^ b
* b ^ (a & b) = (a | b) ^ a
* (a & b) ^ (a | b) = a ^ b
* a + b = a | b + a & b
* a + b = a ^ b + 2 * (a & b)
* a - b = (a ^ (a & b)) - ((a | b) ^ a)
* a - b = ((a | b) ^ b) - ((a | b) ^ a)
* a - b = (a ^ (a & b)) - (b ^ (a & b))
* a - b = ((a | b) ^ b) - (b ^ (a & b))
* a ^ b = ~(a & b) & (a | b)

## Combinatoria

* nc0 + nc1 + nc2 + ... + ncn = 2^n
* ncr = n-1cr-1 + n-1cr
* ncr = n! / r! * (n-r)!
* (a+b)^n = nc0 * a^n * b^0 + nc1 * a^n-1 * b^1 + nc2 * a^n-2 * b^2 + ... + ncn * a^0 * b^n	
* Con repeticion = n+r-1Cr
* Permutaciones = n! / (n1! * n2! * ... * nk!)
* n_sumatoria_k (nCk)^2 = 2nCn

## Números de catalan

* Cn = 1/(n+1) * 2nCn
* Cn = (2n)!/((n+1)!n!)
* Cn = (4n-2)/(n+1) * Cn-1
* Hay Cn árboles binarios con n nodos
* Hay Cn árboles binarios completos con n+1 hojas
* Hay Cn caminos de n pasos en una grilla de nxn sin pasar por la diagonal
* Hay Cn formas de dividir un poligono de n+2 lados en n triangulos
* Hay Cn secuencias de parentesis balanceados de longitud 2n

## Matrices

La suma de A y B es una matriz C donde Cij = Aij + Bij

El producto de A y B es una matriz C donde Cij = Σ Aik * Bkj

El producto escalar de A y k es una matriz C donde Cij = k * Aij

* A^-1 * A = Matriz identidad
* det(A) = det(A^T)
* det(A*B) = det(A) * det(B)
* det(A^-1) = 1/det(A)
* Para hallar los caminos de k pasos entre dos nodos, elevar la matriz de adyacencia a la k y en la matriz de adyacencia poner 1 si hay camino y 0 si no hay camino

## Geometria

* Lanzar una recta desde un punto P para ver si esta dentro del poligono: contar las intersecciones con los lados del poligono, si es par esta fuera, si es impar esta dentro

* Todo poligono cumple:
vertices - aristas + caras = 2

## Probabilidad

* P(A') = 1 - P(A)
* P(A∪B) = P(A) + P(B) - P(A∩B)
* P(A∩B) = P(A) * P(B|A) y si A y B son independientes P(A∩B) = P(A) * P(B)
* P(A|B) = P(A∩B) / P(B)
* Valor esperado de una variable aleatoria X: E[X] = Σ x * P(X = x)
* Varianza de una variable aleatoria X: Var[X] = E[X^2] - E[X]^2
* E[X + Y] = E[X] + E[Y]

## Distribuciones

### Uniforme: 

* P(X = x) = 1/n
* E[X] = (a+b)/2

### Binomial:

* P(X = x) = nCx * p^x * (1-p)^(n-x)
* E[X] = n * p

### Geometrica:

* P(X = x) = (1-p)^(x-1) * p
* E[X] = 1/p

## Teoría de números

* gcd(a,b) = gcd(a,b-a)
* a^p ≡ a (mod p), a^(p-1) ≡ 1 (mod p) si p es primo
* Aproximadamente el número de primos menores o iguales a n es n/ln(n)

## Scheduling

Tenemos dos maquinas y cada trabajo debe hacerse primero en a y luego en b dado su tiempo en cada maquina, da la agenda optima que minimiza los tiempos.

* ordenar por min(a, b) y realizar los de menor tiempo en a primero, luego los de menor tiempo en b, pero en orden inverso

```cpp
sort(all(jobs));
vector<Job> a, b;
for(Job j:jobs){
    if(j.a<j.b)a.push_back(j);
    else b.push_back(j);
}
a.insert(a.end(), b.rbegin(), b.rend());
return a;
```

Tenemos n trabajos con un tiempo de duracion y un deadline, queremos maximizar el numero de trabajos que podemos hacer.

* ordenar por deadline

```cpp
sort(all(jobs));
set<ii> s;
vi schedule;
for(int i=sz(jobs)-1;i>=0;i--){
    int t=jobs[i].deadline-(i?jobs[i-1].deadline:0);
    s.insert({jobs[i].duration, jobs[i].idx});
    while(t && !s.empty()){
        auto it=s.begin();
        if(it->first<=t){
            t-=it->first;
            schedule.push_back(it->second);
        } else {
            s.insert({it->first-t, it->second});
            t=0;
        }
        s.erase(it);
    }
}
return schedule;
```

### Juegos

* Nim: Si la xor de las pilas es 0, el segundo jugador gana, si no, el primer jugador gana
* Sprague-Grundy: rx = mex(r1, r2, ..., rk) donde r1, r2, ..., rk son los nimbers de los estados a los que se puede llegar desde s


* c < a+b (a,b,c lados de un triangulo) y c el mayor

* si se va a recibir reales, recibirlos como strings y luego convertirlos 

* Al crear un struct ordenar bien los datos para mejor memoria (ordernar por tamaño de los datos)

```cpp
struct {
    double a;       // 8 bytes
    long long a;    // 8 bytes
    int bs[4];      // 4 bytes
    int b;          // 4 bytes
    char c;         // 1 byte
    bool d;         // 1 byte
} st;
```

* compilar: g++ a.cpp && ./a.out < in.txt > out.txt

* añadir el teorema multinomial

* añadir el binomio de newton

* revisar dinic teoria automac primera fecha mexico K

* añadir puentes online

* revisar st de cses 

* gauss jordan modulo (descomunal)