def balanced(arr):
    arr.sort()
    def helper(subarr):
        if not subarr:
            return []
        mid=len(subarr)//2
        return [subarr[mid]]+helper(subarr[:mid])+helper(subarr[mid+1:])
    return helper(arr)
n=int(input())
arr=list(map(int,input().split()))
result=balanced(arr)
print(' '.join(map(str,result)))
