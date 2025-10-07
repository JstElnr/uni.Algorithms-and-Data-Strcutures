from bisect import bisect_right
n=int(input())
powers=list(map(int,input().split()))
powers.sort()
prefixsum=[0]*(n+1)
for i in range(n):
    prefixsum[i+1]=prefixsum[i]+powers[i]
q=int(input())
for j in range(q):
    markpower=int(input())
    idx=bisect_right(powers,markpower)
    totalpower=prefixsum[idx]
    print(idx,totalpower)