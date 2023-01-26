import sys

N=int(sys.stdin.readline())


inputlist=[]
max=-4001
min=4001
avr=0
for i in range(0,N):
    A=int(sys.stdin.readline())
    avr=avr+A
    if(A>max):
        max=A
    if(A<min):
        min=A
    inputlist.append(A)
countlist=[]
countmax=0
for i in range(-4000,4001):
    count=0
    for a in range(0,len(inputlist)):
        if(i==inputlist[a]):
            count=count+1
    if(count>countmax):
        countmax=count
    countlist.append(count)

avr=avr/N



shortlist=[]

for i in range(-4000,4001):
    if(countlist[i+4000]==countmax):
        shortlist.append(i)
        


print(round(avr))
print(sorted(inputlist)[N//2])
if(len(shortlist)>1):
    print(shortlist[1])
else:
    print(shortlist[0])
print(max-min)