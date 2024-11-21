n, k = map(int, input().split())
s = input
d = dict()

l = r = bestl = bestr = 0

while r < n:
    if d.get(s[r], 0) < k:
        if r - l > bestr - bestl:
            bestr, bestl = r, l
        d[s[r]] = d.get(s[r], 0) + 1
        r += 1
    else:
        while l < n and d.get(s[r], 0) >= k:
            d[s[l]] -= 1
            l += 1
    print(bestr - bestl + 1, bestl + 1)
