                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module display
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _display_putbcd_PARM_2
                                     12 	.globl _ISR_PCA
                                     13 	.globl _convert_24h_to_12h
                                     14 	.globl _UART_SM0
                                     15 	.globl _UART_SM1
                                     16 	.globl _UART_SM2
                                     17 	.globl _UART_REN
                                     18 	.globl _UART_TB8
                                     19 	.globl _UART_RB8
                                     20 	.globl _UART_TI
                                     21 	.globl _UART_RI
                                     22 	.globl _PCA_CF
                                     23 	.globl _PCA_CR
                                     24 	.globl _PCA_CCF2
                                     25 	.globl _PCA_CCF1
                                     26 	.globl _PCA_CCF0
                                     27 	.globl _TMR_TCON_TF1
                                     28 	.globl _TMR_TCON_TR1
                                     29 	.globl _TMR_TCON_TF0
                                     30 	.globl _TMR_TCON_TR0
                                     31 	.globl _TMR_TCON_IE1
                                     32 	.globl _TMR_TCON_IT1
                                     33 	.globl _TMR_TCON_IE0
                                     34 	.globl _TMR_TCON_IT0
                                     35 	.globl _INT_IP_PPCA
                                     36 	.globl _INT_IP_PLVD
                                     37 	.globl _INT_IP_PADC
                                     38 	.globl _INT_IP_PS
                                     39 	.globl _INT_IP_PT1
                                     40 	.globl _INT_IP_PX1
                                     41 	.globl _INT_IP_PT0
                                     42 	.globl _INT_IP_PX0
                                     43 	.globl _INT_IE_EA
                                     44 	.globl _INT_IE_ELVD
                                     45 	.globl _INT_IE_EADC
                                     46 	.globl _INT_IE_ES
                                     47 	.globl _INT_IE_ET1
                                     48 	.globl _INT_IE_EX1
                                     49 	.globl _INT_IE_ET0
                                     50 	.globl _INT_IE_EX0
                                     51 	.globl _PORT_P5_7
                                     52 	.globl _PORT_P5_6
                                     53 	.globl _PORT_P5_5
                                     54 	.globl _PORT_P5_4
                                     55 	.globl _PORT_P5_3
                                     56 	.globl _PORT_P5_2
                                     57 	.globl _PORT_P5_1
                                     58 	.globl _PORT_P5_0
                                     59 	.globl _PORT_P4_7
                                     60 	.globl _PORT_P4_6
                                     61 	.globl _PORT_P4_5
                                     62 	.globl _PORT_P4_4
                                     63 	.globl _PORT_P4_3
                                     64 	.globl _PORT_P4_2
                                     65 	.globl _PORT_P4_1
                                     66 	.globl _PORT_P4_0
                                     67 	.globl _PORT_P3_7
                                     68 	.globl _PORT_P3_6
                                     69 	.globl _PORT_P3_5
                                     70 	.globl _PORT_P3_4
                                     71 	.globl _PORT_P3_3
                                     72 	.globl _PORT_P3_2
                                     73 	.globl _PORT_P3_1
                                     74 	.globl _PORT_P3_0
                                     75 	.globl _PORT_P2_7
                                     76 	.globl _PORT_P2_6
                                     77 	.globl _PORT_P2_5
                                     78 	.globl _PORT_P2_4
                                     79 	.globl _PORT_P2_3
                                     80 	.globl _PORT_P2_2
                                     81 	.globl _PORT_P2_1
                                     82 	.globl _PORT_P2_0
                                     83 	.globl _PORT_P1_7
                                     84 	.globl _PORT_P1_6
                                     85 	.globl _PORT_P1_5
                                     86 	.globl _PORT_P1_4
                                     87 	.globl _PORT_P1_3
                                     88 	.globl _PORT_P1_2
                                     89 	.globl _PORT_P1_1
                                     90 	.globl _PORT_P1_0
                                     91 	.globl _CY
                                     92 	.globl _AC
                                     93 	.globl _F0
                                     94 	.globl _RS1
                                     95 	.globl _RS0
                                     96 	.globl _OV
                                     97 	.globl _F1
                                     98 	.globl _P
                                     99 	.globl _IAP_CONTR
                                    100 	.globl _IAP_TRIG
                                    101 	.globl _IAP_CMD
                                    102 	.globl _IAP_ADDR
                                    103 	.globl _IAP_ADDRL
                                    104 	.globl _IAP_ADDRH
                                    105 	.globl _IAP_DATA
                                    106 	.globl _UART_SADEN
                                    107 	.globl _UART_SADDR
                                    108 	.globl _UART_SBUF
                                    109 	.globl _UART_SCON
                                    110 	.globl _PCA_CMOD
                                    111 	.globl _PCA_CCON
                                    112 	.globl _PCA_PWM2
                                    113 	.globl _PCA_PWM1
                                    114 	.globl _PCA_PWM0
                                    115 	.globl _PCA_C
                                    116 	.globl _PCA_CCAP2_L
                                    117 	.globl _PCA_CCAP2_H
                                    118 	.globl _PCA_CCAP1_L
                                    119 	.globl _PCA_CCAP1_H
                                    120 	.globl _PCA_CCAP0_L
                                    121 	.globl _PCA_CCAP0_H
                                    122 	.globl _PCA_CCAP2
                                    123 	.globl _PCA_CCAP1
                                    124 	.globl _PCA_CCAP0
                                    125 	.globl _PCA_CCAPM2
                                    126 	.globl _PCA_CCAPM1
                                    127 	.globl _PCA_CCAPM0
                                    128 	.globl _CMP_CR2
                                    129 	.globl _CMP_CR1
                                    130 	.globl _ADC_RESL
                                    131 	.globl _ADC_RESH
                                    132 	.globl _ADC_RES
                                    133 	.globl _ADC_CONTR
                                    134 	.globl _ADC_P1ASF
                                    135 	.globl _EEPROM_CONTR
                                    136 	.globl _EEPROM_TRIG
                                    137 	.globl _EEPROM_CMD
                                    138 	.globl _EEPROM_ADDR
                                    139 	.globl _EEPROM_DATA
                                    140 	.globl _TMR_T2
                                    141 	.globl _TMR_T0
                                    142 	.globl _TMR_TMOD
                                    143 	.globl _TMR_TCON
                                    144 	.globl _INT_IP2
                                    145 	.globl _INT_IP
                                    146 	.globl _INT_IE2
                                    147 	.globl _INT_IE
                                    148 	.globl _PORT_P5M0
                                    149 	.globl _PORT_P5M1
                                    150 	.globl _PORT_P4M0
                                    151 	.globl _PORT_P4M1
                                    152 	.globl _PORT_P3M0
                                    153 	.globl _PORT_P3M1
                                    154 	.globl _PORT_P2M0
                                    155 	.globl _PORT_P2M1
                                    156 	.globl _PORT_P1M0
                                    157 	.globl _PORT_P1M1
                                    158 	.globl _PORT_P5
                                    159 	.globl _PORT_P4
                                    160 	.globl _PORT_P3
                                    161 	.globl _PORT_P2
                                    162 	.globl _PORT_P1
                                    163 	.globl _PSW
                                    164 	.globl _PCON2
                                    165 	.globl _AUXR2
                                    166 	.globl _AUXR1
                                    167 	.globl _AUXR
                                    168 	.globl _PCON
                                    169 	.globl _DPTR
                                    170 	.globl _SP
                                    171 	.globl _display_autobrightness
                                    172 	.globl _DS1302_DATA_7
                                    173 	.globl _DS1302_DATA_6
                                    174 	.globl _DS1302_DATA_5
                                    175 	.globl _DS1302_DATA_4
                                    176 	.globl _DS1302_DATA_3
                                    177 	.globl _DS1302_DATA_2
                                    178 	.globl _DS1302_DATA_1
                                    179 	.globl _DS1302_DATA_0
                                    180 	.globl _display_puttime_PARM_2
                                    181 	.globl _display_counts
                                    182 	.globl _display_flash
                                    183 	.globl _display_index
                                    184 	.globl _display_buffer
                                    185 	.globl _DS1302_DATA
                                    186 	.globl _display_puts
                                    187 	.globl _display_putbcd
                                    188 	.globl _display_puttime
                                    189 	.globl _display_putdate
                                    190 	.globl _display_putbool
                                    191 	.globl _display_puttemp
                                    192 ;--------------------------------------------------------
                                    193 ; special function registers
                                    194 ;--------------------------------------------------------
                                    195 	.area RSEG    (ABS,DATA)
      000000                        196 	.org 0x0000
                           000081   197 _SP	=	0x0081
                           008382   198 _DPTR	=	0x8382
                           000087   199 _PCON	=	0x0087
                           00008E   200 _AUXR	=	0x008e
                           0000A2   201 _AUXR1	=	0x00a2
                           00008F   202 _AUXR2	=	0x008f
                           000097   203 _PCON2	=	0x0097
                           0000D0   204 _PSW	=	0x00d0
                           000090   205 _PORT_P1	=	0x0090
                           0000A0   206 _PORT_P2	=	0x00a0
                           0000B0   207 _PORT_P3	=	0x00b0
                           0000C0   208 _PORT_P4	=	0x00c0
                           0000C8   209 _PORT_P5	=	0x00c8
                           000091   210 _PORT_P1M1	=	0x0091
                           000092   211 _PORT_P1M0	=	0x0092
                           000095   212 _PORT_P2M1	=	0x0095
                           000096   213 _PORT_P2M0	=	0x0096
                           0000B1   214 _PORT_P3M1	=	0x00b1
                           0000B2   215 _PORT_P3M0	=	0x00b2
                           0000B3   216 _PORT_P4M1	=	0x00b3
                           0000B4   217 _PORT_P4M0	=	0x00b4
                           0000C9   218 _PORT_P5M1	=	0x00c9
                           0000CA   219 _PORT_P5M0	=	0x00ca
                           0000A8   220 _INT_IE	=	0x00a8
                           0000AF   221 _INT_IE2	=	0x00af
                           0000B8   222 _INT_IP	=	0x00b8
                           0000B5   223 _INT_IP2	=	0x00b5
                           000088   224 _TMR_TCON	=	0x0088
                           000089   225 _TMR_TMOD	=	0x0089
                           008C8A   226 _TMR_T0	=	0x8c8a
                           00D6D7   227 _TMR_T2	=	0xd6d7
                           0000C2   228 _EEPROM_DATA	=	0x00c2
                           00C3C4   229 _EEPROM_ADDR	=	0xc3c4
                           0000C5   230 _EEPROM_CMD	=	0x00c5
                           0000C6   231 _EEPROM_TRIG	=	0x00c6
                           0000C7   232 _EEPROM_CONTR	=	0x00c7
                           00009D   233 _ADC_P1ASF	=	0x009d
                           0000BC   234 _ADC_CONTR	=	0x00bc
                           00BDBE   235 _ADC_RES	=	0xbdbe
                           0000BD   236 _ADC_RESH	=	0x00bd
                           0000BE   237 _ADC_RESL	=	0x00be
                           0000E6   238 _CMP_CR1	=	0x00e6
                           0000E7   239 _CMP_CR2	=	0x00e7
                           0000DA   240 _PCA_CCAPM0	=	0x00da
                           0000DB   241 _PCA_CCAPM1	=	0x00db
                           0000DC   242 _PCA_CCAPM2	=	0x00dc
                           00FAEA   243 _PCA_CCAP0	=	0xfaea
                           00FBEB   244 _PCA_CCAP1	=	0xfbeb
                           00FCEC   245 _PCA_CCAP2	=	0xfcec
                           0000FA   246 _PCA_CCAP0_H	=	0x00fa
                           0000EA   247 _PCA_CCAP0_L	=	0x00ea
                           0000FB   248 _PCA_CCAP1_H	=	0x00fb
                           0000EB   249 _PCA_CCAP1_L	=	0x00eb
                           0000FC   250 _PCA_CCAP2_H	=	0x00fc
                           0000EC   251 _PCA_CCAP2_L	=	0x00ec
                           00F9E9   252 _PCA_C	=	0xf9e9
                           0000F2   253 _PCA_PWM0	=	0x00f2
                           0000F3   254 _PCA_PWM1	=	0x00f3
                           0000F4   255 _PCA_PWM2	=	0x00f4
                           0000D8   256 _PCA_CCON	=	0x00d8
                           0000D9   257 _PCA_CMOD	=	0x00d9
                           000098   258 _UART_SCON	=	0x0098
                           000099   259 _UART_SBUF	=	0x0099
                           0000A9   260 _UART_SADDR	=	0x00a9
                           0000B9   261 _UART_SADEN	=	0x00b9
                           0000C2   262 _IAP_DATA	=	0x00c2
                           0000C3   263 _IAP_ADDRH	=	0x00c3
                           0000C4   264 _IAP_ADDRL	=	0x00c4
                           00C3C4   265 _IAP_ADDR	=	0xc3c4
                           0000C5   266 _IAP_CMD	=	0x00c5
                           0000C6   267 _IAP_TRIG	=	0x00c6
                           0000C7   268 _IAP_CONTR	=	0x00c7
                                    269 ;--------------------------------------------------------
                                    270 ; special function bits
                                    271 ;--------------------------------------------------------
                                    272 	.area RSEG    (ABS,DATA)
      000000                        273 	.org 0x0000
                           0000D0   274 _P	=	0x00d0
                           0000D1   275 _F1	=	0x00d1
                           0000D2   276 _OV	=	0x00d2
                           0000D3   277 _RS0	=	0x00d3
                           0000D4   278 _RS1	=	0x00d4
                           0000D5   279 _F0	=	0x00d5
                           0000D6   280 _AC	=	0x00d6
                           0000D7   281 _CY	=	0x00d7
                           000090   282 _PORT_P1_0	=	0x0090
                           000091   283 _PORT_P1_1	=	0x0091
                           000092   284 _PORT_P1_2	=	0x0092
                           000093   285 _PORT_P1_3	=	0x0093
                           000094   286 _PORT_P1_4	=	0x0094
                           000095   287 _PORT_P1_5	=	0x0095
                           000096   288 _PORT_P1_6	=	0x0096
                           000097   289 _PORT_P1_7	=	0x0097
                           0000A0   290 _PORT_P2_0	=	0x00a0
                           0000A1   291 _PORT_P2_1	=	0x00a1
                           0000A2   292 _PORT_P2_2	=	0x00a2
                           0000A3   293 _PORT_P2_3	=	0x00a3
                           0000A4   294 _PORT_P2_4	=	0x00a4
                           0000A5   295 _PORT_P2_5	=	0x00a5
                           0000A6   296 _PORT_P2_6	=	0x00a6
                           0000A7   297 _PORT_P2_7	=	0x00a7
                           0000B0   298 _PORT_P3_0	=	0x00b0
                           0000B1   299 _PORT_P3_1	=	0x00b1
                           0000B2   300 _PORT_P3_2	=	0x00b2
                           0000B3   301 _PORT_P3_3	=	0x00b3
                           0000B4   302 _PORT_P3_4	=	0x00b4
                           0000B5   303 _PORT_P3_5	=	0x00b5
                           0000B6   304 _PORT_P3_6	=	0x00b6
                           0000B7   305 _PORT_P3_7	=	0x00b7
                           0000C0   306 _PORT_P4_0	=	0x00c0
                           0000C1   307 _PORT_P4_1	=	0x00c1
                           0000C2   308 _PORT_P4_2	=	0x00c2
                           0000C3   309 _PORT_P4_3	=	0x00c3
                           0000C4   310 _PORT_P4_4	=	0x00c4
                           0000C5   311 _PORT_P4_5	=	0x00c5
                           0000C6   312 _PORT_P4_6	=	0x00c6
                           0000C7   313 _PORT_P4_7	=	0x00c7
                           0000C8   314 _PORT_P5_0	=	0x00c8
                           0000C9   315 _PORT_P5_1	=	0x00c9
                           0000CA   316 _PORT_P5_2	=	0x00ca
                           0000CB   317 _PORT_P5_3	=	0x00cb
                           0000CC   318 _PORT_P5_4	=	0x00cc
                           0000CD   319 _PORT_P5_5	=	0x00cd
                           0000CE   320 _PORT_P5_6	=	0x00ce
                           0000CF   321 _PORT_P5_7	=	0x00cf
                           0000A8   322 _INT_IE_EX0	=	0x00a8
                           0000A9   323 _INT_IE_ET0	=	0x00a9
                           0000AA   324 _INT_IE_EX1	=	0x00aa
                           0000AB   325 _INT_IE_ET1	=	0x00ab
                           0000AC   326 _INT_IE_ES	=	0x00ac
                           0000AD   327 _INT_IE_EADC	=	0x00ad
                           0000AE   328 _INT_IE_ELVD	=	0x00ae
                           0000AF   329 _INT_IE_EA	=	0x00af
                           0000B8   330 _INT_IP_PX0	=	0x00b8
                           0000B9   331 _INT_IP_PT0	=	0x00b9
                           0000BA   332 _INT_IP_PX1	=	0x00ba
                           0000BB   333 _INT_IP_PT1	=	0x00bb
                           0000BC   334 _INT_IP_PS	=	0x00bc
                           0000BD   335 _INT_IP_PADC	=	0x00bd
                           0000BE   336 _INT_IP_PLVD	=	0x00be
                           0000BF   337 _INT_IP_PPCA	=	0x00bf
                           000088   338 _TMR_TCON_IT0	=	0x0088
                           000089   339 _TMR_TCON_IE0	=	0x0089
                           00008A   340 _TMR_TCON_IT1	=	0x008a
                           00008B   341 _TMR_TCON_IE1	=	0x008b
                           00008C   342 _TMR_TCON_TR0	=	0x008c
                           00008D   343 _TMR_TCON_TF0	=	0x008d
                           00008E   344 _TMR_TCON_TR1	=	0x008e
                           00008F   345 _TMR_TCON_TF1	=	0x008f
                           0000D8   346 _PCA_CCF0	=	0x00d8
                           0000D9   347 _PCA_CCF1	=	0x00d9
                           0000DA   348 _PCA_CCF2	=	0x00da
                           0000DE   349 _PCA_CR	=	0x00de
                           0000DF   350 _PCA_CF	=	0x00df
                           000098   351 _UART_RI	=	0x0098
                           000099   352 _UART_TI	=	0x0099
                           00009A   353 _UART_RB8	=	0x009a
                           00009B   354 _UART_TB8	=	0x009b
                           00009C   355 _UART_REN	=	0x009c
                           00009D   356 _UART_SM2	=	0x009d
                           00009E   357 _UART_SM1	=	0x009e
                           00009F   358 _UART_SM0	=	0x009f
                                    359 ;--------------------------------------------------------
                                    360 ; overlayable register banks
                                    361 ;--------------------------------------------------------
                                    362 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        363 	.ds 8
                                    364 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        365 	.ds 8
                                    366 ;--------------------------------------------------------
                                    367 ; internal ram data
                                    368 ;--------------------------------------------------------
                                    369 	.area DSEG    (DATA)
                           000021   370 _DS1302_DATA	=	0x0021
      000042                        371 _display_buffer::
      000042                        372 	.ds 4
      000046                        373 _display_index::
      000046                        374 	.ds 1
      000047                        375 _display_flash::
      000047                        376 	.ds 1
      000048                        377 _display_counts::
      000048                        378 	.ds 2
      00004A                        379 _display_puttime_PARM_2:
      00004A                        380 	.ds 1
      00004B                        381 _ISR_PCA_flash_prescaler_65536_154:
      00004B                        382 	.ds 1
                                    383 ;--------------------------------------------------------
                                    384 ; overlayable items in internal ram
                                    385 ;--------------------------------------------------------
                                    386 	.area	OSEG    (OVR,DATA)
                                    387 	.area	OSEG    (OVR,DATA)
      000060                        388 _display_putbcd_PARM_2:
      000060                        389 	.ds 1
                                    390 	.area	OSEG    (OVR,DATA)
                                    391 	.area	OSEG    (OVR,DATA)
                                    392 ;--------------------------------------------------------
                                    393 ; indirectly addressable internal ram data
                                    394 ;--------------------------------------------------------
                                    395 	.area ISEG    (DATA)
                                    396 ;--------------------------------------------------------
                                    397 ; absolute internal ram data
                                    398 ;--------------------------------------------------------
                                    399 	.area IABS    (ABS,DATA)
                                    400 	.area IABS    (ABS,DATA)
                                    401 ;--------------------------------------------------------
                                    402 ; bit data
                                    403 ;--------------------------------------------------------
                                    404 	.area BSEG    (BIT)
                           000008   405 _DS1302_DATA_0	=	0x0008
                           000009   406 _DS1302_DATA_1	=	0x0009
                           00000A   407 _DS1302_DATA_2	=	0x000a
                           00000B   408 _DS1302_DATA_3	=	0x000b
                           00000C   409 _DS1302_DATA_4	=	0x000c
                           00000D   410 _DS1302_DATA_5	=	0x000d
                           00000E   411 _DS1302_DATA_6	=	0x000e
                           00000F   412 _DS1302_DATA_7	=	0x000f
                           00001F   413 _display_autobrightness	=	0x001f
                                    414 ;--------------------------------------------------------
                                    415 ; paged external ram data
                                    416 ;--------------------------------------------------------
                                    417 	.area PSEG    (PAG,XDATA)
                                    418 ;--------------------------------------------------------
                                    419 ; external ram data
                                    420 ;--------------------------------------------------------
                                    421 	.area XSEG    (XDATA)
                                    422 ;--------------------------------------------------------
                                    423 ; absolute external ram data
                                    424 ;--------------------------------------------------------
                                    425 	.area XABS    (ABS,XDATA)
                                    426 ;--------------------------------------------------------
                                    427 ; external initialized ram data
                                    428 ;--------------------------------------------------------
                                    429 	.area XISEG   (XDATA)
                                    430 	.area HOME    (CODE)
                                    431 	.area GSINIT0 (CODE)
                                    432 	.area GSINIT1 (CODE)
                                    433 	.area GSINIT2 (CODE)
                                    434 	.area GSINIT3 (CODE)
                                    435 	.area GSINIT4 (CODE)
                                    436 	.area GSINIT5 (CODE)
                                    437 	.area GSINIT  (CODE)
                                    438 	.area GSFINAL (CODE)
                                    439 	.area CSEG    (CODE)
                                    440 ;--------------------------------------------------------
                                    441 ; global & static initialisations
                                    442 ;--------------------------------------------------------
                                    443 	.area HOME    (CODE)
                                    444 	.area GSINIT  (CODE)
                                    445 	.area GSFINAL (CODE)
                                    446 	.area GSINIT  (CODE)
                                    447 ;------------------------------------------------------------
                                    448 ;Allocation info for local variables in function 'ISR_PCA'
                                    449 ;------------------------------------------------------------
                                    450 ;flash_prescaler           Allocated with name '_ISR_PCA_flash_prescaler_65536_154'
                                    451 ;__1966080031              Allocated to registers r7 
                                    452 ;index                     Allocated to registers 
                                    453 ;------------------------------------------------------------
                                    454 ;	src/display.c:80: static uint8_t flash_prescaler = 0x10;
      0000C7 75 4B 10         [24]  455 	mov	_ISR_PCA_flash_prescaler_65536_154,#0x10
                                    456 ;	src/display.c:12: volatile uint8_t display_buffer[4] = {0x00,0x00,0x00,0x00};
      0000CA 75 42 00         [24]  457 	mov	_display_buffer,#0x00
      0000CD 75 43 00         [24]  458 	mov	(_display_buffer + 0x0001),#0x00
      0000D0 75 44 00         [24]  459 	mov	(_display_buffer + 0x0002),#0x00
      0000D3 75 45 00         [24]  460 	mov	(_display_buffer + 0x0003),#0x00
                                    461 ;	src/display.c:13: volatile uint8_t display_index = 0x03;
      0000D6 75 46 03         [24]  462 	mov	_display_index,#0x03
                                    463 ;	src/display.c:14: volatile uint8_t display_flash = 0x00;
      0000D9 75 47 00         [24]  464 	mov	_display_flash,#0x00
                                    465 ;	src/display.c:15: volatile uint16_t display_counts = 0xff00;
      0000DC 75 48 00         [24]  466 	mov	_display_counts,#0x00
      0000DF 75 49 FF         [24]  467 	mov	(_display_counts + 1),#0xff
                                    468 ;--------------------------------------------------------
                                    469 ; Home
                                    470 ;--------------------------------------------------------
                                    471 	.area HOME    (CODE)
                                    472 	.area HOME    (CODE)
                                    473 ;--------------------------------------------------------
                                    474 ; code
                                    475 ;--------------------------------------------------------
                                    476 	.area CSEG    (CODE)
                                    477 ;------------------------------------------------------------
                                    478 ;Allocation info for local variables in function 'display_puts'
                                    479 ;------------------------------------------------------------
                                    480 ;s                         Allocated to registers r6 r7 
                                    481 ;------------------------------------------------------------
                                    482 ;	src/display.c:17: void display_puts(__code const char* s) {
                                    483 ;	-----------------------------------------
                                    484 ;	 function display_puts
                                    485 ;	-----------------------------------------
      0006F8                        486 _display_puts:
                           000007   487 	ar7 = 0x07
                           000006   488 	ar6 = 0x06
                           000005   489 	ar5 = 0x05
                           000004   490 	ar4 = 0x04
                           000003   491 	ar3 = 0x03
                           000002   492 	ar2 = 0x02
                           000001   493 	ar1 = 0x01
                           000000   494 	ar0 = 0x00
                                    495 ;	src/display.c:18: display_buffer[0] = ledfonts_numeric_normal[*s];
      0006F8 AE 82            [24]  496 	mov	r6,dpl
      0006FA AF 83            [24]  497 	mov  r7,dph
      0006FC E4               [12]  498 	clr	a
      0006FD 93               [24]  499 	movc	a,@a+dptr
      0006FE 90 30 00         [24]  500 	mov	dptr,#_ledfonts_numeric_normal
      000701 93               [24]  501 	movc	a,@a+dptr
      000702 FD               [12]  502 	mov	r5,a
      000703 8D 42            [24]  503 	mov	_display_buffer,r5
                                    504 ;	src/display.c:19: display_buffer[1] = ledfonts_numeric_normal[*(s+1)];
      000705 8E 82            [24]  505 	mov	dpl,r6
      000707 8F 83            [24]  506 	mov	dph,r7
      000709 A3               [24]  507 	inc	dptr
      00070A E4               [12]  508 	clr	a
      00070B 93               [24]  509 	movc	a,@a+dptr
      00070C 90 30 00         [24]  510 	mov	dptr,#_ledfonts_numeric_normal
      00070F 93               [24]  511 	movc	a,@a+dptr
      000710 FD               [12]  512 	mov	r5,a
      000711 8D 43            [24]  513 	mov	(_display_buffer + 0x0001),r5
                                    514 ;	src/display.c:20: display_buffer[2] = ledfonts_numeric_flipped[*(s+2)];
      000713 8E 82            [24]  515 	mov	dpl,r6
      000715 8F 83            [24]  516 	mov	dph,r7
      000717 A3               [24]  517 	inc	dptr
      000718 A3               [24]  518 	inc	dptr
      000719 E4               [12]  519 	clr	a
      00071A 93               [24]  520 	movc	a,@a+dptr
      00071B 90 30 80         [24]  521 	mov	dptr,#_ledfonts_numeric_flipped
      00071E 93               [24]  522 	movc	a,@a+dptr
      00071F FD               [12]  523 	mov	r5,a
      000720 8D 44            [24]  524 	mov	(_display_buffer + 0x0002),r5
                                    525 ;	src/display.c:21: display_buffer[3] = ledfonts_numeric_normal[*(s+3)];
      000722 8E 82            [24]  526 	mov	dpl,r6
      000724 8F 83            [24]  527 	mov	dph,r7
      000726 A3               [24]  528 	inc	dptr
      000727 A3               [24]  529 	inc	dptr
      000728 A3               [24]  530 	inc	dptr
      000729 E4               [12]  531 	clr	a
      00072A 93               [24]  532 	movc	a,@a+dptr
      00072B 90 30 00         [24]  533 	mov	dptr,#_ledfonts_numeric_normal
      00072E 93               [24]  534 	movc	a,@a+dptr
      00072F FF               [12]  535 	mov	r7,a
      000730 8F 45            [24]  536 	mov	(_display_buffer + 0x0003),r7
                                    537 ;	src/display.c:22: }
      000732 22               [24]  538 	ret
                                    539 ;------------------------------------------------------------
                                    540 ;Allocation info for local variables in function 'display_putbcd'
                                    541 ;------------------------------------------------------------
                                    542 ;v2                        Allocated with name '_display_putbcd_PARM_2'
                                    543 ;v1                        Allocated to registers r7 
                                    544 ;------------------------------------------------------------
                                    545 ;	src/display.c:24: void display_putbcd(uint8_t v1, uint8_t v2) {
                                    546 ;	-----------------------------------------
                                    547 ;	 function display_putbcd
                                    548 ;	-----------------------------------------
      000733                        549 _display_putbcd:
                                    550 ;	src/display.c:25: display_buffer[0] = ledfonts_numeric_normal[(v1 >> 0x04)];
      000733 E5 82            [12]  551 	mov	a,dpl
      000735 FF               [12]  552 	mov	r7,a
      000736 C4               [12]  553 	swap	a
      000737 54 0F            [12]  554 	anl	a,#0x0f
      000739 90 30 00         [24]  555 	mov	dptr,#_ledfonts_numeric_normal
      00073C 93               [24]  556 	movc	a,@a+dptr
      00073D FE               [12]  557 	mov	r6,a
      00073E 8E 42            [24]  558 	mov	_display_buffer,r6
                                    559 ;	src/display.c:26: display_buffer[1] = ledfonts_numeric_normal[(v1 & 0x0f)];
      000740 53 07 0F         [24]  560 	anl	ar7,#0x0f
      000743 7E 00            [12]  561 	mov	r6,#0x00
      000745 EF               [12]  562 	mov	a,r7
      000746 24 00            [12]  563 	add	a,#_ledfonts_numeric_normal
      000748 F5 82            [12]  564 	mov	dpl,a
      00074A EE               [12]  565 	mov	a,r6
      00074B 34 30            [12]  566 	addc	a,#(_ledfonts_numeric_normal >> 8)
      00074D F5 83            [12]  567 	mov	dph,a
      00074F E4               [12]  568 	clr	a
      000750 93               [24]  569 	movc	a,@a+dptr
      000751 FF               [12]  570 	mov	r7,a
      000752 8F 43            [24]  571 	mov	(_display_buffer + 0x0001),r7
                                    572 ;	src/display.c:27: display_buffer[2] = ledfonts_numeric_flipped[(v2 >> 0x04)];
      000754 E5 60            [12]  573 	mov	a,_display_putbcd_PARM_2
      000756 C4               [12]  574 	swap	a
      000757 54 0F            [12]  575 	anl	a,#0x0f
      000759 90 30 80         [24]  576 	mov	dptr,#_ledfonts_numeric_flipped
      00075C 93               [24]  577 	movc	a,@a+dptr
      00075D FF               [12]  578 	mov	r7,a
      00075E 8F 44            [24]  579 	mov	(_display_buffer + 0x0002),r7
                                    580 ;	src/display.c:28: display_buffer[3] = ledfonts_numeric_normal[(v2 & 0x0f)];
      000760 AE 60            [24]  581 	mov	r6,_display_putbcd_PARM_2
      000762 53 06 0F         [24]  582 	anl	ar6,#0x0f
      000765 7F 00            [12]  583 	mov	r7,#0x00
      000767 EE               [12]  584 	mov	a,r6
      000768 24 00            [12]  585 	add	a,#_ledfonts_numeric_normal
      00076A F5 82            [12]  586 	mov	dpl,a
      00076C EF               [12]  587 	mov	a,r7
      00076D 34 30            [12]  588 	addc	a,#(_ledfonts_numeric_normal >> 8)
      00076F F5 83            [12]  589 	mov	dph,a
      000771 E4               [12]  590 	clr	a
      000772 93               [24]  591 	movc	a,@a+dptr
      000773 FF               [12]  592 	mov	r7,a
      000774 8F 45            [24]  593 	mov	(_display_buffer + 0x0003),r7
                                    594 ;	src/display.c:29: }
      000776 22               [24]  595 	ret
                                    596 ;------------------------------------------------------------
                                    597 ;Allocation info for local variables in function 'display_puttime'
                                    598 ;------------------------------------------------------------
                                    599 ;minute                    Allocated with name '_display_puttime_PARM_2'
                                    600 ;hour                      Allocated to registers r7 
                                    601 ;------------------------------------------------------------
                                    602 ;	src/display.c:31: void display_puttime(uint8_t hour, uint8_t minute) {
                                    603 ;	-----------------------------------------
                                    604 ;	 function display_puttime
                                    605 ;	-----------------------------------------
      000777                        606 _display_puttime:
      000777 AF 82            [24]  607 	mov	r7,dpl
                                    608 ;	src/display.c:32: if(TIME_DISPLAY_12) {
      000779 90 00 03         [24]  609 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      00077C E0               [24]  610 	movx	a,@dptr
      00077D 23               [12]  611 	rl	a
      00077E 23               [12]  612 	rl	a
      00077F 54 01            [12]  613 	anl	a,#0x01
      000781 60 20            [24]  614 	jz	00104$
                                    615 ;	src/display.c:33: display_putbcd(convert_24h_to_12h(hour),minute);
      000783 8F 82            [24]  616 	mov	dpl,r7
      000785 C0 07            [24]  617 	push	ar7
      000787 12 0B 95         [24]  618 	lcall	_convert_24h_to_12h
      00078A D0 07            [24]  619 	pop	ar7
      00078C 85 4A 60         [24]  620 	mov	_display_putbcd_PARM_2,_display_puttime_PARM_2
      00078F C0 07            [24]  621 	push	ar7
      000791 12 07 33         [24]  622 	lcall	_display_putbcd
      000794 D0 07            [24]  623 	pop	ar7
                                    624 ;	src/display.c:34: if(hour > 0x11)
      000796 EF               [12]  625 	mov	a,r7
      000797 24 EE            [12]  626 	add	a,#0xff - 0x11
      000799 50 10            [24]  627 	jnc	00105$
                                    628 ;	include/display.h:175: display_buffer[3] &= 0x7f;
      00079B 74 7F            [12]  629 	mov	a,#0x7f
      00079D 55 45            [12]  630 	anl	a,(_display_buffer + 0x0003)
      00079F F5 45            [12]  631 	mov	(_display_buffer + 0x0003),a
                                    632 ;	src/display.c:35: display_ampmon();
      0007A1 80 08            [24]  633 	sjmp	00105$
      0007A3                        634 00104$:
                                    635 ;	src/display.c:37: display_putbcd(hour,minute);
      0007A3 85 4A 60         [24]  636 	mov	_display_putbcd_PARM_2,_display_puttime_PARM_2
      0007A6 8F 82            [24]  637 	mov	dpl,r7
      0007A8 12 07 33         [24]  638 	lcall	_display_putbcd
      0007AB                        639 00105$:
                                    640 ;	src/display.c:40: if(DISPLAY_REMOVE_LEADING_ZEROES &&
      0007AB 90 00 02         [24]  641 	mov	dptr,#(_ds1302_sram_data + 0x0002)
      0007AE E0               [24]  642 	movx	a,@dptr
      0007AF FF               [12]  643 	mov	r7,a
      0007B0 30 E0 11         [24]  644 	jnb	acc.0,00110$
                                    645 ;	src/display.c:41: (display_buffer[0] == ledfonts_numeric_normal['0']))
      0007B3 90 30 30         [24]  646 	mov	dptr,#(_ledfonts_numeric_normal + 0x0030)
      0007B6 E4               [12]  647 	clr	a
      0007B7 93               [24]  648 	movc	a,@a+dptr
      0007B8 FF               [12]  649 	mov	r7,a
      0007B9 B5 42 08         [24]  650 	cjne	a,_display_buffer,00110$
                                    651 ;	src/display.c:42: display_buffer[0] = ledfonts_numeric_normal[' '];
      0007BC 90 30 20         [24]  652 	mov	dptr,#(_ledfonts_numeric_normal + 0x0020)
      0007BF E4               [12]  653 	clr	a
      0007C0 93               [24]  654 	movc	a,@a+dptr
      0007C1 FF               [12]  655 	mov	r7,a
      0007C2 8F 42            [24]  656 	mov	_display_buffer,r7
      0007C4                        657 00110$:
                                    658 ;	src/display.c:43: }
      0007C4 22               [24]  659 	ret
                                    660 ;------------------------------------------------------------
                                    661 ;Allocation info for local variables in function 'display_putdate'
                                    662 ;------------------------------------------------------------
                                    663 ;	src/display.c:45: void display_putdate(void) {
                                    664 ;	-----------------------------------------
                                    665 ;	 function display_putdate
                                    666 ;	-----------------------------------------
      0007C5                        667 _display_putdate:
                                    668 ;	src/display.c:46: if(DATE_DISPLAY_MMDD)
      0007C5 90 00 03         [24]  669 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      0007C8 E0               [24]  670 	movx	a,@dptr
      0007C9 23               [12]  671 	rl	a
      0007CA 54 01            [12]  672 	anl	a,#0x01
      0007CC 60 0B            [24]  673 	jz	00102$
                                    674 ;	src/display.c:47: display_putbcd(ds1302.month,ds1302.date);
      0007CE 85 50 82         [24]  675 	mov	dpl,(_ds1302 + 0x0004)
      0007D1 85 4F 60         [24]  676 	mov	_display_putbcd_PARM_2,(_ds1302 + 0x0003)
      0007D4 12 07 33         [24]  677 	lcall	_display_putbcd
      0007D7 80 09            [24]  678 	sjmp	00103$
      0007D9                        679 00102$:
                                    680 ;	src/display.c:49: display_putbcd(ds1302.date,ds1302.month);
      0007D9 85 4F 82         [24]  681 	mov	dpl,(_ds1302 + 0x0003)
      0007DC 85 50 60         [24]  682 	mov	_display_putbcd_PARM_2,(_ds1302 + 0x0004)
      0007DF 12 07 33         [24]  683 	lcall	_display_putbcd
      0007E2                        684 00103$:
                                    685 ;	include/display.h:146: display_buffer[1] &= 0x7f;
      0007E2 74 7F            [12]  686 	mov	a,#0x7f
      0007E4 55 43            [12]  687 	anl	a,(_display_buffer + 0x0001)
      0007E6 F5 43            [12]  688 	mov	(_display_buffer + 0x0001),a
                                    689 ;	src/display.c:52: if(DISPLAY_REMOVE_LEADING_ZEROES){
      0007E8 90 00 02         [24]  690 	mov	dptr,#(_ds1302_sram_data + 0x0002)
      0007EB E0               [24]  691 	movx	a,@dptr
      0007EC FF               [12]  692 	mov	r7,a
      0007ED 30 E0 21         [24]  693 	jnb	acc.0,00111$
                                    694 ;	src/display.c:53: if(display_buffer[0] == ledfonts_numeric_normal['0'])
      0007F0 90 30 30         [24]  695 	mov	dptr,#(_ledfonts_numeric_normal + 0x0030)
      0007F3 E4               [12]  696 	clr	a
      0007F4 93               [24]  697 	movc	a,@a+dptr
      0007F5 B5 42 08         [24]  698 	cjne	a,_display_buffer,00105$
                                    699 ;	src/display.c:54: display_buffer[0] = ledfonts_numeric_normal[' '];
      0007F8 90 30 20         [24]  700 	mov	dptr,#(_ledfonts_numeric_normal + 0x0020)
      0007FB E4               [12]  701 	clr	a
      0007FC 93               [24]  702 	movc	a,@a+dptr
      0007FD FF               [12]  703 	mov	r7,a
      0007FE 8F 42            [24]  704 	mov	_display_buffer,r7
      000800                        705 00105$:
                                    706 ;	src/display.c:55: if(display_buffer[2] == ledfonts_numeric_flipped['0'])
      000800 90 30 B0         [24]  707 	mov	dptr,#(_ledfonts_numeric_flipped + 0x0030)
      000803 E4               [12]  708 	clr	a
      000804 93               [24]  709 	movc	a,@a+dptr
      000805 FF               [12]  710 	mov	r7,a
      000806 B5 44 08         [24]  711 	cjne	a,(_display_buffer + 0x0002),00111$
                                    712 ;	src/display.c:56: display_buffer[2] = ledfonts_numeric_flipped[' '];
      000809 90 30 A0         [24]  713 	mov	dptr,#(_ledfonts_numeric_flipped + 0x0020)
      00080C E4               [12]  714 	clr	a
      00080D 93               [24]  715 	movc	a,@a+dptr
      00080E FF               [12]  716 	mov	r7,a
      00080F 8F 44            [24]  717 	mov	(_display_buffer + 0x0002),r7
      000811                        718 00111$:
                                    719 ;	src/display.c:58: }
      000811 22               [24]  720 	ret
                                    721 ;------------------------------------------------------------
                                    722 ;Allocation info for local variables in function 'display_putbool'
                                    723 ;------------------------------------------------------------
                                    724 ;v                         Allocated to registers r7 
                                    725 ;------------------------------------------------------------
                                    726 ;	src/display.c:60: void display_putbool(uint8_t v) {
                                    727 ;	-----------------------------------------
                                    728 ;	 function display_putbool
                                    729 ;	-----------------------------------------
      000812                        730 _display_putbool:
                                    731 ;	src/display.c:61: if(v) {
      000812 E5 82            [12]  732 	mov	a,dpl
      000814 60 11            [24]  733 	jz	00102$
                                    734 ;	src/display.c:62: display_buffer[2] = ledfonts_numeric_flipped['O'];
      000816 90 30 CF         [24]  735 	mov	dptr,#(_ledfonts_numeric_flipped + 0x004f)
      000819 E4               [12]  736 	clr	a
      00081A 93               [24]  737 	movc	a,@a+dptr
      00081B FF               [12]  738 	mov	r7,a
      00081C 8F 44            [24]  739 	mov	(_display_buffer + 0x0002),r7
                                    740 ;	src/display.c:63: display_buffer[3] = ledfonts_numeric_normal['N'];
      00081E 90 30 4E         [24]  741 	mov	dptr,#(_ledfonts_numeric_normal + 0x004e)
      000821 E4               [12]  742 	clr	a
      000822 93               [24]  743 	movc	a,@a+dptr
      000823 FF               [12]  744 	mov	r7,a
      000824 8F 45            [24]  745 	mov	(_display_buffer + 0x0003),r7
      000826 22               [24]  746 	ret
      000827                        747 00102$:
                                    748 ;	src/display.c:65: display_buffer[2] = ledfonts_numeric_flipped['O'];
      000827 90 30 CF         [24]  749 	mov	dptr,#(_ledfonts_numeric_flipped + 0x004f)
      00082A E4               [12]  750 	clr	a
      00082B 93               [24]  751 	movc	a,@a+dptr
      00082C FF               [12]  752 	mov	r7,a
      00082D 8F 44            [24]  753 	mov	(_display_buffer + 0x0002),r7
                                    754 ;	src/display.c:66: display_buffer[3] = ledfonts_numeric_normal['F'];
      00082F 90 30 46         [24]  755 	mov	dptr,#(_ledfonts_numeric_normal + 0x0046)
      000832 E4               [12]  756 	clr	a
      000833 93               [24]  757 	movc	a,@a+dptr
      000834 FF               [12]  758 	mov	r7,a
      000835 8F 45            [24]  759 	mov	(_display_buffer + 0x0003),r7
                                    760 ;	src/display.c:68: }
      000837 22               [24]  761 	ret
                                    762 ;------------------------------------------------------------
                                    763 ;Allocation info for local variables in function 'display_puttemp'
                                    764 ;------------------------------------------------------------
                                    765 ;v                         Allocated to registers r6 r7 
                                    766 ;------------------------------------------------------------
                                    767 ;	src/display.c:70: void display_puttemp(uint16_t v) {
                                    768 ;	-----------------------------------------
                                    769 ;	 function display_puttemp
                                    770 ;	-----------------------------------------
      000838                        771 _display_puttemp:
      000838 AE 82            [24]  772 	mov	r6,dpl
      00083A AF 83            [24]  773 	mov	r7,dph
                                    774 ;	src/display.c:71: display_buffer[0] = ledfonts_numeric_normal[(v >> 0x08) & 0x0f];
      00083C 8F 05            [24]  775 	mov	ar5,r7
      00083E 53 05 0F         [24]  776 	anl	ar5,#0x0f
      000841 7C 00            [12]  777 	mov	r4,#0x00
      000843 ED               [12]  778 	mov	a,r5
      000844 24 00            [12]  779 	add	a,#_ledfonts_numeric_normal
      000846 F5 82            [12]  780 	mov	dpl,a
      000848 EC               [12]  781 	mov	a,r4
      000849 34 30            [12]  782 	addc	a,#(_ledfonts_numeric_normal >> 8)
      00084B F5 83            [12]  783 	mov	dph,a
      00084D E4               [12]  784 	clr	a
      00084E 93               [24]  785 	movc	a,@a+dptr
      00084F FD               [12]  786 	mov	r5,a
      000850 8D 42            [24]  787 	mov	_display_buffer,r5
                                    788 ;	src/display.c:72: display_buffer[1] = ledfonts_numeric_normal[(v >> 0x04) & 0x0f];
      000852 8E 04            [24]  789 	mov	ar4,r6
      000854 EF               [12]  790 	mov	a,r7
      000855 C4               [12]  791 	swap	a
      000856 CC               [12]  792 	xch	a,r4
      000857 C4               [12]  793 	swap	a
      000858 54 0F            [12]  794 	anl	a,#0x0f
      00085A 6C               [12]  795 	xrl	a,r4
      00085B CC               [12]  796 	xch	a,r4
      00085C 54 0F            [12]  797 	anl	a,#0x0f
      00085E CC               [12]  798 	xch	a,r4
      00085F 6C               [12]  799 	xrl	a,r4
      000860 CC               [12]  800 	xch	a,r4
      000861 53 04 0F         [24]  801 	anl	ar4,#0x0f
      000864 7D 00            [12]  802 	mov	r5,#0x00
      000866 EC               [12]  803 	mov	a,r4
      000867 24 00            [12]  804 	add	a,#_ledfonts_numeric_normal
      000869 F5 82            [12]  805 	mov	dpl,a
      00086B ED               [12]  806 	mov	a,r5
      00086C 34 30            [12]  807 	addc	a,#(_ledfonts_numeric_normal >> 8)
      00086E F5 83            [12]  808 	mov	dph,a
      000870 E4               [12]  809 	clr	a
      000871 93               [24]  810 	movc	a,@a+dptr
      000872 FD               [12]  811 	mov	r5,a
      000873 8D 43            [24]  812 	mov	(_display_buffer + 0x0001),r5
                                    813 ;	src/display.c:73: display_buffer[2] = ledfonts_numeric_flipped[v & 0x0f];
      000875 53 06 0F         [24]  814 	anl	ar6,#0x0f
      000878 7F 00            [12]  815 	mov	r7,#0x00
      00087A EE               [12]  816 	mov	a,r6
      00087B 24 80            [12]  817 	add	a,#_ledfonts_numeric_flipped
      00087D F5 82            [12]  818 	mov	dpl,a
      00087F EF               [12]  819 	mov	a,r7
      000880 34 30            [12]  820 	addc	a,#(_ledfonts_numeric_flipped >> 8)
      000882 F5 83            [12]  821 	mov	dph,a
      000884 E4               [12]  822 	clr	a
      000885 93               [24]  823 	movc	a,@a+dptr
      000886 FF               [12]  824 	mov	r7,a
      000887 8F 44            [24]  825 	mov	(_display_buffer + 0x0002),r7
                                    826 ;	src/display.c:74: display_buffer[3] = ledfonts_numeric_normal['C'];
      000889 90 30 43         [24]  827 	mov	dptr,#(_ledfonts_numeric_normal + 0x0043)
      00088C E4               [12]  828 	clr	a
      00088D 93               [24]  829 	movc	a,@a+dptr
      00088E FF               [12]  830 	mov	r7,a
      00088F 8F 45            [24]  831 	mov	(_display_buffer + 0x0003),r7
                                    832 ;	include/display.h:146: display_buffer[1] &= 0x7f;
      000891 74 7F            [12]  833 	mov	a,#0x7f
      000893 55 43            [12]  834 	anl	a,(_display_buffer + 0x0001)
      000895 F5 43            [12]  835 	mov	(_display_buffer + 0x0001),a
                                    836 ;	src/display.c:75: display_periodon();
                                    837 ;	src/display.c:76: }
      000897 22               [24]  838 	ret
                                    839 ;------------------------------------------------------------
                                    840 ;Allocation info for local variables in function 'ISR_PCA'
                                    841 ;------------------------------------------------------------
                                    842 ;flash_prescaler           Allocated with name '_ISR_PCA_flash_prescaler_65536_154'
                                    843 ;__1966080031              Allocated to registers r7 
                                    844 ;index                     Allocated to registers 
                                    845 ;------------------------------------------------------------
                                    846 ;	src/display.c:78: void ISR_PCA(void) __interrupt(INT_PCA) __using(1)
                                    847 ;	-----------------------------------------
                                    848 ;	 function ISR_PCA
                                    849 ;	-----------------------------------------
      000898                        850 _ISR_PCA:
                           00000F   851 	ar7 = 0x0f
                           00000E   852 	ar6 = 0x0e
                           00000D   853 	ar5 = 0x0d
                           00000C   854 	ar4 = 0x0c
                           00000B   855 	ar3 = 0x0b
                           00000A   856 	ar2 = 0x0a
                           000009   857 	ar1 = 0x09
                           000008   858 	ar0 = 0x08
      000898 C0 E0            [24]  859 	push	acc
      00089A C0 F0            [24]  860 	push	b
      00089C C0 D0            [24]  861 	push	psw
      00089E 75 D0 08         [24]  862 	mov	psw,#0x08
                                    863 ;	src/display.c:81: if(PCA_CF) {
                                    864 ;	src/display.c:87: PCA_CF = 0;										//Disable interrupt flag
                                    865 ;	assignBit
      0008A1 10 DF 02         [24]  866 	jbc	_PCA_CF,00137$
      0008A4 80 3D            [24]  867 	sjmp	00106$
      0008A6                        868 00137$:
                                    869 ;	src/display.c:88: PCA_CCAP0_L = (display_counts & 0x0f); 			//Setup new compare value - Note that the low register MUST be written first to stop the comparison operation!
      0008A6 AF 48            [24]  870 	mov	r7,_display_counts
      0008A8 74 0F            [12]  871 	mov	a,#0x0f
      0008AA 5F               [12]  872 	anl	a,r7
      0008AB F5 EA            [12]  873 	mov	_PCA_CCAP0_L,a
                                    874 ;	src/display.c:89: PCA_CCAP0_H = (display_counts >> 8);			//Setup new compare value
      0008AD 85 49 FA         [24]  875 	mov	_PCA_CCAP0_H,(_display_counts + 1)
                                    876 ;	src/display.c:90: PORT_P2 = display_buffer[display_index];		//Write segment buffer
      0008B0 E5 46            [12]  877 	mov	a,_display_index
      0008B2 24 42            [12]  878 	add	a,#_display_buffer
      0008B4 F9               [12]  879 	mov	r1,a
      0008B5 87 A0            [24]  880 	mov	_PORT_P2,@r1
                                    881 ;	src/display.c:93: if((flash_prescaler < 0x08) && ((display_flash >> display_index) & 0x01))
      0008B7 74 F8            [12]  882 	mov	a,#0x100 - 0x08
      0008B9 25 4B            [12]  883 	add	a,_ISR_PCA_flash_prescaler_65536_154
      0008BB 40 11            [24]  884 	jc	00102$
      0008BD 85 46 F0         [24]  885 	mov	b,_display_index
      0008C0 05 F0            [12]  886 	inc	b
      0008C2 E5 47            [12]  887 	mov	a,_display_flash
      0008C4 80 02            [24]  888 	sjmp	00140$
      0008C6                        889 00139$:
      0008C6 C3               [12]  890 	clr	c
      0008C7 13               [12]  891 	rrc	a
      0008C8                        892 00140$:
      0008C8 D5 F0 FB         [24]  893 	djnz	b,00139$
      0008CB 20 E0 33         [24]  894 	jb	acc.0,00115$
      0008CE                        895 00102$:
                                    896 ;	src/display.c:96: display_drive_common(display_index);
      0008CE AF 46            [24]  897 	mov	r7,_display_index
                                    898 ;	include/board_config.h:46: PORT_P3 &= ~(0x04 << index);
      0008D0 8F F0            [24]  899 	mov	b,r7
      0008D2 05 F0            [12]  900 	inc	b
      0008D4 74 04            [12]  901 	mov	a,#0x04
      0008D6 80 02            [24]  902 	sjmp	00144$
      0008D8                        903 00142$:
      0008D8 25 E0            [12]  904 	add	a,acc
      0008DA                        905 00144$:
      0008DA D5 F0 FB         [24]  906 	djnz	b,00142$
      0008DD F4               [12]  907 	cpl	a
      0008DE FF               [12]  908 	mov	r7,a
      0008DF 52 B0            [12]  909 	anl	_PORT_P3,a
                                    910 ;	src/display.c:96: display_drive_common(display_index);
                                    911 ;	src/display.c:98: return;
      0008E1 80 1E            [24]  912 	sjmp	00115$
      0008E3                        913 00106$:
                                    914 ;	src/display.c:101: if(PCA_CCF0) {
                                    915 ;	src/display.c:106: PCA_CCF0 = 0;				//Disable interrupt flag
                                    916 ;	assignBit
      0008E3 10 D8 02         [24]  917 	jbc	_PCA_CCF0,00145$
      0008E6 80 19            [24]  918 	sjmp	00115$
      0008E8                        919 00145$:
                                    920 ;	include/board_config.h:57: PORT_P3 |= (0x3c);
      0008E8 43 B0 3C         [24]  921 	orl	_PORT_P3,#0x3c
                                    922 ;	src/display.c:108: if(!display_index){
      0008EB E5 46            [12]  923 	mov	a,_display_index
      0008ED 70 0D            [24]  924 	jnz	00110$
                                    925 ;	src/display.c:110: if(!(flash_prescaler--))
      0008EF AF 4B            [24]  926 	mov	r7,_ISR_PCA_flash_prescaler_65536_154
      0008F1 15 4B            [12]  927 	dec	_ISR_PCA_flash_prescaler_65536_154
      0008F3 EF               [12]  928 	mov	a,r7
      0008F4 70 03            [24]  929 	jnz	00108$
                                    930 ;	src/display.c:111: flash_prescaler = 0x10;
      0008F6 75 4B 10         [24]  931 	mov	_ISR_PCA_flash_prescaler_65536_154,#0x10
      0008F9                        932 00108$:
                                    933 ;	src/display.c:112: display_index = 0x04;
      0008F9 75 46 04         [24]  934 	mov	_display_index,#0x04
      0008FC                        935 00110$:
                                    936 ;	src/display.c:114: display_index--;			//Decrement display index
      0008FC E5 46            [12]  937 	mov	a,_display_index
      0008FE 14               [12]  938 	dec	a
      0008FF F5 46            [12]  939 	mov	_display_index,a
                                    940 ;	src/display.c:116: return;
      000901                        941 00115$:
                                    942 ;	src/display.c:118: }
      000901 D0 D0            [24]  943 	pop	psw
      000903 D0 F0            [24]  944 	pop	b
      000905 D0 E0            [24]  945 	pop	acc
      000907 32               [24]  946 	reti
                                    947 ;	eliminated unneeded push/pop dpl
                                    948 ;	eliminated unneeded push/pop dph
                                    949 	.area CSEG    (CODE)
                                    950 	.area CONST   (CODE)
                                    951 	.area XINIT   (CODE)
                                    952 	.area CABS    (ABS,CODE)
