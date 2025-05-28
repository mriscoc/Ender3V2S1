; Purple Theme File
; Professional Firmware Theme File
;=====================================================
C10                  ; Mark as a configuration/theme file
;-----------------------------------------------------
C11 E2  R15 G0 B14  ;Screen Background
C11 E3  R30 G0 B30  ;Cursor
C11 E4  R0  G0 B0   ;Title Background
C11 E5  R31 G63 B31 ;Title Text
C11 E6  R31 G63 B31 ;Text
C11 E7  R30 G0 B30  ;Selected
C11 E8  R20 G0 B20  ;Split Line
C11 E9  R30 G0 B30  ;Highlight
C11 E10 R20 G0 B20  ;Status Background
C11 E11 R31 G63 B31 ;Status Text
C11 E12 R6  G15 B8  ;Popup Background
C11 E13 R26 G53 B26 ;Popup Text
C11 E14 R30 G0 B15  ;Alert Background
C11 E15 R31 G56 B15 ;Alert Text
C11 E16 R31 G63 B31 ;Percent Text
C11 E17 R30 G0 B30  ;Bar Fill
C11 E18 R31 G63 B31 ;Indicator value
C11 E19 R31 G63 B31 ;Coordinate value
;
C11 E0  ;Preview changes
;-----------------------------------------------------
G4 S1                ; Wait a second
M300 P200            ; Beep
M117 Theme Applied
