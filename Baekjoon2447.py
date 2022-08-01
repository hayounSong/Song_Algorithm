import sys


N=int(sys.stdin.readline())

def Star(N):

    count=N 


    if(count==3):
        for i in range(0,3):
            for a in range(0,3):
                if(i==1 and a==1):
                    print(" ",end='')
                else:
                    print("*",end='')

            if(a<3):
                print("\n",end='')
    else:
        for i in range(0,3):
            for a in range(0,3):
                Star(count//3)


Star(N)
    
    
    