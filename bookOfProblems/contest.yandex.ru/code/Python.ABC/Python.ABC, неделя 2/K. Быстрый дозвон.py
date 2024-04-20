s = str(input())

startA = """<a href="tel:"""
startB = """\">"""
end = """</a>"""

print(f"{startA}{s}{startB}{s}{end}")