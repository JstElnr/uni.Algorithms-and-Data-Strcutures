from collections import deque
n=int(input())
s=input().strip()
qS=deque()
qK=deque()
for i,ch in enumerate(s):
    if ch=='S':qS.append(i)
    else:qK.append(i)
while qS and qK:
    iS=qS.popleft()
    iK=qK.popleft()
    if iS<iK:qS.append(iS+n)
    else:qK.append(iK+n)
print("SAKAYANAGI" if qS else "KATSURAGI")