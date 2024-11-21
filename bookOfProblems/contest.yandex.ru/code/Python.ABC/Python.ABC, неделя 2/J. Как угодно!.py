import re

arr = list(map(str, input().split()))
string = "".join(arr)
string = re.sub(r"\(", "", string)
string = re.sub(r"\)", "", string)
string = re.sub(r"\s+", "", string)
string = re.sub(r"-", "", string)

print(string)