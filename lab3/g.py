import math
def solve():
    import sys
    input=sys.stdin.readline
    n,m=map(int,input().split())
    gifts=list(map(int,input().split()))
    def can(capacity):
        flights=0
        for g in gifts:
            flights+=(g+capacity-1)//capacity
            if flights>m:
                return False
        return flights<=m
    low,high=1,max(gifts)
    ans=high
    while low<=high:
        mid=(low+high)//2
        if can(mid):
            ans=mid
            high=mid-1
        else:
            low=mid+1
    print(ans)
if __name__=="__main__":
    solve()