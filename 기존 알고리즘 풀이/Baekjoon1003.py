import sys

dep={}
def zero_fibo(A):
    zerocount=0
    if(A==0):
        zerocount=zerocount+1
        return zerocount
    elif(A==1):
        return 0
    elif(A in dep):
        zerocount=zerocount+dep[A]
        
        return zerocount
    else:
        zerocount=zerocount+zero_fibo(A-1)+zero_fibo(A-2)
        dep[A]=zerocount
        return zerocount
dep_one={}
def one_fibo(A):
    onecount=0
    if(A==0):
        return 0
    elif(A==1):
        onecount=onecount+1
        return onecount
    elif(A in dep_one):
        onecount=onecount+dep_one[A]
        return onecount
    else:
        onecount=onecount+one_fibo(A-1)+one_fibo(A-2)
        dep_one[A]=onecount
        return onecount

N=int(sys.stdin.readline())
ans=[]
for i in range(0,N):

    A=int(sys.stdin.readline())

    
    ans.append((str(zero_fibo(A)),str(one_fibo(A))))

for a in ans:
    print(a[0],a[1])
    