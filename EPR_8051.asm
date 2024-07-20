ORG 0000H        ; Start of the program memory

; Initialization
START:
    MOV TMOD, #20H   ; Timer 1 in 8-bit auto-reload mode
    MOV TH1, #0FDH   ; Baud rate 9600 (assuming 11.0592 MHz crystal)
    MOV TL1, #0FDH   ; Load timer 1 registers
    MOV SCON, #50H   ; Serial mode 1, 8-bit UART
    MOV TCON, #10H   ; Timer 1 ON
    MOV IE, #90H     ; Enable UART interrupt
    MOV P1, #00H     ; Set Port 1 as output (SOR)
    MOV P2, #00H     ; Set Port 2 as input (EOR)
    MOV P3, #00H     ; Set Port 3 for LCD data lines (D0-D7)
    
    ; Initialize LCD
    ACALL INIT_LCD

    ; Main loop
MAIN_LOOP:
    JB P2.0, NO_VEHICLE   ; Check if vehicle detection sensor input (P2.0) is high
    ; Vehicle detected, start reading
    SETB P1.0             ; Send SOR pulse
    ACALL DELAY           ; Wait
    CLR P1.0              ; End SOR pulse

    ; Wait for EOR signal
WAIT_EOR:
    JB P2.1, WAIT_EOR    ; Wait until EOR signal (P2.1) goes low

    ; Read data from RFID module
    MOV R0, #00H         ; Initialize data buffer index
READ_DATA:
    JNB RI, READ_DATA   ; Wait for data to be received
    MOV A, SBUF          ; Read received data
    MOV R1, A            ; Store data in R1
    CLR RI               ; Clear receive interrupt flag

    ; Display data on LCD
    ACALL DISPLAY_LCD

    SJMP MAIN_LOOP       ; Return to main loop

NO_VEHICLE:
    SJMP MAIN_LOOP       ; Loop if no vehicle is detected

; Delay routine for SOR pulse
DELAY:
    MOV R2, #255         ; Set delay counter
DELAY_LOOP:
    DJNZ R2, DELAY_LOOP  ; Decrement counter and loop
    RET

; LCD Initialization
INIT_LCD:
    ; Function Set: 8-bit mode, 2 lines, 5x7 dots
    MOV A, #38H
    ACALL LCD_CMD
    ; Display ON/OFF Control: Display ON, Cursor OFF
    MOV A, #0CH
    ACALL LCD_CMD
    ; Clear Display
    MOV A, #01H
    ACALL LCD_CMD
    ; Entry Mode Set: Increment, no shift
    MOV A, #06H
    ACALL LCD_CMD
    RET

LCD_CMD:
    ; Send command to LCD
    MOV P3, A          ; Send command to data lines
    CLR P1.1           ; Set RS low for command
    CLR P1.2           ; Set RW low for write
    SETB P1.0          ; Pulse E high
    NOP                ; Small delay for setup time
    CLR P1.0           ; Pulse E low
    RET

LCD_DATA:
    ; Send data to LCD
    MOV P3, A          ; Send data to data lines
    SETB P1.1          ; Set RS high for data
    CLR P1.2           ; Set RW low for write
    SETB P1.0          ; Pulse E high
    NOP                ; Small delay for setup time
    CLR P1.0           ; Pulse E low
    RET

DISPLAY_LCD:
    ; Send 'R1' to LCD
    MOV A, R1
    ACALL LCD_DATA
    RET

END
