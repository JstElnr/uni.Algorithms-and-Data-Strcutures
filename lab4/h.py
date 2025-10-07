import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline
class Node:
    __slots__=('val','left','right')
    def __init__(self,v):
        self.val=v
        self.left=None
        self.right=None
def insert(root,val):
    if not root:
        return Node(val)
    if val<root.val:
        root.left=insert(root.left,val)
    else:
        root.right=insert(root.right,val)
    return root
def buildbst(arr):
    root=None
    for v in arr:
        root=insert(root,v)
    return root
def togreatersum(root):
    total=0
    def dfs(node):
        nonlocal total
        if not node: return
        dfs(node.right)
        total+=node.val
        node.val=total
        dfs(node.left)
    dfs(root)
def solve():
    n=int(input())
    vals=list(map(int,input().split()))
    root=buildbst(vals)
    togreatersum(root)
    res=[]
    def inorder(node):
        if not node: return
        inorder(node.left)
        res.append(node.val)
        inorder(node.right)
    inorder(root)
    print(*res[::-1])
if __name__=="__main__":
    solve()