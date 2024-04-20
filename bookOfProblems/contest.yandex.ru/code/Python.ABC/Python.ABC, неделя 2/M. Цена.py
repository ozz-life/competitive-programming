import re

string = str(input())
only_digits = re.sub(r"\D", "", string)
only_digits = int(only_digits)
print(only_digits + 1)
