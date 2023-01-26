import sys 


N=int(sys.stdin.readline())
num=0

    
a=(sys.stdin.readline().strip().split(" "))
for i in range(0,N):
       
    count=0
    c=int(a[i])
    if(c==1):
        continue 
    for b in range(2,c):
        if(c%b==0):
            count=count+1

    if(count==0):
        num=num+1

print(num)