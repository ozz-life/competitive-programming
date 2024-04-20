rub_to_usd = float(input())
usd_to_rub = 1 / rub_to_usd
usd_to_eur = float(input())
eur_to_usd = 1 / usd_to_eur

rub_to_eur = round(usd_to_rub * eur_to_usd, 2)

print(rub_to_eur)
