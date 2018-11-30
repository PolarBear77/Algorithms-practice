import sys
from array import array

line = [ 2, -8, 3, -2, 4, -10]

dp = array('i')

for i in range(len(line)):
      dp.append(0)

for i in range(len(line)):
    print("i:", i)
    current = line[i]
    for j in range(i+1, len(line)):
        current+=line[j]
        print("j:", j)
        if dp[j] < current:
            dp[j] = current
            print("renewed at", j, "with", current+line[j])
print(max(dp))