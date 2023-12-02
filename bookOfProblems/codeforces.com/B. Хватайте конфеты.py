t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    mihay = 0
    byanka = 0 

    for i in a:
        if i % 2 == 0:
            mihay += i
        else:
            byanka += i

    if mihay > byanka:
        print("YES")
    else:
        print("NO")
