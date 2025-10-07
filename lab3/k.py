n,s=map(int,input().split())
arr=list(map(int,input().split()))
left=0
currentsum=0
minlen=n+1
for right in range(n):
    currentsum+=arr[right]
    while currentsum>=s:
        minlen=min(minlen,right-left+1)
        currentsum-=arr[left]
        left+=1
print(minlen)