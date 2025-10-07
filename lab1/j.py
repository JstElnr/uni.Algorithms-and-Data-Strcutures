from collections import deque
import sys
dq = deque()
for line in sys.stdin:
    line =line.strip()
    if not line:
        continue
    if line =='!':
        break
    if line[0] =='+':
        _, num =line.split()
        dq.appendleft(int(num))
    elif line[0] =='-':
        _, num =line.split()
        dq.append(int(num))
    elif line[0] =='*':
        if not dq:
            print("error")
        else:
            if len(dq) ==1:
                val =dq.popleft()
                print(val * 2)
            else:
                val =dq[0] +dq[-1]
                dq.popleft()
                dq.pop()
                print(val)