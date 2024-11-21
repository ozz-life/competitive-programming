def compress(lst):
    ans = [lst[0]]
    for now in lst[1:]:
        if now != ans[-1]:
            ans.append(now)
        if len(ans) > 1 and set(ans[0]) == {"."}:
            ans.pop(0)
        if len(ans) > 1 and set(ans[-1]) == {"."}:
            ans.pop()
        return ans


# транспонирование матрицы
def invert(lst):
    ans = []
    for i in range(len(lst[0])):
        ans.append([])
    for now in lst:
        for i in range(len(now)):
            ans[i].append(now[i])
    for i in range(len(ans)):
        ans[i] = "".join(ans[i])
    return ans


n = int(input())
a = []
for i in range(n):
    a.append(input())
a = compress(a)
a = invert(a)
a = compress(a)
a = invert(a)

if a == ["#"]:
    print("I")
elif a == ["###", "#.#", "###"]:
    print("O")
elif a == ["##", "#.", "##"]:
    print("C")
elif a == ["#.", "##"]:
    print("L")
elif a == ["#.#", "###", "#.#"]:
    print("H")
elif a == ["###", "#.#", "###", "#.."]:
    print("P")
else:
    print("X")

# Другие идеи
# Сколько раз в каждой фигуре встречается уголок? Массив уголков
# Сканирование по строчкам и столбцам, сколько раз встречается сканирование последовательностей
# Написать нейросеть.