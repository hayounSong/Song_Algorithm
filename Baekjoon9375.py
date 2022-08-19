import sys

N=int(sys.stdin.readline())

for n in range(0,N):
    A=int(sys.stdin.readline())
    
    clothes={}
    clist=[]
    for i in range(0,A):
        un=sys.stdin.readline().strip().split(" ")
        
        if(un[1] in clothes):
            clothes[un[1]]=clothes[un[1]]+1
        else:
            clothes[un[1]]=1
            clist.append(un[1])

    clist=list(set(clist))
    count=0
    for i in clist:
        count=count+clothes[i]
    if len(clist)>1:
        count=count+len(clothes)
    
    print(count)