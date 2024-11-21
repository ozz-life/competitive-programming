def bestteamsum(players):
    bestsum = 0
    nowsum = 0
    last = 0
    for first in range(len(players)):
        while last < len(players) and (
            last == first or players[first] + players[first + 1] >= players[last]
        ):
            nowsum += players[last]
            last += 1
        bestsum = max(bestsum, nowsum)
        nowsum -= players[first]
    return bestsum
