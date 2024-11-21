arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

n, k = map(int, input().split())
arr = list(map(int, input().split()))
k_arr = list(map(int, input().split()))


def nearest_right_binary_search(arr, x):  # min i : a[i] >= x
    l = -1  # a[l] < x
    r = len(arr)  # a[r] >= x

    # теперь двигаем указатели, пока они не сойдутся в два соседних элемента
    # один из них будет, всегда меньше или равен, а другой всегда строго больше
    while (
        r > l + 1
    ):  # т.к l и r фиктивные элементы и находятся за пределами массива, в них нельзя тыкать напрямую, т.к можно обратится не туда,
        # поэтому мы всегда обращаемся к m, а m > l and m < r и никогда не ткнём в фиктивный элемент
        m = l + (r - l) // 2
        if arr[m] < x:
            l = m
        if arr[m] >= x:
            r = m

    return r + 1


for n in k_arr:
    print(nearest_right_binary_search(arr, n))
