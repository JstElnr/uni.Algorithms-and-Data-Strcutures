import math
n,h=map(int,input().split())
bags=list(map(int,input().split()))
def canfinish(speed):
    hours=0
    for b in bags:
        hours+=math.ceil(b/speed)
    return hours<=h
left,right=1,max(bags)
ans=right
while left<=right:
    mid=(left+right)//2
    if canfinish(mid):
        ans=mid
        right=mid-1
    else:
        left=mid+1
print(ans)