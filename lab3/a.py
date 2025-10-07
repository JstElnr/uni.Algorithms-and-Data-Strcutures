t=int(input())
goals=list(map(int,input().split()))
n,m=map(int,input().split())
matrix=[list(map(int,input().split())) for i in range(n)]
pos={}
for j in range(n):
    for k in range(m):
        if matrix[j][k] not in pos:
            pos[matrix[j][k]]=(j,k)
for x in goals:
    if x in pos:
        print(*pos[x])
    else:
        print(-1)