import sys 


A=int(sys.stdin.readline())
B=int(sys.stdin.readline())

count=0
min=10000
for i in range(A,B+1):
    icount=0
    for c in range(2,i):
        if i%c==0:
            icount=icount+1
    if(icount==0):
        if(i!=1):
            count=count+i
            if(i<min):
                min=i

if count!=0:
    print(count)
    print(min)
else:
    print(-1)