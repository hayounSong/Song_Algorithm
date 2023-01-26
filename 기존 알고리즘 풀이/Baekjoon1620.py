import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

dogam={}

for i in range(0,N):
    a=sys.stdin.readline().strip()
    dogam[i+1]=a
    dogam[a]=i+1

Mlist=[]

for i in range(0,M):
    Mlist.append(sys.stdin.readline().strip())

for i in range(0,M):
    
    
    if(Mlist[i].isnumeric()):
        print(dogam[int(Mlist[i].strip())])
    else:
        print(dogam[Mlist[i].strip()])