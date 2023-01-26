import sys

A=sys.stdin.readline().split(" ")

A=list(map(int,A))

a=A[0]
b=A[1]
def gcd(a,b):
    sum=a%b
    if(a%b==0):
        return b
    else:
        return gcd(b,sum)


print(gcd(a,b))
print(a*b//gcd(a,b))
