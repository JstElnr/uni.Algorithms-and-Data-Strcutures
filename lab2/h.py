class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
def insert_node(head,x,p):
    new=Node(x)
    if p==0:
        new.next=head
        return new
    cur=head
    for _ in range(p-1):
        cur=cur.next
    new.next=cur.next
    cur.next=new
    return head
def remove_node(head,p):
    if p==0:
        return head.next
    cur=head
    for _ in range(p-1):
        cur=cur.next
    cur.next=cur.next.next
    return head
def print_list(head):
    if not head:
        print(-1)
        return
    cur=head
    while cur:
        print(cur.data,end=" ")
        cur=cur.next
    print()
def replace_node(head,p1,p2):
    if p1==p2:
        return head
    prev1=None
    cur1=head
    for _ in range(p1):
        prev1=cur1
        cur1=cur1.next
    if prev1:
        prev1.next=cur1.next
    else:
        head=cur1.next
    if p2==0:
        cur1.next=head
        return cur1
    cur2=head
    for _ in range(p2-1):
        cur2=cur2.next
    cur1.next=cur2.next
    cur2.next=cur1
    return head
def reverse_list(head):
    prev=None
    cur=head
    while cur:
        nxt=cur.next
        cur.next=prev
        prev=cur
        cur=nxt
    return prev
def length(head):
    c=0
    cur=head
    while cur:
        c+=1
        cur=cur.next
    return c
def cyclic_left(head,x):
    if not head or not head.next:
        return head
    n=length(head)
    x%=n
    if x==0:
        return head
    cur=head
    for _ in range(x-1):
        cur=cur.next
    new_head=cur.next
    cur.next=None
    tail=new_head
    while tail.next:
        tail=tail.next
    tail.next=head
    return new_head
def cyclic_right(head,x):
    if not head or not head.next:
        return head
    n=length(head)
    x%=n
    return cyclic_left(head,n-x)
head=None
while True:
    try:
        cmd=input().strip().split()
    except:
        break
    if not cmd:break
    c=int(cmd[0])
    if c==0:
        break
    elif c==1:
        x=int(cmd[1]);p=int(cmd[2])
        head=insert_node(head,x,p)
    elif c==2:
        p=int(cmd[1])
        head=remove_node(head,p)
    elif c==3:
        print_list(head)
    elif c==4:
        p1=int(cmd[1]);p2=int(cmd[2])
        head=replace_node(head,p1,p2)
    elif c==5:
        head=reverse_list(head)
    elif c==6:
        x=int(cmd[1])
        head=cyclic_left(head,x)
    elif c==7:
        x=int(cmd[1])
        head=cyclic_right(head,x)