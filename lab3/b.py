n,k=map(int,input().split())
a=list(map(int,input().split()))
def cansplit(maxsum):
    count=1
    current=0
    for x in a:
        if current+x>maxsum:
            count+=1
            current=x
        else:
            current+=x
    return count<=k
lo,hi=max(a),sum(a)
while lo<hi:
    mid=(lo+hi)//2
    if cansplit(mid):
        hi=mid
    else:
        lo=mid+1
print(lo)