rows = open('IMDbnames_f.csv', encoding='utf8').read().split('\n')

heights = {}
for r in rows:
    cols = r.split('#')
    if cols[2] and int(cols[2]) > 200:
        name = cols[1]
        if name in heights:
            heights[name] += 1
        else:
            heights[name] = 1

sorted_names = sorted(heights, key=lambda x: heights[x], reverse=True)

for name in heights:
    print(name)