from collections import deque,Counter
t=int(input())
for _ in range(t):
    n=int(input())
    arr=input().split()
    cnt=Counter()
    q=deque()
    res=[]
    for ch in arr:
        cnt[ch]+=1
        q.append(ch)
        while q and cnt[q[0]]>1:
            q.popleft()
        res.append(q[0] if q else "-1")
    print(" ".join(res))