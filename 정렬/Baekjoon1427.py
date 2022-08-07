import sys

N=sys.stdin.readline().strip()

numlist=[]
for i in range(0,len(N)):
    numlist.append(int(N[i]))


for i in range(0,len(numlist)):
    for a in range(0,len(numlist)):
        if(numlist[i]>numlist[a]):
            temp=numlist[i]
            numlist[i]=numlist[a]
            numlist[a]=temp

for i in range(0,len(numlist)):
    print(numlist[i],end='')


