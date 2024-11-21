#!/usr/bin/env python3

rows = open("IMDbnames_f.csv", encoding="utf8").read().split("\n")

count = 0
for r in rows:
    cols = r.split("#")
    cause_of_death = cols[5].lower()
    if "natural" in cause_of_death and "causes" in cause_of_death:
        count += 1

print(count)
