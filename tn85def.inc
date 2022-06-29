;; ATtiny85 MCU definitions for GNU Assembler
;; ------------------------------------------

; Memories
.equ    FLASHEND,       0x0fff * 2  ; Bytes
.equ    PAGESIZE,       32          ; Words
.equ    IOEND,          0x003f      ;
.equ    SRAM_START,     0x0060      ;
.equ    SRAM_SIZE,      512         ;
.equ    RAMEND,         0x025f      ;
.equ    E2END,          0x01ff      ;
.equ    EEPROMEND,      0x01ff      ;
.equ    EEADRBITS,      9           ;

; Interrupt vectors
.equ    INT_VECTORS_SIZE, 15 * 2    ; Size in bytes
.equ    INT0addr,       0x01 * 2    ; External Interrupt 0
.equ    PCI0addr,       0x02 * 2    ; Pin change Interrupt Request 0
.equ    OC1Aaddr,       0x03 * 2    ; Timer/Counter1 Compare Match 1A
.equ    OVF1addr,       0x04 * 2    ; Timer/Counter1 Overflow
.equ    OVF0addr,       0x05 * 2    ; Timer/Counter0 Overflow
.equ    ERDYaddr,       0x06 * 2    ; EEPROM Ready
.equ    ACIaddr,        0x07 * 2    ; Analog comparator
.equ    ADCCaddr,       0x08 * 2    ; ADC Conversion ready
.equ    OC1Baddr,       0x09 * 2    ; Timer/Counter1 Compare Match B
.equ    OC0Aaddr,       0x0a * 2    ; Timer/Counter0 Compare Match A
.equ    OC0Baddr,       0x0b * 2    ; Timer/Counter0 Compare Match B
.equ    WDTaddr,        0x0c * 2    ; Watchdog Time-out
.equ    USI_STARTaddr,  0x0d * 2    ; USI START
.equ    USI_OVFaddr,    0x0e * 2    ; USI Overflow

; I/O Registers
.equ    SREG,       0x3f
.equ    SPL,        0x3d
.equ    SPH,        0x3e
.equ    GIMSK,      0x3b
.equ    GIFR,       0x3a
.equ    TIMSK,      0x39
.equ    TIFR,       0x38
.equ    SPMCSR,     0x37
.equ    MCUCR,      0x35
.equ    MCUSR,      0x34
.equ    TCCR0B,     0x33
.equ    TCNT0,      0x32
.equ    OSCCAL,     0x31
.equ    TCCR1,      0x30
.equ    TCNT1,      0x2f
.equ    OCR1A,      0x2e
.equ    OCR1C,      0x2d
.equ    GTCCR,      0x2c
.equ    OCR1B,      0x2b
.equ    TCCR0A,     0x2a
.equ    OCR0A,      0x29
.equ    OCR0B,      0x28
.equ    PLLCSR,     0x27
.equ    CLKPR,      0x26
.equ    DT1A,       0x25
.equ    DT1B,       0x24
.equ    DTPS,       0x23
.equ    DWDR,       0x22
.equ    WDTCR,      0x21
.equ    PRR,        0x20
.equ    EEARH,      0x1f
.equ    EEARL,      0x1e
.equ    EEDR,       0x1d
.equ    EECR,       0x1c
.equ    PORTB,      0x18
.equ    DDRB,       0x17
.equ    PINB,       0x16
.equ    PCMSK,      0x15
.equ    DIDR0,      0x14
.equ    GPIOR2,     0x13
.equ    GPIOR1,     0x12
.equ    GPIOR0,     0x11
.equ    USIBR,      0x10
.equ    USIDR,      0x0f
.equ    USISR,      0x0e
.equ    USICR,      0x0d
.equ    ACSR,       0x08
.equ    ADMUX,      0x07
.equ    ADCSRA,     0x06
.equ    ADCH,       0x05
.equ    ADCL,       0x04
.equ    ADCSRB,     0x03

; SREG - Status Register
.equ    SREG_C,     0    ; Carry Flag
.equ    SREG_Z,     1    ; Zero Flag
.equ    SREG_N,     2    ; Negative Flag
.equ    SREG_V,     3    ; Two's Complement Overflow Flag
.equ    SREG_S,     4    ; Sign Bit
.equ    SREG_H,     5    ; Half Carry Flag
.equ    SREG_T,     6    ; Bit Copy Storage
.equ    SREG_I,     7    ; Global Interrupt Enable

