import sys

A=sys.stdin.readline().split(" ")

S=int(A[0])
G=int(A[1])

chess=[]

for i in range(0,S):
    A=sys.stdin.readline()
    chess.append(A)

min=2500

for i in range(0,S-7):

    for b in range(0,G-7):
        
        
        count=0
        for c in range(i,i+8):
            for d in range(b,b+8):
                garo=d
                sero=c
                if(sero%2==0 and garo%2==0 and chess[sero][garo]=="W"):
                    count=count+1
                if(sero%2==0 and garo%2==1 and chess[sero][garo]=="B"):
                    count=count+1
                if(sero%2==1 and garo%2==0 and chess[sero][garo]=="B"):
                    count=count+1
                if(sero%2==1 and garo%2==1 and chess[sero][garo]=="W"):
                    count=count+1

        
        count2=0
        for c in range(i,i+8):
            for d in range(b,b+8):
                garo=d
                sero=c
                if(sero%2==0 and garo%2==0 and chess[sero][garo]=="B"):
                    count2=count2+1
                if(sero%2==0 and garo%2==1 and chess[sero][garo]=="W"):
                    count2=count2+1
                if(sero%2==1 and garo%2==0 and chess[sero][garo]=="W"):
                    count2=count2+1
                if(sero%2==1 and garo%2==1 and chess[sero][garo]=="B"):
                    count2=count2+1

        if(count>count2):
            count=count2
        if(count<min):
            min=count

print(min)