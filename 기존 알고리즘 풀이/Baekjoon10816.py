import sys


N=int(sys.stdin.readline())

N_list=sys.stdin.readline().split(" ")
N_list=list(map(int,N_list))

M=int(sys.stdin.readline())

Mlist=sys.stdin.readline().split(" ")
Mlist=list(map(int,Mlist))



count={}
# def binary_count(array,target,start,end):
    
#     mid=(start+end)//2
    
#     if(start>end):
#         return 0
#     elif(array[mid]==target):
#         return(count[target])
#     elif(array[mid]>target):
#         binary_count(array,target,start,mid-1)
#     elif(array[mid]<target):
#         binary_count(array,target,mid+1,end)
    


for i in N_list:
    if(i in count):
        count[i]=count[i]+1
    else:
        count[i]=1

for i in range(M):
    if(Mlist[i] in count):
        print(count[Mlist[i]],end=" ")
    else:
        print("0",end=" ")

