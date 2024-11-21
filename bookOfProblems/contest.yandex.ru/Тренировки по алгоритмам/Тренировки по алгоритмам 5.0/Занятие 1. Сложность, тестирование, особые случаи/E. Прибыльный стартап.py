n, k, d = map(int, input().split())

nowmod = n % k
ans = [n]
flag = True

for i in range(d):
    for newdigit in range(10):
        newmod = (nowmod * 10 + newdigit) % k
        if newmod == 0:
            ans.append(newdigit)
            nowmod = newmod
            break
    else:
        flag = False

if flag:
    print(''.join(map(str, ans)))
else:
    print(-1)
