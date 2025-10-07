n=int(input().strip())
names=[]
for i in range(n):
    name=input().strip()
    names.append(name)
unique=[]
prev=None
for name in names:
    if name!=prev:
        unique.append(name)
    prev=name
unique.reverse()
print("All in all:",len(unique))
print("Students:")
for name in unique:
    print(name)