# Teoria

## Aritmetica modular

* (a + b) % c = (a % c + b % c)%c
* (a - b) % c = (a % c - b % c)%c
* (a * b) % c = (a % c * b % c)%c
* a^(p-1) % p = 1 (si p es primo)
* (a^b) % c = ((a % c)^b) % c
* (a/b) % c = (a * inv(b, c)) % c
* (p-1)! % p = -1 (si p es primo), entonces p es primo cuando (p-1)! + 1 es multiplo de p
* a^phi(b) % b = 1 (si a y b son primos relativos)

## Congruencia

a y b se encuentran en la misma "clase de congruencia" módulo n, si ambos dejan el mismo resto si los dividimos entre n, o, equivalentemente, si a − b es un múltiplo de n.

63 es congruente a 83 modulo 10 y se escribe 63 ≡ 83 (mod 10)

* a ≡ b (mod N) 

## Inverso modular
 
a y b son inversos modulares si a * b ≡ 1 (mod M)

* a^-1 es el inverso modular de a (solo en terminos de notacion) 
* (a/d) % c = (a * inv(d, c)) % c

## Combinatoria

* nc0 + nc1 + nc2 + ... + ncn = 2^n
* ncr = n-1cr-1 + n-1cr
* ncr = n! / r! * (n-r)!
* (a+b)^n = nc0 * a^n * b^0 + nc1 * a^n-1 * b^1 + nc2 * a^n-2 * b^2 + ... + ncn * a^0 * b^n	

## Números de catalan

* Cn = 1/(n+1) * 2nCn
* Hay Cn árboles binarios con n nodos

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

