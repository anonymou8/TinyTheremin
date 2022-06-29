'''
    Script to find optimal tone values for quantized scales
'''

from math import floor, ceil, log2

fn = [
    (65.40639132514966 , 'C2  '),
    (69.29565774421802 , 'C#2 '),
    (73.41619197935188 , 'D2  '),
    (77.78174593052023 , 'D#2 '),
    (82.4068892282175  , 'E2  '),
    (87.30705785825097 , 'F2  '),
    (92.4986056779086  , 'F#2 '),
    (97.99885899543733 , 'G2  '),
    (103.82617439498628, 'G#2 '),
    (110.0             , 'A2  '),
    (116.54094037952248, 'A#2 '),
    (123.47082531403103, 'B2  '),

    (130.8127826502993 , 'C3  '),
    (138.59131548843604, 'C#3 '),
    (146.8323839587038 , 'D3  '),
    (155.56349186104046, 'D#3 '),
    (164.81377845643496, 'E3  '),
    (174.61411571650194, 'F3  '),
    (184.9972113558172 , 'F#3 '),
    (195.99771799087463, 'G3  '),
    (207.65234878997256, 'G#3 '),
    (220.0             , 'A3  '),
    (233.08188075904496, 'A#3 '),
    (246.94165062806206, 'B3  '),

    (261.6255653005986 , 'C4  '),
    (277.1826309768721 , 'C#4 '),
    (293.6647679174076 , 'D4  '),
    (311.1269837220809 , 'D#4 '),
    (329.6275569128699 , 'E4  '),
    (349.2282314330039 , 'F4  '),
    (369.9944227116344 , 'F#4 '),
    (391.99543598174927, 'G4  '),
    (415.3046975799451 , 'G#4 '),
    (440.0             , 'A4  '),
    (466.1637615180899 , 'A#4 '),
    (493.8833012561241 , 'B4  '),

    (523.2511306011972 , 'C5  '),
    (554.3652619537442 , 'C#5 '),
    (587.3295358348151 , 'D5  '),
    (622.2539674441618 , 'D#5 '),
    (659.2551138257398 , 'E5  '),
    (698.4564628660078 , 'F5  '),
    (739.9888454232688 , 'F#5 '),
    (783.9908719634985 , 'G5  '),
    (830.6093951598903 , 'G#5 '),
    (880.0             , 'A5  '),
    (932.3275230361799 , 'A#5 '),
    (987.7666025122483 , 'B5  '),

    (1046.5022612023945, 'C6  '),
    (1108.7305239074883, 'C#6 '),
    (1174.6590716696303, 'D6  '),
    (1244.5079348883237, 'D#6 '),
    (1318.5102276514797, 'E6  '),
    (1396.9129257320155, 'F6  '),
    (1479.9776908465376, 'F#6 '),
    (1567.981743926997 , 'G6  '),
    (1661.2187903197805, 'G#6 '),
    (1760.0            , 'A6  '),
    (1864.6550460723597, 'A#6 '),
    (1975.533205024496 , 'B6  '),

    (2093.004522404789 , 'C7  '),
    (2217.4610478149766, 'C#7 '),
    (2349.31814333926  , 'D7  '),
    (2489.0158697766474, 'D#7 '),
    (2637.02045530296  , 'E7  '),
    (2793.825851464031 , 'F7  '),
    (2959.955381693075 , 'F#7 '),
    (3135.9634878539946, 'G7  '),
    (3322.437580639561 , 'G#7 '),
    (3520.0            , 'A7  '),
    (3729.3100921447194, 'A#7 '),
    (3951.066410048992 , 'B7  '),
]

def ndiff(f, f440):
    # in cents
    return log2(f/f440) * 1200

f0 = 16e6 / (16*13) / (2048*2) / 4
f0k = f0 * 0.86845

print('#   : note : val : cents (floor,  ceil)')

for i,(note_f,note_n) in enumerate(fn[12:48]):
    fl = floor(note_f / f0k)
    ce = ceil(note_f / f0k)

    dfl = abs(ndiff(fl*f0k, note_f))
    dce = abs(ndiff(ce*f0k, note_f))

    m = min((dfl,fl), (dce,ce))

    if m[1] > 255:
        break

    # Human readable display
    print(f'#{i+1:>2} : {note_n} : {m[1]:>3} : {m[0]:5.1f}', end='')
    print(f' ({dfl:5.1f}, {dce:5.1f})')

    # Tabular data
    #~ print(f'{m[1]:>3}, ', end='')
    #~ if not (i+1) % 12:
        #~ print()
