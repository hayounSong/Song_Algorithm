import sys

N=int(sys.stdin.readline())

numlist=[]
for i in range(0,N):
    A=sys.stdin.readline().split(" ")
    A=list(map(int,A))
    numlist.append(A)


for a in range(0,N):
    numlist[a][0],numlist[a][1]=numlist[a][1],numlist[a][0]

numlist=sorted(numlist)
for a in range(0,N):
    numlist[a][0],numlist[a][1]=numlist[a][1],numlist[a][0]

for i in range(0,N):
    print(numlist[i][0],numlist[i][1])