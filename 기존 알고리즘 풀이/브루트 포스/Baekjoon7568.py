import sys


N=int(sys.stdin.readline())

people=[]
lank=[]

for i in range(0,N):
    A=sys.stdin.readline().split(" ")
    A=list(map(int,A))
    people.append(A)

for i in range(0,N):
    count=0
    for a in range(0,N):

        if(people[i][0]<people[a][0] and people[i][1]<people[a][1]):
            count=count+1
    lank.append(count)

for i in range(0,N-1):
    print(lank[i],end=" ")

print(lank[N-1])