import string
import sys
from tokenize import String


N=int(sys.stdin.readline())

Movelist=[]

def Move(N,A,B,C):

    if(N==1):
        Movelist.append((A+" "+C))

    
    else:
        Move(N-1,A,C,B)
        Movelist.append(A+" "+C)
        Move(N-1,B,A,C)
    

Move(N,"1","2","3")

print(len(Movelist))

for i in range(0,len(Movelist)):
    print(Movelist[i])