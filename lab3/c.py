from bisect import bisect_left,bisect_right
n,q=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
def countrange(L,R):
    return bisect_right(a,R)-bisect_left(a,L)
for i in range(q):
    l1,r1,l2,r2=map(int,input().split())
    L_int=max(l1,l2)
    R_int=min(r1,r2)
    count=countrange(l1,r1)+countrange(l2,r2)
    if L_int<=R_int:
        count-=countrange(L_int,R_int)
    print(count)