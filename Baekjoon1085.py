import sys

s=sys.stdin.readline().split(" ")
x=int(s[0])
y=int(s[1])
w=int(s[2])
h=int(s[3])

a=0
if(w-x<h-y):
    a=(w-x)
else:
    a=(h-y)

if(a<=x and a<=y):
    print(a)
elif(x<=a and x<=y):
    print(x)
elif(y<=a and y<=x):
    print(y)