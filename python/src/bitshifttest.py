import random

start = random.randint(1,10)
end = random.randint(1,10)
p = (start + end) // 2
q = (start + end) >> 1
print(start, end, p)
print(start, end, q)
