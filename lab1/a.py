import sys
from collections import deque
input=sys.stdin.readline
t=int(input())
for i in range(t):
    n=int(input())
    dq=deque()
    for j in range(n,0,-1):
        dq.appendleft(j)
        for k in range(j):
            dq.appendleft(dq.pop())
    sys.stdout.write(" ".join(map(str,dq))+"\n")