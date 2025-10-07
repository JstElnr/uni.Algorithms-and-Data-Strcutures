from collections import deque
b=deque(map(int,input().split()))
n=deque(map(int,input().split()))
for step in range(1,10**6+1):
    x,y=b.popleft(),n.popleft()
    if (x==0 and y==9) or (x>y and not(x==9 and y==0)):
        b.append(x);b.append(y)
    else:
        n.append(x);n.append(y)
    if not b:
        print("Nursik",step);break
    if not n:
        print("Boris",step);break
else:
    print("blin nichya")