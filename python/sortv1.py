import random
#random.seed(10) # set seed if desired
import time

def gen(length):
    return [random.randint(0, 4294967295) for i in range(length)]

# length of list to generate and sort
n = 10 ** 7 # 10 Millions 

# generate and stop time
genstart = time.time_ns() # get time in nanoseconds to calculate generation time
liste = gen(n)
genend = time.time_ns()
gendiff = genend - genstart
gendiffseconds = gendiff / (10 ** 9)

# sort and stop time
sortstart = time.time_ns() # get time in nanoseconds to calculate generation time
liste.sort()
sortend = time.time_ns()
sortdiff = sortend - sortstart
sortdiffseconds = sortdiff / (10 ** 9)

# output results
print(f"Generation Time: {gendiff} Nanoseconds or {gendiffseconds} Seconds.")
print(f"Sorting Time: {sortdiff} Nanoseconds or {sortdiffseconds} Seconds.")
