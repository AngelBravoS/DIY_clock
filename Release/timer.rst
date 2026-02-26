                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module timer
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _centiseconds
                                     12 	.globl _ISR_T0
                                     13 	.globl _UART_SM0
                                     14 	.globl _UART_SM1
                                     15 	.globl _UART_SM2
                                     16 	.globl _UART_REN
                                     17 	.globl _UART_TB8
                                     18 	.globl _UART_RB8
                                     19 	.globl _UART_TI
                                     20 	.globl _UART_RI
                                     21 	.globl _PCA_CF
                                     22 	.globl _PCA_CR
                                     23 	.globl _PCA_CCF2
                                     24 	.globl _PCA_CCF1
                                     25 	.globl _PCA_CCF0
                                     26 	.globl _TMR_TCON_TF1
                                     27 	.globl _TMR_TCON_TR1
                                     28 	.globl _TMR_TCON_TF0
                                     29 	.globl _TMR_TCON_TR0
                                     30 	.globl _TMR_TCON_IE1
                                     31 	.globl _TMR_TCON_IT1
                                     32 	.globl _TMR_TCON_IE0
                                     33 	.globl _TMR_TCON_IT0
                                     34 	.globl _INT_IP_PPCA
                                     35 	.globl _INT_IP_PLVD
                                     36 	.globl _INT_IP_PADC
                                     37 	.globl _INT_IP_PS
                                     38 	.globl _INT_IP_PT1
                                     39 	.globl _INT_IP_PX1
                                     40 	.globl _INT_IP_PT0
                                     41 	.globl _INT_IP_PX0
                                     42 	.globl _INT_IE_EA
                                     43 	.globl _INT_IE_ELVD
                                     44 	.globl _INT_IE_EADC
                                     45 	.globl _INT_IE_ES
                                     46 	.globl _INT_IE_ET1
                                     47 	.globl _INT_IE_EX1
                                     48 	.globl _INT_IE_ET0
                                     49 	.globl _INT_IE_EX0
                                     50 	.globl _PORT_P5_7
                                     51 	.globl _PORT_P5_6
                                     52 	.globl _PORT_P5_5
                                     53 	.globl _PORT_P5_4
                                     54 	.globl _PORT_P5_3
                                     55 	.globl _PORT_P5_2
                                     56 	.globl _PORT_P5_1
                                     57 	.globl _PORT_P5_0
                                     58 	.globl _PORT_P4_7
                                     59 	.globl _PORT_P4_6
                                     60 	.globl _PORT_P4_5
                                     61 	.globl _PORT_P4_4
                                     62 	.globl _PORT_P4_3
                                     63 	.globl _PORT_P4_2
                                     64 	.globl _PORT_P4_1
                                     65 	.globl _PORT_P4_0
                                     66 	.globl _PORT_P3_7
                                     67 	.globl _PORT_P3_6
                                     68 	.globl _PORT_P3_5
                                     69 	.globl _PORT_P3_4
                                     70 	.globl _PORT_P3_3
                                     71 	.globl _PORT_P3_2
                                     72 	.globl _PORT_P3_1
                                     73 	.globl _PORT_P3_0
                                     74 	.globl _PORT_P2_7
                                     75 	.globl _PORT_P2_6
                                     76 	.globl _PORT_P2_5
                                     77 	.globl _PORT_P2_4
                                     78 	.globl _PORT_P2_3
                                     79 	.globl _PORT_P2_2
                                     80 	.globl _PORT_P2_1
                                     81 	.globl _PORT_P2_0
                                     82 	.globl _PORT_P1_7
                                     83 	.globl _PORT_P1_6
                                     84 	.globl _PORT_P1_5
                                     85 	.globl _PORT_P1_4
                                     86 	.globl _PORT_P1_3
                                     87 	.globl _PORT_P1_2
                                     88 	.globl _PORT_P1_1
                                     89 	.globl _PORT_P1_0
                                     90 	.globl _CY
                                     91 	.globl _AC
                                     92 	.globl _F0
                                     93 	.globl _RS1
                                     94 	.globl _RS0
                                     95 	.globl _OV
                                     96 	.globl _F1
                                     97 	.globl _P
                                     98 	.globl _IAP_CONTR
                                     99 	.globl _IAP_TRIG
                                    100 	.globl _IAP_CMD
                                    101 	.globl _IAP_ADDR
                                    102 	.globl _IAP_ADDRL
                                    103 	.globl _IAP_ADDRH
                                    104 	.globl _IAP_DATA
                                    105 	.globl _UART_SADEN
                                    106 	.globl _UART_SADDR
                                    107 	.globl _UART_SBUF
                                    108 	.globl _UART_SCON
                                    109 	.globl _PCA_CMOD
                                    110 	.globl _PCA_CCON
                                    111 	.globl _PCA_PWM2
                                    112 	.globl _PCA_PWM1
                                    113 	.globl _PCA_PWM0
                                    114 	.globl _PCA_C
                                    115 	.globl _PCA_CCAP2_L
                                    116 	.globl _PCA_CCAP2_H
                                    117 	.globl _PCA_CCAP1_L
                                    118 	.globl _PCA_CCAP1_H
                                    119 	.globl _PCA_CCAP0_L
                                    120 	.globl _PCA_CCAP0_H
                                    121 	.globl _PCA_CCAP2
                                    122 	.globl _PCA_CCAP1
                                    123 	.globl _PCA_CCAP0
                                    124 	.globl _PCA_CCAPM2
                                    125 	.globl _PCA_CCAPM1
                                    126 	.globl _PCA_CCAPM0
                                    127 	.globl _CMP_CR2
                                    128 	.globl _CMP_CR1
                                    129 	.globl _ADC_RESL
                                    130 	.globl _ADC_RESH
                                    131 	.globl _ADC_RES
                                    132 	.globl _ADC_CONTR
                                    133 	.globl _ADC_P1ASF
                                    134 	.globl _EEPROM_CONTR
                                    135 	.globl _EEPROM_TRIG
                                    136 	.globl _EEPROM_CMD
                                    137 	.globl _EEPROM_ADDR
                                    138 	.globl _EEPROM_DATA
                                    139 	.globl _TMR_T2
                                    140 	.globl _TMR_T0
                                    141 	.globl _TMR_TMOD
                                    142 	.globl _TMR_TCON
                                    143 	.globl _INT_IP2
                                    144 	.globl _INT_IP
                                    145 	.globl _INT_IE2
                                    146 	.globl _INT_IE
                                    147 	.globl _PORT_P5M0
                                    148 	.globl _PORT_P5M1
                                    149 	.globl _PORT_P4M0
                                    150 	.globl _PORT_P4M1
                                    151 	.globl _PORT_P3M0
                                    152 	.globl _PORT_P3M1
                                    153 	.globl _PORT_P2M0
                                    154 	.globl _PORT_P2M1
                                    155 	.globl _PORT_P1M0
                                    156 	.globl _PORT_P1M1
                                    157 	.globl _PORT_P5
                                    158 	.globl _PORT_P4
                                    159 	.globl _PORT_P3
                                    160 	.globl _PORT_P2
                                    161 	.globl _PORT_P1
                                    162 	.globl _PSW
                                    163 	.globl _PCON2
                                    164 	.globl _AUXR2
                                    165 	.globl _AUXR1
                                    166 	.globl _AUXR
                                    167 	.globl _PCON
                                    168 	.globl _DPTR
                                    169 	.globl _SP
                                    170 	.globl _display_autobrightness
                                    171 	.globl _DS1302_DATA_7
                                    172 	.globl _DS1302_DATA_6
                                    173 	.globl _DS1302_DATA_5
                                    174 	.globl _DS1302_DATA_4
                                    175 	.globl _DS1302_DATA_3
                                    176 	.globl _DS1302_DATA_2
                                    177 	.globl _DS1302_DATA_1
                                    178 	.globl _DS1302_DATA_0
                                    179 	.globl _BUTTON_DATA_SELECT_HELD_DOWN
                                    180 	.globl _BUTTON_DATA_SELECT_RELEASED_LONGP
                                    181 	.globl _BUTTON_DATA_SELECT_RELEASED_NORMAL
                                    182 	.globl _BUTTON_DATA_SELECT_PRESSED
                                    183 	.globl _BUTTON_DATA_MENU_HELD_DOWN
                                    184 	.globl _BUTTON_DATA_MENU_RELEASED_LONGP
                                    185 	.globl _BUTTON_DATA_MENU_RELEASED_NORMAL
                                    186 	.globl _BUTTON_DATA_MENU_PRESSED
                                    187 	.globl _ticks_10ms
                                    188 	.globl _DS1302_DATA
                                    189 	.globl _BUTTON_DATA
                                    190 ;--------------------------------------------------------
                                    191 ; special function registers
                                    192 ;--------------------------------------------------------
                                    193 	.area RSEG    (ABS,DATA)
      000000                        194 	.org 0x0000
                           000081   195 _SP	=	0x0081
                           008382   196 _DPTR	=	0x8382
                           000087   197 _PCON	=	0x0087
                           00008E   198 _AUXR	=	0x008e
                           0000A2   199 _AUXR1	=	0x00a2
                           00008F   200 _AUXR2	=	0x008f
                           000097   201 _PCON2	=	0x0097
                           0000D0   202 _PSW	=	0x00d0
                           000090   203 _PORT_P1	=	0x0090
                           0000A0   204 _PORT_P2	=	0x00a0
                           0000B0   205 _PORT_P3	=	0x00b0
                           0000C0   206 _PORT_P4	=	0x00c0
                           0000C8   207 _PORT_P5	=	0x00c8
                           000091   208 _PORT_P1M1	=	0x0091
                           000092   209 _PORT_P1M0	=	0x0092
                           000095   210 _PORT_P2M1	=	0x0095
                           000096   211 _PORT_P2M0	=	0x0096
                           0000B1   212 _PORT_P3M1	=	0x00b1
                           0000B2   213 _PORT_P3M0	=	0x00b2
                           0000B3   214 _PORT_P4M1	=	0x00b3
                           0000B4   215 _PORT_P4M0	=	0x00b4
                           0000C9   216 _PORT_P5M1	=	0x00c9
                           0000CA   217 _PORT_P5M0	=	0x00ca
                           0000A8   218 _INT_IE	=	0x00a8
                           0000AF   219 _INT_IE2	=	0x00af
                           0000B8   220 _INT_IP	=	0x00b8
                           0000B5   221 _INT_IP2	=	0x00b5
                           000088   222 _TMR_TCON	=	0x0088
                           000089   223 _TMR_TMOD	=	0x0089
                           008C8A   224 _TMR_T0	=	0x8c8a
                           00D6D7   225 _TMR_T2	=	0xd6d7
                           0000C2   226 _EEPROM_DATA	=	0x00c2
                           00C3C4   227 _EEPROM_ADDR	=	0xc3c4
                           0000C5   228 _EEPROM_CMD	=	0x00c5
                           0000C6   229 _EEPROM_TRIG	=	0x00c6
                           0000C7   230 _EEPROM_CONTR	=	0x00c7
                           00009D   231 _ADC_P1ASF	=	0x009d
                           0000BC   232 _ADC_CONTR	=	0x00bc
                           00BDBE   233 _ADC_RES	=	0xbdbe
                           0000BD   234 _ADC_RESH	=	0x00bd
                           0000BE   235 _ADC_RESL	=	0x00be
                           0000E6   236 _CMP_CR1	=	0x00e6
                           0000E7   237 _CMP_CR2	=	0x00e7
                           0000DA   238 _PCA_CCAPM0	=	0x00da
                           0000DB   239 _PCA_CCAPM1	=	0x00db
                           0000DC   240 _PCA_CCAPM2	=	0x00dc
                           00FAEA   241 _PCA_CCAP0	=	0xfaea
                           00FBEB   242 _PCA_CCAP1	=	0xfbeb
                           00FCEC   243 _PCA_CCAP2	=	0xfcec
                           0000FA   244 _PCA_CCAP0_H	=	0x00fa
                           0000EA   245 _PCA_CCAP0_L	=	0x00ea
                           0000FB   246 _PCA_CCAP1_H	=	0x00fb
                           0000EB   247 _PCA_CCAP1_L	=	0x00eb
                           0000FC   248 _PCA_CCAP2_H	=	0x00fc
                           0000EC   249 _PCA_CCAP2_L	=	0x00ec
                           00F9E9   250 _PCA_C	=	0xf9e9
                           0000F2   251 _PCA_PWM0	=	0x00f2
                           0000F3   252 _PCA_PWM1	=	0x00f3
                           0000F4   253 _PCA_PWM2	=	0x00f4
                           0000D8   254 _PCA_CCON	=	0x00d8
                           0000D9   255 _PCA_CMOD	=	0x00d9
                           000098   256 _UART_SCON	=	0x0098
                           000099   257 _UART_SBUF	=	0x0099
                           0000A9   258 _UART_SADDR	=	0x00a9
                           0000B9   259 _UART_SADEN	=	0x00b9
                           0000C2   260 _IAP_DATA	=	0x00c2
                           0000C3   261 _IAP_ADDRH	=	0x00c3
                           0000C4   262 _IAP_ADDRL	=	0x00c4
                           00C3C4   263 _IAP_ADDR	=	0xc3c4
                           0000C5   264 _IAP_CMD	=	0x00c5
                           0000C6   265 _IAP_TRIG	=	0x00c6
                           0000C7   266 _IAP_CONTR	=	0x00c7
                                    267 ;--------------------------------------------------------
                                    268 ; special function bits
                                    269 ;--------------------------------------------------------
                                    270 	.area RSEG    (ABS,DATA)
      000000                        271 	.org 0x0000
                           0000D0   272 _P	=	0x00d0
                           0000D1   273 _F1	=	0x00d1
                           0000D2   274 _OV	=	0x00d2
                           0000D3   275 _RS0	=	0x00d3
                           0000D4   276 _RS1	=	0x00d4
                           0000D5   277 _F0	=	0x00d5
                           0000D6   278 _AC	=	0x00d6
                           0000D7   279 _CY	=	0x00d7
                           000090   280 _PORT_P1_0	=	0x0090
                           000091   281 _PORT_P1_1	=	0x0091
                           000092   282 _PORT_P1_2	=	0x0092
                           000093   283 _PORT_P1_3	=	0x0093
                           000094   284 _PORT_P1_4	=	0x0094
                           000095   285 _PORT_P1_5	=	0x0095
                           000096   286 _PORT_P1_6	=	0x0096
                           000097   287 _PORT_P1_7	=	0x0097
                           0000A0   288 _PORT_P2_0	=	0x00a0
                           0000A1   289 _PORT_P2_1	=	0x00a1
                           0000A2   290 _PORT_P2_2	=	0x00a2
                           0000A3   291 _PORT_P2_3	=	0x00a3
                           0000A4   292 _PORT_P2_4	=	0x00a4
                           0000A5   293 _PORT_P2_5	=	0x00a5
                           0000A6   294 _PORT_P2_6	=	0x00a6
                           0000A7   295 _PORT_P2_7	=	0x00a7
                           0000B0   296 _PORT_P3_0	=	0x00b0
                           0000B1   297 _PORT_P3_1	=	0x00b1
                           0000B2   298 _PORT_P3_2	=	0x00b2
                           0000B3   299 _PORT_P3_3	=	0x00b3
                           0000B4   300 _PORT_P3_4	=	0x00b4
                           0000B5   301 _PORT_P3_5	=	0x00b5
                           0000B6   302 _PORT_P3_6	=	0x00b6
                           0000B7   303 _PORT_P3_7	=	0x00b7
                           0000C0   304 _PORT_P4_0	=	0x00c0
                           0000C1   305 _PORT_P4_1	=	0x00c1
                           0000C2   306 _PORT_P4_2	=	0x00c2
                           0000C3   307 _PORT_P4_3	=	0x00c3
                           0000C4   308 _PORT_P4_4	=	0x00c4
                           0000C5   309 _PORT_P4_5	=	0x00c5
                           0000C6   310 _PORT_P4_6	=	0x00c6
                           0000C7   311 _PORT_P4_7	=	0x00c7
                           0000C8   312 _PORT_P5_0	=	0x00c8
                           0000C9   313 _PORT_P5_1	=	0x00c9
                           0000CA   314 _PORT_P5_2	=	0x00ca
                           0000CB   315 _PORT_P5_3	=	0x00cb
                           0000CC   316 _PORT_P5_4	=	0x00cc
                           0000CD   317 _PORT_P5_5	=	0x00cd
                           0000CE   318 _PORT_P5_6	=	0x00ce
                           0000CF   319 _PORT_P5_7	=	0x00cf
                           0000A8   320 _INT_IE_EX0	=	0x00a8
                           0000A9   321 _INT_IE_ET0	=	0x00a9
                           0000AA   322 _INT_IE_EX1	=	0x00aa
                           0000AB   323 _INT_IE_ET1	=	0x00ab
                           0000AC   324 _INT_IE_ES	=	0x00ac
                           0000AD   325 _INT_IE_EADC	=	0x00ad
                           0000AE   326 _INT_IE_ELVD	=	0x00ae
                           0000AF   327 _INT_IE_EA	=	0x00af
                           0000B8   328 _INT_IP_PX0	=	0x00b8
                           0000B9   329 _INT_IP_PT0	=	0x00b9
                           0000BA   330 _INT_IP_PX1	=	0x00ba
                           0000BB   331 _INT_IP_PT1	=	0x00bb
                           0000BC   332 _INT_IP_PS	=	0x00bc
                           0000BD   333 _INT_IP_PADC	=	0x00bd
                           0000BE   334 _INT_IP_PLVD	=	0x00be
                           0000BF   335 _INT_IP_PPCA	=	0x00bf
                           000088   336 _TMR_TCON_IT0	=	0x0088
                           000089   337 _TMR_TCON_IE0	=	0x0089
                           00008A   338 _TMR_TCON_IT1	=	0x008a
                           00008B   339 _TMR_TCON_IE1	=	0x008b
                           00008C   340 _TMR_TCON_TR0	=	0x008c
                           00008D   341 _TMR_TCON_TF0	=	0x008d
                           00008E   342 _TMR_TCON_TR1	=	0x008e
                           00008F   343 _TMR_TCON_TF1	=	0x008f
                           0000D8   344 _PCA_CCF0	=	0x00d8
                           0000D9   345 _PCA_CCF1	=	0x00d9
                           0000DA   346 _PCA_CCF2	=	0x00da
                           0000DE   347 _PCA_CR	=	0x00de
                           0000DF   348 _PCA_CF	=	0x00df
                           000098   349 _UART_RI	=	0x0098
                           000099   350 _UART_TI	=	0x0099
                           00009A   351 _UART_RB8	=	0x009a
                           00009B   352 _UART_TB8	=	0x009b
                           00009C   353 _UART_REN	=	0x009c
                           00009D   354 _UART_SM2	=	0x009d
                           00009E   355 _UART_SM1	=	0x009e
                           00009F   356 _UART_SM0	=	0x009f
                                    357 ;--------------------------------------------------------
                                    358 ; overlayable register banks
                                    359 ;--------------------------------------------------------
                                    360 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        361 	.ds 8
                                    362 	.area REG_BANK_2	(REL,OVR,DATA)
      000010                        363 	.ds 8
                                    364 ;--------------------------------------------------------
                                    365 ; internal ram data
                                    366 ;--------------------------------------------------------
                                    367 	.area DSEG    (DATA)
                           000022   368 _BUTTON_DATA	=	0x0022
                           000021   369 _DS1302_DATA	=	0x0021
      00005E                        370 _ticks_10ms::
      00005E                        371 	.ds 2
                                    372 ;--------------------------------------------------------
                                    373 ; overlayable items in internal ram
                                    374 ;--------------------------------------------------------
                                    375 	.area	OSEG    (OVR,DATA)
                                    376 ;--------------------------------------------------------
                                    377 ; indirectly addressable internal ram data
                                    378 ;--------------------------------------------------------
                                    379 	.area ISEG    (DATA)
                                    380 ;--------------------------------------------------------
                                    381 ; absolute internal ram data
                                    382 ;--------------------------------------------------------
                                    383 	.area IABS    (ABS,DATA)
                                    384 	.area IABS    (ABS,DATA)
                                    385 ;--------------------------------------------------------
                                    386 ; bit data
                                    387 ;--------------------------------------------------------
                                    388 	.area BSEG    (BIT)
                           000010   389 _BUTTON_DATA_MENU_PRESSED	=	0x0010
                           000011   390 _BUTTON_DATA_MENU_RELEASED_NORMAL	=	0x0011
                           000012   391 _BUTTON_DATA_MENU_RELEASED_LONGP	=	0x0012
                           000013   392 _BUTTON_DATA_MENU_HELD_DOWN	=	0x0013
                           000014   393 _BUTTON_DATA_SELECT_PRESSED	=	0x0014
                           000015   394 _BUTTON_DATA_SELECT_RELEASED_NORMAL	=	0x0015
                           000016   395 _BUTTON_DATA_SELECT_RELEASED_LONGP	=	0x0016
                           000017   396 _BUTTON_DATA_SELECT_HELD_DOWN	=	0x0017
                           000008   397 _DS1302_DATA_0	=	0x0008
                           000009   398 _DS1302_DATA_1	=	0x0009
                           00000A   399 _DS1302_DATA_2	=	0x000a
                           00000B   400 _DS1302_DATA_3	=	0x000b
                           00000C   401 _DS1302_DATA_4	=	0x000c
                           00000D   402 _DS1302_DATA_5	=	0x000d
                           00000E   403 _DS1302_DATA_6	=	0x000e
                           00000F   404 _DS1302_DATA_7	=	0x000f
                           00001F   405 _display_autobrightness	=	0x001f
                                    406 ;--------------------------------------------------------
                                    407 ; paged external ram data
                                    408 ;--------------------------------------------------------
                                    409 	.area PSEG    (PAG,XDATA)
                                    410 ;--------------------------------------------------------
                                    411 ; external ram data
                                    412 ;--------------------------------------------------------
                                    413 	.area XSEG    (XDATA)
                                    414 ;--------------------------------------------------------
                                    415 ; absolute external ram data
                                    416 ;--------------------------------------------------------
                                    417 	.area XABS    (ABS,XDATA)
                                    418 ;--------------------------------------------------------
                                    419 ; external initialized ram data
                                    420 ;--------------------------------------------------------
                                    421 	.area XISEG   (XDATA)
                                    422 	.area HOME    (CODE)
                                    423 	.area GSINIT0 (CODE)
                                    424 	.area GSINIT1 (CODE)
                                    425 	.area GSINIT2 (CODE)
                                    426 	.area GSINIT3 (CODE)
                                    427 	.area GSINIT4 (CODE)
                                    428 	.area GSINIT5 (CODE)
                                    429 	.area GSINIT  (CODE)
                                    430 	.area GSFINAL (CODE)
                                    431 	.area CSEG    (CODE)
                                    432 ;--------------------------------------------------------
                                    433 ; global & static initialisations
                                    434 ;--------------------------------------------------------
                                    435 	.area HOME    (CODE)
                                    436 	.area GSINIT  (CODE)
                                    437 	.area GSFINAL (CODE)
                                    438 	.area GSINIT  (CODE)
                                    439 ;	src/timer.c:20: volatile uint16_t ticks_10ms = 0x0000;
      0000F9 E4               [12]  440 	clr	a
      0000FA F5 5E            [12]  441 	mov	_ticks_10ms,a
      0000FC F5 5F            [12]  442 	mov	(_ticks_10ms + 1),a
                                    443 ;--------------------------------------------------------
                                    444 ; Home
                                    445 ;--------------------------------------------------------
                                    446 	.area HOME    (CODE)
                                    447 	.area HOME    (CODE)
                                    448 ;--------------------------------------------------------
                                    449 ; code
                                    450 ;--------------------------------------------------------
                                    451 	.area CSEG    (CODE)
                                    452 ;------------------------------------------------------------
                                    453 ;Allocation info for local variables in function 'ISR_T0'
                                    454 ;------------------------------------------------------------
                                    455 ;	src/timer.c:22: void ISR_T0(void) __interrupt(INT_T0) __using(2) {
                                    456 ;	-----------------------------------------
                                    457 ;	 function ISR_T0
                                    458 ;	-----------------------------------------
      0019EB                        459 _ISR_T0:
                           000017   460 	ar7 = 0x17
                           000016   461 	ar6 = 0x16
                           000015   462 	ar5 = 0x15
                           000014   463 	ar4 = 0x14
                           000013   464 	ar3 = 0x13
                           000012   465 	ar2 = 0x12
                           000011   466 	ar1 = 0x11
                           000010   467 	ar0 = 0x10
      0019EB C0 E0            [24]  468 	push	acc
      0019ED C0 D0            [24]  469 	push	psw
      0019EF 75 D0 10         [24]  470 	mov	psw,#0x10
                                    471 ;	src/timer.c:31: ticks_10ms++;	  //Increment 10ms tick count
      0019F2 AE 5E            [24]  472 	mov	r6,_ticks_10ms
      0019F4 AF 5F            [24]  473 	mov	r7,(_ticks_10ms + 1)
      0019F6 74 01            [12]  474 	mov	a,#0x01
      0019F8 2E               [12]  475 	add	a,r6
      0019F9 F5 5E            [12]  476 	mov	_ticks_10ms,a
      0019FB E4               [12]  477 	clr	a
      0019FC 3F               [12]  478 	addc	a,r7
      0019FD F5 5F            [12]  479 	mov	(_ticks_10ms + 1),a
                                    480 ;	src/timer.c:39: if(ADC_CONTR == ADC_SETUP_THERMISTOR) //If we have triggered the thermistor last time
      0019FF 74 E7            [12]  481 	mov	a,#0xe7
      001A01 B5 BC 0B         [24]  482 	cjne	a,_ADC_CONTR,00102$
                                    483 ;	include/adc.h:68: ADC_RES = 0x0000;				//Clear the ADC result
      001A04 E4               [12]  484 	clr	a
      001A05 F5 BE            [12]  485 	mov	((_ADC_RES >> 0) & 0xFF),a
      001A07 F5 BD            [12]  486 	mov	((_ADC_RES >> 8) & 0xFF),a
                                    487 ;	include/adc.h:69: ADC_CONTR = ADC_SETUP_LDR;		//Must set source bits first before triggering
      001A09 75 BC E6         [24]  488 	mov	_ADC_CONTR,#0xe6
                                    489 ;	include/adc.h:70: ADC_CONTR = ADC_TRIGGER_LDR;
      001A0C 75 BC EE         [24]  490 	mov	_ADC_CONTR,#0xee
                                    491 ;	src/timer.c:40: adc_trigger_ldr();				  //Trigger the LDR now
      001A0F                        492 00102$:
                                    493 ;	src/timer.c:41: if(ADC_CONTR == ADC_SETUP_LDR)		  //If we have triggered the LDR last time
      001A0F 74 E6            [12]  494 	mov	a,#0xe6
      001A11 B5 BC 0B         [24]  495 	cjne	a,_ADC_CONTR,00104$
                                    496 ;	include/adc.h:77: ADC_RES = 0x0000;				//Clear the ADC result
      001A14 E4               [12]  497 	clr	a
      001A15 F5 BE            [12]  498 	mov	((_ADC_RES >> 0) & 0xFF),a
      001A17 F5 BD            [12]  499 	mov	((_ADC_RES >> 8) & 0xFF),a
                                    500 ;	include/adc.h:78: ADC_CONTR = ADC_SETUP_THERMISTOR;	//Must set source bits first before triggering
      001A19 75 BC E7         [24]  501 	mov	_ADC_CONTR,#0xe7
                                    502 ;	include/adc.h:79: ADC_CONTR = ADC_TRIGGER_THERMISTOR;
      001A1C 75 BC EF         [24]  503 	mov	_ADC_CONTR,#0xef
                                    504 ;	src/timer.c:42: adc_trigger_thermistor();		  //Trigger the thermistor now
      001A1F                        505 00104$:
                                    506 ;	src/timer.c:57: BUTTON_MENU_STATE = ((BUTTON_MENU_STATE << 1) | BUTTON_MENU);		//Write new menu button state
      001A1F E5 3E            [12]  507 	mov	a,_BUTTON_MENU_STATE
      001A21 25 E0            [12]  508 	add	a,acc
      001A23 FF               [12]  509 	mov	r7,a
      001A24 A2 B1            [12]  510 	mov	c,_PORT_P3_1
      001A26 E4               [12]  511 	clr	a
      001A27 33               [12]  512 	rlc	a
      001A28 4F               [12]  513 	orl	a,r7
      001A29 F5 3E            [12]  514 	mov	_BUTTON_MENU_STATE,a
                                    515 ;	src/timer.c:58: BUTTON_SELECT_STATE = ((BUTTON_SELECT_STATE << 1) | BUTTON_SELECT); //Write new select button state
      001A2B E5 3F            [12]  516 	mov	a,_BUTTON_SELECT_STATE
      001A2D 25 E0            [12]  517 	add	a,acc
      001A2F FF               [12]  518 	mov	r7,a
      001A30 A2 B0            [12]  519 	mov	c,_PORT_P3_0
      001A32 E4               [12]  520 	clr	a
      001A33 33               [12]  521 	rlc	a
      001A34 4F               [12]  522 	orl	a,r7
      001A35 F5 3F            [12]  523 	mov	_BUTTON_SELECT_STATE,a
                                    524 ;	src/timer.c:61: if((BUTTON_MENU_STATE & BUTTON_DEBOUNCE_MASK) == BUTTON_DEBOUNCE_PATTERN_PRESSED){
      001A37 AE 3E            [24]  525 	mov	r6,_BUTTON_MENU_STATE
      001A39 53 16 87         [24]  526 	anl	ar6,#0x87
      001A3C 7F 00            [12]  527 	mov	r7,#0x00
      001A3E BE 80 0E         [24]  528 	cjne	r6,#0x80,00106$
      001A41 BF 00 0B         [24]  529 	cjne	r7,#0x00,00106$
                                    530 ;	src/timer.c:62: BUTTON_DATA_MENU_PRESSED = 0x01;			//Set new state
                                    531 ;	assignBit
      001A44 D2 10            [12]  532 	setb	_BUTTON_DATA_MENU_PRESSED
                                    533 ;	src/timer.c:63: BUTTON_DATA &= 0xf1;						//Clear other bits
      001A46 53 22 F1         [24]  534 	anl	_BUTTON_DATA,#0xf1
                                    535 ;	src/timer.c:64: BUTTON_MENU_CNT = 0x00;						//Reset counter
      001A49 75 40 00         [24]  536 	mov	_BUTTON_MENU_CNT,#0x00
                                    537 ;	src/timer.c:65: BUTTON_MENU_STATE = 0x00;
      001A4C 75 3E 00         [24]  538 	mov	_BUTTON_MENU_STATE,#0x00
      001A4F                        539 00106$:
                                    540 ;	src/timer.c:67: if((BUTTON_SELECT_STATE & BUTTON_DEBOUNCE_MASK) == BUTTON_DEBOUNCE_PATTERN_PRESSED){
      001A4F AE 3F            [24]  541 	mov	r6,_BUTTON_SELECT_STATE
      001A51 53 16 87         [24]  542 	anl	ar6,#0x87
      001A54 7F 00            [12]  543 	mov	r7,#0x00
      001A56 BE 80 0E         [24]  544 	cjne	r6,#0x80,00108$
      001A59 BF 00 0B         [24]  545 	cjne	r7,#0x00,00108$
                                    546 ;	src/timer.c:68: BUTTON_DATA_SELECT_PRESSED = 0x01;			//Set new state
                                    547 ;	assignBit
      001A5C D2 14            [12]  548 	setb	_BUTTON_DATA_SELECT_PRESSED
                                    549 ;	src/timer.c:69: BUTTON_DATA &= 0x1f;						//Clear other bits
      001A5E 53 22 1F         [24]  550 	anl	_BUTTON_DATA,#0x1f
                                    551 ;	src/timer.c:70: BUTTON_SELECT_CNT = 0x00;					//Reset counter
      001A61 75 41 00         [24]  552 	mov	_BUTTON_SELECT_CNT,#0x00
                                    553 ;	src/timer.c:71: BUTTON_SELECT_STATE = 0x00;
      001A64 75 3F 00         [24]  554 	mov	_BUTTON_SELECT_STATE,#0x00
      001A67                        555 00108$:
                                    556 ;	src/timer.c:76: if((BUTTON_MENU_STATE & BUTTON_DEBOUNCE_MASK) == BUTTON_DEBOUNCE_PATTERN_RELEASED){
      001A67 AE 3E            [24]  557 	mov	r6,_BUTTON_MENU_STATE
      001A69 53 16 87         [24]  558 	anl	ar6,#0x87
      001A6C 7F 00            [12]  559 	mov	r7,#0x00
      001A6E BE 07 1A         [24]  560 	cjne	r6,#0x07,00116$
      001A71 BF 00 17         [24]  561 	cjne	r7,#0x00,00116$
                                    562 ;	src/timer.c:77: if(BUTTON_DATA_MENU_HELD_DOWN) {
                                    563 ;	src/timer.c:78: BUTTON_DATA_MENU_HELD_DOWN = 0;
                                    564 ;	assignBit
      001A74 10 13 0C         [24]  565 	jbc	_BUTTON_DATA_MENU_HELD_DOWN,00114$
                                    566 ;	src/timer.c:80: if(BUTTON_MENU_CNT > BUTTON_LONG_PRESS_COUNT){
      001A77 E5 40            [12]  567 	mov	a,_BUTTON_MENU_CNT
      001A79 24 DF            [12]  568 	add	a,#0xff - 0x20
      001A7B 50 04            [24]  569 	jnc	00110$
                                    570 ;	src/timer.c:81: BUTTON_DATA_MENU_RELEASED_LONGP = 1;
                                    571 ;	assignBit
      001A7D D2 12            [12]  572 	setb	_BUTTON_DATA_MENU_RELEASED_LONGP
      001A7F 80 02            [24]  573 	sjmp	00114$
      001A81                        574 00110$:
                                    575 ;	src/timer.c:83: BUTTON_DATA_MENU_RELEASED_NORMAL = 1;
                                    576 ;	assignBit
      001A81 D2 11            [12]  577 	setb	_BUTTON_DATA_MENU_RELEASED_NORMAL
      001A83                        578 00114$:
                                    579 ;	src/timer.c:86: BUTTON_DATA_MENU_PRESSED = 0;
                                    580 ;	assignBit
      001A83 C2 10            [12]  581 	clr	_BUTTON_DATA_MENU_PRESSED
                                    582 ;	src/timer.c:87: BUTTON_MENU_CNT = 0;
      001A85 75 40 00         [24]  583 	mov	_BUTTON_MENU_CNT,#0x00
                                    584 ;	src/timer.c:88: BUTTON_MENU_STATE = 0xff;
      001A88 75 3E FF         [24]  585 	mov	_BUTTON_MENU_STATE,#0xff
      001A8B                        586 00116$:
                                    587 ;	src/timer.c:90: if((BUTTON_SELECT_STATE & BUTTON_DEBOUNCE_MASK) == BUTTON_DEBOUNCE_PATTERN_RELEASED){
      001A8B AE 3F            [24]  588 	mov	r6,_BUTTON_SELECT_STATE
      001A8D 53 16 87         [24]  589 	anl	ar6,#0x87
      001A90 7F 00            [12]  590 	mov	r7,#0x00
      001A92 BE 07 1A         [24]  591 	cjne	r6,#0x07,00124$
      001A95 BF 00 17         [24]  592 	cjne	r7,#0x00,00124$
                                    593 ;	src/timer.c:91: if(BUTTON_DATA_SELECT_HELD_DOWN) {
                                    594 ;	src/timer.c:92: BUTTON_DATA_SELECT_HELD_DOWN = 0;
                                    595 ;	assignBit
      001A98 10 17 0C         [24]  596 	jbc	_BUTTON_DATA_SELECT_HELD_DOWN,00122$
                                    597 ;	src/timer.c:94: if(BUTTON_SELECT_CNT > BUTTON_LONG_PRESS_COUNT){
      001A9B E5 41            [12]  598 	mov	a,_BUTTON_SELECT_CNT
      001A9D 24 DF            [12]  599 	add	a,#0xff - 0x20
      001A9F 50 04            [24]  600 	jnc	00118$
                                    601 ;	src/timer.c:95: BUTTON_DATA_SELECT_RELEASED_LONGP = 1;
                                    602 ;	assignBit
      001AA1 D2 16            [12]  603 	setb	_BUTTON_DATA_SELECT_RELEASED_LONGP
      001AA3 80 02            [24]  604 	sjmp	00122$
      001AA5                        605 00118$:
                                    606 ;	src/timer.c:97: BUTTON_DATA_SELECT_RELEASED_NORMAL = 1;
                                    607 ;	assignBit
      001AA5 D2 15            [12]  608 	setb	_BUTTON_DATA_SELECT_RELEASED_NORMAL
      001AA7                        609 00122$:
                                    610 ;	src/timer.c:100: BUTTON_DATA_SELECT_PRESSED = 0;
                                    611 ;	assignBit
      001AA7 C2 14            [12]  612 	clr	_BUTTON_DATA_SELECT_PRESSED
                                    613 ;	src/timer.c:101: BUTTON_SELECT_CNT = 0;
      001AA9 75 41 00         [24]  614 	mov	_BUTTON_SELECT_CNT,#0x00
                                    615 ;	src/timer.c:102: BUTTON_SELECT_STATE = 0xff;
      001AAC 75 3F FF         [24]  616 	mov	_BUTTON_SELECT_STATE,#0xff
      001AAF                        617 00124$:
                                    618 ;	src/timer.c:106: if(BUTTON_DATA_MENU_PRESSED)
      001AAF 30 10 0D         [24]  619 	jnb	_BUTTON_DATA_MENU_PRESSED,00128$
                                    620 ;	src/timer.c:107: if(++BUTTON_MENU_CNT >= BUTTON_HELD_DOWN_COUNT)				//Detect held down button
      001AB2 E5 40            [12]  621 	mov	a,_BUTTON_MENU_CNT
      001AB4 04               [12]  622 	inc	a
      001AB5 FF               [12]  623 	mov	r7,a
      001AB6 8F 40            [24]  624 	mov	_BUTTON_MENU_CNT,r7
      001AB8 BF 96 00         [24]  625 	cjne	r7,#0x96,00210$
      001ABB                        626 00210$:
      001ABB 40 02            [24]  627 	jc	00128$
                                    628 ;	src/timer.c:108: BUTTON_DATA_MENU_HELD_DOWN = 1;
                                    629 ;	assignBit
      001ABD D2 13            [12]  630 	setb	_BUTTON_DATA_MENU_HELD_DOWN
      001ABF                        631 00128$:
                                    632 ;	src/timer.c:109: if(BUTTON_DATA_SELECT_PRESSED)
      001ABF 30 14 0D         [24]  633 	jnb	_BUTTON_DATA_SELECT_PRESSED,00135$
                                    634 ;	src/timer.c:110: if(++BUTTON_SELECT_CNT >= BUTTON_HELD_DOWN_COUNT)				//Detect held down button
      001AC2 E5 41            [12]  635 	mov	a,_BUTTON_SELECT_CNT
      001AC4 04               [12]  636 	inc	a
      001AC5 FF               [12]  637 	mov	r7,a
      001AC6 8F 41            [24]  638 	mov	_BUTTON_SELECT_CNT,r7
      001AC8 BF 96 00         [24]  639 	cjne	r7,#0x96,00213$
      001ACB                        640 00213$:
      001ACB 40 02            [24]  641 	jc	00135$
                                    642 ;	src/timer.c:111: BUTTON_DATA_SELECT_HELD_DOWN = 1;
                                    643 ;	assignBit
      001ACD D2 17            [12]  644 	setb	_BUTTON_DATA_SELECT_HELD_DOWN
      001ACF                        645 00135$:
                                    646 ;	src/timer.c:112: }
      001ACF D0 D0            [24]  647 	pop	psw
      001AD1 D0 E0            [24]  648 	pop	acc
      001AD3 32               [24]  649 	reti
                                    650 ;	eliminated unneeded push/pop dpl
                                    651 ;	eliminated unneeded push/pop dph
                                    652 ;	eliminated unneeded push/pop b
                                    653 ;------------------------------------------------------------
                                    654 ;Allocation info for local variables in function 'centiseconds'
                                    655 ;------------------------------------------------------------
                                    656 ;ticks_now                 Allocated to registers 
                                    657 ;------------------------------------------------------------
                                    658 ;	src/timer.c:114: volatile uint16_t centiseconds() {
                                    659 ;	-----------------------------------------
                                    660 ;	 function centiseconds
                                    661 ;	-----------------------------------------
      001AD4                        662 _centiseconds:
                           000007   663 	ar7 = 0x07
                           000006   664 	ar6 = 0x06
                           000005   665 	ar5 = 0x05
                           000004   666 	ar4 = 0x04
                           000003   667 	ar3 = 0x03
                           000002   668 	ar2 = 0x02
                           000001   669 	ar1 = 0x01
                           000000   670 	ar0 = 0x00
                                    671 ;	src/timer.c:116: INT_IE_ET0 = 0;
                                    672 ;	assignBit
      001AD4 C2 A9            [12]  673 	clr	_INT_IE_ET0
                                    674 ;	src/timer.c:117: ticks_now = ticks_10ms;
      001AD6 85 5E 82         [24]  675 	mov	dpl,_ticks_10ms
      001AD9 85 5F 83         [24]  676 	mov	dph,(_ticks_10ms + 1)
                                    677 ;	src/timer.c:118: INT_IE_ET0 = 1;
                                    678 ;	assignBit
      001ADC D2 A9            [12]  679 	setb	_INT_IE_ET0
                                    680 ;	src/timer.c:119: return ticks_now;
                                    681 ;	src/timer.c:120: }
      001ADE 22               [24]  682 	ret
                                    683 	.area CSEG    (CODE)
                                    684 	.area CONST   (CODE)
                                    685 	.area XINIT   (CODE)
                                    686 	.area CABS    (ABS,CODE)
