import bisect
n=int(input())
arr=list(map(int,input().split()))
x=int(input())
idx=bisect.bisect_left(arr,x)
if idx<n and arr[idx]==x:
    print("Yes")
else:
    print("No")