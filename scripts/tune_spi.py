'''
    Displays data from AVR flashed with `tune_spi.bin`
'''

import serial, sys

ser = serial.Serial('/dev/ttyUSB0', 115200)

n = 1152//2

while True:
    ser.write(bytes([0]) * n)
    r = ser.read(n)

    # Write raw bytes to stdout
    #~ sys.stdout.buffer.write(r); continue

    # Display as two bars
    c1 = r[0::2]    # PB3
    c2 = r[1::2]    # PB4
    a1 = sum(c1) / len(c1)
    a2 = sum(c2) / len(c2)
    s1 = '#' * int(a1/255 * 32)
    s2 = '#' * int(a2/255 * 32)
    print(f'{a1:5.1f} {s1:<32} {a2:5.1f} {s2:<32}')



