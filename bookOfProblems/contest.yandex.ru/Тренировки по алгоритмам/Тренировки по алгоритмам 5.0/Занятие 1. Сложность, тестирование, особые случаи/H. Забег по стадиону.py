l, x1, v1, x2, v2 = map(int, input().split())

# 10**30 - признак, что это никогда не произойдёт
ans = 10**30 

for rotation in range(2):
    # расстояние от первого до второго и прибавили длину круга
    deltax = (x2 - x1 + l) % l
    deltav = v1 - v2
    if deltav < 0:
        # Скорость убегания одного от другого, на самом деле скорость догоняния, поэтому смотрим в другом порядке
        deltav = -deltav
        deltax = (-deltax + l) % l
    if deltax == 0:
        ans = 0
    if deltav != 0:
        ans = min(ans, deltax / deltav)
    # Представляем зеркальное отображение
    x2 = (-x2 + l) % l
    v2 = -v2
if ans == 10**30:
    print('NO')
else:
    print('YES')
    print(ans)