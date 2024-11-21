from datetime import datetime

seconds = int(input())
date = datetime.fromtimestamp(seconds)
year = date.year
print(year)
