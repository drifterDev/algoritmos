import heapq
texto = 'PYTHON'
monticulo = []
for letra in texto:
  heapq.heappush(monticulo, letra)
while len(monticulo)>0:
  print(heapq.heappop(monticulo), end='')