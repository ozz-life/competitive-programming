"""Давайте повторим функциональность калькулятора краски на сайте OBI, только без количества слоев.
Округляйте значения, если нужно, только при их печати. Все вычисления производите с полной точностью."""

a = float(input())
h = float(input())
consumption = float(input())
v = int(input())
percent = int(input())

s = a * h
print(round(s, 2))
l = s / consumption * (1 + percent / 100)
print(round(l, 2))
import math

jars = math.ceil(l / v)
print(jars)
print(round(jars * v - l, 2))
