import queue

n, q = list(map(int, input().split()))
noti = 0
notifications = queue.Queue()
aplications = [queue.Queue() for o in range(n + 1)]
visto = [False] * q
eventos = 1
for i in range(q):
    typ, x = list(map(int, input().split()))
    if typ == 1:
        notifications.put((eventos, x))
        aplications[x].put(eventos)
        eventos += 1
        noti += 1
    elif typ == 2:
        while aplications[x].qsize() > 0:
            visto[aplications[x].get()] = True
            noti -= 1
    else:
        while notifications.qsize() > 0 and notifications.queue[0][0] <= int(x):
            j, k = notifications.get()
            if not visto[j]:
                visto[j] = True
                aplications[k].get()
                noti -= 1
    print(noti)
