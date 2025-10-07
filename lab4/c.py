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
    node=root
    while True:
        if val<node.val:
            if node.left is None:
                node.left=Node(val)
                break
            node=node.left
        else:
            if node.right is None:
                node.right=Node(val)
                break
            node=node.right
    return root
def find(root,val):
    node=root
    while node:
        if node.val==val:
            return node
        elif val<node.val:
            node=node.left
        else:
            node=node.right
    return None
def preorder(root):
    stack=[]
    node=root
    while stack or node:
        if node:
            print(node.val,end=' ')
            if node.right:
                stack.append(node.right)
            node=node.left
        else:
            node=stack.pop()
def solve():
    n=int(input())
    gifts=list(map(int,input().split()))
    k=int(input())
    root=None
    for val in gifts:
        root=insert(root,val)
    node=find(root,k)
    if node:
        preorder(node)
    print()
if __name__=="__main__":
    solve()