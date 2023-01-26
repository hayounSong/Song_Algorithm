
import sys

N=int(sys.stdin.readline())


global count
count=0
dep=[0]*(N+1)
ans=[]
for i in range(0,N):
    A=int(sys.stdin.readline())
    ans.append(A)

dep[N]=ans[N-1]


icount=0

for i in range(N-1,-1,-1):
    if(i+1==N):
        dep[i]=ans[i-1]+dep[i+1]
    else:
        if(i==0):
            if(max(dep[i+1],dep[i+2])==dep[i+1]):
                icount=icount+1
            dep[i]=max(dep[i+1],dep[i+2])
        else:
            if(max(dep[i+1],dep[i+2])==dep[i+1]):
                if(icount+1==3 or (i+(3-icount+1)==N)):
                    dep[i]=ans[i-1]+dep[i+2]
                    icount=0
                else:
                    icount=icount+1
                    dep[i]=ans[i-1]+max(dep[i+1],dep[i+2])
            else:
                dep[i]=ans[i-1]+max(dep[i+1],dep[i+2])
    
print(dep[1])