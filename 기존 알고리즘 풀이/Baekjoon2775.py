from glob import glob1
import sys

N=int(sys.stdin.readline())


for i in range(0,N):
    a=int(sys.stdin.readline())+1
    b=int(sys.stdin.readline())
    
    array = [[0 for col in range(b)] for row in range(a)]
    
    for c in range(0,b):
        array[0][c]=c+1
        

    for s in range(1,a):
        for g in range(0,b):
            array[s][g]=0
            for e in range(0,g+1):
                array[s][g]+=array[s-1][e]
            
    #     print("\n")
    print(array[a-1][b-1])
    
# 1 2 3 

#1 3 6 

#1 4 10 