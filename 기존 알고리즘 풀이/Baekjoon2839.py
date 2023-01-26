import sys 

count=0
N=int(sys.stdin.readline())


if(N%5==0):
    print(N//5)
else:
    while (N>0):
        N=N-3
        count=count+1
        if(N%5==0):
            count=count+N/5
            print(int(count))
            break
        elif(N%3==0):
            count=count+N/3
            print(int(count))
            break
        elif(N==1 or N==2):
            print(-1)
            break