; GIMSK - General Interrupt Mask Register
.equ    PCIE,       5    ; Pin Change Interrupt Enable
.equ    INT0,       6    ; External Interrupt Request 0 Enable

; GIFR - General Interrupt Flag register
.equ    PCIF,       5    ; Pin Change Interrupt Flag
.equ    INTF0,      6    ; External Interrupt Flag 0

; TIMSK - Timer/Counter Interrupt Mask Register
.equ    TOIE0,      1    ; Timer/Counter0 Overflow Interrupt Enable
.equ    TOIE1,      2    ; Timer/Counter1 Overflow Interrupt Enable
.equ    OCIE0B,     3    ; Timer/Counter0 Output Compare Match B Interrupt Enable
.equ    OCIE0A,     4    ; Timer/Counter0 Output Compare Match A Interrupt Enable
.equ    OCIE1B,     5    ; OCIE1A: Timer/Counter1 Output Compare B Interrupt Enable
.equ    OCIE1A,     6    ; OCIE1A: Timer/Counter1 Output Compare Interrupt Enable

; TIFR - Timer/Counter0 Interrupt Flag register
.equ    TOV0,       1    ; Timer/Counter0 Overflow Flag
.equ    TOV1,       2    ; Timer/Counter1 Overflow Flag
.equ    OCF0B,      3    ; Timer/Counter0 Output Compare Flag 0B
.equ    OCF0A,      4    ; Timer/Counter0 Output Compare Flag 0A
.equ    OCF1B,      5    ; Timer/Counter1 Output Compare Flag 1B
.equ    OCF1A,      6    ; Timer/Counter1 Output Compare Flag 1A

; SPMCSR - Store Program Memory Control Register
.equ    SPMEN,      0    ; Store Program Memory Enable
.equ    PGERS,      1    ; Page Erase
.equ    PGWRT,      2    ; Page Write
.equ    RFLB,       3    ; Read fuse and lock bits
.equ    CTPB,       4    ; Clear temporary page buffer

; MCUCR - MCU Control Register
.equ    ISC00,      0    ; Interrupt Sense Control 0 Bit 0
.equ    ISC01,      1    ; Interrupt Sense Control 0 Bit 1
.equ    SM0,        3    ; Sleep Mode Select Bit 0
.equ    SM1,        4    ; Sleep Mode Select Bit 1
.equ    SE,         5    ; Sleep Enable
.equ    PUD,        6    ; Pull-up Disable

; MCUSR - MCU Status register
.equ    PORF,       0    ; Power-On Reset Flag
.equ    EXTRF,      1    ; External Reset Flag
.equ    BORF,       2    ; Brown-out Reset Flag
.equ    WDRF,       3    ; Watchdog Reset Flag

; TCCR0B - Timer/Counter Control Register B
.equ    CS00,       0    ; Clock Select
.equ    CS01,       1    ; Clock Select
.equ    CS02,       2    ; Clock Select
.equ    WGM02,      3    ;
.equ    FOC0B,      6    ; Force Output Compare B
.equ    FOC0A,      7    ; Force Output Compare A

; TCCR1 - Timer/Counter Control Register
.equ    CS10,       0    ; Clock Select Bits
.equ    CS11,       1    ; Clock Select Bits
.equ    CS12,       2    ; Clock Select Bits
.equ    CS13,       3    ; Clock Select Bits
.equ    COM1A0,     4    ; Compare Output Mode, Bit 1
.equ    COM1A1,     5    ; Compare Output Mode, Bit 0
.equ    PWM1A,      6    ; Pulse Width Modulator Enable
.equ    CTC1,       7    ; Clear Timer/Counter on Compare Match

; GTCCR - General Timer/Counter Control Register
.equ    PSR0,       0    ; Prescaler Reset Timer/Counter1 and Timer/Counter0
.equ    PSR1,       1    ; Prescaler Reset Timer/Counter1
.equ    FOC1A,      2    ; Force Output Compare 1A
.equ    FOC1B,      3    ; Force Output Compare Match 1B
.equ    COM1B0,     4    ; Comparator B Output Mode
.equ    COM1B1,     5    ; Comparator B Output Mode
.equ    PWM1B,      6    ; Pulse Width Modulator B Enable
.equ    TSM,        7    ; Timer/Counter Synchronization Mode

