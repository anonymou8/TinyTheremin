'''
    Linearization and correction tables script
'''

from math import log

def log_sqrt(x, a, b, c):
    # for `y1 ~ exp((x1^2+a)/b) + c`
    if x <= c:
        return 0
    y = b * log(x - c) - a
    if y < 0:
        return 1
    elif y > 1:
        return 0
    return 1 - y**0.5

def hyp_fwd(x, k, a, c):
    if x >= a:
        return 255
    y = k / (x-a) + c
    if y < 0:
        return 0
    elif y > 255:
        return 255
    return round(y)

# -----------------------------------------------------

for x in range(256):
    # for volume
    y3 = log_sqrt(x, -0.546628, -0.0989998, -0.0102598)
    y3 = hyp_fwd(y3, -41, 0.95, -44)

    # for frequency
    y4 = log_sqrt(x, -0.754761, -0.136679, -0.166249)

    # Volume correction table
    #~ print(f'{255-y3:>3}, ', end='')

    # Frequency correction table
    print(f'{round(y4 * 255):>3}, ', end='')

    # Tone correction table
    #~ d = 21.5
    #~ t = round(y4 * (d + 35) - d)
    #~ print(f'{t * (t>0):>3}, ', end='')

    if not (x+1) % 16:
        print()








