import sys


NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

visited=[0]*(N+1)
ans=[]

def dfs():
    if(len(ans)==M):
        
        print(' '.join(list(map(str,ans))))
        return
    else:
        for i in range(1,N+1):
            if(visited[i]==1 ):
                continue
            else:
                ans.append(i)
                visited[i]==1
                dfs()
                ans.pop()
                visited[i]==0

dfs()
        