import sys
input=sys.stdin.readline
class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
def insert(root,val):
    if root is None:
        return Node(val)
    if val<root.val:
        root.left=insert(root.left,val)
    else:
        root.right=insert(root.right,val)
    return root
def find(root,val):
    node=root
    while node is not None:
        if node.val==val:
            return node
        elif val<node.val:
            node=node.left
        else:
            node=node.right
    return None
def subtreesize(root):
    if root is None:
        return 0
    return 1+subtreesize(root.left)+subtreesize(root.right)
def solve():
    n=int(input())
    arr=list(map(int,input().split()))
    goal=int(input())
    root=None
    for x in arr:
        root=insert(root,x)
    node=find(root,goal)
    print(subtreesize(node))
if __name__=="__main__":
    solve()