import sys 

N,M = map(int, sys.stdin.readline().split(' '))
woods = list(map(int, sys.stdin.readline().split(' ')))

start, end = 0, max(woods)
mid = 0

while start <= end : 
    rest = 0  
    mid = (start + end) // 2
    for i in range(N) : 
        if woods[i]- mid > 0 : 
            rest+= woods[i]- mid
        
    if rest >= M : 
        start = mid + 1
    else :
        end = mid - 1

print(end)