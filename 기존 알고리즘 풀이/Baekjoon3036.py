
import sys

def gcd(a,b):
    n=a%b
    if(n==0):
        return b
    else:
        return gcd(b,n)

N=int(sys.stdin.readline())

A=sys.stdin.readline().split(" ")
A=list(map(int,A))

for i in range(1,N):
    a=gcd(A[0],A[i])
    print(str(A[0]//a)+"/"+str(A[i]//a))