; TCCR0A - Timer/Counter  Control Register A
.equ    WGM00,      0    ; Waveform Generation Mode
.equ    WGM01,      1    ; Waveform Generation Mode
.equ    COM0B0,     4    ; Compare Output Mode, Fast PWm
.equ    COM0B1,     5    ; Compare Output Mode, Fast PWm
.equ    COM0A0,     6    ; Compare Output Mode, Phase Correct PWM Mode
.equ    COM0A1,     7    ; Compare Output Mode, Phase Correct PWM Mode

; PLLCSR - PLL Control and status register
.equ    PLOCK,      0    ; PLL Lock detector
.equ    PLLE,       1    ; PLL Enable
.equ    PCKE,       2    ; PCK Enable
.equ    LSM,        7    ; Low speed mode

; CLKPR - Clock Prescale Register
.equ    CLKPS0,     0    ; Clock Prescaler Select Bit 0
.equ    CLKPS1,     1    ; Clock Prescaler Select Bit 1
.equ    CLKPS2,     2    ; Clock Prescaler Select Bit 2
.equ    CLKPS3,     3    ; Clock Prescaler Select Bit 3
.equ    CLKPCE,     7    ; Clock Prescaler Change Enable

; DTPS - Dead time prescaler register
.equ    DTPS0,      0    ;
.equ    DTPS1,      1    ;

; WDTCR - Watchdog Timer Control Register
.equ    WDTCSR, WDTCR    ; For compatibility
.equ    WDP0,       0    ; Watch Dog Timer Prescaler bit 0
.equ    WDP1,       1    ; Watch Dog Timer Prescaler bit 1
.equ    WDP2,       2    ; Watch Dog Timer Prescaler bit 2
.equ    WDE,        3    ; Watch Dog Enable
.equ    WDCE,       4    ; Watchdog Change Enable
.equ    WDP3,       5    ; Watchdog Timer Prescaler Bit 3
.equ    WDIE,       6    ; Watchdog Timeout Interrupt Enable
.equ    WDIF,       7    ; Watchdog Timeout Interrupt Flag

; PRR - Power Reduction Register
.equ    PRADC,      0    ; Power Reduction ADC
.equ    PRUSI,      1    ; Power Reduction USI
.equ    PRTIM0,     2    ; Power Reduction Timer/Counter0
.equ    PRTIM1,     3    ; Power Reduction Timer/Counter1

; EECR - EEPROM Control Register
.equ    EERE,       0    ; EEPROM Read Enable
.equ    EEPE,       1    ; EEPROM Write Enable
.equ    EEMPE,      2    ; EEPROM Master Write Enable
.equ    EERIE,      3    ; EEPROM Ready Interrupt Enable
.equ    EEPM0,      4    ; EEPROM Programming Mode Bit 0
.equ    EEPM1,      5    ; EEPROM Programming Mode Bit 1

; PORTB - Data Register, Port B
.equ    PB0,        0    ;
.equ    PB1,        1    ;
.equ    PB2,        2    ;
.equ    PB3,        3    ;
.equ    PB4,        4    ;
.equ    PB5,        5    ;

; DDRB - Data Direction Register, Port B
.equ    DDB0,       0    ;
.equ    DDB1,       1    ;
.equ    DDB2,       2    ;
.equ    DDB3,       3    ;
.equ    DDB4,       4    ;
.equ    DDB5,       5    ;

; PINB - Input Pins, Port B
.equ    PINB0,      0    ;
.equ    PINB1,      1    ;
.equ    PINB2,      2    ;
.equ    PINB3,      3    ;
.equ    PINB4,      4    ;
.equ    PINB5,      5    ;

