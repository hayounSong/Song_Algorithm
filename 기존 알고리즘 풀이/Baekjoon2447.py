import sys


N=int(sys.stdin.readline())

Totallist=[[0 for j in range(N//3)] for i in range(N//3)]
def Star(N):
    Starlist=[]
    if(N==3):
        Starlist.append("***")
        Starlist.append("* *")
        Starlist.append("***")
        Totallist.append(Starlist)
    else:
        for i in range(0,N//3):
            for b in range(0,N//3):
                if(i==1 and b==1):
                    for c in range(0,N//3):
                            Starlist.append(" "*(N//3))
                    Totallist.append(Starlist)
                else:
                    Star(N//3) 
            



Star(N)
    
for i in range(0,N//3):
    for d in range(0,N//3):
        print(Totallist[i][d])
        
    