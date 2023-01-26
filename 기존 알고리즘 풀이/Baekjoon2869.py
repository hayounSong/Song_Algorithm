import math
import sys


Num=sys.stdin.readline().strip().split(" ")

A=int(Num[0])
B=int(Num[1])
V=int(Num[2])
High=0
Day=0

if V-A<=B:
    while High < V:
        if Day % 1 == 0:
            Day = Day + 0.5
            High = High + A

        else:
            Day = Day + 0.5
            High = High - B
else:
    Day=(V-A)/(A-B)+1

print(math.ceil(Day))

