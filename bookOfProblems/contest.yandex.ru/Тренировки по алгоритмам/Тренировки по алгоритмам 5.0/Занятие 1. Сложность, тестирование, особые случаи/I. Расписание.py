n = int(input())
year = int(input())
isleap = int((year % 400 == 0) or (year % 4 == 0 and year % 100 != 0))
monthsnames = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
]
monthsdays = [31, 28 + isleap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

holidays = set()

for i in range(n):
    day, month = input().split()
    day = int(day)
    holidays.add((day, month))
weekday = week.index(input())
nowday = 1
nowmonth = 0
daycount = {}
holicount = {}

for day in range(365 + isleap):
    daycount[weekday] = daycount.get(weekday, 0) + 1
    if (nowday, monthsnames[nowmonth]) in holidays:
        holicount[weekday] = holicount.get(weekday, 0) + 1
    weekday = (weekday + 1) % 7
    nowday += 1
    if nowday > monthsdays[nowmonth]:
        nowmonth += 1
        nowday = 1
mindays = 54
maxdays = -1
for weekday in range(7):
    daycount[weekday] -= holicount.get(weekday, 0)
    if daycount[weekday] < mindays:
        mindays = daycount[weekday]
        worstday = week[weekday]
    if daycount[weekday] > maxdays:
        maxdays = daycount[weekday]
        bestday = week[weekday]
print(bestday, worstday)
