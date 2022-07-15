-ili9341
marker -ili9341

\ Level 1 Command
$00 constant NOP	\ No Operation
$01 constant SWRESET	\ Software Reset
$04 constant RDDIDIF	\ Read Display Idetification Information
$09 constant RDDST	\ Read Display Status
$0a constant DRDPM	\ Read Display Power Mode
$0b constant RDDMADCTL	\ Read Display MADCTL
$0c constant RDDCOLMOD	\ Read Display Pixel Format
$0d constant RDDIM	\ Read Display Image Mode
$0e constant RDDSM	\ Read Display Signal Mode
$0f constant RDDSDR	\ Read Display Self-Diagnostic Result
$10 constant SLPIN	\ Enter Sleep Mode
$11 constant SLPOUT	\ Sleep Out
$12 constant PTLON	\ Partial Mode On
$13 constant NORON	\ Normal Display Mode On
$20 constant DINVOFF	\ Display Inversion OFF
$21 constant DINVON	\ Display Inversion ON
$26 constant GAMSET	\ Gamma Set
$28 constant DISPOFF	\ Display OFF
$29 constant DISPON	\ Display ON
$2a constant CASET	\ Column Address Set
$2b constant PASET	\ Page Address Set
$2c constant RAMWR	\ Memory Write
$2d constant RGBSET	\ Color Set
$2e constant RAMRD	\ Memory Read
$30 constant PLTAR	\ Partial Area
$33 constant VSCRDEF	\ Vertical Scrolling Definition
$34 constant TEOFF	\ Tearing Effect Line OFF
$35 constant TEON	\ Tearing Effect Line ON
$36 constant MADCTL	\ Memory Access Control
$37 constant VSCRSADD	\ Vertical Scrolling Start Address
$38 constant IDMOFF	\ Idle Mode OFF
$39 constant IDMON	\ Idle Mode ON
$3a constant PIXSET	\ Pixel Format Set
$3c constant WRMC	\ Write Memory Continue
$3e constant RDMC	\ Read Memory Continue
$44 constant STS	\ Set Tear Scanline
$45 constant GS		\ Get Scanline
$51 constant WRDISBV	\ Write Display Brightness
$52 constant RDDISBV	\ Read Display Brightness Value
$53 constant WRCTRLD	\ Write Control Display
$54 constant RDCTRLD	\ Read Control Display
$55 constant WRCABC	\ Write Adaptive Brightness Control
$55 constant RDCABC	\ Read Adaptive Brightness Control
$5e constant WRCABCMB	\ Write CABC Minimum Brightness (Backlight Control 1)
$5e constant RDCABCMB	\ Read CABC Minimum Brightness (Backlight Control 1)
$da constant RDID1	\ Read ID1
$db constant RDID2	\ Read ID2
$dc constant RDID3	\ Read ID3

\ Level 2 command
$b0 constant IFMODE	\ Interface Mode Control
$b1 constant FRMCTR1	\ Frame Rate Control (In Normal Mode / Full Colors)
$b2 constant FRMCTR2	\ Frame Rate Control (In Idle Mode / 8 Colors)
$b3 constant FRMCTR3	\ Frame Rate Control (In Partial Mode / Full Colors)
$b4 constant INVTR	\ Display Inversion Control
$b5 constant PRCTR	\ Blanking Porch
$b6 constant DISCTRL	\ Display Function Control
$b7 constant ETMOD	\ Entry Mode Set
$b8 constant BLCTRL1	\ Backlight Control 1
$b9 constant BLCTRL2	\ Backlight Control 2
$ba constant BLCTRL3	\ Backlight Control 3
$bb constant BLCTRL4	\ Backlight Control 4
$bc constant BLCTRL5	\ Backlight Control 5
$be constant BLCTRL7	\ Backlight Control 7
$bf constant BLCTRL8	\ Backlight Control 8
$c0 constant PWCTRL1	\ Power Control 1
$c1 constant PWCTRL2	\ Power Control 2
$c5 constant VMCTRL1	\ VCOM Control 1
$c7 constant VMCTRL2	\ VCOM Control 2
$d0 constant NVMWR	\ NV Memory Write
$d1 constant NVPKEY	\ NV Memory Protection Key
$d2 constant RDNVM	\ NV Memory Status Read
$d3 constant RDID4	\ Read ID4
$e0 constant PGAMCTRL	\ Positive Gamma Control
$e1 constant NGAMCTRL	\ Negative Gamma Correction
$e2 constant DGAMCTRL1	\ Digital Gamma Control 1
$e3 constant DGAMCTRL2	\ Digital Gamma Control 2
$f6 constant IFCTL	\ 16bit Data Format Selection (Interface Control)

\ Extended Register Command
$cb constant PWRCTRLA	\ Power Control A
$cf constant PWRCTRLB	\ Power Control B
$e8 constant DRTCTRLA1	\ Driver Timing Control A1
$e9 constant DRTCTRLA2	\ Driver Timing Control A2
$ea constant DRTCTRLB	\ Driver Timing Control B
$ed constant PWRONCTRL	\ Power ON Sequence Control
$f2 constant EN3G	\ Enable 3G
$f7 constant PMPRCTRL	\ Pump Ratio Control

