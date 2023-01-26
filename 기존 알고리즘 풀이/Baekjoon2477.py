import sys

N=int(sys.stdin.readline()) 

dic=[]

maxg=0
maxs=0
ming=501
mins=501

for i in range(0,6):
    A=sys.stdin.readline().split(" ")
    A=list(map(int,A))
    if((A[0]==4 or A[0]==3) and A[1]>maxs):
        maxs=A[1]
    # if((A[0]==4 or A[0]==3) and A[1]<mins):
    #     mins=A[1]
    if((A[0]==1 or A[0]==2) and A[1]>maxg):
        maxg=A[1]
    # if((A[0]==1 or A[0]==2) and A[1]<ming):
    #     ming=A[1]
    dic.append(A)
acount=0

for a in range(0,len(dic)):
    if(a==0):
        if((dic[a+1][1]==maxg or dic[a+1][1]==maxs)or (dic[len(dic)-1][1]==maxg or dic[len(dic)-1][1]==maxs)):
            continue
        else:
            if(dic[a][0]==1 or dic[a][0]==2):
                mins=dic[a][1]
            else:
                ming=dic[a][1]
    elif(a==len(dic)-1):
        if((dic[a-1][1]==maxg or dic[a-1][1]==maxs)or (dic[0][1]==maxg or dic[0][1]==maxs)):
            continue
        else:
            if(dic[a][0]==1 or dic[a][0]==2):
                mins=dic[a][1]
            else:
                ming=dic[a][1]
    else:
        if((dic[a+1][1]==maxg or dic[a+1][1]==maxs)or (dic[a-1][1]==maxg or dic[a-1][1]==maxs)):
            continue
        else:
            if(dic[a][0]==1 or dic[a][0]==2):
                mins=dic[a][1]
            else:
                ming=dic[a][1]
            
    


print((maxg*maxs-ming*mins)*N)
    

