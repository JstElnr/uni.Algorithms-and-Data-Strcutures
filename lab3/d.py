from bisect import bisect_left,bisect_right
n,q=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
for i in range(q):
    a,b,c,d=map(int,input().split())
    count1=bisect_right(arr,b)-bisect_left(arr,a)
    count2=bisect_right(arr,d)-bisect_left(arr,c)
    inter_left=max(a,c)
    inter_right=min(b,d)
    if inter_left<=inter_right:
        overlap=bisect_right(arr,inter_right)-bisect_left(arr,inter_left)
    else:
        overlap=0
    ans=count1+count2-overlap
    print(ans)