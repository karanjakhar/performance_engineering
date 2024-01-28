import sys, random
from tqdm import tqdm
from time import *

n = 4096
init_start = time()
A = [[random.random()
      for row in range(n)]
      for col in range(n)]

B = [[random.random()
      for row in range(n)]
      for col in range(n)]

C = [[0 for row in range(n)]
     for col in range(n)]

init_end = time()

print("init time : %0.6f"%(init_end-init_start))

print("calculating ... \n")

start = time()
for i in tqdm(range(n)):
    for j in range(n):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]
end = time()

print("%0.6f"%(end-start))
