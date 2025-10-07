def solve():
    import sys, math
    data = sys.stdin.read().strip()
    if not data:
        return
    n = int(data)
    if n <= 1:
        print("NO")
        return
    if n <= 3:
        print("YES")
        return
    if n % 2 == 0 or n % 3 == 0:
        print("NO")
        return
    limit = int(math.isqrt(n))
    i = 5
    while i <= limit:
        if n % i == 0 or n % (i + 2) == 0:
            print("NO")
            return
        i += 6
    print("YES")
if __name__ == "__main__":
    solve()