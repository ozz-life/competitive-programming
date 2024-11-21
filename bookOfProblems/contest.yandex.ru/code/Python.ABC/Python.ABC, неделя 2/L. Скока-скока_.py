n = str(input())
n = n[::-1]

groups = [n[i : i + 3] for i in range(0, len(n), 3)]

result = " ".join(groups)[::-1]

print(result)
