s1,s2=input().split()
st1=[]
for ch in s1:
    if ch=="#":
        if st1:
            st1.pop()
    else:
        st1.append(ch)
st2=[]
for ch in s2:
    if ch=="#":
        if st2:
            st2.pop()
    else:
        st2.append(ch)
print("Yes" if ''.join(st1)==''.join(st2) else "No")
