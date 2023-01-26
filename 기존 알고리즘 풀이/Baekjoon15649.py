import sys

NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

s=[]
visited=[0]*(N+1)


def dfs():
    if(len(s)==M):
        print(' '.join(list(map(str,s))))
        return
    else:
        for i in range(1,N+1):
            if i in s:
                continue
            if visited[i]==1:
                continue
            s.append(i)
            dfs()
            s.pop()
            visited[i]=0

dfs()
