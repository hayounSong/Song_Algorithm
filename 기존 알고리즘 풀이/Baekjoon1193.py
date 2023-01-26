import sys

InputNum=int(sys.stdin.readline())

Count=2
Min=2
Max=3
while True:
    if InputNum==1:
        break
    else:

        if InputNum>=Min and InputNum<=Max:
            break;
        else:
            Min= Min + Count
            Max=Max+Count+1
            Count = Count + 1
if InputNum==1:
    print("1/1")
else:
    index=1
    for i in range(Min, Max + 1):

        if Count%2==0:

            if(InputNum==i):
                print(str(index) +"/" + str(Count + 1 - index))
            else:
                index=index+1
        else:
            if (InputNum == i):
                print(str(Count + 1 - index) + "/" + str(index))
            else:
                index = index + 1
