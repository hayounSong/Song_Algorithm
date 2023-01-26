import sys

N=int(sys.stdin.readline())

inputlist=[]
for i in range(0,N):
    A=sys.stdin.readline().strip()
    inputlist.append(A)

def merge(left,right):
    lcount=0
    rcount=0
    ans_list=[]
    while(lcount<len(left) and rcount<len(right)):
        if(len(left[lcount])>len(right[rcount])):
            ans_list.append(right[rcount])
            rcount=rcount+1
        elif(len(left[lcount])<len(right[rcount])):
            ans_list.append(left[lcount])
            lcount=lcount+1
        elif(len(left[lcount])==len(right[rcount])):
            for c in range(0,len(left[lcount])):
                if(left[lcount][c]>right[rcount][c]):
                    ans_list.append(right[rcount])
                    rcount=rcount+1
                    break
                elif(left[lcount][c]<right[rcount][c]):
                    ans_list.append(left[lcount])
                    lcount=lcount+1
                    break
                if(c==len(left[lcount])-1):
                    ans_list.append(left[lcount])
                    lcount=lcount+1
                    break
    while(lcount<len(left)):
        ans_list.append(left[lcount])
        lcount=lcount+1
    while(rcount<len(right)):
        ans_list.append(right[rcount])
        rcount=rcount+1
    return ans_list
                        

def parse(sorted_list):
    if(len(sorted_list)==1):
        return sorted_list
    else:  
        mid=len(sorted_list)//2
        leftlist=sorted_list[:mid]
        rightlist=sorted_list[mid:]

        left=parse(leftlist)
        right=parse(rightlist)
        return merge(left,right)


answer_list=parse(inputlist)

befor=""
for i in answer_list:
    if(i==befor):
        continue
    print(i)
    befor=i

