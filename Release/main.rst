                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _fsm_home_fn
                                     13 	.globl _button_read_and_clear_select
                                     14 	.globl _button_read_and_clear_menu
                                     15 	.globl _ds1302_power_loss_reset
                                     16 	.globl _ds1302_check_SRAM
                                     17 	.globl _ds1302_read_SRAM
                                     18 	.globl _ds1302_reset
                                     19 	.globl _UART_SM0
                                     20 	.globl _UART_SM1
                                     21 	.globl _UART_SM2
                                     22 	.globl _UART_REN
                                     23 	.globl _UART_TB8
                                     24 	.globl _UART_RB8
                                     25 	.globl _UART_TI
                                     26 	.globl _UART_RI
                                     27 	.globl _PCA_CF
                                     28 	.globl _PCA_CR
                                     29 	.globl _PCA_CCF2
                                     30 	.globl _PCA_CCF1
                                     31 	.globl _PCA_CCF0
                                     32 	.globl _TMR_TCON_TF1
                                     33 	.globl _TMR_TCON_TR1
                                     34 	.globl _TMR_TCON_TF0
                                     35 	.globl _TMR_TCON_TR0
                                     36 	.globl _TMR_TCON_IE1
                                     37 	.globl _TMR_TCON_IT1
                                     38 	.globl _TMR_TCON_IE0
                                     39 	.globl _TMR_TCON_IT0
                                     40 	.globl _INT_IP_PPCA
                                     41 	.globl _INT_IP_PLVD
                                     42 	.globl _INT_IP_PADC
                                     43 	.globl _INT_IP_PS
                                     44 	.globl _INT_IP_PT1
                                     45 	.globl _INT_IP_PX1
                                     46 	.globl _INT_IP_PT0
                                     47 	.globl _INT_IP_PX0
                                     48 	.globl _INT_IE_EA
                                     49 	.globl _INT_IE_ELVD
                                     50 	.globl _INT_IE_EADC
                                     51 	.globl _INT_IE_ES
                                     52 	.globl _INT_IE_ET1
                                     53 	.globl _INT_IE_EX1
                                     54 	.globl _INT_IE_ET0
                                     55 	.globl _INT_IE_EX0
                                     56 	.globl _PORT_P5_7
                                     57 	.globl _PORT_P5_6
                                     58 	.globl _PORT_P5_5
                                     59 	.globl _PORT_P5_4
                                     60 	.globl _PORT_P5_3
                                     61 	.globl _PORT_P5_2
                                     62 	.globl _PORT_P5_1
                                     63 	.globl _PORT_P5_0
                                     64 	.globl _PORT_P4_7
                                     65 	.globl _PORT_P4_6
                                     66 	.globl _PORT_P4_5
                                     67 	.globl _PORT_P4_4
                                     68 	.globl _PORT_P4_3
                                     69 	.globl _PORT_P4_2
                                     70 	.globl _PORT_P4_1
                                     71 	.globl _PORT_P4_0
                                     72 	.globl _PORT_P3_7
                                     73 	.globl _PORT_P3_6
                                     74 	.globl _PORT_P3_5
                                     75 	.globl _PORT_P3_4
                                     76 	.globl _PORT_P3_3
                                     77 	.globl _PORT_P3_2
                                     78 	.globl _PORT_P3_1
                                     79 	.globl _PORT_P3_0
                                     80 	.globl _PORT_P2_7
                                     81 	.globl _PORT_P2_6
                                     82 	.globl _PORT_P2_5
                                     83 	.globl _PORT_P2_4
                                     84 	.globl _PORT_P2_3
                                     85 	.globl _PORT_P2_2
                                     86 	.globl _PORT_P2_1
                                     87 	.globl _PORT_P2_0
                                     88 	.globl _PORT_P1_7
                                     89 	.globl _PORT_P1_6
                                     90 	.globl _PORT_P1_5
                                     91 	.globl _PORT_P1_4
                                     92 	.globl _PORT_P1_3
                                     93 	.globl _PORT_P1_2
                                     94 	.globl _PORT_P1_1
                                     95 	.globl _PORT_P1_0
                                     96 	.globl _CY
                                     97 	.globl _AC
                                     98 	.globl _F0
                                     99 	.globl _RS1
                                    100 	.globl _RS0
                                    101 	.globl _OV
                                    102 	.globl _F1
                                    103 	.globl _P
                                    104 	.globl _IAP_CONTR
                                    105 	.globl _IAP_TRIG
                                    106 	.globl _IAP_CMD
                                    107 	.globl _IAP_ADDR
                                    108 	.globl _IAP_ADDRL
                                    109 	.globl _IAP_ADDRH
                                    110 	.globl _IAP_DATA
                                    111 	.globl _UART_SADEN
                                    112 	.globl _UART_SADDR
                                    113 	.globl _UART_SBUF
                                    114 	.globl _UART_SCON
                                    115 	.globl _PCA_CMOD
                                    116 	.globl _PCA_CCON
                                    117 	.globl _PCA_PWM2
                                    118 	.globl _PCA_PWM1
                                    119 	.globl _PCA_PWM0
                                    120 	.globl _PCA_C
                                    121 	.globl _PCA_CCAP2_L
                                    122 	.globl _PCA_CCAP2_H
                                    123 	.globl _PCA_CCAP1_L
                                    124 	.globl _PCA_CCAP1_H
                                    125 	.globl _PCA_CCAP0_L
                                    126 	.globl _PCA_CCAP0_H
                                    127 	.globl _PCA_CCAP2
                                    128 	.globl _PCA_CCAP1
                                    129 	.globl _PCA_CCAP0
                                    130 	.globl _PCA_CCAPM2
                                    131 	.globl _PCA_CCAPM1
                                    132 	.globl _PCA_CCAPM0
                                    133 	.globl _CMP_CR2
                                    134 	.globl _CMP_CR1
                                    135 	.globl _ADC_RESL
                                    136 	.globl _ADC_RESH
                                    137 	.globl _ADC_RES
                                    138 	.globl _ADC_CONTR
                                    139 	.globl _ADC_P1ASF
                                    140 	.globl _EEPROM_CONTR
                                    141 	.globl _EEPROM_TRIG
                                    142 	.globl _EEPROM_CMD
                                    143 	.globl _EEPROM_ADDR
                                    144 	.globl _EEPROM_DATA
                                    145 	.globl _TMR_T2
                                    146 	.globl _TMR_T0
                                    147 	.globl _TMR_TMOD
                                    148 	.globl _TMR_TCON
                                    149 	.globl _INT_IP2
                                    150 	.globl _INT_IP
                                    151 	.globl _INT_IE2
                                    152 	.globl _INT_IE
                                    153 	.globl _PORT_P5M0
                                    154 	.globl _PORT_P5M1
                                    155 	.globl _PORT_P4M0
                                    156 	.globl _PORT_P4M1
                                    157 	.globl _PORT_P3M0
                                    158 	.globl _PORT_P3M1
                                    159 	.globl _PORT_P2M0
                                    160 	.globl _PORT_P2M1
                                    161 	.globl _PORT_P1M0
                                    162 	.globl _PORT_P1M1
                                    163 	.globl _PORT_P5
                                    164 	.globl _PORT_P4
                                    165 	.globl _PORT_P3
                                    166 	.globl _PORT_P2
                                    167 	.globl _PORT_P1
                                    168 	.globl _PSW
                                    169 	.globl _PCON2
                                    170 	.globl _AUXR2
                                    171 	.globl _AUXR1
                                    172 	.globl _AUXR
                                    173 	.globl _PCON
                                    174 	.globl _DPTR
                                    175 	.globl _SP
                                    176 	.globl _alarms
                                    177 	.globl _fsm_home_auto
                                    178 	.globl _BUTTON_DATA_SELECT_HELD_DOWN
                                    179 	.globl _BUTTON_DATA_SELECT_RELEASED_LONGP
                                    180 	.globl _BUTTON_DATA_SELECT_RELEASED_NORMAL
                                    181 	.globl _BUTTON_DATA_SELECT_PRESSED
                                    182 	.globl _BUTTON_DATA_MENU_HELD_DOWN
                                    183 	.globl _BUTTON_DATA_MENU_RELEASED_LONGP
                                    184 	.globl _BUTTON_DATA_MENU_RELEASED_NORMAL
                                    185 	.globl _BUTTON_DATA_MENU_PRESSED
                                    186 	.globl _display_autobrightness
                                    187 	.globl _DS1302_DATA_7
                                    188 	.globl _DS1302_DATA_6
                                    189 	.globl _DS1302_DATA_5
                                    190 	.globl _DS1302_DATA_4
                                    191 	.globl _DS1302_DATA_3
                                    192 	.globl _DS1302_DATA_2
                                    193 	.globl _DS1302_DATA_1
                                    194 	.globl _DS1302_DATA_0
                                    195 	.globl _BUTTON_DATA
                                    196 	.globl _DS1302_DATA
                                    197 ;--------------------------------------------------------
                                    198 ; special function registers
                                    199 ;--------------------------------------------------------
                                    200 	.area RSEG    (ABS,DATA)
      000000                        201 	.org 0x0000
                           000081   202 _SP	=	0x0081
                           008382   203 _DPTR	=	0x8382
                           000087   204 _PCON	=	0x0087
                           00008E   205 _AUXR	=	0x008e
                           0000A2   206 _AUXR1	=	0x00a2
                           00008F   207 _AUXR2	=	0x008f
                           000097   208 _PCON2	=	0x0097
                           0000D0   209 _PSW	=	0x00d0
                           000090   210 _PORT_P1	=	0x0090
                           0000A0   211 _PORT_P2	=	0x00a0
                           0000B0   212 _PORT_P3	=	0x00b0
                           0000C0   213 _PORT_P4	=	0x00c0
                           0000C8   214 _PORT_P5	=	0x00c8
                           000091   215 _PORT_P1M1	=	0x0091
                           000092   216 _PORT_P1M0	=	0x0092
                           000095   217 _PORT_P2M1	=	0x0095
                           000096   218 _PORT_P2M0	=	0x0096
                           0000B1   219 _PORT_P3M1	=	0x00b1
                           0000B2   220 _PORT_P3M0	=	0x00b2
                           0000B3   221 _PORT_P4M1	=	0x00b3
                           0000B4   222 _PORT_P4M0	=	0x00b4
                           0000C9   223 _PORT_P5M1	=	0x00c9
                           0000CA   224 _PORT_P5M0	=	0x00ca
                           0000A8   225 _INT_IE	=	0x00a8
                           0000AF   226 _INT_IE2	=	0x00af
                           0000B8   227 _INT_IP	=	0x00b8
                           0000B5   228 _INT_IP2	=	0x00b5
                           000088   229 _TMR_TCON	=	0x0088
                           000089   230 _TMR_TMOD	=	0x0089
                           008C8A   231 _TMR_T0	=	0x8c8a
                           00D6D7   232 _TMR_T2	=	0xd6d7
                           0000C2   233 _EEPROM_DATA	=	0x00c2
                           00C3C4   234 _EEPROM_ADDR	=	0xc3c4
                           0000C5   235 _EEPROM_CMD	=	0x00c5
                           0000C6   236 _EEPROM_TRIG	=	0x00c6
                           0000C7   237 _EEPROM_CONTR	=	0x00c7
                           00009D   238 _ADC_P1ASF	=	0x009d
                           0000BC   239 _ADC_CONTR	=	0x00bc
                           00BDBE   240 _ADC_RES	=	0xbdbe
                           0000BD   241 _ADC_RESH	=	0x00bd
                           0000BE   242 _ADC_RESL	=	0x00be
                           0000E6   243 _CMP_CR1	=	0x00e6
                           0000E7   244 _CMP_CR2	=	0x00e7
                           0000DA   245 _PCA_CCAPM0	=	0x00da
                           0000DB   246 _PCA_CCAPM1	=	0x00db
                           0000DC   247 _PCA_CCAPM2	=	0x00dc
                           00FAEA   248 _PCA_CCAP0	=	0xfaea
                           00FBEB   249 _PCA_CCAP1	=	0xfbeb
                           00FCEC   250 _PCA_CCAP2	=	0xfcec
                           0000FA   251 _PCA_CCAP0_H	=	0x00fa
                           0000EA   252 _PCA_CCAP0_L	=	0x00ea
                           0000FB   253 _PCA_CCAP1_H	=	0x00fb
                           0000EB   254 _PCA_CCAP1_L	=	0x00eb
                           0000FC   255 _PCA_CCAP2_H	=	0x00fc
                           0000EC   256 _PCA_CCAP2_L	=	0x00ec
                           00F9E9   257 _PCA_C	=	0xf9e9
                           0000F2   258 _PCA_PWM0	=	0x00f2
                           0000F3   259 _PCA_PWM1	=	0x00f3
                           0000F4   260 _PCA_PWM2	=	0x00f4
                           0000D8   261 _PCA_CCON	=	0x00d8
                           0000D9   262 _PCA_CMOD	=	0x00d9
                           000098   263 _UART_SCON	=	0x0098
                           000099   264 _UART_SBUF	=	0x0099
                           0000A9   265 _UART_SADDR	=	0x00a9
                           0000B9   266 _UART_SADEN	=	0x00b9
                           0000C2   267 _IAP_DATA	=	0x00c2
                           0000C3   268 _IAP_ADDRH	=	0x00c3
                           0000C4   269 _IAP_ADDRL	=	0x00c4
                           00C3C4   270 _IAP_ADDR	=	0xc3c4
                           0000C5   271 _IAP_CMD	=	0x00c5
                           0000C6   272 _IAP_TRIG	=	0x00c6
                           0000C7   273 _IAP_CONTR	=	0x00c7
                                    274 ;--------------------------------------------------------
                                    275 ; special function bits
                                    276 ;--------------------------------------------------------
                                    277 	.area RSEG    (ABS,DATA)
      000000                        278 	.org 0x0000
                           0000D0   279 _P	=	0x00d0
                           0000D1   280 _F1	=	0x00d1
                           0000D2   281 _OV	=	0x00d2
                           0000D3   282 _RS0	=	0x00d3
                           0000D4   283 _RS1	=	0x00d4
                           0000D5   284 _F0	=	0x00d5
                           0000D6   285 _AC	=	0x00d6
                           0000D7   286 _CY	=	0x00d7
                           000090   287 _PORT_P1_0	=	0x0090
                           000091   288 _PORT_P1_1	=	0x0091
                           000092   289 _PORT_P1_2	=	0x0092
                           000093   290 _PORT_P1_3	=	0x0093
                           000094   291 _PORT_P1_4	=	0x0094
                           000095   292 _PORT_P1_5	=	0x0095
                           000096   293 _PORT_P1_6	=	0x0096
                           000097   294 _PORT_P1_7	=	0x0097
                           0000A0   295 _PORT_P2_0	=	0x00a0
                           0000A1   296 _PORT_P2_1	=	0x00a1
                           0000A2   297 _PORT_P2_2	=	0x00a2
                           0000A3   298 _PORT_P2_3	=	0x00a3
                           0000A4   299 _PORT_P2_4	=	0x00a4
                           0000A5   300 _PORT_P2_5	=	0x00a5
                           0000A6   301 _PORT_P2_6	=	0x00a6
                           0000A7   302 _PORT_P2_7	=	0x00a7
                           0000B0   303 _PORT_P3_0	=	0x00b0
                           0000B1   304 _PORT_P3_1	=	0x00b1
                           0000B2   305 _PORT_P3_2	=	0x00b2
                           0000B3   306 _PORT_P3_3	=	0x00b3
                           0000B4   307 _PORT_P3_4	=	0x00b4
                           0000B5   308 _PORT_P3_5	=	0x00b5
                           0000B6   309 _PORT_P3_6	=	0x00b6
                           0000B7   310 _PORT_P3_7	=	0x00b7
                           0000C0   311 _PORT_P4_0	=	0x00c0
                           0000C1   312 _PORT_P4_1	=	0x00c1
                           0000C2   313 _PORT_P4_2	=	0x00c2
                           0000C3   314 _PORT_P4_3	=	0x00c3
                           0000C4   315 _PORT_P4_4	=	0x00c4
                           0000C5   316 _PORT_P4_5	=	0x00c5
                           0000C6   317 _PORT_P4_6	=	0x00c6
                           0000C7   318 _PORT_P4_7	=	0x00c7
                           0000C8   319 _PORT_P5_0	=	0x00c8
                           0000C9   320 _PORT_P5_1	=	0x00c9
                           0000CA   321 _PORT_P5_2	=	0x00ca
                           0000CB   322 _PORT_P5_3	=	0x00cb
                           0000CC   323 _PORT_P5_4	=	0x00cc
                           0000CD   324 _PORT_P5_5	=	0x00cd
                           0000CE   325 _PORT_P5_6	=	0x00ce
                           0000CF   326 _PORT_P5_7	=	0x00cf
                           0000A8   327 _INT_IE_EX0	=	0x00a8
                           0000A9   328 _INT_IE_ET0	=	0x00a9
                           0000AA   329 _INT_IE_EX1	=	0x00aa
                           0000AB   330 _INT_IE_ET1	=	0x00ab
                           0000AC   331 _INT_IE_ES	=	0x00ac
                           0000AD   332 _INT_IE_EADC	=	0x00ad
                           0000AE   333 _INT_IE_ELVD	=	0x00ae
                           0000AF   334 _INT_IE_EA	=	0x00af
                           0000B8   335 _INT_IP_PX0	=	0x00b8
                           0000B9   336 _INT_IP_PT0	=	0x00b9
                           0000BA   337 _INT_IP_PX1	=	0x00ba
                           0000BB   338 _INT_IP_PT1	=	0x00bb
                           0000BC   339 _INT_IP_PS	=	0x00bc
                           0000BD   340 _INT_IP_PADC	=	0x00bd
                           0000BE   341 _INT_IP_PLVD	=	0x00be
                           0000BF   342 _INT_IP_PPCA	=	0x00bf
                           000088   343 _TMR_TCON_IT0	=	0x0088
                           000089   344 _TMR_TCON_IE0	=	0x0089
                           00008A   345 _TMR_TCON_IT1	=	0x008a
                           00008B   346 _TMR_TCON_IE1	=	0x008b
                           00008C   347 _TMR_TCON_TR0	=	0x008c
                           00008D   348 _TMR_TCON_TF0	=	0x008d
                           00008E   349 _TMR_TCON_TR1	=	0x008e
                           00008F   350 _TMR_TCON_TF1	=	0x008f
                           0000D8   351 _PCA_CCF0	=	0x00d8
                           0000D9   352 _PCA_CCF1	=	0x00d9
                           0000DA   353 _PCA_CCF2	=	0x00da
                           0000DE   354 _PCA_CR	=	0x00de
                           0000DF   355 _PCA_CF	=	0x00df
                           000098   356 _UART_RI	=	0x0098
                           000099   357 _UART_TI	=	0x0099
                           00009A   358 _UART_RB8	=	0x009a
                           00009B   359 _UART_TB8	=	0x009b
                           00009C   360 _UART_REN	=	0x009c
                           00009D   361 _UART_SM2	=	0x009d
                           00009E   362 _UART_SM1	=	0x009e
                           00009F   363 _UART_SM0	=	0x009f
                                    364 ;--------------------------------------------------------
                                    365 ; overlayable register banks
                                    366 ;--------------------------------------------------------
                                    367 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        368 	.ds 8
                                    369 ;--------------------------------------------------------
                                    370 ; internal ram data
                                    371 ;--------------------------------------------------------
                                    372 	.area DSEG    (DATA)
                           000021   373 _DS1302_DATA	=	0x0021
                           000022   374 _BUTTON_DATA	=	0x0022
      000024                        375 _main_fsm_runstate_65536_175:
      000024                        376 	.ds 1
      000025                        377 _main_ticks_now_262144_204:
      000025                        378 	.ds 2
      000027                        379 _main_ticks_now_327680_210:
      000027                        380 	.ds 2
                                    381 ;--------------------------------------------------------
                                    382 ; overlayable items in internal ram
                                    383 ;--------------------------------------------------------
                                    384 ;--------------------------------------------------------
                                    385 ; Stack segment in internal ram
                                    386 ;--------------------------------------------------------
                                    387 	.area	SSEG
      00006B                        388 __start__stack:
      00006B                        389 	.ds	1
                                    390 
                                    391 ;--------------------------------------------------------
                                    392 ; indirectly addressable internal ram data
                                    393 ;--------------------------------------------------------
                                    394 	.area ISEG    (DATA)
                                    395 ;--------------------------------------------------------
                                    396 ; absolute internal ram data
                                    397 ;--------------------------------------------------------
                                    398 	.area IABS    (ABS,DATA)
                                    399 	.area IABS    (ABS,DATA)
                                    400 ;--------------------------------------------------------
                                    401 ; bit data
                                    402 ;--------------------------------------------------------
                                    403 	.area BSEG    (BIT)
                           000008   404 _DS1302_DATA_0	=	0x0008
                           000009   405 _DS1302_DATA_1	=	0x0009
                           00000A   406 _DS1302_DATA_2	=	0x000a
                           00000B   407 _DS1302_DATA_3	=	0x000b
                           00000C   408 _DS1302_DATA_4	=	0x000c
                           00000D   409 _DS1302_DATA_5	=	0x000d
                           00000E   410 _DS1302_DATA_6	=	0x000e
                           00000F   411 _DS1302_DATA_7	=	0x000f
                           00001F   412 _display_autobrightness	=	0x001f
                           000010   413 _BUTTON_DATA_MENU_PRESSED	=	0x0010
                           000011   414 _BUTTON_DATA_MENU_RELEASED_NORMAL	=	0x0011
                           000012   415 _BUTTON_DATA_MENU_RELEASED_LONGP	=	0x0012
                           000013   416 _BUTTON_DATA_MENU_HELD_DOWN	=	0x0013
                           000014   417 _BUTTON_DATA_SELECT_PRESSED	=	0x0014
                           000015   418 _BUTTON_DATA_SELECT_RELEASED_NORMAL	=	0x0015
                           000016   419 _BUTTON_DATA_SELECT_RELEASED_LONGP	=	0x0016
                           000017   420 _BUTTON_DATA_SELECT_HELD_DOWN	=	0x0017
                           00001E   421 _fsm_home_auto	=	0x001e
                                    422 ;--------------------------------------------------------
                                    423 ; paged external ram data
                                    424 ;--------------------------------------------------------
                                    425 	.area PSEG    (PAG,XDATA)
                                    426 ;--------------------------------------------------------
                                    427 ; external ram data
                                    428 ;--------------------------------------------------------
                                    429 	.area XSEG    (XDATA)
                           000004   430 _alarms	=	0x0004
                                    431 ;--------------------------------------------------------
                                    432 ; absolute external ram data
                                    433 ;--------------------------------------------------------
                                    434 	.area XABS    (ABS,XDATA)
                                    435 ;--------------------------------------------------------
                                    436 ; external initialized ram data
                                    437 ;--------------------------------------------------------
                                    438 	.area XISEG   (XDATA)
                                    439 	.area HOME    (CODE)
                                    440 	.area GSINIT0 (CODE)
                                    441 	.area GSINIT1 (CODE)
                                    442 	.area GSINIT2 (CODE)
                                    443 	.area GSINIT3 (CODE)
                                    444 	.area GSINIT4 (CODE)
                                    445 	.area GSINIT5 (CODE)
                                    446 	.area GSINIT  (CODE)
                                    447 	.area GSFINAL (CODE)
                                    448 	.area CSEG    (CODE)
                                    449 ;--------------------------------------------------------
                                    450 ; interrupt vector
                                    451 ;--------------------------------------------------------
                                    452 	.area HOME    (CODE)
      000000                        453 __interrupt_vect:
      000000 02 00 6B         [24]  454 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  455 	reti
      000004                        456 	.ds	7
      00000B 02 19 EB         [24]  457 	ljmp	_ISR_T0
      00000E                        458 	.ds	5
      000013 32               [24]  459 	reti
      000014                        460 	.ds	7
      00001B 32               [24]  461 	reti
      00001C                        462 	.ds	7
      000023 32               [24]  463 	reti
      000024                        464 	.ds	7
      00002B 02 04 8A         [24]  465 	ljmp	_ISR_ADC
      00002E                        466 	.ds	5
      000033 32               [24]  467 	reti
      000034                        468 	.ds	7
      00003B 02 08 98         [24]  469 	ljmp	_ISR_PCA
      00003E                        470 	.ds	5
      000043 32               [24]  471 	reti
      000044                        472 	.ds	7
      00004B 32               [24]  473 	reti
      00004C                        474 	.ds	7
      000053 32               [24]  475 	reti
      000054                        476 	.ds	7
      00005B 32               [24]  477 	reti
      00005C                        478 	.ds	7
      000063 02 05 EF         [24]  479 	ljmp	_ISR_T2
                                    480 ;--------------------------------------------------------
                                    481 ; global & static initialisations
                                    482 ;--------------------------------------------------------
                                    483 	.area HOME    (CODE)
                                    484 	.area GSINIT  (CODE)
                                    485 	.area GSFINAL (CODE)
                                    486 	.area GSINIT  (CODE)
                                    487 	.globl __sdcc_gsinit_startup
                                    488 	.globl __sdcc_program_startup
                                    489 	.globl __start__stack
                                    490 	.globl __mcs51_genXINIT
                                    491 	.globl __mcs51_genXRAMCLEAR
                                    492 	.globl __mcs51_genRAMCLEAR
                                    493 	.area GSFINAL (CODE)
      0000FE 02 00 66         [24]  494 	ljmp	__sdcc_program_startup
                                    495 ;--------------------------------------------------------
                                    496 ; Home
                                    497 ;--------------------------------------------------------
                                    498 	.area HOME    (CODE)
                                    499 	.area HOME    (CODE)
      000066                        500 __sdcc_program_startup:
      000066 02 01 01         [24]  501 	ljmp	_main
                                    502 ;	return from main will return to caller
                                    503 ;--------------------------------------------------------
                                    504 ; code
                                    505 ;--------------------------------------------------------
                                    506 	.area CSEG    (CODE)
                                    507 ;------------------------------------------------------------
                                    508 ;Allocation info for local variables in function 'main'
                                    509 ;------------------------------------------------------------
                                    510 ;fsm_curstate              Allocated to registers r7 
                                    511 ;fsm_fp                    Allocated to registers r5 r6 
                                    512 ;fsm_runstate              Allocated with name '_main_fsm_runstate_65536_175'
                                    513 ;__1310720024              Allocated to registers 
                                    514 ;index                     Allocated to registers 
                                    515 ;__1310720042              Allocated to registers 
                                    516 ;cs                        Allocated to registers 
                                    517 ;ticks_now                 Allocated with name '_main_ticks_now_262144_204'
                                    518 ;__1966080045              Allocated to registers 
                                    519 ;cs                        Allocated to registers 
                                    520 ;ticks_now                 Allocated with name '_main_ticks_now_327680_210'
                                    521 ;------------------------------------------------------------
                                    522 ;	src/main.c:16: void main(void)
                                    523 ;	-----------------------------------------
                                    524 ;	 function main
                                    525 ;	-----------------------------------------
      000101                        526 _main:
                           000007   527 	ar7 = 0x07
                           000006   528 	ar6 = 0x06
                           000005   529 	ar5 = 0x05
                           000004   530 	ar4 = 0x04
                           000003   531 	ar3 = 0x03
                           000002   532 	ar2 = 0x02
                           000001   533 	ar1 = 0x01
                           000000   534 	ar0 = 0x00
                                    535 ;	src/main.c:19: enum fsm_states_highlevel fsm_curstate = fsm_home;
      000101 7F 00            [12]  536 	mov	r7,#0x00
                                    537 ;	src/main.c:20: enum fsm_return (*fsm_fp)(void) = fsm_home_fn;
      000103 7D 0D            [12]  538 	mov	r5,#_fsm_home_fn
      000105 7E 0C            [12]  539 	mov	r6,#(_fsm_home_fn >> 8)
                                    540 ;	include/alarm.h:167: INT_IE2 &= 0xfb;	//TMR2 Interrupt disabled
      000107 53 AF FB         [24]  541 	anl	_INT_IE2,#0xfb
                                    542 ;	include/alarm.h:168: AUXR &= 0xe2;		//TMR2: 12T, STOP, TIMER, NOT BAUD GENERATOR
      00010A 53 8E E2         [24]  543 	anl	_AUXR,#0xe2
                                    544 ;	include/alarm.h:169: TMR_T2 = 0x102a;	//TMR2 Starts from 0x0fd7, overflow rate at 12T is ~30Hz
      00010D 75 D7 2A         [24]  545 	mov	((_TMR_T2 >> 0) & 0xFF),#0x2a
      000110 75 D6 10         [24]  546 	mov	((_TMR_T2 >> 8) & 0xFF),#0x10
                                    547 ;	include/alarm.h:170: AUXR |= 0x10;		//TMR2: RUN
      000113 43 8E 10         [24]  548 	orl	_AUXR,#0x10
                                    549 ;	src/main.c:26: ALARM_BUZZER = 0;
                                    550 ;	assignBit
      000116 C2 95            [12]  551 	clr	_PORT_P1_5
                                    552 ;	include/adc.h:44: | (0x01 << ADC_THERMISTOR_PIN));		//Set both thermistor and LDR input pins as High-Z
      000118 43 91 C0         [24]  553 	orl	_PORT_P1M1,#0xc0
                                    554 ;	include/adc.h:46: | (0x01 << ADC_THERMISTOR_PIN));		//Set both thermistor and LDR input pins as ADC input pins, block digital functions
      00011B 43 9D C0         [24]  555 	orl	_ADC_P1ASF,#0xc0
                                    556 ;	include/adc.h:47: ADC_CONTR = 0x80;		//Turn on the ADC power and set the ADC speed to min
      00011E 75 BC 80         [24]  557 	mov	_ADC_CONTR,#0x80
                                    558 ;	include/adc.h:48: PCON2	  |= 0x20;		//Sets up the ADC to return a right justified result
      000121 43 97 20         [24]  559 	orl	_PCON2,#0x20
                                    560 ;	include/adc.h:49: ADC_RES = 0x0000;		//Clear the ADC result
      000124 E4               [12]  561 	clr	a
      000125 F5 BE            [12]  562 	mov	((_ADC_RES >> 0) & 0xFF),a
      000127 F5 BD            [12]  563 	mov	((_ADC_RES >> 8) & 0xFF),a
                                    564 ;	include/adc.h:50: INT_IE_EADC = 1;		//Enable ADC interrupt
                                    565 ;	assignBit
      000129 D2 AD            [12]  566 	setb	_INT_IE_EADC
                                    567 ;	include/adc.h:60: __endasm; 					 //Wait for ADC power on
      00012B 00               [12]  568 	nop
      00012C 00               [12]  569 	nop
      00012D 00               [12]  570 	nop
      00012E 00               [12]  571 	nop
      00012F 00               [12]  572 	nop
      000130 00               [12]  573 	nop
      000131 00               [12]  574 	nop
      000132 00               [12]  575 	nop
                                    576 ;	include/adc.h:61: ADC_CONTR = ADC_SETUP_LDR;   //Write initial trigger source so that timer interrupt triggers another ADC conversion
      000133 75 BC E6         [24]  577 	mov	_ADC_CONTR,#0xe6
                                    578 ;	include/timer.h:26: TMR_TMOD = 0x00; //Set Timer 0 as 16-bit auto reload TC
      000136 75 89 00         [24]  579 	mov	_TMR_TMOD,#0x00
                                    580 ;	include/timer.h:27: TMR_T0 = 0xb800; //Set Initial value for Timer 0 auto reload
      000139 75 8A 00         [24]  581 	mov	((_TMR_T0 >> 0) & 0xFF),#0x00
      00013C 75 8C B8         [24]  582 	mov	((_TMR_T0 >> 8) & 0xFF),#0xb8
                                    583 ;	include/timer.h:28: TMR_TCON = 0x00; //Reset timer TCON
      00013F 75 88 00         [24]  584 	mov	_TMR_TCON,#0x00
                                    585 ;	include/timer.h:29: AUXR &= 0b01111111; //Set Timer 0 to count up once every 12 ticks
      000142 53 8E 7F         [24]  586 	anl	_AUXR,#0x7f
                                    587 ;	include/timer.h:30: INT_IE_ET0 = 1;  //Enable timer 0 interrupt
                                    588 ;	assignBit
      000145 D2 A9            [12]  589 	setb	_INT_IE_ET0
                                    590 ;	include/timer.h:31: TMR_TCON_TR0 = 1;//Run timer 0 and start 100Hz ticks
                                    591 ;	assignBit
      000147 D2 8C            [12]  592 	setb	_TMR_TCON_TR0
                                    593 ;	include/board_config.h:65: PORT_P2M1 = 0xff; //Configure display port for open-drain operation mode
      000149 75 95 FF         [24]  594 	mov	_PORT_P2M1,#0xff
                                    595 ;	include/board_config.h:66: PORT_P2M0 = 0xff; //Set the mode register 0 first to transition through high-z mode instead of push-pull mode
      00014C 75 96 FF         [24]  596 	mov	_PORT_P2M0,#0xff
                                    597 ;	include/display.h:78: PCA_CMOD = 0x09; //Run at SysClk, enable overflow interrupt.
      00014F 75 D9 09         [24]  598 	mov	_PCA_CMOD,#0x09
                                    599 ;	include/display.h:79: PCA_CCON = 0x00; //Reset the interrupt bits for the PCA
                                    600 ;	include/display.h:80: PCA_C = 0x0000;  //Reset PCA
      000152 E4               [12]  601 	clr	a
      000153 F5 D8            [12]  602 	mov	_PCA_CCON,a
      000155 F5 E9            [12]  603 	mov	((_PCA_C >> 0) & 0xFF),a
      000157 F5 F9            [12]  604 	mov	((_PCA_C >> 8) & 0xFF),a
                                    605 ;	include/display.h:81: PCA_CCAP0 = display_counts; //Set module 0 compare register
      000159 85 48 EA         [24]  606 	mov	((_PCA_CCAP0 >> 0) & 0xFF),_display_counts
      00015C 85 49 FA         [24]  607 	mov	((_PCA_CCAP0 >> 8) & 0xFF),(_display_counts + 1)
                                    608 ;	include/display.h:82: PCA_CCAPM0 = 0x49;  //Set module 0 compare mode - software timer
      00015F 75 DA 49         [24]  609 	mov	_PCA_CCAPM0,#0x49
                                    610 ;	include/display.h:83: PCA_CR = 1;		 //Run PCA
                                    611 ;	assignBit
      000162 D2 DE            [12]  612 	setb	_PCA_CR
                                    613 ;	include/display.h:84: INT_IP_PPCA = 1; //Set PCA interrupt to be high priority
                                    614 ;	assignBit
      000164 D2 BF            [12]  615 	setb	_INT_IP_PPCA
                                    616 ;	include/display.h:85: INT_IE_EA = 1;	 //Enable global interrupts
                                    617 ;	assignBit
      000166 D2 AF            [12]  618 	setb	_INT_IE_EA
                                    619 ;	include/display.h:87: PORT_P2 = display_buffer[3];
      000168 85 45 A0         [24]  620 	mov	_PORT_P2,(_display_buffer + 0x0003)
                                    621 ;	include/board_config.h:46: PORT_P3 &= ~(0x04 << index);
      00016B 53 B0 DF         [24]  622 	anl	_PORT_P3,#0xdf
                                    623 ;	include/display.h:102: display_autobrightness = 1; //Enable display automatic brightness adjust
                                    624 ;	assignBit
      00016E D2 1F            [12]  625 	setb	_display_autobrightness
                                    626 ;	include/button.h:58: BUTTON_MENU_STATE = 0x00;	//Reset menu button state tracker
      000170 75 3E 00         [24]  627 	mov	_BUTTON_MENU_STATE,#0x00
                                    628 ;	include/button.h:59: BUTTON_SELECT_STATE = 0x00; //Reset select button state tracker
      000173 75 3F 00         [24]  629 	mov	_BUTTON_SELECT_STATE,#0x00
                                    630 ;	include/button.h:60: BUTTON_DATA = 0x00;			//Reset button data state
      000176 75 22 00         [24]  631 	mov	_BUTTON_DATA,#0x00
                                    632 ;	include/button.h:61: BUTTON_MENU_CNT = 0x00;		//Reset menu counter
      000179 75 40 00         [24]  633 	mov	_BUTTON_MENU_CNT,#0x00
                                    634 ;	include/button.h:62: BUTTON_SELECT_CNT = 0x00;	//Reset select counter
      00017C 75 41 00         [24]  635 	mov	_BUTTON_SELECT_CNT,#0x00
                                    636 ;	include/timer.h:19: INT_IE_ET0 = 0; //Disable timer interrupt
                                    637 ;	assignBit
      00017F C2 A9            [12]  638 	clr	_INT_IE_ET0
                                    639 ;	include/timer.h:20: ticks_now = ticks_10ms;
      000181 85 5E 25         [24]  640 	mov	_main_ticks_now_262144_204,_ticks_10ms
      000184 85 5F 26         [24]  641 	mov	(_main_ticks_now_262144_204 + 1),(_ticks_10ms + 1)
                                    642 ;	include/timer.h:21: INT_IE_ET0 = 1; //Enable timer interrupt
                                    643 ;	assignBit
      000187 D2 A9            [12]  644 	setb	_INT_IE_ET0
                                    645 ;	include/timer.h:22: while((ticks_10ms - ticks_now) < cs); //Wait
      000189                        646 00116$:
      000189 E5 5E            [12]  647 	mov	a,_ticks_10ms
      00018B C3               [12]  648 	clr	c
      00018C 95 25            [12]  649 	subb	a,_main_ticks_now_262144_204
      00018E FA               [12]  650 	mov	r2,a
      00018F E5 5F            [12]  651 	mov	a,(_ticks_10ms + 1)
      000191 95 26            [12]  652 	subb	a,(_main_ticks_now_262144_204 + 1)
      000193 FC               [12]  653 	mov	r4,a
      000194 C3               [12]  654 	clr	c
      000195 EA               [12]  655 	mov	a,r2
      000196 94 C8            [12]  656 	subb	a,#0xc8
      000198 EC               [12]  657 	mov	a,r4
      000199 94 00            [12]  658 	subb	a,#0x00
      00019B 40 EC            [24]  659 	jc	00116$
                                    660 ;	src/main.c:36: ALARM_BUZZER = 1;
                                    661 ;	assignBit
      00019D D2 95            [12]  662 	setb	_PORT_P1_5
                                    663 ;	include/ds1302.h:76: PORT_P1   &= 0xf8;
      00019F 53 90 F8         [24]  664 	anl	_PORT_P1,#0xf8
                                    665 ;	include/ds1302.h:78: PORT_P1M1 |= 0x02;	//Set high-z first before set to open drain
      0001A2 43 91 02         [24]  666 	orl	_PORT_P1M1,#0x02
                                    667 ;	include/ds1302.h:79: PORT_P1M0 |= 0x07;
      0001A5 43 92 07         [24]  668 	orl	_PORT_P1M0,#0x07
                                    669 ;	src/main.c:39: ds1302_reset();
      0001A8 C0 07            [24]  670 	push	ar7
      0001AA C0 06            [24]  671 	push	ar6
      0001AC C0 05            [24]  672 	push	ar5
      0001AE 12 09 08         [24]  673 	lcall	_ds1302_reset
                                    674 ;	src/main.c:40: ds1302_read_SRAM();
      0001B1 12 0A B1         [24]  675 	lcall	_ds1302_read_SRAM
                                    676 ;	src/main.c:41: if(!ds1302_check_SRAM() ||
      0001B4 12 0A F9         [24]  677 	lcall	_ds1302_check_SRAM
      0001B7 E5 82            [12]  678 	mov	a,dpl
      0001B9 D0 05            [24]  679 	pop	ar5
      0001BB D0 06            [24]  680 	pop	ar6
      0001BD D0 07            [24]  681 	pop	ar7
      0001BF 60 28            [24]  682 	jz	00101$
                                    683 ;	src/main.c:42: ((button_read_and_clear_menu() == BUTTON_HELD_DOWN)
      0001C1 C0 07            [24]  684 	push	ar7
      0001C3 C0 06            [24]  685 	push	ar6
      0001C5 C0 05            [24]  686 	push	ar5
      0001C7 12 06 6C         [24]  687 	lcall	_button_read_and_clear_menu
      0001CA AC 82            [24]  688 	mov	r4,dpl
      0001CC D0 05            [24]  689 	pop	ar5
      0001CE D0 06            [24]  690 	pop	ar6
      0001D0 D0 07            [24]  691 	pop	ar7
      0001D2 BC 02 23         [24]  692 	cjne	r4,#0x02,00102$
                                    693 ;	src/main.c:43: && (button_read_and_clear_select() == BUTTON_HELD_DOWN)))
      0001D5 C0 07            [24]  694 	push	ar7
      0001D7 C0 06            [24]  695 	push	ar6
      0001D9 C0 05            [24]  696 	push	ar5
      0001DB 12 06 40         [24]  697 	lcall	_button_read_and_clear_select
      0001DE AC 82            [24]  698 	mov	r4,dpl
      0001E0 D0 05            [24]  699 	pop	ar5
      0001E2 D0 06            [24]  700 	pop	ar6
      0001E4 D0 07            [24]  701 	pop	ar7
      0001E6 BC 02 0F         [24]  702 	cjne	r4,#0x02,00102$
      0001E9                        703 00101$:
                                    704 ;	src/main.c:44: ds1302_power_loss_reset();
      0001E9 C0 07            [24]  705 	push	ar7
      0001EB C0 06            [24]  706 	push	ar6
      0001ED C0 05            [24]  707 	push	ar5
      0001EF 12 0B 53         [24]  708 	lcall	_ds1302_power_loss_reset
      0001F2 D0 05            [24]  709 	pop	ar5
      0001F4 D0 06            [24]  710 	pop	ar6
      0001F6 D0 07            [24]  711 	pop	ar7
      0001F8                        712 00102$:
                                    713 ;	src/main.c:46: display_autobrightness = 1;
                                    714 ;	assignBit
      0001F8 D2 1F            [12]  715 	setb	_display_autobrightness
                                    716 ;	src/main.c:47: fsm_home_auto = 0;
                                    717 ;	assignBit
      0001FA C2 1E            [12]  718 	clr	_fsm_home_auto
                                    719 ;	src/main.c:49: while(1){
      0001FC                        720 00106$:
                                    721 ;	src/main.c:50: fsm_runstate = fsm_fp();
      0001FC C0 07            [24]  722 	push	ar7
      0001FE C0 06            [24]  723 	push	ar6
      000200 C0 05            [24]  724 	push	ar5
      000202 8D 82            [24]  725 	mov	dpl,r5
      000204 8E 83            [24]  726 	mov	dph,r6
      000206 12 00 69         [24]  727 	lcall	__sdcc_call_dptr
      000209 85 82 24         [24]  728 	mov	_main_fsm_runstate_65536_175,dpl
      00020C D0 05            [24]  729 	pop	ar5
      00020E D0 06            [24]  730 	pop	ar6
      000210 D0 07            [24]  731 	pop	ar7
                                    732 ;	src/main.c:51: fsm_fp = fsm_transition_table_fp[fsm_curstate][fsm_runstate];
      000212 EF               [12]  733 	mov	a,r7
      000213 75 F0 06         [24]  734 	mov	b,#0x06
      000216 A4               [48]  735 	mul	ab
      000217 24 00            [12]  736 	add	a,#_fsm_transition_table_fp
      000219 FA               [12]  737 	mov	r2,a
      00021A 74 33            [12]  738 	mov	a,#(_fsm_transition_table_fp >> 8)
      00021C 35 F0            [12]  739 	addc	a,b
      00021E FB               [12]  740 	mov	r3,a
      00021F E5 24            [12]  741 	mov	a,_main_fsm_runstate_65536_175
      000221 25 24            [12]  742 	add	a,_main_fsm_runstate_65536_175
      000223 2A               [12]  743 	add	a,r2
      000224 F5 82            [12]  744 	mov	dpl,a
      000226 E4               [12]  745 	clr	a
      000227 3B               [12]  746 	addc	a,r3
      000228 F5 83            [12]  747 	mov	dph,a
      00022A E4               [12]  748 	clr	a
      00022B 93               [24]  749 	movc	a,@a+dptr
      00022C FD               [12]  750 	mov	r5,a
      00022D A3               [24]  751 	inc	dptr
      00022E E4               [12]  752 	clr	a
      00022F 93               [24]  753 	movc	a,@a+dptr
      000230 FE               [12]  754 	mov	r6,a
                                    755 ;	src/main.c:52: fsm_curstate = fsm_transition_table_s[fsm_curstate][fsm_runstate];
      000231 EF               [12]  756 	mov	a,r7
      000232 75 F0 03         [24]  757 	mov	b,#0x03
      000235 A4               [48]  758 	mul	ab
      000236 24 18            [12]  759 	add	a,#_fsm_transition_table_s
      000238 FB               [12]  760 	mov	r3,a
      000239 74 33            [12]  761 	mov	a,#(_fsm_transition_table_s >> 8)
      00023B 35 F0            [12]  762 	addc	a,b
      00023D FC               [12]  763 	mov	r4,a
      00023E E5 24            [12]  764 	mov	a,_main_fsm_runstate_65536_175
      000240 2B               [12]  765 	add	a,r3
      000241 F5 82            [12]  766 	mov	dpl,a
      000243 E4               [12]  767 	clr	a
      000244 3C               [12]  768 	addc	a,r4
      000245 F5 83            [12]  769 	mov	dph,a
      000247 E4               [12]  770 	clr	a
      000248 93               [24]  771 	movc	a,@a+dptr
      000249 FF               [12]  772 	mov	r7,a
                                    773 ;	include/timer.h:19: INT_IE_ET0 = 0; //Disable timer interrupt
                                    774 ;	assignBit
      00024A C2 A9            [12]  775 	clr	_INT_IE_ET0
                                    776 ;	include/timer.h:20: ticks_now = ticks_10ms;
      00024C 85 5E 27         [24]  777 	mov	_main_ticks_now_327680_210,_ticks_10ms
      00024F 85 5F 28         [24]  778 	mov	(_main_ticks_now_327680_210 + 1),(_ticks_10ms + 1)
                                    779 ;	include/timer.h:21: INT_IE_ET0 = 1; //Enable timer interrupt
                                    780 ;	assignBit
      000252 D2 A9            [12]  781 	setb	_INT_IE_ET0
                                    782 ;	include/timer.h:22: while((ticks_10ms - ticks_now) < cs); //Wait
      000254                        783 00121$:
      000254 E5 5E            [12]  784 	mov	a,_ticks_10ms
      000256 C3               [12]  785 	clr	c
      000257 95 27            [12]  786 	subb	a,_main_ticks_now_327680_210
      000259 FA               [12]  787 	mov	r2,a
      00025A E5 5F            [12]  788 	mov	a,(_ticks_10ms + 1)
      00025C 95 28            [12]  789 	subb	a,(_main_ticks_now_327680_210 + 1)
      00025E FC               [12]  790 	mov	r4,a
      00025F C3               [12]  791 	clr	c
      000260 EA               [12]  792 	mov	a,r2
      000261 94 0A            [12]  793 	subb	a,#0x0a
      000263 EC               [12]  794 	mov	a,r4
      000264 94 00            [12]  795 	subb	a,#0x00
      000266 40 EC            [24]  796 	jc	00121$
                                    797 ;	src/main.c:53: delay_centiseconds(10); 			//Delay 100ms, update state machine @ 10Hz
                                    798 ;	src/main.c:55: }
      000268 80 92            [24]  799 	sjmp	00106$
                                    800 	.area CSEG    (CODE)
                                    801 	.area CONST   (CODE)
                                    802 	.area XINIT   (CODE)
                                    803 	.area CABS    (ABS,CODE)
