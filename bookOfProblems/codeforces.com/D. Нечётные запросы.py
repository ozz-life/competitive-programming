import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    # сделать prefix_sum
    a = [0] + a
    for i in range(1, n + 1):
        a[i] += a[i - 1]

    for i in range(q):
        l, r, k = map(int, input().split())
        if (k * (r - l + 1) + a[l - 1] + a[-1] - a[r]) % 2:
            print("YES")
        else:
            print("NO")