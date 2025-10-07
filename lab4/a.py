import sys
input=sys.stdin.readline
def solve():
    n,m=map(int,input().split())
    arr=list(map(int,input().split()))
    paths=[input().strip() for r in range(m)]
    tree=[[val,None,None] for val in arr]
    root=0
    for i in range(1,n):
        node=root
        while True:
            if arr[i]<tree[node][0]:
                if tree[node][1] is None:
                    tree[node][1]=i
                    break
                node=tree[node][1]
            else:
                if tree[node][2] is None:
                    tree[node][2]=i
                    break
                node=tree[node][2]
    for path in paths:
        node=root
        ok=True
        for c in path:
            if node is None:
                ok=False

                break
            node=tree[node][1] if c=='L' else tree[node][2]
        if node is None:
            ok=False
        print("YES" if ok else "NO")
if __name__=="__main__":
    solve()