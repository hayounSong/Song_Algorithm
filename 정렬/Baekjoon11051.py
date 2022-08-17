import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])
count=1

for i in range(1,N+1):
    count=count*i
    # count=count%10007
divisor=1

for i in range(1,M+1):
    divisor=divisor*i
    # divisor=divisor%10007

for a in range(1,N-M+1):
    divisor=divisor*a
    

print((count//divisor)%10007)
# count=count%10007
