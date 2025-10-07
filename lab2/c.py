class Node:
    def __init__(self,val):
        self.val=val
        self.next=None
n=int(input())
values=list(map(int,input().split()))
head=Node(values[0])
cur=head
for v in values[1:]:
    cur.next=Node(v)
    cur=cur.next
cur=head
while cur and cur.next:
    cur.next=cur.next.next
    cur=cur.next
cur=head
res=[]
while cur:
    res.append(str(cur.val))
    cur=cur.next
print(" ".join(res))
