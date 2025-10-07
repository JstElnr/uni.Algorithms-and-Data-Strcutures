import sys
import bisect
def solve():
    input=sys.stdin.readline
    n,m=map(int,input().split())
    blocks=list(map(int,input().split()))
    prefixsum=[]
    total=0
    for b in blocks:
        total+=b
        prefixsum.append(total)
    for i in range(m):
        mistakeline=int(input())
        blockindex=bisect.bisect_left(prefixsum,mistakeline)
        print(blockindex+1)
if __name__=="__main__":
    solve()