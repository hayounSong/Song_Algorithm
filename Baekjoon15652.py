import sys



NM=sys.stdin.readline().split(" ")

N=int(NM[0])
M=int(NM[1])

visited=[0]*(N+1)
ans=[]


def merge(leftlist,rightlist):
    lcount=0
    rcount=0
    answer=[]
    while(lcount<len(leftlist) and rcount<len(rightlist)):
        if(leftlist[lcount]<rightlist[rcount]):
            answer.append(leftlist[lcount])
            lcount=lcount+1
        else:
            answer.append(rightlist[rcount])
            rcount=rcount+1
    while(lcount<len(leftlist)):
        answer.append(leftlist[lcount])
        lcount=lcount+1
    while(rcount<len(rightlist)):
        answer.append(rightlist[rcount])
        rcount=rcount+1
    return answer

def parsing(array):

    if(len(array)==1):
        return array
    else:
        mid=len(array)//2
        left=array[:mid]
        right=array[mid:]

        leftlist=parsing(left)
        rightlist=parsing(right)
        return merge(leftlist,rightlist)


def dfs(test):
    if(len(ans)==M):
        

        print(' '.join(list(map(str,ans))))
        return
    else:
        for i in range(1,N+1):
            if(visited[i]==1 or i<test):
                continue
            else:
                ans.append(i)
                visited[i]==1
                dfs(i)
                ans.pop()
                visited[i]==0

dfs(1)
