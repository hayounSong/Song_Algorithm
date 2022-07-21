import sys

def test(a):
    icount=0
    for i in range(2,int(a**0.5)+1):
        if(a%i==0):
            icount=icount+1
            break
    
    return icount


N=int(sys.stdin.readline())



for i in range(0,N):

    A=int(sys.stdin.readline())

    suma=A//2
    sumb=A//2

    while(1):
        if(test(suma)==0):
            if(test(sumb)==0):

                print(suma,sumb)
                break
        suma=suma-1
        sumb=sumb+1


    