import sys

N=int(sys.stdin.readline())

ans=[]
for i in range(0,N):

    A=sys.stdin.readline().split(" ")
    A=list(map(int,A))
    x1=A[0]
    y1=A[1]
    r1=A[2]

    x2=A[3]
    y2=A[4]
    r2=A[5]
    
    d=((x2-x1)**2+(y2-y1)**2)**0.5
    if(abs(r1+r2)<d):
        ans.append(0)
        
    elif(d!=0 and d<abs(r2-r1)):
        ans.append(0)
        
    elif(d==0 and r1!=r2):
        ans.append(0)
    elif(d!=0 and d==abs(r1+r2)):
        ans.append(1)
    elif(d!=0 and abs(r2-r1)==d):
        ans.append(1)
    elif(d==0 and r1==r2):
        ans.append(-1)
    elif(d!=0 and abs(r1-r2)<d<r1+r2):
        ans.append(2)
        
    
for a in ans:
    print(a)