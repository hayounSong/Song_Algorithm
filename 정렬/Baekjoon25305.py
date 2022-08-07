
import sys


A=sys.stdin.readline().split(" ")

A=list(map(int,A))

N=A[0]
k=A[1]


sorted_list=sys.stdin.readline().split(" ")
sorted_list=list(map(int,sorted_list))

def merge(leftlist,rightlist):
    lcount=0 
    rcount=0
    answer_list=[]
    while lcount<len(leftlist) and rcount<len(rightlist):
        if(leftlist[lcount]>rightlist[rcount]):
            answer_list.append(rightlist[rcount])
            rcount=rcount+1
        else:
            answer_list.append(leftlist[lcount])
            lcount=lcount+1
    while(lcount<len(leftlist)):
        answer_list.append(leftlist[lcount])
        lcount=lcount+1
    while(rcount<len(rightlist)):
        answer_list.append(rightlist[rcount])
        rcount=rcount+1 
    return answer_list

def parsing(sorted_list):
    if(len(sorted_list)==1):
        return sorted_list
    else:
        mid=len(sorted_list)//2
        left=sorted_list[:mid]
        right=sorted_list[mid:]

        leftlist=parsing(left)
        rightlist=parsing(right)
        return merge(leftlist,rightlist)

sorted_list=parsing(sorted_list)

print(sorted_list[N-k])