#!/usr/bin/env python3

rows = open('IMDbnames_f.csv', encoding="utf8").read().split("\n")

count = 0
for r in rows:
    cols = r.split("#")
    name, *lastname = cols[1].split(maxsplit=1)
    if "Brando" in lastname:
        count += 1

print(count)