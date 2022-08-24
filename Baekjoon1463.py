import sys


N=int(sys.stdin.readline())

dep=[0]*(N+1)


for i in range(2,N+1):
#4 6 11
    
    if(dep[i]==1):
        continue
    if(i%3==0 and i%2==0):
        dep[i]=dep[i]+1 #1
        dep[i]=dep[i]+min(dep[i//3],dep[i//2],dep[i-1])
        
    elif(i%3==0 and i%2!=0):
        dep[i]=dep[i]+1
        dep[i]=dep[i]+min(dep[i//3],dep[i-1])
    elif(i%2==0 and i%3!=0):
        dep[i]=dep[i]+1
        dep[i]=dep[i]+min(dep[i//2],dep[i-1])
    else:
        dep[i]=dep[i]+1
        dep[i]=dep[i]+dep[i-1]

print(dep[N])


# def sum(N):
#     global count
#     if(N==1):
#         return 0
#     else:
#         if(N%3==0 and N%2==0):
#             count=count+1
#             return min(sum[N//3],sum[N//2],sum[N-1])
#         elif(N%3==0):
#             count=count+1
#             return min(sum[N//3],sum[N-1])
#         elif(N%2==0):
#             count=count+1
#             return min(sum[N//2],sum[N-1])
#         else:
#             count=count+1
#             return sum(N-1)

# sum(N)
# print(count)