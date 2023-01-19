a = True
b = False
x = 7
if a:
    x = 5
    if b:
        y = 4
    elif a:
        y = 3
    elif b:
        y = 4
        print(f, x, a)
    elif c:
        y = 6
    else:
        y = 2

z = (x * 3 * 7) / y

if z > 10:
    y = 5
