import sys

n, r, c = map(int, sys.stdin.readline().split(' '))

ans = 0 
def solution(x,y,n) : 
    global ans
    if x == r and y == c : 
        print(ans)
        exit()
    if n == 1: 
        ans +=1 
        return 
    if not (x<=r<x+n and y<=c<y+n) : 
        ans += n*n 
        return 
    temp = n//2
    solution(x,y,temp)
    solution(x, y+temp, temp)
    solution(x+temp, y, temp)
    solution(x+temp, y+temp, temp)

solution(0,0,2**n)
print(ans)
        