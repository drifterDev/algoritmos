import heapq
a = []
heapq.heappush(a, 12)
heapq.heappush(a, 34)
heapq.heappush(a, 7)
print(heapq.heappop(a))
print(a[0])
print(len(a))
b = [51, 26, 48]
heapq.heapify(b)
print(heapq.heappop(b))