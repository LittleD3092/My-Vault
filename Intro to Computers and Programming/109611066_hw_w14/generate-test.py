import random

MAX_COL = 10
MAX_NODE = 20

size = random.randint(1, MAX_COL)
print(size)
for i in range(size):
    start = random.randint(1, MAX_NODE)
    end = random.randint(start, MAX_NODE)
    print(start, end)