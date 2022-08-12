import sys

A1=int(sys.stdin.readline())
A=sys.stdin.readline().split(" ")
A=list(map(int,A))
B1=int(sys.stdin.readline())

B=sys.stdin.readline().split(" ")

B=list(map(int,B))

A=sorted(A)

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

for i in range(0,B1):
    print(binary_search(A,B[i],0,A1-1),end=" ")

