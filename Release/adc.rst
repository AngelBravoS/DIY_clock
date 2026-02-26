                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module adc
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _ISR_ADC
                                     12 	.globl _eeprom_end
                                     13 	.globl _eeprom_write
                                     14 	.globl _eeprom_erase
                                     15 	.globl _eeprom_start
                                     16 	.globl _UART_SM0
                                     17 	.globl _UART_SM1
                                     18 	.globl _UART_SM2
                                     19 	.globl _UART_REN
                                     20 	.globl _UART_TB8
                                     21 	.globl _UART_RB8
                                     22 	.globl _UART_TI
                                     23 	.globl _UART_RI
                                     24 	.globl _PCA_CF
                                     25 	.globl _PCA_CR
                                     26 	.globl _PCA_CCF2
                                     27 	.globl _PCA_CCF1
                                     28 	.globl _PCA_CCF0
                                     29 	.globl _TMR_TCON_TF1
                                     30 	.globl _TMR_TCON_TR1
                                     31 	.globl _TMR_TCON_TF0
                                     32 	.globl _TMR_TCON_TR0
                                     33 	.globl _TMR_TCON_IE1
                                     34 	.globl _TMR_TCON_IT1
                                     35 	.globl _TMR_TCON_IE0
                                     36 	.globl _TMR_TCON_IT0
                                     37 	.globl _INT_IP_PPCA
                                     38 	.globl _INT_IP_PLVD
                                     39 	.globl _INT_IP_PADC
                                     40 	.globl _INT_IP_PS
                                     41 	.globl _INT_IP_PT1
                                     42 	.globl _INT_IP_PX1
                                     43 	.globl _INT_IP_PT0
                                     44 	.globl _INT_IP_PX0
                                     45 	.globl _INT_IE_EA
                                     46 	.globl _INT_IE_ELVD
                                     47 	.globl _INT_IE_EADC
                                     48 	.globl _INT_IE_ES
                                     49 	.globl _INT_IE_ET1
                                     50 	.globl _INT_IE_EX1
                                     51 	.globl _INT_IE_ET0
                                     52 	.globl _INT_IE_EX0
                                     53 	.globl _PORT_P5_7
                                     54 	.globl _PORT_P5_6
                                     55 	.globl _PORT_P5_5
                                     56 	.globl _PORT_P5_4
                                     57 	.globl _PORT_P5_3
                                     58 	.globl _PORT_P5_2
                                     59 	.globl _PORT_P5_1
                                     60 	.globl _PORT_P5_0
                                     61 	.globl _PORT_P4_7
                                     62 	.globl _PORT_P4_6
                                     63 	.globl _PORT_P4_5
                                     64 	.globl _PORT_P4_4
                                     65 	.globl _PORT_P4_3
                                     66 	.globl _PORT_P4_2
                                     67 	.globl _PORT_P4_1
                                     68 	.globl _PORT_P4_0
                                     69 	.globl _PORT_P3_7
                                     70 	.globl _PORT_P3_6
                                     71 	.globl _PORT_P3_5
                                     72 	.globl _PORT_P3_4
                                     73 	.globl _PORT_P3_3
                                     74 	.globl _PORT_P3_2
                                     75 	.globl _PORT_P3_1
                                     76 	.globl _PORT_P3_0
                                     77 	.globl _PORT_P2_7
                                     78 	.globl _PORT_P2_6
                                     79 	.globl _PORT_P2_5
                                     80 	.globl _PORT_P2_4
                                     81 	.globl _PORT_P2_3
                                     82 	.globl _PORT_P2_2
                                     83 	.globl _PORT_P2_1
                                     84 	.globl _PORT_P2_0
                                     85 	.globl _PORT_P1_7
                                     86 	.globl _PORT_P1_6
                                     87 	.globl _PORT_P1_5
                                     88 	.globl _PORT_P1_4
                                     89 	.globl _PORT_P1_3
                                     90 	.globl _PORT_P1_2
                                     91 	.globl _PORT_P1_1
                                     92 	.globl _PORT_P1_0
                                     93 	.globl _CY
                                     94 	.globl _AC
                                     95 	.globl _F0
                                     96 	.globl _RS1
                                     97 	.globl _RS0
                                     98 	.globl _OV
                                     99 	.globl _F1
                                    100 	.globl _P
                                    101 	.globl _IAP_CONTR
                                    102 	.globl _IAP_TRIG
                                    103 	.globl _IAP_CMD
                                    104 	.globl _IAP_ADDR
                                    105 	.globl _IAP_ADDRL
                                    106 	.globl _IAP_ADDRH
                                    107 	.globl _IAP_DATA
                                    108 	.globl _UART_SADEN
                                    109 	.globl _UART_SADDR
                                    110 	.globl _UART_SBUF
                                    111 	.globl _UART_SCON
                                    112 	.globl _PCA_CMOD
                                    113 	.globl _PCA_CCON
                                    114 	.globl _PCA_PWM2
                                    115 	.globl _PCA_PWM1
                                    116 	.globl _PCA_PWM0
                                    117 	.globl _PCA_C
                                    118 	.globl _PCA_CCAP2_L
                                    119 	.globl _PCA_CCAP2_H
                                    120 	.globl _PCA_CCAP1_L
                                    121 	.globl _PCA_CCAP1_H
                                    122 	.globl _PCA_CCAP0_L
                                    123 	.globl _PCA_CCAP0_H
                                    124 	.globl _PCA_CCAP2
                                    125 	.globl _PCA_CCAP1
                                    126 	.globl _PCA_CCAP0
                                    127 	.globl _PCA_CCAPM2
                                    128 	.globl _PCA_CCAPM1
                                    129 	.globl _PCA_CCAPM0
                                    130 	.globl _CMP_CR2
                                    131 	.globl _CMP_CR1
                                    132 	.globl _ADC_RESL
                                    133 	.globl _ADC_RESH
                                    134 	.globl _ADC_RES
                                    135 	.globl _ADC_CONTR
                                    136 	.globl _ADC_P1ASF
                                    137 	.globl _EEPROM_CONTR
                                    138 	.globl _EEPROM_TRIG
                                    139 	.globl _EEPROM_CMD
                                    140 	.globl _EEPROM_ADDR
                                    141 	.globl _EEPROM_DATA
                                    142 	.globl _TMR_T2
                                    143 	.globl _TMR_T0
                                    144 	.globl _TMR_TMOD
                                    145 	.globl _TMR_TCON
                                    146 	.globl _INT_IP2
                                    147 	.globl _INT_IP
                                    148 	.globl _INT_IE2
                                    149 	.globl _INT_IE
                                    150 	.globl _PORT_P5M0
                                    151 	.globl _PORT_P5M1
                                    152 	.globl _PORT_P4M0
                                    153 	.globl _PORT_P4M1
                                    154 	.globl _PORT_P3M0
                                    155 	.globl _PORT_P3M1
                                    156 	.globl _PORT_P2M0
                                    157 	.globl _PORT_P2M1
                                    158 	.globl _PORT_P1M0
                                    159 	.globl _PORT_P1M1
                                    160 	.globl _PORT_P5
                                    161 	.globl _PORT_P4
                                    162 	.globl _PORT_P3
                                    163 	.globl _PORT_P2
                                    164 	.globl _PORT_P1
                                    165 	.globl _PSW
                                    166 	.globl _PCON2
                                    167 	.globl _AUXR2
                                    168 	.globl _AUXR1
                                    169 	.globl _AUXR
                                    170 	.globl _PCON
                                    171 	.globl _DPTR
                                    172 	.globl _SP
                                    173 	.globl _display_autobrightness
                                    174 	.globl _DS1302_DATA_7
                                    175 	.globl _DS1302_DATA_6
                                    176 	.globl _DS1302_DATA_5
                                    177 	.globl _DS1302_DATA_4
                                    178 	.globl _DS1302_DATA_3
                                    179 	.globl _DS1302_DATA_2
                                    180 	.globl _DS1302_DATA_1
                                    181 	.globl _DS1302_DATA_0
                                    182 	.globl _adc_calibrate_LDR_PARM_2
                                    183 	.globl _adc_thermistor_reading
                                    184 	.globl _adc_ldr_reading
                                    185 	.globl _DS1302_DATA
                                    186 	.globl _adc_calibrate_LDR
                                    187 ;--------------------------------------------------------
                                    188 ; special function registers
                                    189 ;--------------------------------------------------------
                                    190 	.area RSEG    (ABS,DATA)
      000000                        191 	.org 0x0000
                           000081   192 _SP	=	0x0081
                           008382   193 _DPTR	=	0x8382
                           000087   194 _PCON	=	0x0087
                           00008E   195 _AUXR	=	0x008e
                           0000A2   196 _AUXR1	=	0x00a2
                           00008F   197 _AUXR2	=	0x008f
                           000097   198 _PCON2	=	0x0097
                           0000D0   199 _PSW	=	0x00d0
                           000090   200 _PORT_P1	=	0x0090
                           0000A0   201 _PORT_P2	=	0x00a0
                           0000B0   202 _PORT_P3	=	0x00b0
                           0000C0   203 _PORT_P4	=	0x00c0
                           0000C8   204 _PORT_P5	=	0x00c8
                           000091   205 _PORT_P1M1	=	0x0091
                           000092   206 _PORT_P1M0	=	0x0092
                           000095   207 _PORT_P2M1	=	0x0095
                           000096   208 _PORT_P2M0	=	0x0096
                           0000B1   209 _PORT_P3M1	=	0x00b1
                           0000B2   210 _PORT_P3M0	=	0x00b2
                           0000B3   211 _PORT_P4M1	=	0x00b3
                           0000B4   212 _PORT_P4M0	=	0x00b4
                           0000C9   213 _PORT_P5M1	=	0x00c9
                           0000CA   214 _PORT_P5M0	=	0x00ca
                           0000A8   215 _INT_IE	=	0x00a8
                           0000AF   216 _INT_IE2	=	0x00af
                           0000B8   217 _INT_IP	=	0x00b8
                           0000B5   218 _INT_IP2	=	0x00b5
                           000088   219 _TMR_TCON	=	0x0088
                           000089   220 _TMR_TMOD	=	0x0089
                           008C8A   221 _TMR_T0	=	0x8c8a
                           00D6D7   222 _TMR_T2	=	0xd6d7
                           0000C2   223 _EEPROM_DATA	=	0x00c2
                           00C3C4   224 _EEPROM_ADDR	=	0xc3c4
                           0000C5   225 _EEPROM_CMD	=	0x00c5
                           0000C6   226 _EEPROM_TRIG	=	0x00c6
                           0000C7   227 _EEPROM_CONTR	=	0x00c7
                           00009D   228 _ADC_P1ASF	=	0x009d
                           0000BC   229 _ADC_CONTR	=	0x00bc
                           00BDBE   230 _ADC_RES	=	0xbdbe
                           0000BD   231 _ADC_RESH	=	0x00bd
                           0000BE   232 _ADC_RESL	=	0x00be
                           0000E6   233 _CMP_CR1	=	0x00e6
                           0000E7   234 _CMP_CR2	=	0x00e7
                           0000DA   235 _PCA_CCAPM0	=	0x00da
                           0000DB   236 _PCA_CCAPM1	=	0x00db
                           0000DC   237 _PCA_CCAPM2	=	0x00dc
                           00FAEA   238 _PCA_CCAP0	=	0xfaea
                           00FBEB   239 _PCA_CCAP1	=	0xfbeb
                           00FCEC   240 _PCA_CCAP2	=	0xfcec
                           0000FA   241 _PCA_CCAP0_H	=	0x00fa
                           0000EA   242 _PCA_CCAP0_L	=	0x00ea
                           0000FB   243 _PCA_CCAP1_H	=	0x00fb
                           0000EB   244 _PCA_CCAP1_L	=	0x00eb
                           0000FC   245 _PCA_CCAP2_H	=	0x00fc
                           0000EC   246 _PCA_CCAP2_L	=	0x00ec
                           00F9E9   247 _PCA_C	=	0xf9e9
                           0000F2   248 _PCA_PWM0	=	0x00f2
                           0000F3   249 _PCA_PWM1	=	0x00f3
                           0000F4   250 _PCA_PWM2	=	0x00f4
                           0000D8   251 _PCA_CCON	=	0x00d8
                           0000D9   252 _PCA_CMOD	=	0x00d9
                           000098   253 _UART_SCON	=	0x0098
                           000099   254 _UART_SBUF	=	0x0099
                           0000A9   255 _UART_SADDR	=	0x00a9
                           0000B9   256 _UART_SADEN	=	0x00b9
                           0000C2   257 _IAP_DATA	=	0x00c2
                           0000C3   258 _IAP_ADDRH	=	0x00c3
                           0000C4   259 _IAP_ADDRL	=	0x00c4
                           00C3C4   260 _IAP_ADDR	=	0xc3c4
                           0000C5   261 _IAP_CMD	=	0x00c5
                           0000C6   262 _IAP_TRIG	=	0x00c6
                           0000C7   263 _IAP_CONTR	=	0x00c7
                                    264 ;--------------------------------------------------------
                                    265 ; special function bits
                                    266 ;--------------------------------------------------------
                                    267 	.area RSEG    (ABS,DATA)
      000000                        268 	.org 0x0000
                           0000D0   269 _P	=	0x00d0
                           0000D1   270 _F1	=	0x00d1
                           0000D2   271 _OV	=	0x00d2
                           0000D3   272 _RS0	=	0x00d3
                           0000D4   273 _RS1	=	0x00d4
                           0000D5   274 _F0	=	0x00d5
                           0000D6   275 _AC	=	0x00d6
                           0000D7   276 _CY	=	0x00d7
                           000090   277 _PORT_P1_0	=	0x0090
                           000091   278 _PORT_P1_1	=	0x0091
                           000092   279 _PORT_P1_2	=	0x0092
                           000093   280 _PORT_P1_3	=	0x0093
                           000094   281 _PORT_P1_4	=	0x0094
                           000095   282 _PORT_P1_5	=	0x0095
                           000096   283 _PORT_P1_6	=	0x0096
                           000097   284 _PORT_P1_7	=	0x0097
                           0000A0   285 _PORT_P2_0	=	0x00a0
                           0000A1   286 _PORT_P2_1	=	0x00a1
                           0000A2   287 _PORT_P2_2	=	0x00a2
                           0000A3   288 _PORT_P2_3	=	0x00a3
                           0000A4   289 _PORT_P2_4	=	0x00a4
                           0000A5   290 _PORT_P2_5	=	0x00a5
                           0000A6   291 _PORT_P2_6	=	0x00a6
                           0000A7   292 _PORT_P2_7	=	0x00a7
                           0000B0   293 _PORT_P3_0	=	0x00b0
                           0000B1   294 _PORT_P3_1	=	0x00b1
                           0000B2   295 _PORT_P3_2	=	0x00b2
                           0000B3   296 _PORT_P3_3	=	0x00b3
                           0000B4   297 _PORT_P3_4	=	0x00b4
                           0000B5   298 _PORT_P3_5	=	0x00b5
                           0000B6   299 _PORT_P3_6	=	0x00b6
                           0000B7   300 _PORT_P3_7	=	0x00b7
                           0000C0   301 _PORT_P4_0	=	0x00c0
                           0000C1   302 _PORT_P4_1	=	0x00c1
                           0000C2   303 _PORT_P4_2	=	0x00c2
                           0000C3   304 _PORT_P4_3	=	0x00c3
                           0000C4   305 _PORT_P4_4	=	0x00c4
                           0000C5   306 _PORT_P4_5	=	0x00c5
                           0000C6   307 _PORT_P4_6	=	0x00c6
                           0000C7   308 _PORT_P4_7	=	0x00c7
                           0000C8   309 _PORT_P5_0	=	0x00c8
                           0000C9   310 _PORT_P5_1	=	0x00c9
                           0000CA   311 _PORT_P5_2	=	0x00ca
                           0000CB   312 _PORT_P5_3	=	0x00cb
                           0000CC   313 _PORT_P5_4	=	0x00cc
                           0000CD   314 _PORT_P5_5	=	0x00cd
                           0000CE   315 _PORT_P5_6	=	0x00ce
                           0000CF   316 _PORT_P5_7	=	0x00cf
                           0000A8   317 _INT_IE_EX0	=	0x00a8
                           0000A9   318 _INT_IE_ET0	=	0x00a9
                           0000AA   319 _INT_IE_EX1	=	0x00aa
                           0000AB   320 _INT_IE_ET1	=	0x00ab
                           0000AC   321 _INT_IE_ES	=	0x00ac
                           0000AD   322 _INT_IE_EADC	=	0x00ad
                           0000AE   323 _INT_IE_ELVD	=	0x00ae
                           0000AF   324 _INT_IE_EA	=	0x00af
                           0000B8   325 _INT_IP_PX0	=	0x00b8
                           0000B9   326 _INT_IP_PT0	=	0x00b9
                           0000BA   327 _INT_IP_PX1	=	0x00ba
                           0000BB   328 _INT_IP_PT1	=	0x00bb
                           0000BC   329 _INT_IP_PS	=	0x00bc
                           0000BD   330 _INT_IP_PADC	=	0x00bd
                           0000BE   331 _INT_IP_PLVD	=	0x00be
                           0000BF   332 _INT_IP_PPCA	=	0x00bf
                           000088   333 _TMR_TCON_IT0	=	0x0088
                           000089   334 _TMR_TCON_IE0	=	0x0089
                           00008A   335 _TMR_TCON_IT1	=	0x008a
                           00008B   336 _TMR_TCON_IE1	=	0x008b
                           00008C   337 _TMR_TCON_TR0	=	0x008c
                           00008D   338 _TMR_TCON_TF0	=	0x008d
                           00008E   339 _TMR_TCON_TR1	=	0x008e
                           00008F   340 _TMR_TCON_TF1	=	0x008f
                           0000D8   341 _PCA_CCF0	=	0x00d8
                           0000D9   342 _PCA_CCF1	=	0x00d9
                           0000DA   343 _PCA_CCF2	=	0x00da
                           0000DE   344 _PCA_CR	=	0x00de
                           0000DF   345 _PCA_CF	=	0x00df
                           000098   346 _UART_RI	=	0x0098
                           000099   347 _UART_TI	=	0x0099
                           00009A   348 _UART_RB8	=	0x009a
                           00009B   349 _UART_TB8	=	0x009b
                           00009C   350 _UART_REN	=	0x009c
                           00009D   351 _UART_SM2	=	0x009d
                           00009E   352 _UART_SM1	=	0x009e
                           00009F   353 _UART_SM0	=	0x009f
                                    354 ;--------------------------------------------------------
                                    355 ; overlayable register banks
                                    356 ;--------------------------------------------------------
                                    357 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        358 	.ds 8
                                    359 	.area REG_BANK_3	(REL,OVR,DATA)
      000018                        360 	.ds 8
                                    361 ;--------------------------------------------------------
                                    362 ; overlayable bit register bank
                                    363 ;--------------------------------------------------------
                                    364 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        365 bits:
      000020                        366 	.ds 1
                           008000   367 	b0 = bits[0]
                           008100   368 	b1 = bits[1]
                           008200   369 	b2 = bits[2]
                           008300   370 	b3 = bits[3]
                           008400   371 	b4 = bits[4]
                           008500   372 	b5 = bits[5]
                           008600   373 	b6 = bits[6]
                           008700   374 	b7 = bits[7]
                                    375 ;--------------------------------------------------------
                                    376 ; internal ram data
                                    377 ;--------------------------------------------------------
                                    378 	.area DSEG    (DATA)
                           000021   379 _DS1302_DATA	=	0x0021
      000029                        380 _adc_ldr_reading::
      000029                        381 	.ds 2
      00002B                        382 _adc_thermistor_reading::
      00002B                        383 	.ds 2
      00002D                        384 _adc_calibrate_LDR_PARM_2:
      00002D                        385 	.ds 2
      00002F                        386 _adc_calibrate_LDR_ldr_min_65536_159:
      00002F                        387 	.ds 2
      000031                        388 _adc_calibrate_LDR_gradient_65536_160:
      000031                        389 	.ds 4
      000035                        390 _adc_calibrate_LDR_intercept_65536_160:
      000035                        391 	.ds 4
      000039                        392 _adc_calibrate_LDR_i_65536_160:
      000039                        393 	.ds 2
                                    394 ;--------------------------------------------------------
                                    395 ; overlayable items in internal ram
                                    396 ;--------------------------------------------------------
                                    397 ;--------------------------------------------------------
                                    398 ; indirectly addressable internal ram data
                                    399 ;--------------------------------------------------------
                                    400 	.area ISEG    (DATA)
                                    401 ;--------------------------------------------------------
                                    402 ; absolute internal ram data
                                    403 ;--------------------------------------------------------
                                    404 	.area IABS    (ABS,DATA)
                                    405 	.area IABS    (ABS,DATA)
                                    406 ;--------------------------------------------------------
                                    407 ; bit data
                                    408 ;--------------------------------------------------------
                                    409 	.area BSEG    (BIT)
                           000008   410 _DS1302_DATA_0	=	0x0008
                           000009   411 _DS1302_DATA_1	=	0x0009
                           00000A   412 _DS1302_DATA_2	=	0x000a
                           00000B   413 _DS1302_DATA_3	=	0x000b
                           00000C   414 _DS1302_DATA_4	=	0x000c
                           00000D   415 _DS1302_DATA_5	=	0x000d
                           00000E   416 _DS1302_DATA_6	=	0x000e
                           00000F   417 _DS1302_DATA_7	=	0x000f
                           00001F   418 _display_autobrightness	=	0x001f
                                    419 ;--------------------------------------------------------
                                    420 ; paged external ram data
                                    421 ;--------------------------------------------------------
                                    422 	.area PSEG    (PAG,XDATA)
                                    423 ;--------------------------------------------------------
                                    424 ; external ram data
                                    425 ;--------------------------------------------------------
                                    426 	.area XSEG    (XDATA)
                                    427 ;--------------------------------------------------------
                                    428 ; absolute external ram data
                                    429 ;--------------------------------------------------------
                                    430 	.area XABS    (ABS,XDATA)
                                    431 ;--------------------------------------------------------
                                    432 ; external initialized ram data
                                    433 ;--------------------------------------------------------
                                    434 	.area XISEG   (XDATA)
                                    435 	.area HOME    (CODE)
                                    436 	.area GSINIT0 (CODE)
                                    437 	.area GSINIT1 (CODE)
                                    438 	.area GSINIT2 (CODE)
                                    439 	.area GSINIT3 (CODE)
                                    440 	.area GSINIT4 (CODE)
                                    441 	.area GSINIT5 (CODE)
                                    442 	.area GSINIT  (CODE)
                                    443 	.area GSFINAL (CODE)
                                    444 	.area CSEG    (CODE)
                                    445 ;--------------------------------------------------------
                                    446 ; global & static initialisations
                                    447 ;--------------------------------------------------------
                                    448 	.area HOME    (CODE)
                                    449 	.area GSINIT  (CODE)
                                    450 	.area GSFINAL (CODE)
                                    451 	.area GSINIT  (CODE)
                                    452 ;--------------------------------------------------------
                                    453 ; Home
                                    454 ;--------------------------------------------------------
                                    455 	.area HOME    (CODE)
                                    456 	.area HOME    (CODE)
                                    457 ;--------------------------------------------------------
                                    458 ; code
                                    459 ;--------------------------------------------------------
                                    460 	.area CSEG    (CODE)
                                    461 ;------------------------------------------------------------
                                    462 ;Allocation info for local variables in function 'adc_calibrate_LDR'
                                    463 ;------------------------------------------------------------
                                    464 ;ldr_max                   Allocated with name '_adc_calibrate_LDR_PARM_2'
                                    465 ;ldr_min                   Allocated with name '_adc_calibrate_LDR_ldr_min_65536_159'
                                    466 ;gradient                  Allocated with name '_adc_calibrate_LDR_gradient_65536_160'
                                    467 ;intercept                 Allocated with name '_adc_calibrate_LDR_intercept_65536_160'
                                    468 ;i                         Allocated with name '_adc_calibrate_LDR_i_65536_160'
                                    469 ;------------------------------------------------------------
                                    470 ;	src/adc.c:13: void adc_calibrate_LDR(uint16_t ldr_min,uint16_t ldr_max) {
                                    471 ;	-----------------------------------------
                                    472 ;	 function adc_calibrate_LDR
                                    473 ;	-----------------------------------------
      00026A                        474 _adc_calibrate_LDR:
                           000007   475 	ar7 = 0x07
                           000006   476 	ar6 = 0x06
                           000005   477 	ar5 = 0x05
                           000004   478 	ar4 = 0x04
                           000003   479 	ar3 = 0x03
                           000002   480 	ar2 = 0x02
                           000001   481 	ar1 = 0x01
                           000000   482 	ar0 = 0x00
      00026A 85 82 2F         [24]  483 	mov	_adc_calibrate_LDR_ldr_min_65536_159,dpl
      00026D 85 83 30         [24]  484 	mov	(_adc_calibrate_LDR_ldr_min_65536_159 + 1),dph
                                    485 ;	src/adc.c:14: float gradient = (((float)(DISPLAY_COUNTS_RANGE))/((-1.00f)*(float)(ldr_max - ldr_min)));
      000270 E5 2D            [12]  486 	mov	a,_adc_calibrate_LDR_PARM_2
      000272 C3               [12]  487 	clr	c
      000273 95 2F            [12]  488 	subb	a,_adc_calibrate_LDR_ldr_min_65536_159
      000275 F5 82            [12]  489 	mov	dpl,a
      000277 E5 2E            [12]  490 	mov	a,(_adc_calibrate_LDR_PARM_2 + 1)
      000279 95 30            [12]  491 	subb	a,(_adc_calibrate_LDR_ldr_min_65536_159 + 1)
      00027B F5 83            [12]  492 	mov	dph,a
      00027D 12 1C DD         [24]  493 	lcall	___uint2fs
      000280 AA 82            [24]  494 	mov	r2,dpl
      000282 AB 83            [24]  495 	mov	r3,dph
      000284 AC F0            [24]  496 	mov	r4,b
      000286 B2 E7            [12]  497 	cpl	acc.7
      000288 FD               [12]  498 	mov	r5,a
      000289 C0 02            [24]  499 	push	ar2
      00028B C0 03            [24]  500 	push	ar3
      00028D C0 04            [24]  501 	push	ar4
      00028F C0 05            [24]  502 	push	ar5
      000291 90 D4 00         [24]  503 	mov	dptr,#0xd400
      000294 75 F0 68         [24]  504 	mov	b,#0x68
      000297 74 47            [12]  505 	mov	a,#0x47
      000299 12 1D 5D         [24]  506 	lcall	___fsdiv
      00029C 85 82 31         [24]  507 	mov	_adc_calibrate_LDR_gradient_65536_160,dpl
      00029F 85 83 32         [24]  508 	mov	(_adc_calibrate_LDR_gradient_65536_160 + 1),dph
      0002A2 85 F0 33         [24]  509 	mov	(_adc_calibrate_LDR_gradient_65536_160 + 2),b
      0002A5 F5 34            [12]  510 	mov	(_adc_calibrate_LDR_gradient_65536_160 + 3),a
      0002A7 E5 81            [12]  511 	mov	a,sp
      0002A9 24 FC            [12]  512 	add	a,#0xfc
      0002AB F5 81            [12]  513 	mov	sp,a
                                    514 ;	src/adc.c:15: float intercept = ((float)DISPLAY_COUNTS_MAX - gradient*((float)ldr_min));
      0002AD 85 2F 82         [24]  515 	mov	dpl,_adc_calibrate_LDR_ldr_min_65536_159
      0002B0 85 30 83         [24]  516 	mov	dph,(_adc_calibrate_LDR_ldr_min_65536_159 + 1)
      0002B3 12 1C DD         [24]  517 	lcall	___uint2fs
      0002B6 A8 82            [24]  518 	mov	r0,dpl
      0002B8 A9 83            [24]  519 	mov	r1,dph
      0002BA AC F0            [24]  520 	mov	r4,b
      0002BC FD               [12]  521 	mov	r5,a
      0002BD C0 00            [24]  522 	push	ar0
      0002BF C0 01            [24]  523 	push	ar1
      0002C1 C0 04            [24]  524 	push	ar4
      0002C3 C0 05            [24]  525 	push	ar5
      0002C5 85 31 82         [24]  526 	mov	dpl,_adc_calibrate_LDR_gradient_65536_160
      0002C8 85 32 83         [24]  527 	mov	dph,(_adc_calibrate_LDR_gradient_65536_160 + 1)
      0002CB 85 33 F0         [24]  528 	mov	b,(_adc_calibrate_LDR_gradient_65536_160 + 2)
      0002CE E5 34            [12]  529 	mov	a,(_adc_calibrate_LDR_gradient_65536_160 + 3)
      0002D0 12 1A F3         [24]  530 	lcall	___fsmul
      0002D3 AA 82            [24]  531 	mov	r2,dpl
      0002D5 AB 83            [24]  532 	mov	r3,dph
      0002D7 AC F0            [24]  533 	mov	r4,b
      0002D9 FD               [12]  534 	mov	r5,a
      0002DA E5 81            [12]  535 	mov	a,sp
      0002DC 24 FC            [12]  536 	add	a,#0xfc
      0002DE F5 81            [12]  537 	mov	sp,a
      0002E0 C0 02            [24]  538 	push	ar2
      0002E2 C0 03            [24]  539 	push	ar3
      0002E4 C0 04            [24]  540 	push	ar4
      0002E6 C0 05            [24]  541 	push	ar5
      0002E8 90 00 00         [24]  542 	mov	dptr,#0x0000
      0002EB 75 F0 6A         [24]  543 	mov	b,#0x6a
      0002EE 74 47            [12]  544 	mov	a,#0x47
      0002F0 12 1A E8         [24]  545 	lcall	___fssub
      0002F3 85 82 35         [24]  546 	mov	_adc_calibrate_LDR_intercept_65536_160,dpl
      0002F6 85 83 36         [24]  547 	mov	(_adc_calibrate_LDR_intercept_65536_160 + 1),dph
      0002F9 85 F0 37         [24]  548 	mov	(_adc_calibrate_LDR_intercept_65536_160 + 2),b
      0002FC F5 38            [12]  549 	mov	(_adc_calibrate_LDR_intercept_65536_160 + 3),a
      0002FE E5 81            [12]  550 	mov	a,sp
      000300 24 FC            [12]  551 	add	a,#0xfc
      000302 F5 81            [12]  552 	mov	sp,a
                                    553 ;	src/adc.c:18: eeprom_start();
      000304 12 0B C7         [24]  554 	lcall	_eeprom_start
                                    555 ;	src/adc.c:19: eeprom_erase(0x00);	//Erase EEPROM sectors holding LDR lookup table
      000307 75 82 00         [24]  556 	mov	dpl,#0x00
      00030A 12 0B CB         [24]  557 	lcall	_eeprom_erase
                                    558 ;	src/adc.c:20: eeprom_erase(0x02);	//Erase EEPROM sectors holding LDR lookup table
      00030D 75 82 02         [24]  559 	mov	dpl,#0x02
      000310 12 0B CB         [24]  560 	lcall	_eeprom_erase
                                    561 ;	src/adc.c:21: eeprom_erase(0x04);	//Erase EEPROM sectors holding LDR lookup table
      000313 75 82 04         [24]  562 	mov	dpl,#0x04
      000316 12 0B CB         [24]  563 	lcall	_eeprom_erase
                                    564 ;	src/adc.c:22: eeprom_erase(0x08);	//Erase EEPROM sectors holding LDR lookup table
      000319 75 82 08         [24]  565 	mov	dpl,#0x08
      00031C 12 0B CB         [24]  566 	lcall	_eeprom_erase
                                    567 ;	src/adc.c:23: for(i=0;i<1024;i++){
      00031F E4               [12]  568 	clr	a
      000320 F5 39            [12]  569 	mov	_adc_calibrate_LDR_i_65536_160,a
      000322 F5 3A            [12]  570 	mov	(_adc_calibrate_LDR_i_65536_160 + 1),a
      000324                        571 00108$:
                                    572 ;	src/adc.c:24: if((i >= ldr_min) && (i <= ldr_max)){
      000324 C3               [12]  573 	clr	c
      000325 E5 39            [12]  574 	mov	a,_adc_calibrate_LDR_i_65536_160
      000327 95 2F            [12]  575 	subb	a,_adc_calibrate_LDR_ldr_min_65536_159
      000329 E5 3A            [12]  576 	mov	a,(_adc_calibrate_LDR_i_65536_160 + 1)
      00032B 95 30            [12]  577 	subb	a,(_adc_calibrate_LDR_ldr_min_65536_159 + 1)
      00032D 50 03            [24]  578 	jnc	00132$
      00032F 02 04 10         [24]  579 	ljmp	00102$
      000332                        580 00132$:
      000332 C3               [12]  581 	clr	c
      000333 E5 2D            [12]  582 	mov	a,_adc_calibrate_LDR_PARM_2
      000335 95 39            [12]  583 	subb	a,_adc_calibrate_LDR_i_65536_160
      000337 E5 2E            [12]  584 	mov	a,(_adc_calibrate_LDR_PARM_2 + 1)
      000339 95 3A            [12]  585 	subb	a,(_adc_calibrate_LDR_i_65536_160 + 1)
      00033B 50 03            [24]  586 	jnc	00133$
      00033D 02 04 10         [24]  587 	ljmp	00102$
      000340                        588 00133$:
                                    589 ;	src/adc.c:25: eeprom_write(2*i,((uint16_t)((gradient*(float)(i)) + intercept)) & 0x00ff);
      000340 AC 39            [24]  590 	mov	r4,_adc_calibrate_LDR_i_65536_160
      000342 AD 3A            [24]  591 	mov	r5,(_adc_calibrate_LDR_i_65536_160 + 1)
      000344 EC               [12]  592 	mov	a,r4
      000345 2C               [12]  593 	add	a,r4
      000346 FC               [12]  594 	mov	r4,a
      000347 ED               [12]  595 	mov	a,r5
      000348 33               [12]  596 	rlc	a
      000349 FD               [12]  597 	mov	r5,a
      00034A 8C 02            [24]  598 	mov	ar2,r4
      00034C 8D 03            [24]  599 	mov	ar3,r5
      00034E 85 39 82         [24]  600 	mov	dpl,_adc_calibrate_LDR_i_65536_160
      000351 85 3A 83         [24]  601 	mov	dph,(_adc_calibrate_LDR_i_65536_160 + 1)
      000354 C0 05            [24]  602 	push	ar5
      000356 C0 04            [24]  603 	push	ar4
      000358 C0 03            [24]  604 	push	ar3
      00035A C0 02            [24]  605 	push	ar2
      00035C 12 1C DD         [24]  606 	lcall	___uint2fs
      00035F A8 82            [24]  607 	mov	r0,dpl
      000361 A9 83            [24]  608 	mov	r1,dph
      000363 AE F0            [24]  609 	mov	r6,b
      000365 FF               [12]  610 	mov	r7,a
      000366 C0 00            [24]  611 	push	ar0
      000368 C0 01            [24]  612 	push	ar1
      00036A C0 06            [24]  613 	push	ar6
      00036C C0 07            [24]  614 	push	ar7
      00036E 85 31 82         [24]  615 	mov	dpl,_adc_calibrate_LDR_gradient_65536_160
      000371 85 32 83         [24]  616 	mov	dph,(_adc_calibrate_LDR_gradient_65536_160 + 1)
      000374 85 33 F0         [24]  617 	mov	b,(_adc_calibrate_LDR_gradient_65536_160 + 2)
      000377 E5 34            [12]  618 	mov	a,(_adc_calibrate_LDR_gradient_65536_160 + 3)
      000379 12 1A F3         [24]  619 	lcall	___fsmul
      00037C A8 82            [24]  620 	mov	r0,dpl
      00037E A9 83            [24]  621 	mov	r1,dph
      000380 AE F0            [24]  622 	mov	r6,b
      000382 FF               [12]  623 	mov	r7,a
      000383 E5 81            [12]  624 	mov	a,sp
      000385 24 FC            [12]  625 	add	a,#0xfc
      000387 F5 81            [12]  626 	mov	sp,a
      000389 C0 35            [24]  627 	push	_adc_calibrate_LDR_intercept_65536_160
      00038B C0 36            [24]  628 	push	(_adc_calibrate_LDR_intercept_65536_160 + 1)
      00038D C0 37            [24]  629 	push	(_adc_calibrate_LDR_intercept_65536_160 + 2)
      00038F C0 38            [24]  630 	push	(_adc_calibrate_LDR_intercept_65536_160 + 3)
      000391 88 82            [24]  631 	mov	dpl,r0
      000393 89 83            [24]  632 	mov	dph,r1
      000395 8E F0            [24]  633 	mov	b,r6
      000397 EF               [12]  634 	mov	a,r7
      000398 12 1C 84         [24]  635 	lcall	___fsadd
      00039B A8 82            [24]  636 	mov	r0,dpl
      00039D A9 83            [24]  637 	mov	r1,dph
      00039F AE F0            [24]  638 	mov	r6,b
      0003A1 FF               [12]  639 	mov	r7,a
      0003A2 E5 81            [12]  640 	mov	a,sp
      0003A4 24 FC            [12]  641 	add	a,#0xfc
      0003A6 F5 81            [12]  642 	mov	sp,a
      0003A8 D0 02            [24]  643 	pop	ar2
      0003AA D0 03            [24]  644 	pop	ar3
      0003AC D0 04            [24]  645 	pop	ar4
      0003AE D0 05            [24]  646 	pop	ar5
      0003B0 88 82            [24]  647 	mov	dpl,r0
      0003B2 89 83            [24]  648 	mov	dph,r1
      0003B4 8E F0            [24]  649 	mov	b,r6
      0003B6 EF               [12]  650 	mov	a,r7
      0003B7 C0 07            [24]  651 	push	ar7
      0003B9 C0 06            [24]  652 	push	ar6
      0003BB C0 05            [24]  653 	push	ar5
      0003BD C0 04            [24]  654 	push	ar4
      0003BF C0 03            [24]  655 	push	ar3
      0003C1 C0 02            [24]  656 	push	ar2
      0003C3 C0 01            [24]  657 	push	ar1
      0003C5 C0 00            [24]  658 	push	ar0
      0003C7 12 1C E9         [24]  659 	lcall	___fs2uint
      0003CA 85 82 60         [24]  660 	mov	_eeprom_write_PARM_2,dpl
      0003CD D0 00            [24]  661 	pop	ar0
      0003CF D0 01            [24]  662 	pop	ar1
      0003D1 D0 02            [24]  663 	pop	ar2
      0003D3 D0 03            [24]  664 	pop	ar3
      0003D5 8A 82            [24]  665 	mov	dpl,r2
      0003D7 8B 83            [24]  666 	mov	dph,r3
      0003D9 C0 01            [24]  667 	push	ar1
      0003DB C0 00            [24]  668 	push	ar0
      0003DD 12 0B DD         [24]  669 	lcall	_eeprom_write
      0003E0 D0 00            [24]  670 	pop	ar0
      0003E2 D0 01            [24]  671 	pop	ar1
      0003E4 D0 04            [24]  672 	pop	ar4
      0003E6 D0 05            [24]  673 	pop	ar5
      0003E8 D0 06            [24]  674 	pop	ar6
      0003EA D0 07            [24]  675 	pop	ar7
                                    676 ;	src/adc.c:26: eeprom_write((2*i)+1,((uint16_t)((gradient*(float)(i)) + intercept)) >> 8);
      0003EC 0C               [12]  677 	inc	r4
      0003ED BC 00 01         [24]  678 	cjne	r4,#0x00,00134$
      0003F0 0D               [12]  679 	inc	r5
      0003F1                        680 00134$:
      0003F1 88 82            [24]  681 	mov	dpl,r0
      0003F3 89 83            [24]  682 	mov	dph,r1
      0003F5 8E F0            [24]  683 	mov	b,r6
      0003F7 EF               [12]  684 	mov	a,r7
      0003F8 C0 05            [24]  685 	push	ar5
      0003FA C0 04            [24]  686 	push	ar4
      0003FC 12 1C E9         [24]  687 	lcall	___fs2uint
      0003FF AF 83            [24]  688 	mov	r7,dph
      000401 D0 04            [24]  689 	pop	ar4
      000403 D0 05            [24]  690 	pop	ar5
      000405 8F 60            [24]  691 	mov	_eeprom_write_PARM_2,r7
      000407 8C 82            [24]  692 	mov	dpl,r4
      000409 8D 83            [24]  693 	mov	dph,r5
      00040B 12 0B DD         [24]  694 	lcall	_eeprom_write
                                    695 ;	src/adc.c:27: continue;
      00040E 80 63            [24]  696 	sjmp	00106$
      000410                        697 00102$:
                                    698 ;	src/adc.c:29: if(i < ldr_min){
      000410 C3               [12]  699 	clr	c
      000411 E5 39            [12]  700 	mov	a,_adc_calibrate_LDR_i_65536_160
      000413 95 2F            [12]  701 	subb	a,_adc_calibrate_LDR_ldr_min_65536_159
      000415 E5 3A            [12]  702 	mov	a,(_adc_calibrate_LDR_i_65536_160 + 1)
      000417 95 30            [12]  703 	subb	a,(_adc_calibrate_LDR_ldr_min_65536_159 + 1)
      000419 50 2D            [24]  704 	jnc	00105$
                                    705 ;	src/adc.c:30: eeprom_write((2*i),DISPLAY_COUNTS_MAX & 0x00ff);
      00041B A8 39            [24]  706 	mov	r0,_adc_calibrate_LDR_i_65536_160
      00041D A9 3A            [24]  707 	mov	r1,(_adc_calibrate_LDR_i_65536_160 + 1)
      00041F E8               [12]  708 	mov	a,r0
      000420 28               [12]  709 	add	a,r0
      000421 F8               [12]  710 	mov	r0,a
      000422 E9               [12]  711 	mov	a,r1
      000423 33               [12]  712 	rlc	a
      000424 F9               [12]  713 	mov	r1,a
      000425 88 82            [24]  714 	mov	dpl,r0
      000427 89 83            [24]  715 	mov	dph,r1
      000429 75 60 00         [24]  716 	mov	_eeprom_write_PARM_2,#0x00
      00042C C0 01            [24]  717 	push	ar1
      00042E C0 00            [24]  718 	push	ar0
      000430 12 0B DD         [24]  719 	lcall	_eeprom_write
      000433 D0 00            [24]  720 	pop	ar0
      000435 D0 01            [24]  721 	pop	ar1
                                    722 ;	src/adc.c:31: eeprom_write((2*i)+1,DISPLAY_COUNTS_MAX >> 8);
      000437 08               [12]  723 	inc	r0
      000438 B8 00 01         [24]  724 	cjne	r0,#0x00,00136$
      00043B 09               [12]  725 	inc	r1
      00043C                        726 00136$:
      00043C 88 82            [24]  727 	mov	dpl,r0
      00043E 89 83            [24]  728 	mov	dph,r1
      000440 75 60 EA         [24]  729 	mov	_eeprom_write_PARM_2,#0xea
      000443 12 0B DD         [24]  730 	lcall	_eeprom_write
                                    731 ;	src/adc.c:32: continue;
      000446 80 2B            [24]  732 	sjmp	00106$
      000448                        733 00105$:
                                    734 ;	src/adc.c:34: eeprom_write((2*i),DISPLAY_COUNTS_MIN & 0x00ff);
      000448 A8 39            [24]  735 	mov	r0,_adc_calibrate_LDR_i_65536_160
      00044A A9 3A            [24]  736 	mov	r1,(_adc_calibrate_LDR_i_65536_160 + 1)
      00044C E8               [12]  737 	mov	a,r0
      00044D 28               [12]  738 	add	a,r0
      00044E F8               [12]  739 	mov	r0,a
      00044F E9               [12]  740 	mov	a,r1
      000450 33               [12]  741 	rlc	a
      000451 F9               [12]  742 	mov	r1,a
      000452 88 82            [24]  743 	mov	dpl,r0
      000454 89 83            [24]  744 	mov	dph,r1
      000456 75 60 2C         [24]  745 	mov	_eeprom_write_PARM_2,#0x2c
      000459 C0 01            [24]  746 	push	ar1
      00045B C0 00            [24]  747 	push	ar0
      00045D 12 0B DD         [24]  748 	lcall	_eeprom_write
      000460 D0 00            [24]  749 	pop	ar0
      000462 D0 01            [24]  750 	pop	ar1
                                    751 ;	src/adc.c:35: eeprom_write((2*i)+1,DISPLAY_COUNTS_MIN >> 8);
      000464 08               [12]  752 	inc	r0
      000465 B8 00 01         [24]  753 	cjne	r0,#0x00,00137$
      000468 09               [12]  754 	inc	r1
      000469                        755 00137$:
      000469 88 82            [24]  756 	mov	dpl,r0
      00046B 89 83            [24]  757 	mov	dph,r1
      00046D 75 60 01         [24]  758 	mov	_eeprom_write_PARM_2,#0x01
      000470 12 0B DD         [24]  759 	lcall	_eeprom_write
      000473                        760 00106$:
                                    761 ;	src/adc.c:23: for(i=0;i<1024;i++){
      000473 05 39            [12]  762 	inc	_adc_calibrate_LDR_i_65536_160
      000475 E4               [12]  763 	clr	a
      000476 B5 39 02         [24]  764 	cjne	a,_adc_calibrate_LDR_i_65536_160,00138$
      000479 05 3A            [12]  765 	inc	(_adc_calibrate_LDR_i_65536_160 + 1)
      00047B                        766 00138$:
      00047B A8 39            [24]  767 	mov	r0,_adc_calibrate_LDR_i_65536_160
      00047D A9 3A            [24]  768 	mov	r1,(_adc_calibrate_LDR_i_65536_160 + 1)
      00047F 74 FC            [12]  769 	mov	a,#0x100 - 0x04
      000481 29               [12]  770 	add	a,r1
      000482 40 03            [24]  771 	jc	00139$
      000484 02 03 24         [24]  772 	ljmp	00108$
      000487                        773 00139$:
                                    774 ;	src/adc.c:37: eeprom_end();
                                    775 ;	src/adc.c:38: }
      000487 02 0C 09         [24]  776 	ljmp	_eeprom_end
                                    777 ;------------------------------------------------------------
                                    778 ;Allocation info for local variables in function 'ISR_ADC'
                                    779 ;------------------------------------------------------------
                                    780 ;display_counts_buffer     Allocated to registers r6 r7 
                                    781 ;------------------------------------------------------------
                                    782 ;	src/adc.c:57: void ISR_ADC(void) __interrupt(INT_ADC) __using(3) {
                                    783 ;	-----------------------------------------
                                    784 ;	 function ISR_ADC
                                    785 ;	-----------------------------------------
      00048A                        786 _ISR_ADC:
                           00001F   787 	ar7 = 0x1f
                           00001E   788 	ar6 = 0x1e
                           00001D   789 	ar5 = 0x1d
                           00001C   790 	ar4 = 0x1c
                           00001B   791 	ar3 = 0x1b
                           00001A   792 	ar2 = 0x1a
                           000019   793 	ar1 = 0x19
                           000018   794 	ar0 = 0x18
      00048A C0 20            [24]  795 	push	bits
      00048C C0 E0            [24]  796 	push	acc
      00048E C0 F0            [24]  797 	push	b
      000490 C0 82            [24]  798 	push	dpl
      000492 C0 83            [24]  799 	push	dph
      000494 C0 07            [24]  800 	push	(0+7)
      000496 C0 06            [24]  801 	push	(0+6)
      000498 C0 05            [24]  802 	push	(0+5)
      00049A C0 04            [24]  803 	push	(0+4)
      00049C C0 03            [24]  804 	push	(0+3)
      00049E C0 02            [24]  805 	push	(0+2)
      0004A0 C0 01            [24]  806 	push	(0+1)
      0004A2 C0 00            [24]  807 	push	(0+0)
      0004A4 C0 D0            [24]  808 	push	psw
      0004A6 75 D0 18         [24]  809 	mov	psw,#0x18
                                    810 ;	src/adc.c:59: ADC_CONTR ^= 0x10; //Clear the ADC flag
      0004A9 63 BC 10         [24]  811 	xrl	_ADC_CONTR,#0x10
                                    812 ;	src/adc.c:61: if(ADC_CONTR == ADC_SETUP_THERMISTOR){
      0004AC 74 E7            [12]  813 	mov	a,#0xe7
      0004AE B5 BC 09         [24]  814 	cjne	a,_ADC_CONTR,00104$
                                    815 ;	src/adc.c:62: adc_thermistor_reading = ADC_RES;
      0004B1 85 BE 2B         [24]  816 	mov	_adc_thermistor_reading,((_ADC_RES >> 0) & 0xFF)
      0004B4 85 BD 2C         [24]  817 	mov	(_adc_thermistor_reading + 1),((_ADC_RES >> 8) & 0xFF)
      0004B7 02 05 D2         [24]  818 	ljmp	00106$
      0004BA                        819 00104$:
                                    820 ;	src/adc.c:64: adc_ldr_reading = ADC_RES;
      0004BA 85 BE 29         [24]  821 	mov	_adc_ldr_reading,((_ADC_RES >> 0) & 0xFF)
      0004BD 85 BD 2A         [24]  822 	mov	(_adc_ldr_reading + 1),((_ADC_RES >> 8) & 0xFF)
                                    823 ;	src/adc.c:65: if(display_autobrightness) {
      0004C0 20 1F 03         [24]  824 	jb	_display_autobrightness,00118$
      0004C3 02 05 D2         [24]  825 	ljmp	00106$
      0004C6                        826 00118$:
                                    827 ;	src/adc.c:67: display_counts_buffer = (((float)EEPROM_PWM_FROM_LDR_TABLE[adc_ldr_reading]/100.0) + ((99.00) *((float)display_counts/100.0)));
      0004C6 E5 29            [12]  828 	mov	a,_adc_ldr_reading
      0004C8 25 E0            [12]  829 	add	a,acc
      0004CA FE               [12]  830 	mov	r6,a
      0004CB E5 2A            [12]  831 	mov	a,(_adc_ldr_reading + 1)
      0004CD 33               [12]  832 	rlc	a
      0004CE FF               [12]  833 	mov	r7,a
      0004CF 8E 82            [24]  834 	mov	dpl,r6
      0004D1 74 20            [12]  835 	mov	a,#(_EEPROM_PWM_FROM_LDR_TABLE >> 8)
      0004D3 2F               [12]  836 	add	a,r7
      0004D4 F5 83            [12]  837 	mov	dph,a
      0004D6 E4               [12]  838 	clr	a
      0004D7 93               [24]  839 	movc	a,@a+dptr
      0004D8 FE               [12]  840 	mov	r6,a
      0004D9 A3               [24]  841 	inc	dptr
      0004DA E4               [12]  842 	clr	a
      0004DB 93               [24]  843 	movc	a,@a+dptr
      0004DC FF               [12]  844 	mov	r7,a
      0004DD 8E 82            [24]  845 	mov	dpl,r6
      0004DF 8F 83            [24]  846 	mov	dph,r7
      0004E1 75 D0 00         [24]  847 	mov	psw,#0x00
      0004E4 12 1C DD         [24]  848 	lcall	___uint2fs
      0004E7 75 D0 18         [24]  849 	mov	psw,#0x18
      0004EA AC 82            [24]  850 	mov	r4,dpl
      0004EC AD 83            [24]  851 	mov	r5,dph
      0004EE AE F0            [24]  852 	mov	r6,b
      0004F0 FF               [12]  853 	mov	r7,a
      0004F1 E4               [12]  854 	clr	a
      0004F2 C0 E0            [24]  855 	push	acc
      0004F4 C0 E0            [24]  856 	push	acc
      0004F6 74 C8            [12]  857 	mov	a,#0xc8
      0004F8 C0 E0            [24]  858 	push	acc
      0004FA 74 42            [12]  859 	mov	a,#0x42
      0004FC C0 E0            [24]  860 	push	acc
      0004FE 8C 82            [24]  861 	mov	dpl,r4
      000500 8D 83            [24]  862 	mov	dph,r5
      000502 8E F0            [24]  863 	mov	b,r6
      000504 EF               [12]  864 	mov	a,r7
      000505 75 D0 00         [24]  865 	mov	psw,#0x00
      000508 12 1D 5D         [24]  866 	lcall	___fsdiv
      00050B 75 D0 18         [24]  867 	mov	psw,#0x18
      00050E AC 82            [24]  868 	mov	r4,dpl
      000510 AD 83            [24]  869 	mov	r5,dph
      000512 AE F0            [24]  870 	mov	r6,b
      000514 FF               [12]  871 	mov	r7,a
      000515 E5 81            [12]  872 	mov	a,sp
      000517 24 FC            [12]  873 	add	a,#0xfc
      000519 F5 81            [12]  874 	mov	sp,a
      00051B 85 48 82         [24]  875 	mov	dpl,_display_counts
      00051E 85 49 83         [24]  876 	mov	dph,(_display_counts + 1)
      000521 C0 1F            [24]  877 	push	ar7
      000523 C0 1E            [24]  878 	push	ar6
      000525 C0 1D            [24]  879 	push	ar5
      000527 C0 1C            [24]  880 	push	ar4
      000529 75 D0 00         [24]  881 	mov	psw,#0x00
      00052C 12 1C DD         [24]  882 	lcall	___uint2fs
      00052F 75 D0 18         [24]  883 	mov	psw,#0x18
      000532 A8 82            [24]  884 	mov	r0,dpl
      000534 A9 83            [24]  885 	mov	r1,dph
      000536 AA F0            [24]  886 	mov	r2,b
      000538 FB               [12]  887 	mov	r3,a
      000539 E4               [12]  888 	clr	a
      00053A C0 E0            [24]  889 	push	acc
      00053C C0 E0            [24]  890 	push	acc
      00053E 74 C8            [12]  891 	mov	a,#0xc8
      000540 C0 E0            [24]  892 	push	acc
      000542 74 42            [12]  893 	mov	a,#0x42
      000544 C0 E0            [24]  894 	push	acc
      000546 88 82            [24]  895 	mov	dpl,r0
      000548 89 83            [24]  896 	mov	dph,r1
      00054A 8A F0            [24]  897 	mov	b,r2
      00054C EB               [12]  898 	mov	a,r3
      00054D 75 D0 00         [24]  899 	mov	psw,#0x00
      000550 12 1D 5D         [24]  900 	lcall	___fsdiv
      000553 75 D0 18         [24]  901 	mov	psw,#0x18
      000556 A8 82            [24]  902 	mov	r0,dpl
      000558 A9 83            [24]  903 	mov	r1,dph
      00055A AA F0            [24]  904 	mov	r2,b
      00055C FB               [12]  905 	mov	r3,a
      00055D E5 81            [12]  906 	mov	a,sp
      00055F 24 FC            [12]  907 	add	a,#0xfc
      000561 F5 81            [12]  908 	mov	sp,a
      000563 C0 18            [24]  909 	push	ar0
      000565 C0 19            [24]  910 	push	ar1
      000567 C0 1A            [24]  911 	push	ar2
      000569 C0 1B            [24]  912 	push	ar3
      00056B 90 00 00         [24]  913 	mov	dptr,#0x0000
      00056E 75 F0 C6         [24]  914 	mov	b,#0xc6
      000571 74 42            [12]  915 	mov	a,#0x42
      000573 75 D0 00         [24]  916 	mov	psw,#0x00
      000576 12 1A F3         [24]  917 	lcall	___fsmul
      000579 75 D0 18         [24]  918 	mov	psw,#0x18
      00057C A8 82            [24]  919 	mov	r0,dpl
      00057E A9 83            [24]  920 	mov	r1,dph
      000580 AA F0            [24]  921 	mov	r2,b
      000582 FB               [12]  922 	mov	r3,a
      000583 E5 81            [12]  923 	mov	a,sp
      000585 24 FC            [12]  924 	add	a,#0xfc
      000587 F5 81            [12]  925 	mov	sp,a
      000589 D0 1C            [24]  926 	pop	ar4
      00058B D0 1D            [24]  927 	pop	ar5
      00058D D0 1E            [24]  928 	pop	ar6
      00058F D0 1F            [24]  929 	pop	ar7
      000591 C0 18            [24]  930 	push	ar0
      000593 C0 19            [24]  931 	push	ar1
      000595 C0 1A            [24]  932 	push	ar2
      000597 C0 1B            [24]  933 	push	ar3
      000599 8C 82            [24]  934 	mov	dpl,r4
      00059B 8D 83            [24]  935 	mov	dph,r5
      00059D 8E F0            [24]  936 	mov	b,r6
      00059F EF               [12]  937 	mov	a,r7
      0005A0 75 D0 00         [24]  938 	mov	psw,#0x00
      0005A3 12 1C 84         [24]  939 	lcall	___fsadd
      0005A6 75 D0 18         [24]  940 	mov	psw,#0x18
      0005A9 AC 82            [24]  941 	mov	r4,dpl
      0005AB AD 83            [24]  942 	mov	r5,dph
      0005AD AE F0            [24]  943 	mov	r6,b
      0005AF FF               [12]  944 	mov	r7,a
      0005B0 E5 81            [12]  945 	mov	a,sp
      0005B2 24 FC            [12]  946 	add	a,#0xfc
      0005B4 F5 81            [12]  947 	mov	sp,a
      0005B6 8C 82            [24]  948 	mov	dpl,r4
      0005B8 8D 83            [24]  949 	mov	dph,r5
      0005BA 8E F0            [24]  950 	mov	b,r6
      0005BC EF               [12]  951 	mov	a,r7
      0005BD 75 D0 00         [24]  952 	mov	psw,#0x00
      0005C0 12 1C E9         [24]  953 	lcall	___fs2uint
      0005C3 75 D0 18         [24]  954 	mov	psw,#0x18
      0005C6 AE 82            [24]  955 	mov	r6,dpl
      0005C8 AF 83            [24]  956 	mov	r7,dph
                                    957 ;	src/adc.c:68: INT_IP_PPCA = 0; //Block PCA interrupt from stacking on top of ADC ISR
                                    958 ;	assignBit
      0005CA C2 BF            [12]  959 	clr	_INT_IP_PPCA
                                    960 ;	src/adc.c:69: display_counts = display_counts_buffer;
      0005CC 8E 48            [24]  961 	mov	_display_counts,r6
      0005CE 8F 49            [24]  962 	mov	(_display_counts + 1),r7
                                    963 ;	src/adc.c:70: INT_IP_PPCA = 1; //Re-enable PCA interrupt high priority
                                    964 ;	assignBit
      0005D0 D2 BF            [12]  965 	setb	_INT_IP_PPCA
      0005D2                        966 00106$:
                                    967 ;	src/adc.c:73: }
      0005D2 D0 D0            [24]  968 	pop	psw
      0005D4 D0 00            [24]  969 	pop	(0+0)
      0005D6 D0 01            [24]  970 	pop	(0+1)
      0005D8 D0 02            [24]  971 	pop	(0+2)
      0005DA D0 03            [24]  972 	pop	(0+3)
      0005DC D0 04            [24]  973 	pop	(0+4)
      0005DE D0 05            [24]  974 	pop	(0+5)
      0005E0 D0 06            [24]  975 	pop	(0+6)
      0005E2 D0 07            [24]  976 	pop	(0+7)
      0005E4 D0 83            [24]  977 	pop	dph
      0005E6 D0 82            [24]  978 	pop	dpl
      0005E8 D0 F0            [24]  979 	pop	b
      0005EA D0 E0            [24]  980 	pop	acc
      0005EC D0 20            [24]  981 	pop	bits
      0005EE 32               [24]  982 	reti
                                    983 	.area CSEG    (CODE)
                                    984 	.area CONST   (CODE)
                                    985 	.area XINIT   (CODE)
                                    986 	.area CABS    (ABS,CODE)
