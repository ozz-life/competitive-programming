s = 'ZpglnRxqenU'

def accum(s):
    arr = [char.upper() for char in s]
    result = ""

    for i, char in enumerate(arr):
        if i == 0:
            result += char.capitalize()
        result += (char * (i + 1)).capitalize()
        result += "-"

    return result[1:-1]