s =input().strip()
stack =[]
for char in s:
    if stack and stack[-1] ==char:
        stack.pop()
    else:
        stack.append(char)
print("YES" if not stack else "NO")