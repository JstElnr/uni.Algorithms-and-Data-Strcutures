def cancatch(sheep,k,L):
    count=0
    for x1,y1,x2,y2 in sheep:
        if x2<=L and y2<=L:
            count+=1
    return count>=k
def minsqrtsize(n,k,sheep):
    left=0
    right=10**9
    answer=right
    while left<=right:
        mid=(left+right)//2
        if cancatch(sheep,k,mid):
            answer=mid
            right=mid-1
        else:
            left=mid+1
    return answer
n,k=map(int,input().split())
sheep=[tuple(map(int,input().split())) for i in range(n)]
print(minsqrtsize(n,k,sheep))