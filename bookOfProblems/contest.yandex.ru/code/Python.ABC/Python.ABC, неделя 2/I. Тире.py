# WA test 3

import re

arr = list(map(str, input().split()))
string = " ".join(arr)
string = re.sub(r"--", "—", string)

print(string)