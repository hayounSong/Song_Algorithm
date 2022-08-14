from calendar import c
import sys


N=sys.stdin.readline().strip()

dic=[]

for i in range(0,len(N)):
    
    for a in range(i,len(N)):
        dic.append(N[i:a+1])

dic=set(dic)
print(len(dic))

