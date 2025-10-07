def solve():
    import sys
    input=sys.stdin.readline
    n=int(input())
    ages=list(map(int,input().split()))
    stack=[]
    res=[]
    for age in ages:
        while stack and stack[-1]>age:
            stack.pop()
        if not stack:
            res.append(-1)
        else:
            res.append(stack[-1])
        stack.append(age)
    print(" ".join(map(str,res)))
if __name__=="__main__":
    solve()