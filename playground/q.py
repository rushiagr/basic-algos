from queue import Queue

q = Queue()

q.put(1)
q.put(2)
while not q.empty():
    print(q.get())

# Note: if q is empty and you do q.get() it'll block. If you don't want to
# block, do q.get(False) or q.get_nowait(). Now it'll raise queue.Empty
# exception
