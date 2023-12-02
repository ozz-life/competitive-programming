#!/usr/bin/env python
# import sys

# открываем файлы для чтения и записи
with open("input.txt", "r") as fin, open("output.txt", "w") as fout:
    n, k = fin.readline().split()

    a_arr = list(map(int, fin.readline().split()))
    k_arr = list(map(int, fin.readline().split()))

    def binary_search(a, x):
        l = 0
        r = len(a) - 1
        while l <= r:
            m = l + (r - l) // 2
            if a[m] == x:
                print("YES", file=fout)
                return
            if a[m] < x:
                l = m + 1
            if a[m] > x:
                r = m - 1

        print("NO", file=fout)

    for x in k_arr:
        binary_search(a_arr, x)