; PCMSK - Pin Change Enable Mask
.equ    PCINT0,     0    ; Pin Change Enable Mask Bit 0
.equ    PCINT1,     1    ; Pin Change Enable Mask Bit 1
.equ    PCINT2,     2    ; Pin Change Enable Mask Bit 2
.equ    PCINT3,     3    ; Pin Change Enable Mask Bit 3
.equ    PCINT4,     4    ; Pin Change Enable Mask Bit 4
.equ    PCINT5,     5    ; Pin Change Enable Mask Bit 5

; DIDR0 - Digital Input Disable Register 0
.equ    AIN0D,      0    ; AIN0 Digital Input Disable
.equ    AIN1D,      1    ; AIN1 Digital Input Disable
.equ    ADC1D,      2    ; ADC1 Digital input Disable
.equ    ADC3D,      3    ; ADC3 Digital input Disable
.equ    ADC2D,      4    ; ADC2 Digital input Disable
.equ    ADC0D,      5    ; ADC0 Digital input Disable

; USISR - USI Status Register
.equ    USICNT0,    0    ; USI Counter Value Bit 0
.equ    USICNT1,    1    ; USI Counter Value Bit 1
.equ    USICNT2,    2    ; USI Counter Value Bit 2
.equ    USICNT3,    3    ; USI Counter Value Bit 3
.equ    USIDC,      4    ; Data Output Collision
.equ    USIPF,      5    ; Stop Condition Flag
.equ    USIOIF,     6    ; Counter Overflow Interrupt Flag
.equ    USISIF,     7    ; Start Condition Interrupt Flag

; USICR - USI Control Register
.equ    USITC,      0    ; Toggle Clock Port Pin
.equ    USICLK,     1    ; Clock Strobe
.equ    USICS0,     2    ; USI Clock Source Select Bit 0
.equ    USICS1,     3    ; USI Clock Source Select Bit 1
.equ    USIWM0,     4    ; USI Wire Mode Bit 0
.equ    USIWM1,     5    ; USI Wire Mode Bit 1
.equ    USIOIE,     6    ; Counter Overflow Interrupt Enable
.equ    USISIE,     7    ; Start Condition Interrupt Enable

; ACSR - Analog Comparator Control And Status Register
.equ    ACIS0,      0    ; Analog Comparator Interrupt Mode Select bit 0
.equ    ACIS1,      1    ; Analog Comparator Interrupt Mode Select bit 1
.equ    ACIE,       3    ; Analog Comparator Interrupt Enable
.equ    ACI,        4    ; Analog Comparator Interrupt Flag
.equ    ACO,        5    ; Analog Compare Output
.equ    ACBG,       6    ; Analog Comparator Bandgap Select
.equ    ACD,        7    ; Analog Comparator Disable

; ADMUX - The ADC multiplexer Selection Register
.equ    MUX0,       0    ; Analog Channel and Gain Selection Bits
.equ    MUX1,       1    ; Analog Channel and Gain Selection Bits
.equ    MUX2,       2    ; Analog Channel and Gain Selection Bits
.equ    MUX3,       3    ; Analog Channel and Gain Selection Bits
.equ    REFS2,      4    ; Reference Selection Bit 2
.equ    ADLAR,      5    ; Left Adjust Result
.equ    REFS0,      6    ; Reference Selection Bit 0
.equ    REFS1,      7    ; Reference Selection Bit 1

; ADCSRA - The ADC Control and Status register
.equ    ADPS0,      0    ; ADC  Prescaler Select Bits
.equ    ADPS1,      1    ; ADC  Prescaler Select Bits
.equ    ADPS2,      2    ; ADC  Prescaler Select Bits
.equ    ADIE,       3    ; ADC Interrupt Enable
.equ    ADIF,       4    ; ADC Interrupt Flag
.equ    ADATE,      5    ; ADC Auto Trigger Enable
.equ    ADSC,       6    ; ADC Start Conversion
.equ    ADEN,       7    ; ADC Enable

; ADCSRB - ADC Control and Status Register B
.equ    ADTS0,      0    ; ADC Auto Trigger Source 0
.equ    ADTS1,      1    ; ADC Auto Trigger Source 1
.equ    ADTS2,      2    ; ADC Auto Trigger Source 2
.equ    IPR,        5    ; Input Polarity Mode
.equ    ACME,       6    ; Analog Comparator Multiplexer Enable
.equ    BIN,        7    ; Bipolar Input Mode

; end.
