import sys


NM=sys.stdin.readline().split(" ")
N=int(NM[0])
M=int(NM[1])
Nlist=[]
for i in range(0,N):
    Nlist.append(sys.stdin.readline().strip())

Mlist=[]
for i in range(0,M):
    Mlist.append(sys.stdin.readline().strip())

Nlist=sorted(Nlist)
Mlist=sorted(Mlist)
def binary_search(array,target,start,end):
    mid=(start+end)//2

    if(start>end):
        return 0
    elif(array[mid]==target):
        return 1
    elif(array[mid]>target):
        return binary_search(array,target,start,mid-1)
    else:
        return binary_search(array,target,mid+1,end)
ans_list=[]    

for i in range(0,M):
    if(binary_search(Nlist,Mlist[i],0,N-1)==1):
        ans_list.append(Mlist[i])
    else:
        continue
    # print(binary_search(Nlist,Mlist[i],0,N-1))

print(len(ans_list))
for i in range(0,len(ans_list)):
    print(ans_list[i])