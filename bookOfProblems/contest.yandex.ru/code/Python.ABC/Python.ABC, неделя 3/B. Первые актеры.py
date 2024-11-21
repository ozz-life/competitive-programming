#!/usr/bin/env python3

rows = open('IMDbnames_f.csv', encoding="utf8").read().split("\n")
for r in rows[0:10]:
    cols = r.split("#")
    print(cols[1])