import sys

N=int(sys.stdin.readline())

numlist=[]
for i in range(0,N):
    A=sys.stdin.readline().split(" ")
    A=list(map(int,A))
    numlist.append(A)



# for i in range(0,N):
#     for a in range(0,N):
#         if(numlist[i][0]<numlist[a][0]):
#             temp1=numlist[i][0]
#             temp2=numlist[i][1]

#             numlist[i][0]=numlist[a][0]
#             numlist[i][1]=numlist[a][1]
#             numlist[a][0]=temp1
#             numlist[a][1]=temp2 

#         if(numlist[i][0]==numlist[a][0]):
#             if(numlist[i][1]<numlist[a][1]):
#                 temp1=numlist[i][0]
#                 temp2=numlist[i][1]

#                 numlist[i][0]=numlist[a][0]
#                 numlist[i][1]=numlist[a][1]
#                 numlist[a][0]=temp1
#                 numlist[a][1]=temp2 
numlist=sorted(numlist)
for i in range(0,N):
    print(numlist[i][0],numlist[i][1])