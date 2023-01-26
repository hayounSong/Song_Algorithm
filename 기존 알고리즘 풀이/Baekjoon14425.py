import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

Nlist=[]
Mlist=[]
for i in range(0,N):
    Nlist.append(sys.stdin.readline().strip("\n"))
for i in range(0,M):
    Mlist.append(sys.stdin.readline().strip("\n"))
Nlist=sorted(Nlist)
def binary_search(array,element,start,end):
    mid=(start+end)//2
    # print(mid)
    
    # if(len(array)%2==1 and start>=end):
    #     return 0
    if(start>end):
        return 0

    elif( element==array[mid]):
        return 1

    elif(element<array[mid]):
        return binary_search(array,element,start,mid-1)
    elif(element>array[mid]):
        return binary_search(array,element,mid+1,end)

dcount=0
for i in range(0,M):
    dcount=dcount+binary_search(Nlist,Mlist[i],0,N-1)
    
print(dcount)
        
