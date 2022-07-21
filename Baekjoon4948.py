import sys

while(1):
    N=int(sys.stdin.readline())
    if(N==0):
        break
    count=0
    for i in range(N+1,N*2+1):
        icount=0
        for d in range(2,int(i**0.5)+1):
            if(i%d==0):
                icount=icount+1
                break
        if(icount==0):
            count=count+1

    print(count)