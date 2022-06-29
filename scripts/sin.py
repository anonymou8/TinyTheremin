'''
    Sine table generation script; half wave.

    Full wave is symmetrical if harmonics' phases are alighed at 0.
'''

from math import sin, pi

n = 2048

for i in range(n):
    a = i/n * pi

    # Simple sine; inverted
    #~ s = 1 - sin(a)

    # 1st + 6th harmonics; inverted
    s = 1 - (sin(a) + 0.5*sin(a*6)) / 1.5

    print(f'{round(127 * s):>3}, ', end='')

    if not (i+1) % 32:
        print()


