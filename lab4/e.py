from collections import deque,defaultdict
import sys
input=sys.stdin.readline
def solve():
    n=int(input())
    left=[0]*(n+1)
    right=[0]*(n+1)
    for i in range(n-1):
        x,y,z=map(int,input().split())
        if z==0:
            left[x]=y
        else:
            right[x]=y
    q=deque([(1,1)])
    levelcount=defaultdict(int)
    maxwidth=0
    while q:
        node,lvl=q.popleft()
        levelcount[lvl]+=1
        if levelcount[lvl]>maxwidth:
            maxwidth=levelcount[lvl]
        if left[node]:
            q.append((left[node],lvl+1))
        if right[node]:
            q.append((right[node],lvl+1))
    print(maxwidth)
if __name__=="__main__":
    solve()