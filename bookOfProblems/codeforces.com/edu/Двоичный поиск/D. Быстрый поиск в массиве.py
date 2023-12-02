def leftside_binary_search(a, x):
    l = -1
    r = len(a)

    while l + 1 < r:
        m = l + (r - l) // 2
        if a[m] <= x:
            l = m
        if a[m] > x:
            r = m

    return l + 1 # в с l

def rightside_binary_search(a, x):  # min i : a[i] >= x
    l = -1
    r = len(a)
    while l + 1 < r:
        m = l + (r - l) // 2
        if a[m] < x:
            l = m
        if a[m] >= x:
            r = m

    return r + 1 # в с r

n = int(input())
a = list(map(int, input().split()))
k = int(input())
lr = []

for line in range(k):
    l, r = map(int, input().split())
    lr.append([l, r])

a.sort()

for pair in lr:
    l, r = pair
    low = leftside_binary_search(a, r)
    high = rightside_binary_search(a, l)
    print(high - low + 1)
# First sort the array and then You have to calculate two index:
# left = index of leftmost element which is greater or equal to l
# right = index of rightmost element which is less than or equal to r
# Now your answer will be right — left + 1.

# массив от 0 до n - 1
# left = -1  # a[left] <= x
# right = n  # a[right] > x
# while right - left > 1:
#     mid = (left + right) // 2
#     if a[mid] <= x:
#         left = mid
#     else:
#         right = mid
# print(left)
