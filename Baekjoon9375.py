import sys

def collect(first,second):
    count=1
    mim=0
    for i in range(1,first+1):
        count=count*i
    mim=count
    for s in range(1,second+1):
        count=count//s
    return count

ans=[]
N=int(sys.stdin.readline())

for n in range(0,N):
    A=int(sys.stdin.readline())
    
    clothes={}
    clist=[]
    for i in range(0,A):
        un=sys.stdin.readline().strip().split(" ")
        
        if(un[1] in clothes):
            clothes[un[1]]=clothes[un[1]]+1
        if(un[1] not in clothes):
            clothes[un[1]]=1
            clist.append(un[1])

    clist=list(set(clist))
    count=1


    for i in clist:
        count=count*(clothes[i]+1)

    ans.append(count-1)


for i in ans:
    print(i)