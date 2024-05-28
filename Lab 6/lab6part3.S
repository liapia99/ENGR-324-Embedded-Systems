#define __SFR_OFFSET 0
#include "avr/io.h"

.global start
.global forever

start:
  SBI DDRD, 0 ; Set PD0 as Output (one)
  SBI DDRD, 1 ; Set PD1 as Output (one)
  SBI DDRD, 2 ; Set PD2 as Output (one)
  SBI DDRD, 3 ; Set PD3 as Output (one)
  SBI DDRD, 4 ; Set PD4 as Output (one)
  SBI DDRD, 5 ; Set PD5 as Output (one)
  SBI DDRD, 6 ; Set PD6 as Output (one)
  RET

forever:
  ; Display 0
  LDI R16, 0x3F ; 0
  OUT PORTD, R16
  RCALL delay

  ; Display 1
  LDI R16, 0x06 ; 1
  OUT PORTD, R16
  RCALL delay

  ; Display 2
  LDI R16, 0x5B ; 2
  OUT PORTD, R16
  RCALL delay

  ; Display 3
  LDI R16, 0x4F ; 3
  OUT PORTD, R16
  RCALL delay

  ; Display 4
  LDI R16, 0x66 ; 4
  OUT PORTD, R16
  RCALL delay

  ; Display 5
  LDI R16, 0x6D ; 5
  OUT PORTD, R16
  RCALL delay

  ; Display 6
  LDI R16, 0x7D ; 6
  OUT PORTD, R16
  RCALL delay

  ; Display 7
  LDI R16, 0x07 ; 7
  OUT PORTD, R16
  RCALL delay

  ; Display 8
  LDI R16, 0x7F ; 8
  OUT PORTD, R16
  RCALL delay

  ; Display 9
  LDI R16, 0x67 ; 9
  OUT PORTD, R16
  RCALL delay

  ; Display A
  LDI R16, 0x77 ; A
  OUT PORTD, R16
  RCALL delay

  ; Display b
  LDI R16, 0x7C ; b
  OUT PORTD, R16
  RCALL delay

  ; Display C
  LDI R16, 0x39 ; C
  OUT PORTD, R16
  RCALL delay

  ; Display d
  LDI R16, 0x5E ; d
  OUT PORTD, R16
  RCALL delay

  ; Display E
  LDI R16, 0x79 ; E
  OUT PORTD, R16
  RCALL delay

  ; Display F
  LDI R16, 0x71 ; F
  OUT PORTD, R16
  RCALL delay

  RJMP forever ; Repeat forever

delay:
  ldi  r18, 41
  ldi  r19, 150
  ldi  r20, 128
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
  RET
