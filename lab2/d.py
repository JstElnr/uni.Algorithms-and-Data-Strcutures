from collections import Counter
n=int(input().strip())
arr=list(map(int,input().split()))
freq=Counter(arr)
maxcount=max(freq.values())
modes=[]
for num,count in freq.items():
    if count==maxcount:
        modes.append(num)
modes.sort(reverse=True)
print(*modes)