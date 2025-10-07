n=int(input().strip())
arr=list(map(int,input().split()))
x=int(input().strip())
mindist=abs(arr[0]-x)
idx=0
for i in range(1,n):
    dist=abs(arr[i]-x)
    if dist<mindist:
        mindist=dist
        idx=i
print(idx)