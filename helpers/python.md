# Tips for python

```python
# Fast output in case of many lines
outputs = []
print('\n'.join(outputs))
```

```python
# Use functions to use local variables
def main():
  pass

main()
```

```python
lista = [0]*n
lista = [[0]*n for _ in range(n)]
```

```python
for val in lista:
  pass

for i,val in enumerate(lista):
  pass
```

```python
# For recursive functions
stack = []
stack.append(1)
stack.pop()
```

```python
# Use a list instead of a string
s = []
for i in range(10**5):
  s.append('a')
print(''.join(s))
```

```python
lista = [[0]*m for _ in range(n)]
# Flattening 2d lists into 1d
lista = [0]*(n*m)
```

```python
for i in range(n):
  weight=weights[i]
  value=values[i]
# Use zip
for weight,value in zip(weights,values):
  pass
```

```python
from sys import setrecursionlimit, stdin, stdout

setrecursionlimit(1000000)

sys.stdin = open("input.in", "r")
sys.stdout = open("output.out", "w")
```

```python
inverso = pow(a, -1, MOD)
```