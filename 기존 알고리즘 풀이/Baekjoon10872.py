import sys



N=int(sys.stdin.readline())

def fact(A):
    counter=A
    if(A>1):
        counter=A*fact(A-1)
    
    return counter

if(N==0):
    print(1)
else:    
    print(fact(N))