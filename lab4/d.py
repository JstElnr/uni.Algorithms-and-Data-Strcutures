import sys
sys.setrecursionlimit(10000)
input=sys.stdin.readline
class Node:
    __slots__=('val','left','right','level')
    def __init__(self,val,level):
        self.val=val
        self.left=None
        self.right=None
        self.level=level
def insert(root,val):
    cur=root
    while True:
        if val<cur.val:
            if cur.left is None:
                cur.left=Node(val,cur.level+1)
                return cur.left
            cur=cur.left
        else:
            if cur.right is None:
                cur.right=Node(val,cur.level+1)
                return cur.right
            cur=cur.right
def solve():
    n=int(input())
    arr=list(map(int,input().split()))
    root=Node(arr[0],0)
    levelsums={0:arr[0]}
    maxlevel=0
    for val in arr[1:]:
        node=insert(root,val)
        lvl=node.level
        levelsums[lvl]=levelsums.get(lvl,0)+val
        if lvl>maxlevel:
            maxlevel=lvl
    print(maxlevel+1)
    print(' '.join(str(levelsums.get(i,0)) for i in range(maxlevel+1)))
if __name__=="__main__":
    solve()