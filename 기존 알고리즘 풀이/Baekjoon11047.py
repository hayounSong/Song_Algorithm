import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])
money=[]
for i in range(0,N):
    money.append(int(sys.stdin.readline()))
count=0
while(M!=0):
    for i in range(N-1,-1,-1):
        if(money[i]<=M):
            thismoney=money[i]
            break
            
    
    count=count+M//thismoney
    
    M=M%thismoney

print(count)
