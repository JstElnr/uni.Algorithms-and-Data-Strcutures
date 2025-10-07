import sys
sys.setrecursionlimit(20000)
input=sys.stdin.readline
class Node:
    __slots__=('val','left','right')
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
def insert(root,val):
    cur=root
    while True:
        if val<cur.val:
            if cur.left is None:
                cur.left=Node(val)
                return
            cur=cur.left
        else:
            if cur.right is None:
                cur.right=Node(val)
                return
            cur=cur.right
def counttriangles(root):
    if root is None:
        return 0
    cnt=0
    if root.left is not None and root.right is not None:
        cnt+=1
    cnt+=counttriangles(root.left)
    cnt+=counttriangles(root.right)
    return cnt
def solve():
    n=int(input())
    values=list(map(int,input().split()))
    if n==0:
        print(0)
        return
    root=Node(values[0])
    for v in values[1:]:
        insert(root,v)
    print(counttriangles(root))
if __name__=="__main__":
    solve()