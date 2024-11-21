n = int(input())
length = len(str(n))

arr = []
for i in range(length):
    arr.append(n % 10)
    n //= 10

print(sum(arr))
