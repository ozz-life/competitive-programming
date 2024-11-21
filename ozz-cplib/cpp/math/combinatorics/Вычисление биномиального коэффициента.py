# при вызове функции заполняем все, что выше/левее
# в списке биномиальных коэффициентов bcs храним значения, начиная с n=4 и k=2
def Binc(bcs, n, k):
    if k > n:
        return 0
    if k > n // 2:
        k = n - k  # страшую часть строки не храним - она симметрична
    if k == 0:
        return 1
    if k == 1:
        return n
    while len(bcs) < n - 3:
        # заполняем выше
        for i in range(len(bcs), n - 3):
            r = []
            for j in range(2, i // 2 + 3):
                r.append(Binc(bcs, i + 3, j - 1) + Binc(bcs, i + 3, j))
            bcs.append(r)
    r = bcs[n - 4]
    if len(r) < k - 1:
        # заполняем левее
        for i in range(len(r), k - 1):
            r.append(Binc(bcs, n - 1, k - 1) + Binc(bcs, n - 1, k))
    return bcs[n - 4][k - 2]


# конец функции

# для контоля рассчитаем C(1000,500)
bcs = []  # пустой список биномиальных коэффициентов
t1 = time.clock()
print(Binc(bcs, 1000, 500))
t2 = time.clock()
print(t2 - t1)

# а это вывод таблички из начала статьи
for n in range(0, 16):
    print("n=%2d " % n, end="")
    for k in range(0, n + 1):
        print("%5d" % Binc(bcs, n, k), end="")
    print()
