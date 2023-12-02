arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

n, k = map(int, input().split())
arr = list(map(int, input().split()))
k_arr = list(map(int, input().split()))


def binary_search(arr, x):
    # берём отрезок, с нулевого до последнего элемента
    l = 0
    r = len(arr) - 1
    
    # на этом отрезке ищем элемент Х. Пока отрезок не пустой
    while l <= r: # иди r >= l, не важно
        # мы тыкаемся в середину. Объявляем миддл внутри цикла.
        m = l + (r - l) // 2
        if arr[m] == x:
            return "YES"
        # если элемент меньше Х, это значит что все элементы левее ещё меньше, поэтому надо искать с m + 1
        if arr[m] < x:
            l = m + 1
        if arr[m] > x:
            r = m - 1
    # Если while закончился, то значит мы отрезок проверили и он остался пустым, выводим None
    return "NO"


for n in k_arr:
    print(binary_search(arr, n))
