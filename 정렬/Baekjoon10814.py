import sys

N=int(sys.stdin.readline())

inputlist=[]

for i in range(0,N):
    im=[]
    A=sys.stdin.readline().strip().split(" ")
    im.append(int(A[0]))
    im.append(i)
    im.append(A[1])
    inputlist.append(im)

def merge(left,right):
    lcount=0
    rcount=0
    ans=[]
    while lcount<len(left) and rcount<len(right):
        if(left[lcount][0]>right[rcount][0]):
            ans.append(right[rcount])
            rcount=rcount+1
        elif(left[lcount][0]<right[rcount][0]):
            ans.append(left[lcount])
            lcount=lcount+1
        else:
            if(left[lcount][1]>right[rcount][1]):
                ans.append(right[rcount])
                rcount=rcount+1
            else:
                ans.append(left[lcount])
                lcount=lcount+1
    while(lcount<len(left)):
        ans.append(left[lcount])
        lcount=lcount+1
    while(rcount<len(right)):
        ans.append(right[rcount])
        rcount=rcount+1
    return ans

def parse(sorted_list):
    if(len(sorted_list)==1):
        return sorted_list
    mid=len(sorted_list)//2
    left_list=sorted_list[:mid]
    right_list=sorted_list[mid:]
    
    left=parse(left_list)
    right=parse(right_list)
    return merge(left,right)


sorted_list=parse(inputlist)

for i in range(0,len(sorted_list)):
    print(sorted_list[i][0],sorted_list[i][2])