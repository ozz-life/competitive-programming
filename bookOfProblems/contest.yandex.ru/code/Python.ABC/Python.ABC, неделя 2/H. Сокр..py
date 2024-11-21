arr = list(map(str, input().split()))

for i, word in enumerate(arr):
    if "ический" in word:
        arr[i] = word.replace("ический", ".")
    elif "ическая" in word:
        arr[i] = word.replace("ическая", ".")

print(" ".join(arr))
