                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module fsm
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _fsm_transition_table_s
                                     12 	.globl _fsm_transition_table_fp
                                     13 	.globl _centiseconds
                                     14 	.globl _adc_calibrate_LDR
                                     15 	.globl _button_read_and_clear_select
                                     16 	.globl _button_read_and_clear_menu
                                     17 	.globl _display_puttemp
                                     18 	.globl _display_putbool
                                     19 	.globl _display_putdate
                                     20 	.globl _display_puttime
                                     21 	.globl _display_putbcd
                                     22 	.globl _display_puts
                                     23 	.globl _ds1302_calculate_CRC
                                     24 	.globl _bcd_add_16
                                     25 	.globl _bcd_add
                                     26 	.globl _ds1302_write_SRAM
                                     27 	.globl _ds1302_set_time
                                     28 	.globl _ds1302_start
                                     29 	.globl _UART_SM0
                                     30 	.globl _UART_SM1
                                     31 	.globl _UART_SM2
                                     32 	.globl _UART_REN
                                     33 	.globl _UART_TB8
                                     34 	.globl _UART_RB8
                                     35 	.globl _UART_TI
                                     36 	.globl _UART_RI
                                     37 	.globl _PCA_CF
                                     38 	.globl _PCA_CR
                                     39 	.globl _PCA_CCF2
                                     40 	.globl _PCA_CCF1
                                     41 	.globl _PCA_CCF0
                                     42 	.globl _TMR_TCON_TF1
                                     43 	.globl _TMR_TCON_TR1
                                     44 	.globl _TMR_TCON_TF0
                                     45 	.globl _TMR_TCON_TR0
                                     46 	.globl _TMR_TCON_IE1
                                     47 	.globl _TMR_TCON_IT1
                                     48 	.globl _TMR_TCON_IE0
                                     49 	.globl _TMR_TCON_IT0
                                     50 	.globl _INT_IP_PPCA
                                     51 	.globl _INT_IP_PLVD
                                     52 	.globl _INT_IP_PADC
                                     53 	.globl _INT_IP_PS
                                     54 	.globl _INT_IP_PT1
                                     55 	.globl _INT_IP_PX1
                                     56 	.globl _INT_IP_PT0
                                     57 	.globl _INT_IP_PX0
                                     58 	.globl _INT_IE_EA
                                     59 	.globl _INT_IE_ELVD
                                     60 	.globl _INT_IE_EADC
                                     61 	.globl _INT_IE_ES
                                     62 	.globl _INT_IE_ET1
                                     63 	.globl _INT_IE_EX1
                                     64 	.globl _INT_IE_ET0
                                     65 	.globl _INT_IE_EX0
                                     66 	.globl _PORT_P5_7
                                     67 	.globl _PORT_P5_6
                                     68 	.globl _PORT_P5_5
                                     69 	.globl _PORT_P5_4
                                     70 	.globl _PORT_P5_3
                                     71 	.globl _PORT_P5_2
                                     72 	.globl _PORT_P5_1
                                     73 	.globl _PORT_P5_0
                                     74 	.globl _PORT_P4_7
                                     75 	.globl _PORT_P4_6
                                     76 	.globl _PORT_P4_5
                                     77 	.globl _PORT_P4_4
                                     78 	.globl _PORT_P4_3
                                     79 	.globl _PORT_P4_2
                                     80 	.globl _PORT_P4_1
                                     81 	.globl _PORT_P4_0
                                     82 	.globl _PORT_P3_7
                                     83 	.globl _PORT_P3_6
                                     84 	.globl _PORT_P3_5
                                     85 	.globl _PORT_P3_4
                                     86 	.globl _PORT_P3_3
                                     87 	.globl _PORT_P3_2
                                     88 	.globl _PORT_P3_1
                                     89 	.globl _PORT_P3_0
                                     90 	.globl _PORT_P2_7
                                     91 	.globl _PORT_P2_6
                                     92 	.globl _PORT_P2_5
                                     93 	.globl _PORT_P2_4
                                     94 	.globl _PORT_P2_3
                                     95 	.globl _PORT_P2_2
                                     96 	.globl _PORT_P2_1
                                     97 	.globl _PORT_P2_0
                                     98 	.globl _PORT_P1_7
                                     99 	.globl _PORT_P1_6
                                    100 	.globl _PORT_P1_5
                                    101 	.globl _PORT_P1_4
                                    102 	.globl _PORT_P1_3
                                    103 	.globl _PORT_P1_2
                                    104 	.globl _PORT_P1_1
                                    105 	.globl _PORT_P1_0
                                    106 	.globl _CY
                                    107 	.globl _AC
                                    108 	.globl _F0
                                    109 	.globl _RS1
                                    110 	.globl _RS0
                                    111 	.globl _OV
                                    112 	.globl _F1
                                    113 	.globl _P
                                    114 	.globl _IAP_CONTR
                                    115 	.globl _IAP_TRIG
                                    116 	.globl _IAP_CMD
                                    117 	.globl _IAP_ADDR
                                    118 	.globl _IAP_ADDRL
                                    119 	.globl _IAP_ADDRH
                                    120 	.globl _IAP_DATA
                                    121 	.globl _UART_SADEN
                                    122 	.globl _UART_SADDR
                                    123 	.globl _UART_SBUF
                                    124 	.globl _UART_SCON
                                    125 	.globl _PCA_CMOD
                                    126 	.globl _PCA_CCON
                                    127 	.globl _PCA_PWM2
                                    128 	.globl _PCA_PWM1
                                    129 	.globl _PCA_PWM0
                                    130 	.globl _PCA_C
                                    131 	.globl _PCA_CCAP2_L
                                    132 	.globl _PCA_CCAP2_H
                                    133 	.globl _PCA_CCAP1_L
                                    134 	.globl _PCA_CCAP1_H
                                    135 	.globl _PCA_CCAP0_L
                                    136 	.globl _PCA_CCAP0_H
                                    137 	.globl _PCA_CCAP2
                                    138 	.globl _PCA_CCAP1
                                    139 	.globl _PCA_CCAP0
                                    140 	.globl _PCA_CCAPM2
                                    141 	.globl _PCA_CCAPM1
                                    142 	.globl _PCA_CCAPM0
                                    143 	.globl _CMP_CR2
                                    144 	.globl _CMP_CR1
                                    145 	.globl _ADC_RESL
                                    146 	.globl _ADC_RESH
                                    147 	.globl _ADC_RES
                                    148 	.globl _ADC_CONTR
                                    149 	.globl _ADC_P1ASF
                                    150 	.globl _EEPROM_CONTR
                                    151 	.globl _EEPROM_TRIG
                                    152 	.globl _EEPROM_CMD
                                    153 	.globl _EEPROM_ADDR
                                    154 	.globl _EEPROM_DATA
                                    155 	.globl _TMR_T2
                                    156 	.globl _TMR_T0
                                    157 	.globl _TMR_TMOD
                                    158 	.globl _TMR_TCON
                                    159 	.globl _INT_IP2
                                    160 	.globl _INT_IP
                                    161 	.globl _INT_IE2
                                    162 	.globl _INT_IE
                                    163 	.globl _PORT_P5M0
                                    164 	.globl _PORT_P5M1
                                    165 	.globl _PORT_P4M0
                                    166 	.globl _PORT_P4M1
                                    167 	.globl _PORT_P3M0
                                    168 	.globl _PORT_P3M1
                                    169 	.globl _PORT_P2M0
                                    170 	.globl _PORT_P2M1
                                    171 	.globl _PORT_P1M0
                                    172 	.globl _PORT_P1M1
                                    173 	.globl _PORT_P5
                                    174 	.globl _PORT_P4
                                    175 	.globl _PORT_P3
                                    176 	.globl _PORT_P2
                                    177 	.globl _PORT_P1
                                    178 	.globl _PSW
                                    179 	.globl _PCON2
                                    180 	.globl _AUXR2
                                    181 	.globl _AUXR1
                                    182 	.globl _AUXR
                                    183 	.globl _PCON
                                    184 	.globl _DPTR
                                    185 	.globl _SP
                                    186 	.globl _alarms
                                    187 	.globl _fsm_home_auto
                                    188 	.globl _BUTTON_DATA_SELECT_HELD_DOWN
                                    189 	.globl _BUTTON_DATA_SELECT_RELEASED_LONGP
                                    190 	.globl _BUTTON_DATA_SELECT_RELEASED_NORMAL
                                    191 	.globl _BUTTON_DATA_SELECT_PRESSED
                                    192 	.globl _BUTTON_DATA_MENU_HELD_DOWN
                                    193 	.globl _BUTTON_DATA_MENU_RELEASED_LONGP
                                    194 	.globl _BUTTON_DATA_MENU_RELEASED_NORMAL
                                    195 	.globl _BUTTON_DATA_MENU_PRESSED
                                    196 	.globl _display_autobrightness
                                    197 	.globl _DS1302_DATA_7
                                    198 	.globl _DS1302_DATA_6
                                    199 	.globl _DS1302_DATA_5
                                    200 	.globl _DS1302_DATA_4
                                    201 	.globl _DS1302_DATA_3
                                    202 	.globl _DS1302_DATA_2
                                    203 	.globl _DS1302_DATA_1
                                    204 	.globl _DS1302_DATA_0
                                    205 	.globl _transition_ticks
                                    206 	.globl _alarm_lastpoll
                                    207 	.globl _BUTTON_DATA
                                    208 	.globl _DS1302_DATA
                                    209 	.globl _fsm_home_fn
                                    210 	.globl _fsm_set_fn
                                    211 	.globl _fsm_alarm_fn
                                    212 	.globl _fsm_config_fn
                                    213 ;--------------------------------------------------------
                                    214 ; special function registers
                                    215 ;--------------------------------------------------------
                                    216 	.area RSEG    (ABS,DATA)
      000000                        217 	.org 0x0000
                           000081   218 _SP	=	0x0081
                           008382   219 _DPTR	=	0x8382
                           000087   220 _PCON	=	0x0087
                           00008E   221 _AUXR	=	0x008e
                           0000A2   222 _AUXR1	=	0x00a2
                           00008F   223 _AUXR2	=	0x008f
                           000097   224 _PCON2	=	0x0097
                           0000D0   225 _PSW	=	0x00d0
                           000090   226 _PORT_P1	=	0x0090
                           0000A0   227 _PORT_P2	=	0x00a0
                           0000B0   228 _PORT_P3	=	0x00b0
                           0000C0   229 _PORT_P4	=	0x00c0
                           0000C8   230 _PORT_P5	=	0x00c8
                           000091   231 _PORT_P1M1	=	0x0091
                           000092   232 _PORT_P1M0	=	0x0092
                           000095   233 _PORT_P2M1	=	0x0095
                           000096   234 _PORT_P2M0	=	0x0096
                           0000B1   235 _PORT_P3M1	=	0x00b1
                           0000B2   236 _PORT_P3M0	=	0x00b2
                           0000B3   237 _PORT_P4M1	=	0x00b3
                           0000B4   238 _PORT_P4M0	=	0x00b4
                           0000C9   239 _PORT_P5M1	=	0x00c9
                           0000CA   240 _PORT_P5M0	=	0x00ca
                           0000A8   241 _INT_IE	=	0x00a8
                           0000AF   242 _INT_IE2	=	0x00af
                           0000B8   243 _INT_IP	=	0x00b8
                           0000B5   244 _INT_IP2	=	0x00b5
                           000088   245 _TMR_TCON	=	0x0088
                           000089   246 _TMR_TMOD	=	0x0089
                           008C8A   247 _TMR_T0	=	0x8c8a
                           00D6D7   248 _TMR_T2	=	0xd6d7
                           0000C2   249 _EEPROM_DATA	=	0x00c2
                           00C3C4   250 _EEPROM_ADDR	=	0xc3c4
                           0000C5   251 _EEPROM_CMD	=	0x00c5
                           0000C6   252 _EEPROM_TRIG	=	0x00c6
                           0000C7   253 _EEPROM_CONTR	=	0x00c7
                           00009D   254 _ADC_P1ASF	=	0x009d
                           0000BC   255 _ADC_CONTR	=	0x00bc
                           00BDBE   256 _ADC_RES	=	0xbdbe
                           0000BD   257 _ADC_RESH	=	0x00bd
                           0000BE   258 _ADC_RESL	=	0x00be
                           0000E6   259 _CMP_CR1	=	0x00e6
                           0000E7   260 _CMP_CR2	=	0x00e7
                           0000DA   261 _PCA_CCAPM0	=	0x00da
                           0000DB   262 _PCA_CCAPM1	=	0x00db
                           0000DC   263 _PCA_CCAPM2	=	0x00dc
                           00FAEA   264 _PCA_CCAP0	=	0xfaea
                           00FBEB   265 _PCA_CCAP1	=	0xfbeb
                           00FCEC   266 _PCA_CCAP2	=	0xfcec
                           0000FA   267 _PCA_CCAP0_H	=	0x00fa
                           0000EA   268 _PCA_CCAP0_L	=	0x00ea
                           0000FB   269 _PCA_CCAP1_H	=	0x00fb
                           0000EB   270 _PCA_CCAP1_L	=	0x00eb
                           0000FC   271 _PCA_CCAP2_H	=	0x00fc
                           0000EC   272 _PCA_CCAP2_L	=	0x00ec
                           00F9E9   273 _PCA_C	=	0xf9e9
                           0000F2   274 _PCA_PWM0	=	0x00f2
                           0000F3   275 _PCA_PWM1	=	0x00f3
                           0000F4   276 _PCA_PWM2	=	0x00f4
                           0000D8   277 _PCA_CCON	=	0x00d8
                           0000D9   278 _PCA_CMOD	=	0x00d9
                           000098   279 _UART_SCON	=	0x0098
                           000099   280 _UART_SBUF	=	0x0099
                           0000A9   281 _UART_SADDR	=	0x00a9
                           0000B9   282 _UART_SADEN	=	0x00b9
                           0000C2   283 _IAP_DATA	=	0x00c2
                           0000C3   284 _IAP_ADDRH	=	0x00c3
                           0000C4   285 _IAP_ADDRL	=	0x00c4
                           00C3C4   286 _IAP_ADDR	=	0xc3c4
                           0000C5   287 _IAP_CMD	=	0x00c5
                           0000C6   288 _IAP_TRIG	=	0x00c6
                           0000C7   289 _IAP_CONTR	=	0x00c7
                                    290 ;--------------------------------------------------------
                                    291 ; special function bits
                                    292 ;--------------------------------------------------------
                                    293 	.area RSEG    (ABS,DATA)
      000000                        294 	.org 0x0000
                           0000D0   295 _P	=	0x00d0
                           0000D1   296 _F1	=	0x00d1
                           0000D2   297 _OV	=	0x00d2
                           0000D3   298 _RS0	=	0x00d3
                           0000D4   299 _RS1	=	0x00d4
                           0000D5   300 _F0	=	0x00d5
                           0000D6   301 _AC	=	0x00d6
                           0000D7   302 _CY	=	0x00d7
                           000090   303 _PORT_P1_0	=	0x0090
                           000091   304 _PORT_P1_1	=	0x0091
                           000092   305 _PORT_P1_2	=	0x0092
                           000093   306 _PORT_P1_3	=	0x0093
                           000094   307 _PORT_P1_4	=	0x0094
                           000095   308 _PORT_P1_5	=	0x0095
                           000096   309 _PORT_P1_6	=	0x0096
                           000097   310 _PORT_P1_7	=	0x0097
                           0000A0   311 _PORT_P2_0	=	0x00a0
                           0000A1   312 _PORT_P2_1	=	0x00a1
                           0000A2   313 _PORT_P2_2	=	0x00a2
                           0000A3   314 _PORT_P2_3	=	0x00a3
                           0000A4   315 _PORT_P2_4	=	0x00a4
                           0000A5   316 _PORT_P2_5	=	0x00a5
                           0000A6   317 _PORT_P2_6	=	0x00a6
                           0000A7   318 _PORT_P2_7	=	0x00a7
                           0000B0   319 _PORT_P3_0	=	0x00b0
                           0000B1   320 _PORT_P3_1	=	0x00b1
                           0000B2   321 _PORT_P3_2	=	0x00b2
                           0000B3   322 _PORT_P3_3	=	0x00b3
                           0000B4   323 _PORT_P3_4	=	0x00b4
                           0000B5   324 _PORT_P3_5	=	0x00b5
                           0000B6   325 _PORT_P3_6	=	0x00b6
                           0000B7   326 _PORT_P3_7	=	0x00b7
                           0000C0   327 _PORT_P4_0	=	0x00c0
                           0000C1   328 _PORT_P4_1	=	0x00c1
                           0000C2   329 _PORT_P4_2	=	0x00c2
                           0000C3   330 _PORT_P4_3	=	0x00c3
                           0000C4   331 _PORT_P4_4	=	0x00c4
                           0000C5   332 _PORT_P4_5	=	0x00c5
                           0000C6   333 _PORT_P4_6	=	0x00c6
                           0000C7   334 _PORT_P4_7	=	0x00c7
                           0000C8   335 _PORT_P5_0	=	0x00c8
                           0000C9   336 _PORT_P5_1	=	0x00c9
                           0000CA   337 _PORT_P5_2	=	0x00ca
                           0000CB   338 _PORT_P5_3	=	0x00cb
                           0000CC   339 _PORT_P5_4	=	0x00cc
                           0000CD   340 _PORT_P5_5	=	0x00cd
                           0000CE   341 _PORT_P5_6	=	0x00ce
                           0000CF   342 _PORT_P5_7	=	0x00cf
                           0000A8   343 _INT_IE_EX0	=	0x00a8
                           0000A9   344 _INT_IE_ET0	=	0x00a9
                           0000AA   345 _INT_IE_EX1	=	0x00aa
                           0000AB   346 _INT_IE_ET1	=	0x00ab
                           0000AC   347 _INT_IE_ES	=	0x00ac
                           0000AD   348 _INT_IE_EADC	=	0x00ad
                           0000AE   349 _INT_IE_ELVD	=	0x00ae
                           0000AF   350 _INT_IE_EA	=	0x00af
                           0000B8   351 _INT_IP_PX0	=	0x00b8
                           0000B9   352 _INT_IP_PT0	=	0x00b9
                           0000BA   353 _INT_IP_PX1	=	0x00ba
                           0000BB   354 _INT_IP_PT1	=	0x00bb
                           0000BC   355 _INT_IP_PS	=	0x00bc
                           0000BD   356 _INT_IP_PADC	=	0x00bd
                           0000BE   357 _INT_IP_PLVD	=	0x00be
                           0000BF   358 _INT_IP_PPCA	=	0x00bf
                           000088   359 _TMR_TCON_IT0	=	0x0088
                           000089   360 _TMR_TCON_IE0	=	0x0089
                           00008A   361 _TMR_TCON_IT1	=	0x008a
                           00008B   362 _TMR_TCON_IE1	=	0x008b
                           00008C   363 _TMR_TCON_TR0	=	0x008c
                           00008D   364 _TMR_TCON_TF0	=	0x008d
                           00008E   365 _TMR_TCON_TR1	=	0x008e
                           00008F   366 _TMR_TCON_TF1	=	0x008f
                           0000D8   367 _PCA_CCF0	=	0x00d8
                           0000D9   368 _PCA_CCF1	=	0x00d9
                           0000DA   369 _PCA_CCF2	=	0x00da
                           0000DE   370 _PCA_CR	=	0x00de
                           0000DF   371 _PCA_CF	=	0x00df
                           000098   372 _UART_RI	=	0x0098
                           000099   373 _UART_TI	=	0x0099
                           00009A   374 _UART_RB8	=	0x009a
                           00009B   375 _UART_TB8	=	0x009b
                           00009C   376 _UART_REN	=	0x009c
                           00009D   377 _UART_SM2	=	0x009d
                           00009E   378 _UART_SM1	=	0x009e
                           00009F   379 _UART_SM0	=	0x009f
                                    380 ;--------------------------------------------------------
                                    381 ; overlayable register banks
                                    382 ;--------------------------------------------------------
                                    383 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        384 	.ds 8
                                    385 ;--------------------------------------------------------
                                    386 ; internal ram data
                                    387 ;--------------------------------------------------------
                                    388 	.area DSEG    (DATA)
                           000021   389 _DS1302_DATA	=	0x0021
                           000022   390 _BUTTON_DATA	=	0x0022
      000054                        391 _alarm_lastpoll::
      000054                        392 	.ds 1
      000055                        393 _transition_ticks::
      000055                        394 	.ds 2
      000057                        395 _fsm_home_fn_curstate_65536_174:
      000057                        396 	.ds 1
      000058                        397 _fsm_set_fn_curstate_65536_250:
      000058                        398 	.ds 1
      000059                        399 _fsm_alarm_fn_curstate_65536_262:
      000059                        400 	.ds 1
      00005A                        401 _fsm_alarm_fn_sub_curstate_65536_262:
      00005A                        402 	.ds 1
      00005B                        403 _fsm_config_fn_curstate_65536_308:
      00005B                        404 	.ds 1
      00005C                        405 _fsm_config_fn_config_tmp_65536_308:
      00005C                        406 	.ds 2
                                    407 ;--------------------------------------------------------
                                    408 ; overlayable items in internal ram
                                    409 ;--------------------------------------------------------
                                    410 ;--------------------------------------------------------
                                    411 ; indirectly addressable internal ram data
                                    412 ;--------------------------------------------------------
                                    413 	.area ISEG    (DATA)
                                    414 ;--------------------------------------------------------
                                    415 ; absolute internal ram data
                                    416 ;--------------------------------------------------------
                                    417 	.area IABS    (ABS,DATA)
                                    418 	.area IABS    (ABS,DATA)
                                    419 ;--------------------------------------------------------
                                    420 ; bit data
                                    421 ;--------------------------------------------------------
                                    422 	.area BSEG    (BIT)
                           000008   423 _DS1302_DATA_0	=	0x0008
                           000009   424 _DS1302_DATA_1	=	0x0009
                           00000A   425 _DS1302_DATA_2	=	0x000a
                           00000B   426 _DS1302_DATA_3	=	0x000b
                           00000C   427 _DS1302_DATA_4	=	0x000c
                           00000D   428 _DS1302_DATA_5	=	0x000d
                           00000E   429 _DS1302_DATA_6	=	0x000e
                           00000F   430 _DS1302_DATA_7	=	0x000f
                           00001F   431 _display_autobrightness	=	0x001f
                           000010   432 _BUTTON_DATA_MENU_PRESSED	=	0x0010
                           000011   433 _BUTTON_DATA_MENU_RELEASED_NORMAL	=	0x0011
                           000012   434 _BUTTON_DATA_MENU_RELEASED_LONGP	=	0x0012
                           000013   435 _BUTTON_DATA_MENU_HELD_DOWN	=	0x0013
                           000014   436 _BUTTON_DATA_SELECT_PRESSED	=	0x0014
                           000015   437 _BUTTON_DATA_SELECT_RELEASED_NORMAL	=	0x0015
                           000016   438 _BUTTON_DATA_SELECT_RELEASED_LONGP	=	0x0016
                           000017   439 _BUTTON_DATA_SELECT_HELD_DOWN	=	0x0017
                           00001E   440 _fsm_home_auto	=	0x001e
                                    441 ;--------------------------------------------------------
                                    442 ; paged external ram data
                                    443 ;--------------------------------------------------------
                                    444 	.area PSEG    (PAG,XDATA)
                                    445 ;--------------------------------------------------------
                                    446 ; external ram data
                                    447 ;--------------------------------------------------------
                                    448 	.area XSEG    (XDATA)
                           000004   449 _alarms	=	0x0004
                                    450 ;--------------------------------------------------------
                                    451 ; absolute external ram data
                                    452 ;--------------------------------------------------------
                                    453 	.area XABS    (ABS,XDATA)
                                    454 ;--------------------------------------------------------
                                    455 ; external initialized ram data
                                    456 ;--------------------------------------------------------
                                    457 	.area XISEG   (XDATA)
                                    458 	.area HOME    (CODE)
                                    459 	.area GSINIT0 (CODE)
                                    460 	.area GSINIT1 (CODE)
                                    461 	.area GSINIT2 (CODE)
                                    462 	.area GSINIT3 (CODE)
                                    463 	.area GSINIT4 (CODE)
                                    464 	.area GSINIT5 (CODE)
                                    465 	.area GSINIT  (CODE)
                                    466 	.area GSFINAL (CODE)
                                    467 	.area CSEG    (CODE)
                                    468 ;--------------------------------------------------------
                                    469 ; global & static initialisations
                                    470 ;--------------------------------------------------------
                                    471 	.area HOME    (CODE)
                                    472 	.area GSINIT  (CODE)
                                    473 	.area GSFINAL (CODE)
                                    474 	.area GSINIT  (CODE)
                                    475 ;------------------------------------------------------------
                                    476 ;Allocation info for local variables in function 'fsm_home_fn'
                                    477 ;------------------------------------------------------------
                                    478 ;__1310720038              Allocated to registers 
                                    479 ;alarm_index               Allocated to registers r5 
                                    480 ;temp_cache                Allocated to registers r6 r7 
                                    481 ;menu_state                Allocated to registers r7 
                                    482 ;select_state              Allocated to registers r6 
                                    483 ;__1310720021              Allocated to registers 
                                    484 ;__1310720019              Allocated to registers 
                                    485 ;__1310720017              Allocated to registers 
                                    486 ;__1310720015              Allocated to registers 
                                    487 ;__1310720013              Allocated to registers 
                                    488 ;__1310720011              Allocated to registers r5 
                                    489 ;__1310720009              Allocated to registers 
                                    490 ;__3276800040              Allocated to registers 
                                    491 ;__3276800041              Allocated to registers 
                                    492 ;__3276800042              Allocated with name '(_ds1302 + 0x0005)'
                                    493 ;index                     Allocated to registers 
                                    494 ;dow                       Allocated to registers 
                                    495 ;__1966080048              Allocated to registers 
                                    496 ;tmp                       Allocated to registers r6 r7 
                                    497 ;curstate                  Allocated with name '_fsm_home_fn_curstate_65536_174'
                                    498 ;------------------------------------------------------------
                                    499 ;	src/fsm.c:15: static enum fsm_states_home curstate = fsm_home_start;
      0000E2 75 57 00         [24]  500 	mov	_fsm_home_fn_curstate_65536_174,#0x00
                                    501 ;------------------------------------------------------------
                                    502 ;Allocation info for local variables in function 'fsm_set_fn'
                                    503 ;------------------------------------------------------------
                                    504 ;fsm_set_temp              Allocated to registers r5 
                                    505 ;menu_state                Allocated to registers r7 
                                    506 ;select_state              Allocated to registers r6 
                                    507 ;curstate                  Allocated with name '_fsm_set_fn_curstate_65536_250'
                                    508 ;------------------------------------------------------------
                                    509 ;	src/fsm.c:167: static enum fsm_states_set curstate = fsm_set_label; //Default display hhmm
      0000E5 75 58 00         [24]  510 	mov	_fsm_set_fn_curstate_65536_250,#0x00
                                    511 ;------------------------------------------------------------
                                    512 ;Allocation info for local variables in function 'fsm_alarm_fn'
                                    513 ;------------------------------------------------------------
                                    514 ;alarm_temp                Allocated to registers r5 
                                    515 ;menu_state                Allocated to registers r7 
                                    516 ;select_state              Allocated to registers r6 
                                    517 ;__1966080053              Allocated to registers 
                                    518 ;__2621440058              Allocated to registers 
                                    519 ;__2621440059              Allocated to registers r4 
                                    520 ;__2621440060              Allocated to registers r6 
                                    521 ;index                     Allocated to registers 
                                    522 ;dow                       Allocated to registers 
                                    523 ;__2621440064              Allocated to registers r5 
                                    524 ;__2621440065              Allocated to registers r6 
                                    525 ;index                     Allocated to registers 
                                    526 ;dow                       Allocated to registers 
                                    527 ;curstate                  Allocated with name '_fsm_alarm_fn_curstate_65536_262'
                                    528 ;sub_curstate              Allocated with name '_fsm_alarm_fn_sub_curstate_65536_262'
                                    529 ;------------------------------------------------------------
                                    530 ;	src/fsm.c:263: static enum fsm_states_alarm curstate = fsm_alarm_label;
      0000E8 75 59 00         [24]  531 	mov	_fsm_alarm_fn_curstate_65536_262,#0x00
                                    532 ;	src/fsm.c:264: static enum fsm_substates_alarm sub_curstate = fsm_alarm_substate_toggle;
      0000EB 75 5A 00         [24]  533 	mov	_fsm_alarm_fn_sub_curstate_65536_262,#0x00
                                    534 ;------------------------------------------------------------
                                    535 ;Allocation info for local variables in function 'fsm_config_fn'
                                    536 ;------------------------------------------------------------
                                    537 ;config_tmp2               Allocated to registers r4 r5 
                                    538 ;menu_state                Allocated to registers r7 
                                    539 ;select_state              Allocated to registers r6 
                                    540 ;__1966080071              Allocated to registers 
                                    541 ;__3276800067              Allocated to registers 
                                    542 ;tmp                       Allocated to registers r4 r5 
                                    543 ;__3276800069              Allocated to registers 
                                    544 ;tmp                       Allocated to registers r4 r5 
                                    545 ;tmp                       Allocated to registers r4 r5 
                                    546 ;curstate                  Allocated with name '_fsm_config_fn_curstate_65536_308'
                                    547 ;config_tmp                Allocated with name '_fsm_config_fn_config_tmp_65536_308'
                                    548 ;------------------------------------------------------------
                                    549 ;	src/fsm.c:397: static enum fsm_states_config curstate = fsm_config_label;
      0000EE 75 5B 00         [24]  550 	mov	_fsm_config_fn_curstate_65536_308,#0x00
                                    551 ;	src/fsm.c:11: uint8_t alarm_lastpoll = 0;					  ///< Time alarm was last polled (minutes)
      0000F1 75 54 00         [24]  552 	mov	_alarm_lastpoll,#0x00
                                    553 ;	src/fsm.c:12: uint16_t transition_ticks = 0;				  ///< 10ms timer ticks at last transition
      0000F4 E4               [12]  554 	clr	a
      0000F5 F5 55            [12]  555 	mov	_transition_ticks,a
      0000F7 F5 56            [12]  556 	mov	(_transition_ticks + 1),a
                                    557 ;--------------------------------------------------------
                                    558 ; Home
                                    559 ;--------------------------------------------------------
                                    560 	.area HOME    (CODE)
                                    561 	.area HOME    (CODE)
                                    562 ;--------------------------------------------------------
                                    563 ; code
                                    564 ;--------------------------------------------------------
                                    565 	.area CSEG    (CODE)
                                    566 ;------------------------------------------------------------
                                    567 ;Allocation info for local variables in function 'fsm_home_fn'
                                    568 ;------------------------------------------------------------
                                    569 ;__1310720038              Allocated to registers 
                                    570 ;alarm_index               Allocated to registers r5 
                                    571 ;temp_cache                Allocated to registers r6 r7 
                                    572 ;menu_state                Allocated to registers r7 
                                    573 ;select_state              Allocated to registers r6 
                                    574 ;__1310720021              Allocated to registers 
                                    575 ;__1310720019              Allocated to registers 
                                    576 ;__1310720017              Allocated to registers 
                                    577 ;__1310720015              Allocated to registers 
                                    578 ;__1310720013              Allocated to registers 
                                    579 ;__1310720011              Allocated to registers r5 
                                    580 ;__1310720009              Allocated to registers 
                                    581 ;__3276800040              Allocated to registers 
                                    582 ;__3276800041              Allocated to registers 
                                    583 ;__3276800042              Allocated with name '(_ds1302 + 0x0005)'
                                    584 ;index                     Allocated to registers 
                                    585 ;dow                       Allocated to registers 
                                    586 ;__1966080048              Allocated to registers 
                                    587 ;tmp                       Allocated to registers r6 r7 
                                    588 ;curstate                  Allocated with name '_fsm_home_fn_curstate_65536_174'
                                    589 ;------------------------------------------------------------
                                    590 ;	src/fsm.c:14: enum fsm_return fsm_home_fn() __reentrant {
                                    591 ;	-----------------------------------------
                                    592 ;	 function fsm_home_fn
                                    593 ;	-----------------------------------------
      000C0D                        594 _fsm_home_fn:
                           000007   595 	ar7 = 0x07
                           000006   596 	ar6 = 0x06
                           000005   597 	ar5 = 0x05
                           000004   598 	ar4 = 0x04
                           000003   599 	ar3 = 0x03
                           000002   600 	ar2 = 0x02
                           000001   601 	ar1 = 0x01
                           000000   602 	ar0 = 0x00
                                    603 ;	src/fsm.c:21: menu_state = button_read_and_clear_menu();
      000C0D 12 06 6C         [24]  604 	lcall	_button_read_and_clear_menu
      000C10 AF 82            [24]  605 	mov	r7,dpl
                                    606 ;	src/fsm.c:22: select_state = button_read_and_clear_select();
      000C12 C0 07            [24]  607 	push	ar7
      000C14 12 06 40         [24]  608 	lcall	_button_read_and_clear_select
      000C17 AE 82            [24]  609 	mov	r6,dpl
      000C19 D0 07            [24]  610 	pop	ar7
                                    611 ;	src/fsm.c:24: if(curstate != fsm_home_alarm){
      000C1B 74 07            [12]  612 	mov	a,#0x07
      000C1D B5 57 03         [24]  613 	cjne	a,_fsm_home_fn_curstate_65536_174,00336$
      000C20 02 0D 5A         [24]  614 	ljmp	00134$
      000C23                        615 00336$:
                                    616 ;	src/fsm.c:25: if((menu_state == BUTTON_LONG_PRESSED) && (select_state == BUTTON_LONG_PRESSED)){
      000C23 BF 01 03         [24]  617 	cjne	r7,#0x01,00337$
      000C26 EF               [12]  618 	mov	a,r7
      000C27 80 01            [24]  619 	sjmp	00338$
      000C29                        620 00337$:
      000C29 E4               [12]  621 	clr	a
      000C2A                        622 00338$:
      000C2A FD               [12]  623 	mov	r5,a
      000C2B 60 0A            [24]  624 	jz	00102$
      000C2D BE 01 07         [24]  625 	cjne	r6,#0x01,00102$
                                    626 ;	src/fsm.c:27: curstate = fsm_home_start; //Reset state back to default
      000C30 75 57 00         [24]  627 	mov	_fsm_home_fn_curstate_65536_174,#0x00
                                    628 ;	src/fsm.c:28: return fsm_ok; //Return OK to transition to configuration mode
      000C33 75 82 00         [24]  629 	mov	dpl,#0x00
      000C36 22               [24]  630 	ret
      000C37                        631 00102$:
                                    632 ;	src/fsm.c:32: if(menu_state == BUTTON_PRESSED){
      000C37 EF               [12]  633 	mov	a,r7
      000C38 70 21            [24]  634 	jnz	00107$
                                    635 ;	src/fsm.c:34: transition_ticks = centiseconds();
      000C3A C0 07            [24]  636 	push	ar7
      000C3C C0 06            [24]  637 	push	ar6
      000C3E C0 05            [24]  638 	push	ar5
      000C40 12 1A D4         [24]  639 	lcall	_centiseconds
      000C43 85 82 55         [24]  640 	mov	_transition_ticks,dpl
      000C46 85 83 56         [24]  641 	mov	(_transition_ticks + 1),dph
      000C49 D0 05            [24]  642 	pop	ar5
      000C4B D0 06            [24]  643 	pop	ar6
      000C4D D0 07            [24]  644 	pop	ar7
                                    645 ;	src/fsm.c:35: fsm_home_auto = 0;
                                    646 ;	assignBit
      000C4F C2 1E            [12]  647 	clr	_fsm_home_auto
                                    648 ;	src/fsm.c:36: if(++curstate == fsm_home_end)
      000C51 05 57            [12]  649 	inc	_fsm_home_fn_curstate_65536_174
      000C53 74 06            [12]  650 	mov	a,#0x06
      000C55 B5 57 03         [24]  651 	cjne	a,_fsm_home_fn_curstate_65536_174,00107$
                                    652 ;	src/fsm.c:37: curstate = fsm_home_start;
      000C58 75 57 00         [24]  653 	mov	_fsm_home_fn_curstate_65536_174,#0x00
      000C5B                        654 00107$:
                                    655 ;	src/fsm.c:40: if(menu_state == BUTTON_LONG_PRESSED){
      000C5B ED               [12]  656 	mov	a,r5
      000C5C 60 16            [24]  657 	jz	00109$
                                    658 ;	src/fsm.c:42: transition_ticks = centiseconds();
      000C5E C0 07            [24]  659 	push	ar7
      000C60 C0 06            [24]  660 	push	ar6
      000C62 12 1A D4         [24]  661 	lcall	_centiseconds
      000C65 85 82 55         [24]  662 	mov	_transition_ticks,dpl
      000C68 85 83 56         [24]  663 	mov	(_transition_ticks + 1),dph
      000C6B D0 06            [24]  664 	pop	ar6
      000C6D D0 07            [24]  665 	pop	ar7
                                    666 ;	src/fsm.c:43: fsm_home_auto = 0;
                                    667 ;	assignBit
      000C6F C2 1E            [12]  668 	clr	_fsm_home_auto
                                    669 ;	src/fsm.c:44: curstate = fsm_home_start;
      000C71 75 57 00         [24]  670 	mov	_fsm_home_fn_curstate_65536_174,#0x00
      000C74                        671 00109$:
                                    672 ;	src/fsm.c:47: if(select_state == BUTTON_PRESSED){
      000C74 EE               [12]  673 	mov	a,r6
      000C75 70 13            [24]  674 	jnz	00114$
                                    675 ;	src/fsm.c:48: if(display_autobrightness){
                                    676 ;	src/fsm.c:49: display_autobrightness = 0;
                                    677 ;	assignBit
      000C77 10 1F 02         [24]  678 	jbc	_display_autobrightness,00347$
      000C7A 80 0C            [24]  679 	sjmp	00111$
      000C7C                        680 00347$:
                                    681 ;	src/fsm.c:50: INT_IE_EA = 0;
                                    682 ;	assignBit
      000C7C C2 AF            [12]  683 	clr	_INT_IE_EA
                                    684 ;	src/fsm.c:51: display_counts = DISPLAY_COUNTS_MAX;
      000C7E 75 48 00         [24]  685 	mov	_display_counts,#0x00
      000C81 75 49 EA         [24]  686 	mov	(_display_counts + 1),#0xea
                                    687 ;	src/fsm.c:52: INT_IE_EA = 1;
                                    688 ;	assignBit
      000C84 D2 AF            [12]  689 	setb	_INT_IE_EA
      000C86 80 02            [24]  690 	sjmp	00114$
      000C88                        691 00111$:
                                    692 ;	src/fsm.c:54: display_autobrightness = 1;
                                    693 ;	assignBit
      000C88 D2 1F            [12]  694 	setb	_display_autobrightness
      000C8A                        695 00114$:
                                    696 ;	src/fsm.c:58: if(curstate != fsm_home_start) {
      000C8A E5 57            [12]  697 	mov	a,_fsm_home_fn_curstate_65536_174
      000C8C 70 03            [24]  698 	jnz	00348$
      000C8E 02 0D 33         [24]  699 	ljmp	00131$
      000C91                        700 00348$:
                                    701 ;	src/fsm.c:59: if(fsm_home_auto){
      000C91 30 1E 67         [24]  702 	jnb	_fsm_home_auto,00126$
                                    703 ;	src/fsm.c:61: if((centiseconds() - transition_ticks) > FSM_HOME_AUTO_SCROLL_TICKS){
      000C94 C0 07            [24]  704 	push	ar7
      000C96 C0 06            [24]  705 	push	ar6
      000C98 12 1A D4         [24]  706 	lcall	_centiseconds
      000C9B E5 82            [12]  707 	mov	a,dpl
      000C9D 85 83 F0         [24]  708 	mov	b,dph
      000CA0 D0 06            [24]  709 	pop	ar6
      000CA2 D0 07            [24]  710 	pop	ar7
      000CA4 C3               [12]  711 	clr	c
      000CA5 95 55            [12]  712 	subb	a,_transition_ticks
      000CA7 FC               [12]  713 	mov	r4,a
      000CA8 E5 F0            [12]  714 	mov	a,b
      000CAA 95 56            [12]  715 	subb	a,(_transition_ticks + 1)
      000CAC FD               [12]  716 	mov	r5,a
      000CAD C3               [12]  717 	clr	c
      000CAE 74 C8            [12]  718 	mov	a,#0xc8
      000CB0 9C               [12]  719 	subb	a,r4
      000CB1 E4               [12]  720 	clr	a
      000CB2 9D               [12]  721 	subb	a,r5
      000CB3 40 03            [24]  722 	jc	00350$
      000CB5 02 0D 5A         [24]  723 	ljmp	00134$
      000CB8                        724 00350$:
                                    725 ;	src/fsm.c:64: while(++curstate != fsm_home_end){
      000CB8                        726 00118$:
      000CB8 05 57            [12]  727 	inc	_fsm_home_fn_curstate_65536_174
      000CBA 74 06            [12]  728 	mov	a,#0x06
      000CBC B5 57 02         [24]  729 	cjne	a,_fsm_home_fn_curstate_65536_174,00351$
      000CBF 80 22            [24]  730 	sjmp	00120$
      000CC1                        731 00351$:
                                    732 ;	src/fsm.c:65: if((ds1302_sram_data[0x03] >> curstate) & 0x01){
      000CC1 90 00 03         [24]  733 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      000CC4 E0               [24]  734 	movx	a,@dptr
      000CC5 FD               [12]  735 	mov	r5,a
      000CC6 85 57 F0         [24]  736 	mov	b,_fsm_home_fn_curstate_65536_174
      000CC9 05 F0            [12]  737 	inc	b
      000CCB ED               [12]  738 	mov	a,r5
      000CCC 80 02            [24]  739 	sjmp	00353$
      000CCE                        740 00352$:
      000CCE C3               [12]  741 	clr	c
      000CCF 13               [12]  742 	rrc	a
      000CD0                        743 00353$:
      000CD0 D5 F0 FB         [24]  744 	djnz	b,00352$
      000CD3 30 E0 E2         [24]  745 	jnb	acc.0,00118$
                                    746 ;	src/fsm.c:67: transition_ticks = centiseconds();
      000CD6 12 1A D4         [24]  747 	lcall	_centiseconds
      000CD9 85 82 55         [24]  748 	mov	_transition_ticks,dpl
      000CDC 85 83 56         [24]  749 	mov	(_transition_ticks + 1),dph
                                    750 ;	src/fsm.c:68: return fsm_repeat;
      000CDF 75 82 01         [24]  751 	mov	dpl,#0x01
      000CE2 22               [24]  752 	ret
      000CE3                        753 00120$:
                                    754 ;	src/fsm.c:72: transition_ticks = centiseconds();
      000CE3 C0 07            [24]  755 	push	ar7
      000CE5 C0 06            [24]  756 	push	ar6
      000CE7 12 1A D4         [24]  757 	lcall	_centiseconds
      000CEA 85 82 55         [24]  758 	mov	_transition_ticks,dpl
      000CED 85 83 56         [24]  759 	mov	(_transition_ticks + 1),dph
      000CF0 D0 06            [24]  760 	pop	ar6
      000CF2 D0 07            [24]  761 	pop	ar7
                                    762 ;	src/fsm.c:73: fsm_home_auto = 0;
                                    763 ;	assignBit
      000CF4 C2 1E            [12]  764 	clr	_fsm_home_auto
                                    765 ;	src/fsm.c:74: curstate = fsm_home_start;
      000CF6 75 57 00         [24]  766 	mov	_fsm_home_fn_curstate_65536_174,#0x00
      000CF9 80 5F            [24]  767 	sjmp	00134$
      000CFB                        768 00126$:
                                    769 ;	src/fsm.c:78: if(((centiseconds() - transition_ticks) > FSM_HOME_RESET_TICKS)) {
      000CFB C0 07            [24]  770 	push	ar7
      000CFD C0 06            [24]  771 	push	ar6
      000CFF 12 1A D4         [24]  772 	lcall	_centiseconds
      000D02 E5 82            [12]  773 	mov	a,dpl
      000D04 85 83 F0         [24]  774 	mov	b,dph
      000D07 D0 06            [24]  775 	pop	ar6
      000D09 D0 07            [24]  776 	pop	ar7
      000D0B C3               [12]  777 	clr	c
      000D0C 95 55            [12]  778 	subb	a,_transition_ticks
      000D0E FC               [12]  779 	mov	r4,a
      000D0F E5 F0            [12]  780 	mov	a,b
      000D11 95 56            [12]  781 	subb	a,(_transition_ticks + 1)
      000D13 FD               [12]  782 	mov	r5,a
      000D14 C3               [12]  783 	clr	c
      000D15 74 F4            [12]  784 	mov	a,#0xf4
      000D17 9C               [12]  785 	subb	a,r4
      000D18 74 01            [12]  786 	mov	a,#0x01
      000D1A 9D               [12]  787 	subb	a,r5
      000D1B 50 3D            [24]  788 	jnc	00134$
                                    789 ;	src/fsm.c:80: transition_ticks = centiseconds();
      000D1D C0 07            [24]  790 	push	ar7
      000D1F C0 06            [24]  791 	push	ar6
      000D21 12 1A D4         [24]  792 	lcall	_centiseconds
      000D24 85 82 55         [24]  793 	mov	_transition_ticks,dpl
      000D27 85 83 56         [24]  794 	mov	(_transition_ticks + 1),dph
      000D2A D0 06            [24]  795 	pop	ar6
      000D2C D0 07            [24]  796 	pop	ar7
                                    797 ;	src/fsm.c:81: curstate = fsm_home_start;
      000D2E 75 57 00         [24]  798 	mov	_fsm_home_fn_curstate_65536_174,#0x00
      000D31 80 27            [24]  799 	sjmp	00134$
      000D33                        800 00131$:
                                    801 ;	src/fsm.c:88: if((centiseconds() - transition_ticks) > FSM_HOME_AUTO_ENABLE_TICKS) {
      000D33 C0 07            [24]  802 	push	ar7
      000D35 C0 06            [24]  803 	push	ar6
      000D37 12 1A D4         [24]  804 	lcall	_centiseconds
      000D3A E5 82            [12]  805 	mov	a,dpl
      000D3C 85 83 F0         [24]  806 	mov	b,dph
      000D3F D0 06            [24]  807 	pop	ar6
      000D41 D0 07            [24]  808 	pop	ar7
      000D43 C3               [12]  809 	clr	c
      000D44 95 55            [12]  810 	subb	a,_transition_ticks
      000D46 FC               [12]  811 	mov	r4,a
      000D47 E5 F0            [12]  812 	mov	a,b
      000D49 95 56            [12]  813 	subb	a,(_transition_ticks + 1)
      000D4B FD               [12]  814 	mov	r5,a
      000D4C C3               [12]  815 	clr	c
      000D4D 74 E8            [12]  816 	mov	a,#0xe8
      000D4F 9C               [12]  817 	subb	a,r4
      000D50 74 03            [12]  818 	mov	a,#0x03
      000D52 9D               [12]  819 	subb	a,r5
      000D53 50 05            [24]  820 	jnc	00134$
                                    821 ;	src/fsm.c:90: fsm_home_auto = 1;
                                    822 ;	assignBit
      000D55 D2 1E            [12]  823 	setb	_fsm_home_auto
                                    824 ;	src/fsm.c:91: goto find_auto_target;
      000D57 02 0C B8         [24]  825 	ljmp	00118$
      000D5A                        826 00134$:
                                    827 ;	include/ds1302.h:352: ds1302_start(0xbf); //Start clock burst read
      000D5A 75 82 BF         [24]  828 	mov	dpl,#0xbf
      000D5D C0 07            [24]  829 	push	ar7
      000D5F C0 06            [24]  830 	push	ar6
      000D61 12 09 23         [24]  831 	lcall	_ds1302_start
      000D64 D0 06            [24]  832 	pop	ar6
      000D66 D0 07            [24]  833 	pop	ar7
                                    834 ;	include/ds1302.h:353: ds1302.seconds = ds1302_read_byte(); //Read in seconds register
                                    835 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                    836 ;	assignBit
      000D68 D2 91            [12]  837 	setb	_PORT_P1_1
                                    838 ;	include/ds1302.h:130: __endasm;
      000D6A 00               [12]  839 	nop
      000D6B 00               [12]  840 	nop
      000D6C 00               [12]  841 	nop
                                    842 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                    843 ;	assignBit
      000D6D A2 91            [12]  844 	mov	c,_PORT_P1_1
      000D6F 92 08            [24]  845 	mov	_DS1302_DATA_0,c
                                    846 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                    847 ;	assignBit
      000D71 D2 92            [12]  848 	setb	_PORT_P1_2
                                    849 ;	include/ds1302.h:139: __endasm;
      000D73 00               [12]  850 	nop
      000D74 00               [12]  851 	nop
      000D75 00               [12]  852 	nop
      000D76 00               [12]  853 	nop
                                    854 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                    855 ;	assignBit
      000D77 C2 92            [12]  856 	clr	_PORT_P1_2
                                    857 ;	include/ds1302.h:145: __endasm;
      000D79 00               [12]  858 	nop
      000D7A 00               [12]  859 	nop
      000D7B 00               [12]  860 	nop
                                    861 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                    862 ;	assignBit
      000D7C A2 91            [12]  863 	mov	c,_PORT_P1_1
      000D7E 92 09            [24]  864 	mov	_DS1302_DATA_1,c
                                    865 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                    866 ;	assignBit
      000D80 D2 92            [12]  867 	setb	_PORT_P1_2
                                    868 ;	include/ds1302.h:154: __endasm;
      000D82 00               [12]  869 	nop
      000D83 00               [12]  870 	nop
      000D84 00               [12]  871 	nop
      000D85 00               [12]  872 	nop
                                    873 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                    874 ;	assignBit
      000D86 C2 92            [12]  875 	clr	_PORT_P1_2
                                    876 ;	include/ds1302.h:160: __endasm;
      000D88 00               [12]  877 	nop
      000D89 00               [12]  878 	nop
      000D8A 00               [12]  879 	nop
                                    880 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                    881 ;	assignBit
      000D8B A2 91            [12]  882 	mov	c,_PORT_P1_1
      000D8D 92 0A            [24]  883 	mov	_DS1302_DATA_2,c
                                    884 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                    885 ;	assignBit
      000D8F D2 92            [12]  886 	setb	_PORT_P1_2
                                    887 ;	include/ds1302.h:169: __endasm;
      000D91 00               [12]  888 	nop
      000D92 00               [12]  889 	nop
      000D93 00               [12]  890 	nop
      000D94 00               [12]  891 	nop
                                    892 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                    893 ;	assignBit
      000D95 C2 92            [12]  894 	clr	_PORT_P1_2
                                    895 ;	include/ds1302.h:175: __endasm;
      000D97 00               [12]  896 	nop
      000D98 00               [12]  897 	nop
      000D99 00               [12]  898 	nop
                                    899 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                    900 ;	assignBit
      000D9A A2 91            [12]  901 	mov	c,_PORT_P1_1
      000D9C 92 0B            [24]  902 	mov	_DS1302_DATA_3,c
                                    903 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                    904 ;	assignBit
      000D9E D2 92            [12]  905 	setb	_PORT_P1_2
                                    906 ;	include/ds1302.h:184: __endasm;
      000DA0 00               [12]  907 	nop
      000DA1 00               [12]  908 	nop
      000DA2 00               [12]  909 	nop
      000DA3 00               [12]  910 	nop
                                    911 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                    912 ;	assignBit
      000DA4 C2 92            [12]  913 	clr	_PORT_P1_2
                                    914 ;	include/ds1302.h:190: __endasm;
      000DA6 00               [12]  915 	nop
      000DA7 00               [12]  916 	nop
      000DA8 00               [12]  917 	nop
                                    918 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                    919 ;	assignBit
      000DA9 A2 91            [12]  920 	mov	c,_PORT_P1_1
      000DAB 92 0C            [24]  921 	mov	_DS1302_DATA_4,c
                                    922 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                    923 ;	assignBit
      000DAD D2 92            [12]  924 	setb	_PORT_P1_2
                                    925 ;	include/ds1302.h:199: __endasm;
      000DAF 00               [12]  926 	nop
      000DB0 00               [12]  927 	nop
      000DB1 00               [12]  928 	nop
      000DB2 00               [12]  929 	nop
                                    930 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                    931 ;	assignBit
      000DB3 C2 92            [12]  932 	clr	_PORT_P1_2
                                    933 ;	include/ds1302.h:205: __endasm;
      000DB5 00               [12]  934 	nop
      000DB6 00               [12]  935 	nop
      000DB7 00               [12]  936 	nop
                                    937 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                    938 ;	assignBit
      000DB8 A2 91            [12]  939 	mov	c,_PORT_P1_1
      000DBA 92 0D            [24]  940 	mov	_DS1302_DATA_5,c
                                    941 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                    942 ;	assignBit
      000DBC D2 92            [12]  943 	setb	_PORT_P1_2
                                    944 ;	include/ds1302.h:214: __endasm;
      000DBE 00               [12]  945 	nop
      000DBF 00               [12]  946 	nop
      000DC0 00               [12]  947 	nop
      000DC1 00               [12]  948 	nop
                                    949 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                    950 ;	assignBit
      000DC2 C2 92            [12]  951 	clr	_PORT_P1_2
                                    952 ;	include/ds1302.h:220: __endasm;
      000DC4 00               [12]  953 	nop
      000DC5 00               [12]  954 	nop
      000DC6 00               [12]  955 	nop
                                    956 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                    957 ;	assignBit
      000DC7 A2 91            [12]  958 	mov	c,_PORT_P1_1
      000DC9 92 0E            [24]  959 	mov	_DS1302_DATA_6,c
                                    960 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                    961 ;	assignBit
      000DCB D2 92            [12]  962 	setb	_PORT_P1_2
                                    963 ;	include/ds1302.h:229: __endasm;
      000DCD 00               [12]  964 	nop
      000DCE 00               [12]  965 	nop
      000DCF 00               [12]  966 	nop
      000DD0 00               [12]  967 	nop
                                    968 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                    969 ;	assignBit
      000DD1 C2 92            [12]  970 	clr	_PORT_P1_2
                                    971 ;	include/ds1302.h:235: __endasm;
      000DD3 00               [12]  972 	nop
      000DD4 00               [12]  973 	nop
      000DD5 00               [12]  974 	nop
                                    975 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                    976 ;	assignBit
      000DD6 A2 91            [12]  977 	mov	c,_PORT_P1_1
      000DD8 92 0F            [24]  978 	mov	_DS1302_DATA_7,c
                                    979 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                    980 ;	assignBit
      000DDA D2 92            [12]  981 	setb	_PORT_P1_2
                                    982 ;	include/ds1302.h:243: __endasm;
      000DDC 00               [12]  983 	nop
      000DDD 00               [12]  984 	nop
      000DDE 00               [12]  985 	nop
      000DDF 00               [12]  986 	nop
                                    987 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                    988 ;	assignBit
      000DE0 C2 92            [12]  989 	clr	_PORT_P1_2
                                    990 ;	include/ds1302.h:246: return DS1302_DATA;
      000DE2 E5 21            [12]  991 	mov	a,_DS1302_DATA
                                    992 ;	include/ds1302.h:353: ds1302.seconds = ds1302_read_byte(); //Read in seconds register
      000DE4 F5 4C            [12]  993 	mov	_ds1302,a
                                    994 ;	include/ds1302.h:354: ds1302.minutes = ds1302_read_byte(); //Read in minutes register
                                    995 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                    996 ;	assignBit
      000DE6 D2 91            [12]  997 	setb	_PORT_P1_1
                                    998 ;	include/ds1302.h:130: __endasm;
      000DE8 00               [12]  999 	nop
      000DE9 00               [12] 1000 	nop
      000DEA 00               [12] 1001 	nop
                                   1002 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1003 ;	assignBit
      000DEB A2 91            [12] 1004 	mov	c,_PORT_P1_1
      000DED 92 08            [24] 1005 	mov	_DS1302_DATA_0,c
                                   1006 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1007 ;	assignBit
      000DEF D2 92            [12] 1008 	setb	_PORT_P1_2
                                   1009 ;	include/ds1302.h:139: __endasm;
      000DF1 00               [12] 1010 	nop
      000DF2 00               [12] 1011 	nop
      000DF3 00               [12] 1012 	nop
      000DF4 00               [12] 1013 	nop
                                   1014 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1015 ;	assignBit
      000DF5 C2 92            [12] 1016 	clr	_PORT_P1_2
                                   1017 ;	include/ds1302.h:145: __endasm;
      000DF7 00               [12] 1018 	nop
      000DF8 00               [12] 1019 	nop
      000DF9 00               [12] 1020 	nop
                                   1021 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1022 ;	assignBit
      000DFA A2 91            [12] 1023 	mov	c,_PORT_P1_1
      000DFC 92 09            [24] 1024 	mov	_DS1302_DATA_1,c
                                   1025 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1026 ;	assignBit
      000DFE D2 92            [12] 1027 	setb	_PORT_P1_2
                                   1028 ;	include/ds1302.h:154: __endasm;
      000E00 00               [12] 1029 	nop
      000E01 00               [12] 1030 	nop
      000E02 00               [12] 1031 	nop
      000E03 00               [12] 1032 	nop
                                   1033 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1034 ;	assignBit
      000E04 C2 92            [12] 1035 	clr	_PORT_P1_2
                                   1036 ;	include/ds1302.h:160: __endasm;
      000E06 00               [12] 1037 	nop
      000E07 00               [12] 1038 	nop
      000E08 00               [12] 1039 	nop
                                   1040 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1041 ;	assignBit
      000E09 A2 91            [12] 1042 	mov	c,_PORT_P1_1
      000E0B 92 0A            [24] 1043 	mov	_DS1302_DATA_2,c
                                   1044 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1045 ;	assignBit
      000E0D D2 92            [12] 1046 	setb	_PORT_P1_2
                                   1047 ;	include/ds1302.h:169: __endasm;
      000E0F 00               [12] 1048 	nop
      000E10 00               [12] 1049 	nop
      000E11 00               [12] 1050 	nop
      000E12 00               [12] 1051 	nop
                                   1052 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1053 ;	assignBit
      000E13 C2 92            [12] 1054 	clr	_PORT_P1_2
                                   1055 ;	include/ds1302.h:175: __endasm;
      000E15 00               [12] 1056 	nop
      000E16 00               [12] 1057 	nop
      000E17 00               [12] 1058 	nop
                                   1059 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1060 ;	assignBit
      000E18 A2 91            [12] 1061 	mov	c,_PORT_P1_1
      000E1A 92 0B            [24] 1062 	mov	_DS1302_DATA_3,c
                                   1063 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1064 ;	assignBit
      000E1C D2 92            [12] 1065 	setb	_PORT_P1_2
                                   1066 ;	include/ds1302.h:184: __endasm;
      000E1E 00               [12] 1067 	nop
      000E1F 00               [12] 1068 	nop
      000E20 00               [12] 1069 	nop
      000E21 00               [12] 1070 	nop
                                   1071 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1072 ;	assignBit
      000E22 C2 92            [12] 1073 	clr	_PORT_P1_2
                                   1074 ;	include/ds1302.h:190: __endasm;
      000E24 00               [12] 1075 	nop
      000E25 00               [12] 1076 	nop
      000E26 00               [12] 1077 	nop
                                   1078 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1079 ;	assignBit
      000E27 A2 91            [12] 1080 	mov	c,_PORT_P1_1
      000E29 92 0C            [24] 1081 	mov	_DS1302_DATA_4,c
                                   1082 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1083 ;	assignBit
      000E2B D2 92            [12] 1084 	setb	_PORT_P1_2
                                   1085 ;	include/ds1302.h:199: __endasm;
      000E2D 00               [12] 1086 	nop
      000E2E 00               [12] 1087 	nop
      000E2F 00               [12] 1088 	nop
      000E30 00               [12] 1089 	nop
                                   1090 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1091 ;	assignBit
      000E31 C2 92            [12] 1092 	clr	_PORT_P1_2
                                   1093 ;	include/ds1302.h:205: __endasm;
      000E33 00               [12] 1094 	nop
      000E34 00               [12] 1095 	nop
      000E35 00               [12] 1096 	nop
                                   1097 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1098 ;	assignBit
      000E36 A2 91            [12] 1099 	mov	c,_PORT_P1_1
      000E38 92 0D            [24] 1100 	mov	_DS1302_DATA_5,c
                                   1101 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1102 ;	assignBit
      000E3A D2 92            [12] 1103 	setb	_PORT_P1_2
                                   1104 ;	include/ds1302.h:214: __endasm;
      000E3C 00               [12] 1105 	nop
      000E3D 00               [12] 1106 	nop
      000E3E 00               [12] 1107 	nop
      000E3F 00               [12] 1108 	nop
                                   1109 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1110 ;	assignBit
      000E40 C2 92            [12] 1111 	clr	_PORT_P1_2
                                   1112 ;	include/ds1302.h:220: __endasm;
      000E42 00               [12] 1113 	nop
      000E43 00               [12] 1114 	nop
      000E44 00               [12] 1115 	nop
                                   1116 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1117 ;	assignBit
      000E45 A2 91            [12] 1118 	mov	c,_PORT_P1_1
      000E47 92 0E            [24] 1119 	mov	_DS1302_DATA_6,c
                                   1120 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1121 ;	assignBit
      000E49 D2 92            [12] 1122 	setb	_PORT_P1_2
                                   1123 ;	include/ds1302.h:229: __endasm;
      000E4B 00               [12] 1124 	nop
      000E4C 00               [12] 1125 	nop
      000E4D 00               [12] 1126 	nop
      000E4E 00               [12] 1127 	nop
                                   1128 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1129 ;	assignBit
      000E4F C2 92            [12] 1130 	clr	_PORT_P1_2
                                   1131 ;	include/ds1302.h:235: __endasm;
      000E51 00               [12] 1132 	nop
      000E52 00               [12] 1133 	nop
      000E53 00               [12] 1134 	nop
                                   1135 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1136 ;	assignBit
      000E54 A2 91            [12] 1137 	mov	c,_PORT_P1_1
      000E56 92 0F            [24] 1138 	mov	_DS1302_DATA_7,c
                                   1139 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1140 ;	assignBit
      000E58 D2 92            [12] 1141 	setb	_PORT_P1_2
                                   1142 ;	include/ds1302.h:243: __endasm;
      000E5A 00               [12] 1143 	nop
      000E5B 00               [12] 1144 	nop
      000E5C 00               [12] 1145 	nop
      000E5D 00               [12] 1146 	nop
                                   1147 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1148 ;	assignBit
      000E5E C2 92            [12] 1149 	clr	_PORT_P1_2
                                   1150 ;	include/ds1302.h:246: return DS1302_DATA;
      000E60 AD 21            [24] 1151 	mov	r5,_DS1302_DATA
                                   1152 ;	include/ds1302.h:354: ds1302.minutes = ds1302_read_byte(); //Read in minutes register
      000E62 8D 4D            [24] 1153 	mov	(_ds1302 + 0x0001),r5
                                   1154 ;	include/ds1302.h:355: ds1302.hour    = ds1302_read_byte(); //Read in hours register
                                   1155 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                   1156 ;	assignBit
      000E64 D2 91            [12] 1157 	setb	_PORT_P1_1
                                   1158 ;	include/ds1302.h:130: __endasm;
      000E66 00               [12] 1159 	nop
      000E67 00               [12] 1160 	nop
      000E68 00               [12] 1161 	nop
                                   1162 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1163 ;	assignBit
      000E69 A2 91            [12] 1164 	mov	c,_PORT_P1_1
      000E6B 92 08            [24] 1165 	mov	_DS1302_DATA_0,c
                                   1166 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1167 ;	assignBit
      000E6D D2 92            [12] 1168 	setb	_PORT_P1_2
                                   1169 ;	include/ds1302.h:139: __endasm;
      000E6F 00               [12] 1170 	nop
      000E70 00               [12] 1171 	nop
      000E71 00               [12] 1172 	nop
      000E72 00               [12] 1173 	nop
                                   1174 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1175 ;	assignBit
      000E73 C2 92            [12] 1176 	clr	_PORT_P1_2
                                   1177 ;	include/ds1302.h:145: __endasm;
      000E75 00               [12] 1178 	nop
      000E76 00               [12] 1179 	nop
      000E77 00               [12] 1180 	nop
                                   1181 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1182 ;	assignBit
      000E78 A2 91            [12] 1183 	mov	c,_PORT_P1_1
      000E7A 92 09            [24] 1184 	mov	_DS1302_DATA_1,c
                                   1185 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1186 ;	assignBit
      000E7C D2 92            [12] 1187 	setb	_PORT_P1_2
                                   1188 ;	include/ds1302.h:154: __endasm;
      000E7E 00               [12] 1189 	nop
      000E7F 00               [12] 1190 	nop
      000E80 00               [12] 1191 	nop
      000E81 00               [12] 1192 	nop
                                   1193 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1194 ;	assignBit
      000E82 C2 92            [12] 1195 	clr	_PORT_P1_2
                                   1196 ;	include/ds1302.h:160: __endasm;
      000E84 00               [12] 1197 	nop
      000E85 00               [12] 1198 	nop
      000E86 00               [12] 1199 	nop
                                   1200 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1201 ;	assignBit
      000E87 A2 91            [12] 1202 	mov	c,_PORT_P1_1
      000E89 92 0A            [24] 1203 	mov	_DS1302_DATA_2,c
                                   1204 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1205 ;	assignBit
      000E8B D2 92            [12] 1206 	setb	_PORT_P1_2
                                   1207 ;	include/ds1302.h:169: __endasm;
      000E8D 00               [12] 1208 	nop
      000E8E 00               [12] 1209 	nop
      000E8F 00               [12] 1210 	nop
      000E90 00               [12] 1211 	nop
                                   1212 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1213 ;	assignBit
      000E91 C2 92            [12] 1214 	clr	_PORT_P1_2
                                   1215 ;	include/ds1302.h:175: __endasm;
      000E93 00               [12] 1216 	nop
      000E94 00               [12] 1217 	nop
      000E95 00               [12] 1218 	nop
                                   1219 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1220 ;	assignBit
      000E96 A2 91            [12] 1221 	mov	c,_PORT_P1_1
      000E98 92 0B            [24] 1222 	mov	_DS1302_DATA_3,c
                                   1223 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1224 ;	assignBit
      000E9A D2 92            [12] 1225 	setb	_PORT_P1_2
                                   1226 ;	include/ds1302.h:184: __endasm;
      000E9C 00               [12] 1227 	nop
      000E9D 00               [12] 1228 	nop
      000E9E 00               [12] 1229 	nop
      000E9F 00               [12] 1230 	nop
                                   1231 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1232 ;	assignBit
      000EA0 C2 92            [12] 1233 	clr	_PORT_P1_2
                                   1234 ;	include/ds1302.h:190: __endasm;
      000EA2 00               [12] 1235 	nop
      000EA3 00               [12] 1236 	nop
      000EA4 00               [12] 1237 	nop
                                   1238 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1239 ;	assignBit
      000EA5 A2 91            [12] 1240 	mov	c,_PORT_P1_1
      000EA7 92 0C            [24] 1241 	mov	_DS1302_DATA_4,c
                                   1242 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1243 ;	assignBit
      000EA9 D2 92            [12] 1244 	setb	_PORT_P1_2
                                   1245 ;	include/ds1302.h:199: __endasm;
      000EAB 00               [12] 1246 	nop
      000EAC 00               [12] 1247 	nop
      000EAD 00               [12] 1248 	nop
      000EAE 00               [12] 1249 	nop
                                   1250 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1251 ;	assignBit
      000EAF C2 92            [12] 1252 	clr	_PORT_P1_2
                                   1253 ;	include/ds1302.h:205: __endasm;
      000EB1 00               [12] 1254 	nop
      000EB2 00               [12] 1255 	nop
      000EB3 00               [12] 1256 	nop
                                   1257 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1258 ;	assignBit
      000EB4 A2 91            [12] 1259 	mov	c,_PORT_P1_1
      000EB6 92 0D            [24] 1260 	mov	_DS1302_DATA_5,c
                                   1261 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1262 ;	assignBit
      000EB8 D2 92            [12] 1263 	setb	_PORT_P1_2
                                   1264 ;	include/ds1302.h:214: __endasm;
      000EBA 00               [12] 1265 	nop
      000EBB 00               [12] 1266 	nop
      000EBC 00               [12] 1267 	nop
      000EBD 00               [12] 1268 	nop
                                   1269 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1270 ;	assignBit
      000EBE C2 92            [12] 1271 	clr	_PORT_P1_2
                                   1272 ;	include/ds1302.h:220: __endasm;
      000EC0 00               [12] 1273 	nop
      000EC1 00               [12] 1274 	nop
      000EC2 00               [12] 1275 	nop
                                   1276 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1277 ;	assignBit
      000EC3 A2 91            [12] 1278 	mov	c,_PORT_P1_1
      000EC5 92 0E            [24] 1279 	mov	_DS1302_DATA_6,c
                                   1280 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1281 ;	assignBit
      000EC7 D2 92            [12] 1282 	setb	_PORT_P1_2
                                   1283 ;	include/ds1302.h:229: __endasm;
      000EC9 00               [12] 1284 	nop
      000ECA 00               [12] 1285 	nop
      000ECB 00               [12] 1286 	nop
      000ECC 00               [12] 1287 	nop
                                   1288 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1289 ;	assignBit
      000ECD C2 92            [12] 1290 	clr	_PORT_P1_2
                                   1291 ;	include/ds1302.h:235: __endasm;
      000ECF 00               [12] 1292 	nop
      000ED0 00               [12] 1293 	nop
      000ED1 00               [12] 1294 	nop
                                   1295 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1296 ;	assignBit
      000ED2 A2 91            [12] 1297 	mov	c,_PORT_P1_1
      000ED4 92 0F            [24] 1298 	mov	_DS1302_DATA_7,c
                                   1299 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1300 ;	assignBit
      000ED6 D2 92            [12] 1301 	setb	_PORT_P1_2
                                   1302 ;	include/ds1302.h:243: __endasm;
      000ED8 00               [12] 1303 	nop
      000ED9 00               [12] 1304 	nop
      000EDA 00               [12] 1305 	nop
      000EDB 00               [12] 1306 	nop
                                   1307 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1308 ;	assignBit
      000EDC C2 92            [12] 1309 	clr	_PORT_P1_2
                                   1310 ;	include/ds1302.h:246: return DS1302_DATA;
      000EDE E5 21            [12] 1311 	mov	a,_DS1302_DATA
                                   1312 ;	include/ds1302.h:355: ds1302.hour    = ds1302_read_byte(); //Read in hours register
      000EE0 F5 4E            [12] 1313 	mov	(_ds1302 + 0x0002),a
                                   1314 ;	include/ds1302.h:356: ds1302.date    = ds1302_read_byte(); //Read in date register
                                   1315 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                   1316 ;	assignBit
      000EE2 D2 91            [12] 1317 	setb	_PORT_P1_1
                                   1318 ;	include/ds1302.h:130: __endasm;
      000EE4 00               [12] 1319 	nop
      000EE5 00               [12] 1320 	nop
      000EE6 00               [12] 1321 	nop
                                   1322 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1323 ;	assignBit
      000EE7 A2 91            [12] 1324 	mov	c,_PORT_P1_1
      000EE9 92 08            [24] 1325 	mov	_DS1302_DATA_0,c
                                   1326 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1327 ;	assignBit
      000EEB D2 92            [12] 1328 	setb	_PORT_P1_2
                                   1329 ;	include/ds1302.h:139: __endasm;
      000EED 00               [12] 1330 	nop
      000EEE 00               [12] 1331 	nop
      000EEF 00               [12] 1332 	nop
      000EF0 00               [12] 1333 	nop
                                   1334 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1335 ;	assignBit
      000EF1 C2 92            [12] 1336 	clr	_PORT_P1_2
                                   1337 ;	include/ds1302.h:145: __endasm;
      000EF3 00               [12] 1338 	nop
      000EF4 00               [12] 1339 	nop
      000EF5 00               [12] 1340 	nop
                                   1341 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1342 ;	assignBit
      000EF6 A2 91            [12] 1343 	mov	c,_PORT_P1_1
      000EF8 92 09            [24] 1344 	mov	_DS1302_DATA_1,c
                                   1345 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1346 ;	assignBit
      000EFA D2 92            [12] 1347 	setb	_PORT_P1_2
                                   1348 ;	include/ds1302.h:154: __endasm;
      000EFC 00               [12] 1349 	nop
      000EFD 00               [12] 1350 	nop
      000EFE 00               [12] 1351 	nop
      000EFF 00               [12] 1352 	nop
                                   1353 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1354 ;	assignBit
      000F00 C2 92            [12] 1355 	clr	_PORT_P1_2
                                   1356 ;	include/ds1302.h:160: __endasm;
      000F02 00               [12] 1357 	nop
      000F03 00               [12] 1358 	nop
      000F04 00               [12] 1359 	nop
                                   1360 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1361 ;	assignBit
      000F05 A2 91            [12] 1362 	mov	c,_PORT_P1_1
      000F07 92 0A            [24] 1363 	mov	_DS1302_DATA_2,c
                                   1364 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1365 ;	assignBit
      000F09 D2 92            [12] 1366 	setb	_PORT_P1_2
                                   1367 ;	include/ds1302.h:169: __endasm;
      000F0B 00               [12] 1368 	nop
      000F0C 00               [12] 1369 	nop
      000F0D 00               [12] 1370 	nop
      000F0E 00               [12] 1371 	nop
                                   1372 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1373 ;	assignBit
      000F0F C2 92            [12] 1374 	clr	_PORT_P1_2
                                   1375 ;	include/ds1302.h:175: __endasm;
      000F11 00               [12] 1376 	nop
      000F12 00               [12] 1377 	nop
      000F13 00               [12] 1378 	nop
                                   1379 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1380 ;	assignBit
      000F14 A2 91            [12] 1381 	mov	c,_PORT_P1_1
      000F16 92 0B            [24] 1382 	mov	_DS1302_DATA_3,c
                                   1383 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1384 ;	assignBit
      000F18 D2 92            [12] 1385 	setb	_PORT_P1_2
                                   1386 ;	include/ds1302.h:184: __endasm;
      000F1A 00               [12] 1387 	nop
      000F1B 00               [12] 1388 	nop
      000F1C 00               [12] 1389 	nop
      000F1D 00               [12] 1390 	nop
                                   1391 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1392 ;	assignBit
      000F1E C2 92            [12] 1393 	clr	_PORT_P1_2
                                   1394 ;	include/ds1302.h:190: __endasm;
      000F20 00               [12] 1395 	nop
      000F21 00               [12] 1396 	nop
      000F22 00               [12] 1397 	nop
                                   1398 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1399 ;	assignBit
      000F23 A2 91            [12] 1400 	mov	c,_PORT_P1_1
      000F25 92 0C            [24] 1401 	mov	_DS1302_DATA_4,c
                                   1402 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1403 ;	assignBit
      000F27 D2 92            [12] 1404 	setb	_PORT_P1_2
                                   1405 ;	include/ds1302.h:199: __endasm;
      000F29 00               [12] 1406 	nop
      000F2A 00               [12] 1407 	nop
      000F2B 00               [12] 1408 	nop
      000F2C 00               [12] 1409 	nop
                                   1410 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1411 ;	assignBit
      000F2D C2 92            [12] 1412 	clr	_PORT_P1_2
                                   1413 ;	include/ds1302.h:205: __endasm;
      000F2F 00               [12] 1414 	nop
      000F30 00               [12] 1415 	nop
      000F31 00               [12] 1416 	nop
                                   1417 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1418 ;	assignBit
      000F32 A2 91            [12] 1419 	mov	c,_PORT_P1_1
      000F34 92 0D            [24] 1420 	mov	_DS1302_DATA_5,c
                                   1421 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1422 ;	assignBit
      000F36 D2 92            [12] 1423 	setb	_PORT_P1_2
                                   1424 ;	include/ds1302.h:214: __endasm;
      000F38 00               [12] 1425 	nop
      000F39 00               [12] 1426 	nop
      000F3A 00               [12] 1427 	nop
      000F3B 00               [12] 1428 	nop
                                   1429 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1430 ;	assignBit
      000F3C C2 92            [12] 1431 	clr	_PORT_P1_2
                                   1432 ;	include/ds1302.h:220: __endasm;
      000F3E 00               [12] 1433 	nop
      000F3F 00               [12] 1434 	nop
      000F40 00               [12] 1435 	nop
                                   1436 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1437 ;	assignBit
      000F41 A2 91            [12] 1438 	mov	c,_PORT_P1_1
      000F43 92 0E            [24] 1439 	mov	_DS1302_DATA_6,c
                                   1440 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1441 ;	assignBit
      000F45 D2 92            [12] 1442 	setb	_PORT_P1_2
                                   1443 ;	include/ds1302.h:229: __endasm;
      000F47 00               [12] 1444 	nop
      000F48 00               [12] 1445 	nop
      000F49 00               [12] 1446 	nop
      000F4A 00               [12] 1447 	nop
                                   1448 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1449 ;	assignBit
      000F4B C2 92            [12] 1450 	clr	_PORT_P1_2
                                   1451 ;	include/ds1302.h:235: __endasm;
      000F4D 00               [12] 1452 	nop
      000F4E 00               [12] 1453 	nop
      000F4F 00               [12] 1454 	nop
                                   1455 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1456 ;	assignBit
      000F50 A2 91            [12] 1457 	mov	c,_PORT_P1_1
      000F52 92 0F            [24] 1458 	mov	_DS1302_DATA_7,c
                                   1459 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1460 ;	assignBit
      000F54 D2 92            [12] 1461 	setb	_PORT_P1_2
                                   1462 ;	include/ds1302.h:243: __endasm;
      000F56 00               [12] 1463 	nop
      000F57 00               [12] 1464 	nop
      000F58 00               [12] 1465 	nop
      000F59 00               [12] 1466 	nop
                                   1467 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1468 ;	assignBit
      000F5A C2 92            [12] 1469 	clr	_PORT_P1_2
                                   1470 ;	include/ds1302.h:246: return DS1302_DATA;
      000F5C E5 21            [12] 1471 	mov	a,_DS1302_DATA
                                   1472 ;	include/ds1302.h:356: ds1302.date    = ds1302_read_byte(); //Read in date register
      000F5E F5 4F            [12] 1473 	mov	(_ds1302 + 0x0003),a
                                   1474 ;	include/ds1302.h:357: ds1302.month   = ds1302_read_byte(); //Read in month register
                                   1475 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                   1476 ;	assignBit
      000F60 D2 91            [12] 1477 	setb	_PORT_P1_1
                                   1478 ;	include/ds1302.h:130: __endasm;
      000F62 00               [12] 1479 	nop
      000F63 00               [12] 1480 	nop
      000F64 00               [12] 1481 	nop
                                   1482 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1483 ;	assignBit
      000F65 A2 91            [12] 1484 	mov	c,_PORT_P1_1
      000F67 92 08            [24] 1485 	mov	_DS1302_DATA_0,c
                                   1486 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1487 ;	assignBit
      000F69 D2 92            [12] 1488 	setb	_PORT_P1_2
                                   1489 ;	include/ds1302.h:139: __endasm;
      000F6B 00               [12] 1490 	nop
      000F6C 00               [12] 1491 	nop
      000F6D 00               [12] 1492 	nop
      000F6E 00               [12] 1493 	nop
                                   1494 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1495 ;	assignBit
      000F6F C2 92            [12] 1496 	clr	_PORT_P1_2
                                   1497 ;	include/ds1302.h:145: __endasm;
      000F71 00               [12] 1498 	nop
      000F72 00               [12] 1499 	nop
      000F73 00               [12] 1500 	nop
                                   1501 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1502 ;	assignBit
      000F74 A2 91            [12] 1503 	mov	c,_PORT_P1_1
      000F76 92 09            [24] 1504 	mov	_DS1302_DATA_1,c
                                   1505 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1506 ;	assignBit
      000F78 D2 92            [12] 1507 	setb	_PORT_P1_2
                                   1508 ;	include/ds1302.h:154: __endasm;
      000F7A 00               [12] 1509 	nop
      000F7B 00               [12] 1510 	nop
      000F7C 00               [12] 1511 	nop
      000F7D 00               [12] 1512 	nop
                                   1513 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1514 ;	assignBit
      000F7E C2 92            [12] 1515 	clr	_PORT_P1_2
                                   1516 ;	include/ds1302.h:160: __endasm;
      000F80 00               [12] 1517 	nop
      000F81 00               [12] 1518 	nop
      000F82 00               [12] 1519 	nop
                                   1520 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1521 ;	assignBit
      000F83 A2 91            [12] 1522 	mov	c,_PORT_P1_1
      000F85 92 0A            [24] 1523 	mov	_DS1302_DATA_2,c
                                   1524 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1525 ;	assignBit
      000F87 D2 92            [12] 1526 	setb	_PORT_P1_2
                                   1527 ;	include/ds1302.h:169: __endasm;
      000F89 00               [12] 1528 	nop
      000F8A 00               [12] 1529 	nop
      000F8B 00               [12] 1530 	nop
      000F8C 00               [12] 1531 	nop
                                   1532 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1533 ;	assignBit
      000F8D C2 92            [12] 1534 	clr	_PORT_P1_2
                                   1535 ;	include/ds1302.h:175: __endasm;
      000F8F 00               [12] 1536 	nop
      000F90 00               [12] 1537 	nop
      000F91 00               [12] 1538 	nop
                                   1539 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1540 ;	assignBit
      000F92 A2 91            [12] 1541 	mov	c,_PORT_P1_1
      000F94 92 0B            [24] 1542 	mov	_DS1302_DATA_3,c
                                   1543 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1544 ;	assignBit
      000F96 D2 92            [12] 1545 	setb	_PORT_P1_2
                                   1546 ;	include/ds1302.h:184: __endasm;
      000F98 00               [12] 1547 	nop
      000F99 00               [12] 1548 	nop
      000F9A 00               [12] 1549 	nop
      000F9B 00               [12] 1550 	nop
                                   1551 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1552 ;	assignBit
      000F9C C2 92            [12] 1553 	clr	_PORT_P1_2
                                   1554 ;	include/ds1302.h:190: __endasm;
      000F9E 00               [12] 1555 	nop
      000F9F 00               [12] 1556 	nop
      000FA0 00               [12] 1557 	nop
                                   1558 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1559 ;	assignBit
      000FA1 A2 91            [12] 1560 	mov	c,_PORT_P1_1
      000FA3 92 0C            [24] 1561 	mov	_DS1302_DATA_4,c
                                   1562 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1563 ;	assignBit
      000FA5 D2 92            [12] 1564 	setb	_PORT_P1_2
                                   1565 ;	include/ds1302.h:199: __endasm;
      000FA7 00               [12] 1566 	nop
      000FA8 00               [12] 1567 	nop
      000FA9 00               [12] 1568 	nop
      000FAA 00               [12] 1569 	nop
                                   1570 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1571 ;	assignBit
      000FAB C2 92            [12] 1572 	clr	_PORT_P1_2
                                   1573 ;	include/ds1302.h:205: __endasm;
      000FAD 00               [12] 1574 	nop
      000FAE 00               [12] 1575 	nop
      000FAF 00               [12] 1576 	nop
                                   1577 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1578 ;	assignBit
      000FB0 A2 91            [12] 1579 	mov	c,_PORT_P1_1
      000FB2 92 0D            [24] 1580 	mov	_DS1302_DATA_5,c
                                   1581 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1582 ;	assignBit
      000FB4 D2 92            [12] 1583 	setb	_PORT_P1_2
                                   1584 ;	include/ds1302.h:214: __endasm;
      000FB6 00               [12] 1585 	nop
      000FB7 00               [12] 1586 	nop
      000FB8 00               [12] 1587 	nop
      000FB9 00               [12] 1588 	nop
                                   1589 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1590 ;	assignBit
      000FBA C2 92            [12] 1591 	clr	_PORT_P1_2
                                   1592 ;	include/ds1302.h:220: __endasm;
      000FBC 00               [12] 1593 	nop
      000FBD 00               [12] 1594 	nop
      000FBE 00               [12] 1595 	nop
                                   1596 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1597 ;	assignBit
      000FBF A2 91            [12] 1598 	mov	c,_PORT_P1_1
      000FC1 92 0E            [24] 1599 	mov	_DS1302_DATA_6,c
                                   1600 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1601 ;	assignBit
      000FC3 D2 92            [12] 1602 	setb	_PORT_P1_2
                                   1603 ;	include/ds1302.h:229: __endasm;
      000FC5 00               [12] 1604 	nop
      000FC6 00               [12] 1605 	nop
      000FC7 00               [12] 1606 	nop
      000FC8 00               [12] 1607 	nop
                                   1608 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1609 ;	assignBit
      000FC9 C2 92            [12] 1610 	clr	_PORT_P1_2
                                   1611 ;	include/ds1302.h:235: __endasm;
      000FCB 00               [12] 1612 	nop
      000FCC 00               [12] 1613 	nop
      000FCD 00               [12] 1614 	nop
                                   1615 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1616 ;	assignBit
      000FCE A2 91            [12] 1617 	mov	c,_PORT_P1_1
      000FD0 92 0F            [24] 1618 	mov	_DS1302_DATA_7,c
                                   1619 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1620 ;	assignBit
      000FD2 D2 92            [12] 1621 	setb	_PORT_P1_2
                                   1622 ;	include/ds1302.h:243: __endasm;
      000FD4 00               [12] 1623 	nop
      000FD5 00               [12] 1624 	nop
      000FD6 00               [12] 1625 	nop
      000FD7 00               [12] 1626 	nop
                                   1627 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1628 ;	assignBit
      000FD8 C2 92            [12] 1629 	clr	_PORT_P1_2
                                   1630 ;	include/ds1302.h:246: return DS1302_DATA;
      000FDA E5 21            [12] 1631 	mov	a,_DS1302_DATA
                                   1632 ;	include/ds1302.h:357: ds1302.month   = ds1302_read_byte(); //Read in month register
      000FDC F5 50            [12] 1633 	mov	(_ds1302 + 0x0004),a
                                   1634 ;	include/ds1302.h:358: ds1302.day 	   = ds1302_read_byte(); //Read in day of week register
                                   1635 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                   1636 ;	assignBit
      000FDE D2 91            [12] 1637 	setb	_PORT_P1_1
                                   1638 ;	include/ds1302.h:130: __endasm;
      000FE0 00               [12] 1639 	nop
      000FE1 00               [12] 1640 	nop
      000FE2 00               [12] 1641 	nop
                                   1642 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1643 ;	assignBit
      000FE3 A2 91            [12] 1644 	mov	c,_PORT_P1_1
      000FE5 92 08            [24] 1645 	mov	_DS1302_DATA_0,c
                                   1646 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1647 ;	assignBit
      000FE7 D2 92            [12] 1648 	setb	_PORT_P1_2
                                   1649 ;	include/ds1302.h:139: __endasm;
      000FE9 00               [12] 1650 	nop
      000FEA 00               [12] 1651 	nop
      000FEB 00               [12] 1652 	nop
      000FEC 00               [12] 1653 	nop
                                   1654 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1655 ;	assignBit
      000FED C2 92            [12] 1656 	clr	_PORT_P1_2
                                   1657 ;	include/ds1302.h:145: __endasm;
      000FEF 00               [12] 1658 	nop
      000FF0 00               [12] 1659 	nop
      000FF1 00               [12] 1660 	nop
                                   1661 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1662 ;	assignBit
      000FF2 A2 91            [12] 1663 	mov	c,_PORT_P1_1
      000FF4 92 09            [24] 1664 	mov	_DS1302_DATA_1,c
                                   1665 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1666 ;	assignBit
      000FF6 D2 92            [12] 1667 	setb	_PORT_P1_2
                                   1668 ;	include/ds1302.h:154: __endasm;
      000FF8 00               [12] 1669 	nop
      000FF9 00               [12] 1670 	nop
      000FFA 00               [12] 1671 	nop
      000FFB 00               [12] 1672 	nop
                                   1673 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1674 ;	assignBit
      000FFC C2 92            [12] 1675 	clr	_PORT_P1_2
                                   1676 ;	include/ds1302.h:160: __endasm;
      000FFE 00               [12] 1677 	nop
      000FFF 00               [12] 1678 	nop
      001000 00               [12] 1679 	nop
                                   1680 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1681 ;	assignBit
      001001 A2 91            [12] 1682 	mov	c,_PORT_P1_1
      001003 92 0A            [24] 1683 	mov	_DS1302_DATA_2,c
                                   1684 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1685 ;	assignBit
      001005 D2 92            [12] 1686 	setb	_PORT_P1_2
                                   1687 ;	include/ds1302.h:169: __endasm;
      001007 00               [12] 1688 	nop
      001008 00               [12] 1689 	nop
      001009 00               [12] 1690 	nop
      00100A 00               [12] 1691 	nop
                                   1692 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1693 ;	assignBit
      00100B C2 92            [12] 1694 	clr	_PORT_P1_2
                                   1695 ;	include/ds1302.h:175: __endasm;
      00100D 00               [12] 1696 	nop
      00100E 00               [12] 1697 	nop
      00100F 00               [12] 1698 	nop
                                   1699 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1700 ;	assignBit
      001010 A2 91            [12] 1701 	mov	c,_PORT_P1_1
      001012 92 0B            [24] 1702 	mov	_DS1302_DATA_3,c
                                   1703 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1704 ;	assignBit
      001014 D2 92            [12] 1705 	setb	_PORT_P1_2
                                   1706 ;	include/ds1302.h:184: __endasm;
      001016 00               [12] 1707 	nop
      001017 00               [12] 1708 	nop
      001018 00               [12] 1709 	nop
      001019 00               [12] 1710 	nop
                                   1711 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1712 ;	assignBit
      00101A C2 92            [12] 1713 	clr	_PORT_P1_2
                                   1714 ;	include/ds1302.h:190: __endasm;
      00101C 00               [12] 1715 	nop
      00101D 00               [12] 1716 	nop
      00101E 00               [12] 1717 	nop
                                   1718 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1719 ;	assignBit
      00101F A2 91            [12] 1720 	mov	c,_PORT_P1_1
      001021 92 0C            [24] 1721 	mov	_DS1302_DATA_4,c
                                   1722 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1723 ;	assignBit
      001023 D2 92            [12] 1724 	setb	_PORT_P1_2
                                   1725 ;	include/ds1302.h:199: __endasm;
      001025 00               [12] 1726 	nop
      001026 00               [12] 1727 	nop
      001027 00               [12] 1728 	nop
      001028 00               [12] 1729 	nop
                                   1730 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1731 ;	assignBit
      001029 C2 92            [12] 1732 	clr	_PORT_P1_2
                                   1733 ;	include/ds1302.h:205: __endasm;
      00102B 00               [12] 1734 	nop
      00102C 00               [12] 1735 	nop
      00102D 00               [12] 1736 	nop
                                   1737 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1738 ;	assignBit
      00102E A2 91            [12] 1739 	mov	c,_PORT_P1_1
      001030 92 0D            [24] 1740 	mov	_DS1302_DATA_5,c
                                   1741 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1742 ;	assignBit
      001032 D2 92            [12] 1743 	setb	_PORT_P1_2
                                   1744 ;	include/ds1302.h:214: __endasm;
      001034 00               [12] 1745 	nop
      001035 00               [12] 1746 	nop
      001036 00               [12] 1747 	nop
      001037 00               [12] 1748 	nop
                                   1749 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1750 ;	assignBit
      001038 C2 92            [12] 1751 	clr	_PORT_P1_2
                                   1752 ;	include/ds1302.h:220: __endasm;
      00103A 00               [12] 1753 	nop
      00103B 00               [12] 1754 	nop
      00103C 00               [12] 1755 	nop
                                   1756 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1757 ;	assignBit
      00103D A2 91            [12] 1758 	mov	c,_PORT_P1_1
      00103F 92 0E            [24] 1759 	mov	_DS1302_DATA_6,c
                                   1760 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1761 ;	assignBit
      001041 D2 92            [12] 1762 	setb	_PORT_P1_2
                                   1763 ;	include/ds1302.h:229: __endasm;
      001043 00               [12] 1764 	nop
      001044 00               [12] 1765 	nop
      001045 00               [12] 1766 	nop
      001046 00               [12] 1767 	nop
                                   1768 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1769 ;	assignBit
      001047 C2 92            [12] 1770 	clr	_PORT_P1_2
                                   1771 ;	include/ds1302.h:235: __endasm;
      001049 00               [12] 1772 	nop
      00104A 00               [12] 1773 	nop
      00104B 00               [12] 1774 	nop
                                   1775 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1776 ;	assignBit
      00104C A2 91            [12] 1777 	mov	c,_PORT_P1_1
      00104E 92 0F            [24] 1778 	mov	_DS1302_DATA_7,c
                                   1779 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1780 ;	assignBit
      001050 D2 92            [12] 1781 	setb	_PORT_P1_2
                                   1782 ;	include/ds1302.h:243: __endasm;
      001052 00               [12] 1783 	nop
      001053 00               [12] 1784 	nop
      001054 00               [12] 1785 	nop
      001055 00               [12] 1786 	nop
                                   1787 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1788 ;	assignBit
      001056 C2 92            [12] 1789 	clr	_PORT_P1_2
                                   1790 ;	include/ds1302.h:246: return DS1302_DATA;
      001058 E5 21            [12] 1791 	mov	a,_DS1302_DATA
                                   1792 ;	include/ds1302.h:358: ds1302.day 	   = ds1302_read_byte(); //Read in day of week register
      00105A F5 51            [12] 1793 	mov	(_ds1302 + 0x0005),a
                                   1794 ;	include/ds1302.h:359: ds1302.year    = ds1302_read_byte(); //Read in year register
                                   1795 ;	include/ds1302.h:123: DS1302_IO = 1;		//Stop driving I/O line
                                   1796 ;	assignBit
      00105C D2 91            [12] 1797 	setb	_PORT_P1_1
                                   1798 ;	include/ds1302.h:130: __endasm;
      00105E 00               [12] 1799 	nop
      00105F 00               [12] 1800 	nop
      001060 00               [12] 1801 	nop
                                   1802 ;	include/ds1302.h:131: DS1302_DATA_0 = DS1302_IO;
                                   1803 ;	assignBit
      001061 A2 91            [12] 1804 	mov	c,_PORT_P1_1
      001063 92 08            [24] 1805 	mov	_DS1302_DATA_0,c
                                   1806 ;	include/ds1302.h:133: DS1302_CLK = 1;
                                   1807 ;	assignBit
      001065 D2 92            [12] 1808 	setb	_PORT_P1_2
                                   1809 ;	include/ds1302.h:139: __endasm;
      001067 00               [12] 1810 	nop
      001068 00               [12] 1811 	nop
      001069 00               [12] 1812 	nop
      00106A 00               [12] 1813 	nop
                                   1814 ;	include/ds1302.h:140: DS1302_CLK = 0;
                                   1815 ;	assignBit
      00106B C2 92            [12] 1816 	clr	_PORT_P1_2
                                   1817 ;	include/ds1302.h:145: __endasm;
      00106D 00               [12] 1818 	nop
      00106E 00               [12] 1819 	nop
      00106F 00               [12] 1820 	nop
                                   1821 ;	include/ds1302.h:146: DS1302_DATA_1 = DS1302_IO;
                                   1822 ;	assignBit
      001070 A2 91            [12] 1823 	mov	c,_PORT_P1_1
      001072 92 09            [24] 1824 	mov	_DS1302_DATA_1,c
                                   1825 ;	include/ds1302.h:148: DS1302_CLK = 1;
                                   1826 ;	assignBit
      001074 D2 92            [12] 1827 	setb	_PORT_P1_2
                                   1828 ;	include/ds1302.h:154: __endasm;
      001076 00               [12] 1829 	nop
      001077 00               [12] 1830 	nop
      001078 00               [12] 1831 	nop
      001079 00               [12] 1832 	nop
                                   1833 ;	include/ds1302.h:155: DS1302_CLK = 0;
                                   1834 ;	assignBit
      00107A C2 92            [12] 1835 	clr	_PORT_P1_2
                                   1836 ;	include/ds1302.h:160: __endasm;
      00107C 00               [12] 1837 	nop
      00107D 00               [12] 1838 	nop
      00107E 00               [12] 1839 	nop
                                   1840 ;	include/ds1302.h:161: DS1302_DATA_2 = DS1302_IO;
                                   1841 ;	assignBit
      00107F A2 91            [12] 1842 	mov	c,_PORT_P1_1
      001081 92 0A            [24] 1843 	mov	_DS1302_DATA_2,c
                                   1844 ;	include/ds1302.h:163: DS1302_CLK = 1;
                                   1845 ;	assignBit
      001083 D2 92            [12] 1846 	setb	_PORT_P1_2
                                   1847 ;	include/ds1302.h:169: __endasm;
      001085 00               [12] 1848 	nop
      001086 00               [12] 1849 	nop
      001087 00               [12] 1850 	nop
      001088 00               [12] 1851 	nop
                                   1852 ;	include/ds1302.h:170: DS1302_CLK = 0;
                                   1853 ;	assignBit
      001089 C2 92            [12] 1854 	clr	_PORT_P1_2
                                   1855 ;	include/ds1302.h:175: __endasm;
      00108B 00               [12] 1856 	nop
      00108C 00               [12] 1857 	nop
      00108D 00               [12] 1858 	nop
                                   1859 ;	include/ds1302.h:176: DS1302_DATA_3 = DS1302_IO;
                                   1860 ;	assignBit
      00108E A2 91            [12] 1861 	mov	c,_PORT_P1_1
      001090 92 0B            [24] 1862 	mov	_DS1302_DATA_3,c
                                   1863 ;	include/ds1302.h:178: DS1302_CLK = 1;
                                   1864 ;	assignBit
      001092 D2 92            [12] 1865 	setb	_PORT_P1_2
                                   1866 ;	include/ds1302.h:184: __endasm;
      001094 00               [12] 1867 	nop
      001095 00               [12] 1868 	nop
      001096 00               [12] 1869 	nop
      001097 00               [12] 1870 	nop
                                   1871 ;	include/ds1302.h:185: DS1302_CLK = 0;
                                   1872 ;	assignBit
      001098 C2 92            [12] 1873 	clr	_PORT_P1_2
                                   1874 ;	include/ds1302.h:190: __endasm;
      00109A 00               [12] 1875 	nop
      00109B 00               [12] 1876 	nop
      00109C 00               [12] 1877 	nop
                                   1878 ;	include/ds1302.h:191: DS1302_DATA_4 = DS1302_IO;
                                   1879 ;	assignBit
      00109D A2 91            [12] 1880 	mov	c,_PORT_P1_1
      00109F 92 0C            [24] 1881 	mov	_DS1302_DATA_4,c
                                   1882 ;	include/ds1302.h:193: DS1302_CLK = 1;
                                   1883 ;	assignBit
      0010A1 D2 92            [12] 1884 	setb	_PORT_P1_2
                                   1885 ;	include/ds1302.h:199: __endasm;
      0010A3 00               [12] 1886 	nop
      0010A4 00               [12] 1887 	nop
      0010A5 00               [12] 1888 	nop
      0010A6 00               [12] 1889 	nop
                                   1890 ;	include/ds1302.h:200: DS1302_CLK = 0;
                                   1891 ;	assignBit
      0010A7 C2 92            [12] 1892 	clr	_PORT_P1_2
                                   1893 ;	include/ds1302.h:205: __endasm;
      0010A9 00               [12] 1894 	nop
      0010AA 00               [12] 1895 	nop
      0010AB 00               [12] 1896 	nop
                                   1897 ;	include/ds1302.h:206: DS1302_DATA_5 = DS1302_IO;
                                   1898 ;	assignBit
      0010AC A2 91            [12] 1899 	mov	c,_PORT_P1_1
      0010AE 92 0D            [24] 1900 	mov	_DS1302_DATA_5,c
                                   1901 ;	include/ds1302.h:208: DS1302_CLK = 1;
                                   1902 ;	assignBit
      0010B0 D2 92            [12] 1903 	setb	_PORT_P1_2
                                   1904 ;	include/ds1302.h:214: __endasm;
      0010B2 00               [12] 1905 	nop
      0010B3 00               [12] 1906 	nop
      0010B4 00               [12] 1907 	nop
      0010B5 00               [12] 1908 	nop
                                   1909 ;	include/ds1302.h:215: DS1302_CLK = 0;
                                   1910 ;	assignBit
      0010B6 C2 92            [12] 1911 	clr	_PORT_P1_2
                                   1912 ;	include/ds1302.h:220: __endasm;
      0010B8 00               [12] 1913 	nop
      0010B9 00               [12] 1914 	nop
      0010BA 00               [12] 1915 	nop
                                   1916 ;	include/ds1302.h:221: DS1302_DATA_6 = DS1302_IO;
                                   1917 ;	assignBit
      0010BB A2 91            [12] 1918 	mov	c,_PORT_P1_1
      0010BD 92 0E            [24] 1919 	mov	_DS1302_DATA_6,c
                                   1920 ;	include/ds1302.h:223: DS1302_CLK = 1;
                                   1921 ;	assignBit
      0010BF D2 92            [12] 1922 	setb	_PORT_P1_2
                                   1923 ;	include/ds1302.h:229: __endasm;
      0010C1 00               [12] 1924 	nop
      0010C2 00               [12] 1925 	nop
      0010C3 00               [12] 1926 	nop
      0010C4 00               [12] 1927 	nop
                                   1928 ;	include/ds1302.h:230: DS1302_CLK = 0;
                                   1929 ;	assignBit
      0010C5 C2 92            [12] 1930 	clr	_PORT_P1_2
                                   1931 ;	include/ds1302.h:235: __endasm;
      0010C7 00               [12] 1932 	nop
      0010C8 00               [12] 1933 	nop
      0010C9 00               [12] 1934 	nop
                                   1935 ;	include/ds1302.h:236: DS1302_DATA_7 = DS1302_IO;
                                   1936 ;	assignBit
      0010CA A2 91            [12] 1937 	mov	c,_PORT_P1_1
      0010CC 92 0F            [24] 1938 	mov	_DS1302_DATA_7,c
                                   1939 ;	include/ds1302.h:237: DS1302_CLK = 1;
                                   1940 ;	assignBit
      0010CE D2 92            [12] 1941 	setb	_PORT_P1_2
                                   1942 ;	include/ds1302.h:243: __endasm;
      0010D0 00               [12] 1943 	nop
      0010D1 00               [12] 1944 	nop
      0010D2 00               [12] 1945 	nop
      0010D3 00               [12] 1946 	nop
                                   1947 ;	include/ds1302.h:244: DS1302_CLK = 0;
                                   1948 ;	assignBit
      0010D4 C2 92            [12] 1949 	clr	_PORT_P1_2
                                   1950 ;	include/ds1302.h:246: return DS1302_DATA;
      0010D6 E5 21            [12] 1951 	mov	a,_DS1302_DATA
                                   1952 ;	include/ds1302.h:359: ds1302.year    = ds1302_read_byte(); //Read in year register
      0010D8 F5 52            [12] 1953 	mov	(_ds1302 + 0x0006),a
                                   1954 ;	include/ds1302.h:322: DS1302_CE = 0; //Drop CE to end communication.
                                   1955 ;	assignBit
      0010DA C2 90            [12] 1956 	clr	_PORT_P1_0
                                   1957 ;	src/fsm.c:100: if((alarm_lastpoll != ds1302.minutes) && alarm_global_state()){
      0010DC ED               [12] 1958 	mov	a,r5
      0010DD B5 54 03         [24] 1959 	cjne	a,_alarm_lastpoll,00357$
      0010E0 02 11 7B         [24] 1960 	ljmp	00143$
      0010E3                       1961 00357$:
                                   1962 ;	include/alarm.h:84: return (ds1302_sram_data[3] & 0x01);
      0010E3 90 00 03         [24] 1963 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      0010E6 E0               [24] 1964 	movx	a,@dptr
      0010E7 FD               [12] 1965 	mov	r5,a
      0010E8 20 E0 03         [24] 1966 	jb	acc.0,00358$
      0010EB 02 11 7B         [24] 1967 	ljmp	00143$
      0010EE                       1968 00358$:
                                   1969 ;	src/fsm.c:100: if((alarm_lastpoll != ds1302.minutes) && alarm_global_state()){
                                   1970 ;	src/fsm.c:116: alarm_lastpoll = ds1302.minutes;
      0010EE 7D 00            [12] 1971 	mov	r5,#0x00
      0010F0                       1972 00182$:
                                   1973 ;	src/fsm.c:102: for(;alarm_index < NUM_ALARMS;alarm_index++){
      0010F0 BD 07 00         [24] 1974 	cjne	r5,#0x07,00359$
      0010F3                       1975 00359$:
      0010F3 40 03            [24] 1976 	jc	00360$
      0010F5 02 11 78         [24] 1977 	ljmp	00141$
      0010F8                       1978 00360$:
                                   1979 ;	src/fsm.c:103: if(alarm_dow_state(alarm_index,ds1302.day) && (
      0010F8 C0 06            [24] 1980 	push	ar6
                                   1981 ;	include/alarm.h:106: return ((alarms[index].dow_and_enable >> dow) & 0x01);
      0010FA ED               [12] 1982 	mov	a,r5
      0010FB 75 F0 03         [24] 1983 	mov	b,#0x03
      0010FE A4               [48] 1984 	mul	ab
      0010FF FB               [12] 1985 	mov	r3,a
      001100 AC F0            [24] 1986 	mov	r4,b
      001102 24 04            [12] 1987 	add	a,#_alarms
      001104 FA               [12] 1988 	mov	r2,a
      001105 EC               [12] 1989 	mov	a,r4
      001106 34 00            [12] 1990 	addc	a,#(_alarms >> 8)
      001108 FE               [12] 1991 	mov	r6,a
      001109 8A 82            [24] 1992 	mov	dpl,r2
      00110B 8E 83            [24] 1993 	mov	dph,r6
      00110D A3               [24] 1994 	inc	dptr
      00110E A3               [24] 1995 	inc	dptr
      00110F E0               [24] 1996 	movx	a,@dptr
      001110 FE               [12] 1997 	mov	r6,a
      001111 85 51 F0         [24] 1998 	mov	b,(_ds1302 + 0x0005)
      001114 05 F0            [12] 1999 	inc	b
      001116 EE               [12] 2000 	mov	a,r6
      001117 80 02            [24] 2001 	sjmp	00362$
      001119                       2002 00361$:
      001119 C3               [12] 2003 	clr	c
      00111A 13               [12] 2004 	rrc	a
      00111B                       2005 00362$:
      00111B D5 F0 FB         [24] 2006 	djnz	b,00361$
      00111E D0 06            [24] 2007 	pop	ar6
      001120 30 E0 51         [24] 2008 	jnb	acc.0,00183$
                                   2009 ;	src/fsm.c:103: if(alarm_dow_state(alarm_index,ds1302.day) && (
                                   2010 ;	src/fsm.c:104: alarms[alarm_index].dow_and_enable & 0x01)){
      001123 C0 06            [24] 2011 	push	ar6
      001125 EB               [12] 2012 	mov	a,r3
      001126 24 04            [12] 2013 	add	a,#_alarms
      001128 FA               [12] 2014 	mov	r2,a
      001129 EC               [12] 2015 	mov	a,r4
      00112A 34 00            [12] 2016 	addc	a,#(_alarms >> 8)
      00112C FE               [12] 2017 	mov	r6,a
      00112D 8A 82            [24] 2018 	mov	dpl,r2
      00112F 8E 83            [24] 2019 	mov	dph,r6
      001131 A3               [24] 2020 	inc	dptr
      001132 A3               [24] 2021 	inc	dptr
      001133 E0               [24] 2022 	movx	a,@dptr
      001134 D0 06            [24] 2023 	pop	ar6
      001136 30 E0 3B         [24] 2024 	jnb	acc.0,00183$
                                   2025 ;	src/fsm.c:105: if((alarms[alarm_index].hour == ds1302.hour) &&
      001139 EB               [12] 2026 	mov	a,r3
      00113A 24 04            [12] 2027 	add	a,#_alarms
      00113C F5 82            [12] 2028 	mov	dpl,a
      00113E EC               [12] 2029 	mov	a,r4
      00113F 34 00            [12] 2030 	addc	a,#(_alarms >> 8)
      001141 F5 83            [12] 2031 	mov	dph,a
      001143 E0               [24] 2032 	movx	a,@dptr
      001144 FA               [12] 2033 	mov	r2,a
      001145 B5 4E 2C         [24] 2034 	cjne	a,(_ds1302 + 0x0002),00183$
                                   2035 ;	src/fsm.c:106: (alarms[alarm_index].minute == ds1302.minutes)){
      001148 EB               [12] 2036 	mov	a,r3
      001149 24 04            [12] 2037 	add	a,#_alarms
      00114B FB               [12] 2038 	mov	r3,a
      00114C EC               [12] 2039 	mov	a,r4
      00114D 34 00            [12] 2040 	addc	a,#(_alarms >> 8)
      00114F FC               [12] 2041 	mov	r4,a
      001150 8B 82            [24] 2042 	mov	dpl,r3
      001152 8C 83            [24] 2043 	mov	dph,r4
      001154 A3               [24] 2044 	inc	dptr
      001155 E0               [24] 2045 	movx	a,@dptr
      001156 FC               [12] 2046 	mov	r4,a
      001157 B5 4D 1A         [24] 2047 	cjne	a,(_ds1302 + 0x0001),00183$
                                   2048 ;	include/alarm.h:130: INT_IE2 &= 0xfb;
      00115A 53 AF FB         [24] 2049 	anl	_INT_IE2,#0xfb
                                   2050 ;	include/alarm.h:131: alarm_counter = 0x00;
      00115D E4               [12] 2051 	clr	a
      00115E F5 3B            [12] 2052 	mov	_alarm_counter,a
      001160 F5 3C            [12] 2053 	mov	(_alarm_counter + 1),a
                                   2054 ;	include/alarm.h:132: INT_IE2 |= 0x04;
      001162 43 AF 04         [24] 2055 	orl	_INT_IE2,#0x04
                                   2056 ;	src/fsm.c:108: display_autobrightness = 0;
                                   2057 ;	assignBit
      001165 C2 1F            [12] 2058 	clr	_display_autobrightness
                                   2059 ;	src/fsm.c:109: INT_IE_EA = 0;
                                   2060 ;	assignBit
      001167 C2 AF            [12] 2061 	clr	_INT_IE_EA
                                   2062 ;	src/fsm.c:110: display_counts = DISPLAY_COUNTS_MAX;
      001169 75 48 00         [24] 2063 	mov	_display_counts,#0x00
      00116C 75 49 EA         [24] 2064 	mov	(_display_counts + 1),#0xea
                                   2065 ;	src/fsm.c:111: INT_IE_EA = 1;
                                   2066 ;	assignBit
      00116F D2 AF            [12] 2067 	setb	_INT_IE_EA
                                   2068 ;	src/fsm.c:112: curstate = fsm_home_alarm;
      001171 75 57 07         [24] 2069 	mov	_fsm_home_fn_curstate_65536_174,#0x07
      001174                       2070 00183$:
                                   2071 ;	src/fsm.c:102: for(;alarm_index < NUM_ALARMS;alarm_index++){
      001174 0D               [12] 2072 	inc	r5
      001175 02 10 F0         [24] 2073 	ljmp	00182$
      001178                       2074 00141$:
                                   2075 ;	src/fsm.c:116: alarm_lastpoll = ds1302.minutes;
      001178 85 4D 54         [24] 2076 	mov	_alarm_lastpoll,(_ds1302 + 0x0001)
      00117B                       2077 00143$:
                                   2078 ;	src/fsm.c:119: switch(curstate) {
      00117B E5 57            [12] 2079 	mov	a,_fsm_home_fn_curstate_65536_174
      00117D 24 F8            [12] 2080 	add	a,#0xff - 0x07
      00117F 50 03            [24] 2081 	jnc	00369$
      001181 02 12 96         [24] 2082 	ljmp	00163$
      001184                       2083 00369$:
      001184 E5 57            [12] 2084 	mov	a,_fsm_home_fn_curstate_65536_174
      001186 24 0B            [12] 2085 	add	a,#(00370$-3-.)
      001188 83               [24] 2086 	movc	a,@a+pc
      001189 F5 82            [12] 2087 	mov	dpl,a
      00118B E5 57            [12] 2088 	mov	a,_fsm_home_fn_curstate_65536_174
      00118D 24 0C            [12] 2089 	add	a,#(00371$-3-.)
      00118F 83               [24] 2090 	movc	a,@a+pc
      001190 F5 83            [12] 2091 	mov	dph,a
      001192 E4               [12] 2092 	clr	a
      001193 73               [24] 2093 	jmp	@a+dptr
      001194                       2094 00370$:
      001194 A4                    2095 	.db	00146$
      001195 E3                    2096 	.db	00154$
      001196 03                    2097 	.db	00157$
      001197 61                    2098 	.db	00160$
      001198 88                    2099 	.db	00161$
      001199 8D                    2100 	.db	00162$
      00119A 96                    2101 	.db	00163$
      00119B A4                    2102 	.db	00146$
      00119C                       2103 00371$:
      00119C 11                    2104 	.db	00146$>>8
      00119D 11                    2105 	.db	00154$>>8
      00119E 12                    2106 	.db	00157$>>8
      00119F 12                    2107 	.db	00160$>>8
      0011A0 12                    2108 	.db	00161$>>8
      0011A1 12                    2109 	.db	00162$>>8
      0011A2 12                    2110 	.db	00163$>>8
      0011A3 11                    2111 	.db	00146$>>8
                                   2112 ;	src/fsm.c:121: case fsm_home_time:
      0011A4                       2113 00146$:
                                   2114 ;	src/fsm.c:123: if(curstate == fsm_home_alarm){
      0011A4 74 07            [12] 2115 	mov	a,#0x07
      0011A6 B5 57 1A         [24] 2116 	cjne	a,_fsm_home_fn_curstate_65536_174,00151$
                                   2117 ;	src/fsm.c:124: display_flash = 0x0f;
      0011A9 75 47 0F         [24] 2118 	mov	_display_flash,#0x0f
                                   2119 ;	src/fsm.c:125: if((menu_state == BUTTON_LONG_PRESSED) && (select_state == BUTTON_LONG_PRESSED)){
      0011AC BF 01 14         [24] 2120 	cjne	r7,#0x01,00151$
      0011AF BE 01 11         [24] 2121 	cjne	r6,#0x01,00151$
                                   2122 ;	src/fsm.c:126: display_flash = 0x00;
      0011B2 75 47 00         [24] 2123 	mov	_display_flash,#0x00
                                   2124 ;	include/alarm.h:149: INT_IE2 &= 0xfb;
      0011B5 53 AF FB         [24] 2125 	anl	_INT_IE2,#0xfb
                                   2126 ;	include/alarm.h:150: INT_IE_EA = 0;
                                   2127 ;	assignBit
      0011B8 C2 AF            [12] 2128 	clr	_INT_IE_EA
                                   2129 ;	include/alarm.h:151: ALARM_BUZZER_DRIVE_INACTIVE();
                                   2130 ;	assignBit
      0011BA D2 95            [12] 2131 	setb	_PORT_P1_5
                                   2132 ;	include/alarm.h:152: INT_IE_EA = 1;
                                   2133 ;	assignBit
      0011BC D2 AF            [12] 2134 	setb	_INT_IE_EA
                                   2135 ;	src/fsm.c:128: display_autobrightness = 1;
                                   2136 ;	assignBit
      0011BE D2 1F            [12] 2137 	setb	_display_autobrightness
                                   2138 ;	src/fsm.c:129: curstate = fsm_home_start; //Reset state back to default
      0011C0 75 57 00         [24] 2139 	mov	_fsm_home_fn_curstate_65536_174,#0x00
      0011C3                       2140 00151$:
                                   2141 ;	src/fsm.c:132: display_puttime(ds1302.hour,ds1302.minutes);
      0011C3 85 4E 82         [24] 2142 	mov	dpl,(_ds1302 + 0x0002)
      0011C6 85 4D 4A         [24] 2143 	mov	_display_puttime_PARM_2,(_ds1302 + 0x0001)
      0011C9 12 07 77         [24] 2144 	lcall	_display_puttime
                                   2145 ;	src/fsm.c:133: if(ds1302.seconds % 2)
      0011CC E5 4C            [12] 2146 	mov	a,_ds1302
      0011CE 20 E0 03         [24] 2147 	jb	acc.0,00378$
      0011D1 02 12 96         [24] 2148 	ljmp	00163$
      0011D4                       2149 00378$:
                                   2150 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      0011D4 74 7F            [12] 2151 	mov	a,#0x7f
      0011D6 55 43            [12] 2152 	anl	a,(_display_buffer + 0x0001)
      0011D8 F5 43            [12] 2153 	mov	(_display_buffer + 0x0001),a
                                   2154 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      0011DA 74 7F            [12] 2155 	mov	a,#0x7f
      0011DC 55 44            [12] 2156 	anl	a,(_display_buffer + 0x0002)
      0011DE F5 44            [12] 2157 	mov	(_display_buffer + 0x0002),a
                                   2158 ;	src/fsm.c:135: break;
      0011E0 02 12 96         [24] 2159 	ljmp	00163$
                                   2160 ;	src/fsm.c:136: case fsm_home_mmss:
      0011E3                       2161 00154$:
                                   2162 ;	src/fsm.c:138: display_putbcd(ds1302.minutes,ds1302.seconds);
      0011E3 85 4D 82         [24] 2163 	mov	dpl,(_ds1302 + 0x0001)
      0011E6 85 4C 60         [24] 2164 	mov	_display_putbcd_PARM_2,_ds1302
      0011E9 12 07 33         [24] 2165 	lcall	_display_putbcd
                                   2166 ;	src/fsm.c:139: if(ds1302.seconds % 2)
      0011EC E5 4C            [12] 2167 	mov	a,_ds1302
      0011EE 20 E0 03         [24] 2168 	jb	acc.0,00379$
      0011F1 02 12 96         [24] 2169 	ljmp	00163$
      0011F4                       2170 00379$:
                                   2171 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      0011F4 74 7F            [12] 2172 	mov	a,#0x7f
      0011F6 55 43            [12] 2173 	anl	a,(_display_buffer + 0x0001)
      0011F8 F5 43            [12] 2174 	mov	(_display_buffer + 0x0001),a
                                   2175 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      0011FA 74 7F            [12] 2176 	mov	a,#0x7f
      0011FC 55 44            [12] 2177 	anl	a,(_display_buffer + 0x0002)
      0011FE F5 44            [12] 2178 	mov	(_display_buffer + 0x0002),a
                                   2179 ;	src/fsm.c:141: break;
      001200 02 12 96         [24] 2180 	ljmp	00163$
                                   2181 ;	src/fsm.c:142: case fsm_home_temp:
      001203                       2182 00157$:
                                   2183 ;	src/fsm.c:143: temp_cache = EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()];
                                   2184 ;	include/adc.h:147: INT_IE_EADC = 0;				//Disable ADC interrupt
                                   2185 ;	assignBit
      001203 C2 AD            [12] 2186 	clr	_INT_IE_EADC
                                   2187 ;	include/adc.h:148: tmp = adc_thermistor_reading;	//Store temporary result
      001205 AE 2B            [24] 2188 	mov	r6,_adc_thermistor_reading
      001207 AF 2C            [24] 2189 	mov	r7,(_adc_thermistor_reading + 1)
                                   2190 ;	include/adc.h:149: INT_IE_EADC = 1;				//Enable ADC interrupt
                                   2191 ;	assignBit
      001209 D2 AD            [12] 2192 	setb	_INT_IE_EADC
                                   2193 ;	src/fsm.c:143: temp_cache = EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()];
      00120B EE               [12] 2194 	mov	a,r6
      00120C 2E               [12] 2195 	add	a,r6
      00120D FE               [12] 2196 	mov	r6,a
      00120E EF               [12] 2197 	mov	a,r7
      00120F 33               [12] 2198 	rlc	a
      001210 FF               [12] 2199 	mov	r7,a
      001211 8E 82            [24] 2200 	mov	dpl,r6
      001213 74 28            [12] 2201 	mov	a,#(_EEPROM_TEMP_FROM_THERMISTOR_TABLE >> 8)
      001215 2F               [12] 2202 	add	a,r7
      001216 F5 83            [12] 2203 	mov	dph,a
      001218 E4               [12] 2204 	clr	a
      001219 93               [24] 2205 	movc	a,@a+dptr
      00121A FE               [12] 2206 	mov	r6,a
      00121B A3               [24] 2207 	inc	dptr
      00121C E4               [12] 2208 	clr	a
      00121D 93               [24] 2209 	movc	a,@a+dptr
      00121E FF               [12] 2210 	mov	r7,a
                                   2211 ;	src/fsm.c:144: temp_cache = bcd_add_16(temp_cache,(ds1302_sram_data[DS1302_BBSRAM_SIZE-2] |
      00121F 90 00 1D         [24] 2212 	mov	dptr,#(_ds1302_sram_data + 0x001d)
      001222 E0               [24] 2213 	movx	a,@dptr
      001223 FD               [12] 2214 	mov	r5,a
                                   2215 ;	src/fsm.c:145: (ds1302_sram_data[DS1302_BBSRAM_SIZE-1] << 0x08)));
      001224 90 00 1E         [24] 2216 	mov	dptr,#(_ds1302_sram_data + 0x001e)
      001227 E0               [24] 2217 	movx	a,@dptr
      001228 FB               [12] 2218 	mov	r3,a
      001229 E4               [12] 2219 	clr	a
      00122A FC               [12] 2220 	mov	r4,a
      00122B FA               [12] 2221 	mov	r2,a
      00122C ED               [12] 2222 	mov	a,r5
      00122D 42 04            [12] 2223 	orl	ar4,a
      00122F EA               [12] 2224 	mov	a,r2
      001230 42 03            [12] 2225 	orl	ar3,a
      001232 8C 60            [24] 2226 	mov	_bcd_add_16_PARM_2,r4
      001234 8B 61            [24] 2227 	mov	(_bcd_add_16_PARM_2 + 1),r3
      001236 8E 82            [24] 2228 	mov	dpl,r6
      001238 8F 83            [24] 2229 	mov	dph,r7
      00123A 12 0B AE         [24] 2230 	lcall	_bcd_add_16
      00123D AE 82            [24] 2231 	mov	r6,dpl
      00123F AF 83            [24] 2232 	mov	r7,dph
                                   2233 ;	src/fsm.c:146: if(temp_cache > 0x0999)
      001241 8E 04            [24] 2234 	mov	ar4,r6
      001243 8F 05            [24] 2235 	mov	ar5,r7
      001245 C3               [12] 2236 	clr	c
      001246 74 99            [12] 2237 	mov	a,#0x99
      001248 9C               [12] 2238 	subb	a,r4
      001249 74 09            [12] 2239 	mov	a,#0x09
      00124B 9D               [12] 2240 	subb	a,r5
      00124C 50 04            [24] 2241 	jnc	00159$
                                   2242 ;	src/fsm.c:147: temp_cache = 0x0999;
      00124E 7E 99            [12] 2243 	mov	r6,#0x99
      001250 7F 09            [12] 2244 	mov	r7,#0x09
      001252                       2245 00159$:
                                   2246 ;	src/fsm.c:148: display_puttemp(temp_cache);
      001252 8E 82            [24] 2247 	mov	dpl,r6
      001254 8F 83            [24] 2248 	mov	dph,r7
      001256 12 08 38         [24] 2249 	lcall	_display_puttemp
                                   2250 ;	include/display.h:146: display_buffer[1] &= 0x7f;
      001259 74 7F            [12] 2251 	mov	a,#0x7f
      00125B 55 43            [12] 2252 	anl	a,(_display_buffer + 0x0001)
      00125D F5 43            [12] 2253 	mov	(_display_buffer + 0x0001),a
                                   2254 ;	src/fsm.c:150: break;
                                   2255 ;	src/fsm.c:151: case fsm_home_dow:
      00125F 80 35            [24] 2256 	sjmp	00163$
      001261                       2257 00160$:
                                   2258 ;	src/fsm.c:152: display_puts(ledstrings[ds1302.day-1]);
      001261 AE 51            [24] 2259 	mov	r6,(_ds1302 + 0x0005)
      001263 7F 00            [12] 2260 	mov	r7,#0x00
      001265 EE               [12] 2261 	mov	a,r6
      001266 24 FF            [12] 2262 	add	a,#0xff
      001268 F5 60            [12] 2263 	mov	__mulint_PARM_2,a
      00126A EF               [12] 2264 	mov	a,r7
      00126B 34 FF            [12] 2265 	addc	a,#0xff
      00126D F5 61            [12] 2266 	mov	(__mulint_PARM_2 + 1),a
      00126F 90 00 05         [24] 2267 	mov	dptr,#0x0005
      001272 12 1C 67         [24] 2268 	lcall	__mulint
      001275 AE 82            [24] 2269 	mov	r6,dpl
      001277 AF 83            [24] 2270 	mov	r7,dph
      001279 EE               [12] 2271 	mov	a,r6
      00127A 24 00            [12] 2272 	add	a,#_ledstrings
      00127C F5 82            [12] 2273 	mov	dpl,a
      00127E EF               [12] 2274 	mov	a,r7
      00127F 34 31            [12] 2275 	addc	a,#(_ledstrings >> 8)
      001281 F5 83            [12] 2276 	mov	dph,a
      001283 12 06 F8         [24] 2277 	lcall	_display_puts
                                   2278 ;	src/fsm.c:153: break;
                                   2279 ;	src/fsm.c:154: case fsm_home_date:
      001286 80 0E            [24] 2280 	sjmp	00163$
      001288                       2281 00161$:
                                   2282 ;	src/fsm.c:155: display_putdate();
      001288 12 07 C5         [24] 2283 	lcall	_display_putdate
                                   2284 ;	src/fsm.c:156: break;
                                   2285 ;	src/fsm.c:157: case fsm_home_yyyy:
      00128B 80 09            [24] 2286 	sjmp	00163$
      00128D                       2287 00162$:
                                   2288 ;	src/fsm.c:159: display_putbcd(0x20,ds1302.year);
      00128D 85 52 60         [24] 2289 	mov	_display_putbcd_PARM_2,(_ds1302 + 0x0006)
      001290 75 82 20         [24] 2290 	mov	dpl,#0x20
      001293 12 07 33         [24] 2291 	lcall	_display_putbcd
                                   2292 ;	src/fsm.c:161: }
      001296                       2293 00163$:
                                   2294 ;	src/fsm.c:163: return fsm_repeat;	//Return repeat so we come back to this state.
      001296 75 82 01         [24] 2295 	mov	dpl,#0x01
                                   2296 ;	src/fsm.c:164: }
      001299 22               [24] 2297 	ret
                                   2298 ;------------------------------------------------------------
                                   2299 ;Allocation info for local variables in function 'fsm_set_fn'
                                   2300 ;------------------------------------------------------------
                                   2301 ;fsm_set_temp              Allocated to registers r5 
                                   2302 ;menu_state                Allocated to registers r7 
                                   2303 ;select_state              Allocated to registers r6 
                                   2304 ;curstate                  Allocated with name '_fsm_set_fn_curstate_65536_250'
                                   2305 ;------------------------------------------------------------
                                   2306 ;	src/fsm.c:166: enum fsm_return fsm_set_fn() __reentrant {
                                   2307 ;	-----------------------------------------
                                   2308 ;	 function fsm_set_fn
                                   2309 ;	-----------------------------------------
      00129A                       2310 _fsm_set_fn:
                                   2311 ;	src/fsm.c:172: menu_state = button_read_and_clear_menu();
      00129A 12 06 6C         [24] 2312 	lcall	_button_read_and_clear_menu
      00129D AF 82            [24] 2313 	mov	r7,dpl
                                   2314 ;	src/fsm.c:173: select_state = button_read_and_clear_select();
      00129F C0 07            [24] 2315 	push	ar7
      0012A1 12 06 40         [24] 2316 	lcall	_button_read_and_clear_select
      0012A4 AE 82            [24] 2317 	mov	r6,dpl
      0012A6 D0 07            [24] 2318 	pop	ar7
                                   2319 ;	src/fsm.c:175: if(curstate != fsm_set_label){
      0012A8 E5 58            [12] 2320 	mov	a,_fsm_set_fn_curstate_65536_250
      0012AA 60 20            [24] 2321 	jz	00108$
                                   2322 ;	src/fsm.c:176: if(menu_state == BUTTON_LONG_PRESSED){
      0012AC BF 01 10         [24] 2323 	cjne	r7,#0x01,00102$
                                   2324 ;	src/fsm.c:178: display_flash = 0x00;
      0012AF 75 47 00         [24] 2325 	mov	_display_flash,#0x00
                                   2326 ;	src/fsm.c:179: ds1302_set_time();		  //Set new time
      0012B2 12 0A 81         [24] 2327 	lcall	_ds1302_set_time
                                   2328 ;	src/fsm.c:180: alarm_lastpoll = 0x60;	  //Reset last poll time, force compare
      0012B5 75 54 60         [24] 2329 	mov	_alarm_lastpoll,#0x60
                                   2330 ;	src/fsm.c:181: curstate = fsm_set_label; //Set state back to default
      0012B8 75 58 00         [24] 2331 	mov	_fsm_set_fn_curstate_65536_250,#0x00
                                   2332 ;	src/fsm.c:182: return fsm_ok;
      0012BB 75 82 00         [24] 2333 	mov	dpl,#0x00
      0012BE 22               [24] 2334 	ret
      0012BF                       2335 00102$:
                                   2336 ;	src/fsm.c:184: if(menu_state == BUTTON_PRESSED){
      0012BF EF               [12] 2337 	mov	a,r7
      0012C0 70 0A            [24] 2338 	jnz	00108$
                                   2339 ;	src/fsm.c:186: if(++curstate == fsm_set_end)
      0012C2 05 58            [12] 2340 	inc	_fsm_set_fn_curstate_65536_250
      0012C4 74 07            [12] 2341 	mov	a,#0x07
      0012C6 B5 58 03         [24] 2342 	cjne	a,_fsm_set_fn_curstate_65536_250,00108$
                                   2343 ;	src/fsm.c:187: curstate = fsm_set_start;
      0012C9 75 58 01         [24] 2344 	mov	_fsm_set_fn_curstate_65536_250,#0x01
      0012CC                       2345 00108$:
                                   2346 ;	src/fsm.c:191: fsm_set_temp = 0;
      0012CC 7D 00            [12] 2347 	mov	r5,#0x00
                                   2348 ;	src/fsm.c:192: if((select_state == BUTTON_PRESSED) || (select_state == BUTTON_HELD_DOWN))
      0012CE EE               [12] 2349 	mov	a,r6
      0012CF 60 03            [24] 2350 	jz	00109$
      0012D1 BE 02 02         [24] 2351 	cjne	r6,#0x02,00110$
      0012D4                       2352 00109$:
                                   2353 ;	src/fsm.c:193: fsm_set_temp = 1;
      0012D4 7D 01            [12] 2354 	mov	r5,#0x01
      0012D6                       2355 00110$:
                                   2356 ;	src/fsm.c:196: switch(curstate) {
      0012D6 E5 58            [12] 2357 	mov	a,_fsm_set_fn_curstate_65536_250
      0012D8 24 F9            [12] 2358 	add	a,#0xff - 0x06
      0012DA 50 03            [24] 2359 	jnc	00242$
      0012DC 02 14 21         [24] 2360 	ljmp	00149$
      0012DF                       2361 00242$:
      0012DF E5 58            [12] 2362 	mov	a,_fsm_set_fn_curstate_65536_250
      0012E1 75 F0 03         [24] 2363 	mov	b,#0x03
      0012E4 A4               [48] 2364 	mul	ab
      0012E5 90 12 E9         [24] 2365 	mov	dptr,#00243$
      0012E8 73               [24] 2366 	jmp	@a+dptr
      0012E9                       2367 00243$:
      0012E9 02 12 FE         [24] 2368 	ljmp	00112$
      0012EC 02 13 13         [24] 2369 	ljmp	00118$
      0012EF 02 13 13         [24] 2370 	ljmp	00118$
      0012F2 02 13 67         [24] 2371 	ljmp	00128$
      0012F5 02 13 67         [24] 2372 	ljmp	00128$
      0012F8 02 13 C5         [24] 2373 	ljmp	00143$
      0012FB 02 13 E6         [24] 2374 	ljmp	00146$
                                   2375 ;	src/fsm.c:197: case fsm_set_label:
      0012FE                       2376 00112$:
                                   2377 ;	src/fsm.c:198: if(select_state == BUTTON_PRESSED)
      0012FE EE               [12] 2378 	mov	a,r6
      0012FF 70 02            [24] 2379 	jnz	00114$
                                   2380 ;	src/fsm.c:199: curstate++;
      001301 05 58            [12] 2381 	inc	_fsm_set_fn_curstate_65536_250
      001303                       2382 00114$:
                                   2383 ;	src/fsm.c:200: if(menu_state == BUTTON_PRESSED)
      001303 EF               [12] 2384 	mov	a,r7
      001304 70 04            [24] 2385 	jnz	00116$
                                   2386 ;	src/fsm.c:201: return fsm_fail;
      001306 75 82 02         [24] 2387 	mov	dpl,#0x02
      001309 22               [24] 2388 	ret
      00130A                       2389 00116$:
                                   2390 ;	src/fsm.c:202: display_puts(ledstrings[ledstrings_setc]);
      00130A 90 31 23         [24] 2391 	mov	dptr,#(_ledstrings + 0x0023)
      00130D 12 06 F8         [24] 2392 	lcall	_display_puts
                                   2393 ;	src/fsm.c:203: break;
      001310 02 14 21         [24] 2394 	ljmp	00149$
                                   2395 ;	src/fsm.c:205: case fsm_set_mm:
      001313                       2396 00118$:
                                   2397 ;	src/fsm.c:206: if(curstate == fsm_set_hh){
      001313 74 01            [12] 2398 	mov	a,#0x01
      001315 B5 58 1B         [24] 2399 	cjne	a,_fsm_set_fn_curstate_65536_250,00122$
                                   2400 ;	src/fsm.c:207: ds1302.hour = bcd_add(ds1302.hour,fsm_set_temp);
      001318 8D 60            [24] 2401 	mov	_bcd_add_PARM_2,r5
      00131A 85 4E 82         [24] 2402 	mov	dpl,(_ds1302 + 0x0002)
      00131D C0 05            [24] 2403 	push	ar5
      00131F 12 0B 9E         [24] 2404 	lcall	_bcd_add
      001322 AF 82            [24] 2405 	mov	r7,dpl
      001324 D0 05            [24] 2406 	pop	ar5
                                   2407 ;	src/fsm.c:208: if(ds1302.hour > 0x23)
      001326 EF               [12] 2408 	mov	a,r7
      001327 F5 4E            [12] 2409 	mov	(_ds1302 + 0x0002),a
      001329 24 DC            [12] 2410 	add	a,#0xff - 0x23
      00132B 50 03            [24] 2411 	jnc	00120$
                                   2412 ;	src/fsm.c:209: ds1302.hour = 0x00;
      00132D 75 4E 00         [24] 2413 	mov	(_ds1302 + 0x0002),#0x00
      001330                       2414 00120$:
                                   2415 ;	src/fsm.c:210: display_flash = 0x03;
      001330 75 47 03         [24] 2416 	mov	_display_flash,#0x03
      001333                       2417 00122$:
                                   2418 ;	src/fsm.c:212: if(curstate == fsm_set_mm){
      001333 74 02            [12] 2419 	mov	a,#0x02
      001335 B5 58 17         [24] 2420 	cjne	a,_fsm_set_fn_curstate_65536_250,00126$
                                   2421 ;	src/fsm.c:213: ds1302.minutes = bcd_add(ds1302.minutes,fsm_set_temp);
      001338 8D 60            [24] 2422 	mov	_bcd_add_PARM_2,r5
      00133A 85 4D 82         [24] 2423 	mov	dpl,(_ds1302 + 0x0001)
      00133D 12 0B 9E         [24] 2424 	lcall	_bcd_add
                                   2425 ;	src/fsm.c:214: if(ds1302.minutes > 0x59)
      001340 E5 82            [12] 2426 	mov	a,dpl
      001342 FF               [12] 2427 	mov	r7,a
      001343 F5 4D            [12] 2428 	mov	(_ds1302 + 0x0001),a
      001345 24 A6            [12] 2429 	add	a,#0xff - 0x59
      001347 50 03            [24] 2430 	jnc	00124$
                                   2431 ;	src/fsm.c:215: ds1302.minutes = 0;
      001349 75 4D 00         [24] 2432 	mov	(_ds1302 + 0x0001),#0x00
      00134C                       2433 00124$:
                                   2434 ;	src/fsm.c:216: display_flash = 0x0c;
      00134C 75 47 0C         [24] 2435 	mov	_display_flash,#0x0c
      00134F                       2436 00126$:
                                   2437 ;	src/fsm.c:218: display_puttime(ds1302.hour,ds1302.minutes);
      00134F 85 4E 82         [24] 2438 	mov	dpl,(_ds1302 + 0x0002)
      001352 85 4D 4A         [24] 2439 	mov	_display_puttime_PARM_2,(_ds1302 + 0x0001)
      001355 12 07 77         [24] 2440 	lcall	_display_puttime
                                   2441 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      001358 74 7F            [12] 2442 	mov	a,#0x7f
      00135A 55 43            [12] 2443 	anl	a,(_display_buffer + 0x0001)
      00135C F5 43            [12] 2444 	mov	(_display_buffer + 0x0001),a
                                   2445 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      00135E 74 7F            [12] 2446 	mov	a,#0x7f
      001360 55 44            [12] 2447 	anl	a,(_display_buffer + 0x0002)
      001362 F5 44            [12] 2448 	mov	(_display_buffer + 0x0002),a
                                   2449 ;	src/fsm.c:220: break;
      001364 02 14 21         [24] 2450 	ljmp	00149$
                                   2451 ;	src/fsm.c:222: case fsm_set_month:
      001367                       2452 00128$:
                                   2453 ;	src/fsm.c:223: if(curstate == fsm_set_dd){
      001367 74 03            [12] 2454 	mov	a,#0x03
      001369 B5 58 2A         [24] 2455 	cjne	a,_fsm_set_fn_curstate_65536_250,00135$
                                   2456 ;	src/fsm.c:224: ds1302.date = bcd_add(ds1302.date,fsm_set_temp);
      00136C 8D 60            [24] 2457 	mov	_bcd_add_PARM_2,r5
      00136E 85 4F 82         [24] 2458 	mov	dpl,(_ds1302 + 0x0003)
      001371 C0 05            [24] 2459 	push	ar5
      001373 12 0B 9E         [24] 2460 	lcall	_bcd_add
      001376 AF 82            [24] 2461 	mov	r7,dpl
      001378 D0 05            [24] 2462 	pop	ar5
                                   2463 ;	src/fsm.c:225: if(ds1302.date > 0x31)
      00137A EF               [12] 2464 	mov	a,r7
      00137B F5 4F            [12] 2465 	mov	(_ds1302 + 0x0003),a
      00137D 24 CE            [12] 2466 	add	a,#0xff - 0x31
      00137F 50 03            [24] 2467 	jnc	00130$
                                   2468 ;	src/fsm.c:227: ds1302.date = 0x00;
      001381 75 4F 00         [24] 2469 	mov	(_ds1302 + 0x0003),#0x00
      001384                       2470 00130$:
                                   2471 ;	src/fsm.c:228: if(DATE_DISPLAY_MMDD)
      001384 90 00 03         [24] 2472 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      001387 E0               [24] 2473 	movx	a,@dptr
      001388 23               [12] 2474 	rl	a
      001389 54 01            [12] 2475 	anl	a,#0x01
      00138B FF               [12] 2476 	mov	r7,a
      00138C 60 05            [24] 2477 	jz	00132$
                                   2478 ;	src/fsm.c:229: display_flash = 0x0c;
      00138E 75 47 0C         [24] 2479 	mov	_display_flash,#0x0c
      001391 80 03            [24] 2480 	sjmp	00135$
      001393                       2481 00132$:
                                   2482 ;	src/fsm.c:231: display_flash = 0x03;
      001393 75 47 03         [24] 2483 	mov	_display_flash,#0x03
      001396                       2484 00135$:
                                   2485 ;	src/fsm.c:233: if(curstate == fsm_set_month){
      001396 74 04            [12] 2486 	mov	a,#0x04
      001398 B5 58 25         [24] 2487 	cjne	a,_fsm_set_fn_curstate_65536_250,00142$
                                   2488 ;	src/fsm.c:234: ds1302.month = bcd_add(ds1302.month,fsm_set_temp);
      00139B 8D 60            [24] 2489 	mov	_bcd_add_PARM_2,r5
      00139D 85 50 82         [24] 2490 	mov	dpl,(_ds1302 + 0x0004)
      0013A0 12 0B 9E         [24] 2491 	lcall	_bcd_add
                                   2492 ;	src/fsm.c:235: if(ds1302.month > 0x12)
      0013A3 E5 82            [12] 2493 	mov	a,dpl
      0013A5 F5 50            [12] 2494 	mov	(_ds1302 + 0x0004),a
      0013A7 24 ED            [12] 2495 	add	a,#0xff - 0x12
      0013A9 50 03            [24] 2496 	jnc	00137$
                                   2497 ;	src/fsm.c:236: ds1302.month = 0x00;
      0013AB 75 50 00         [24] 2498 	mov	(_ds1302 + 0x0004),#0x00
      0013AE                       2499 00137$:
                                   2500 ;	src/fsm.c:237: if(DATE_DISPLAY_MMDD)
      0013AE 90 00 03         [24] 2501 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      0013B1 E0               [24] 2502 	movx	a,@dptr
      0013B2 23               [12] 2503 	rl	a
      0013B3 54 01            [12] 2504 	anl	a,#0x01
      0013B5 FF               [12] 2505 	mov	r7,a
      0013B6 60 05            [24] 2506 	jz	00139$
                                   2507 ;	src/fsm.c:238: display_flash = 0x03;
      0013B8 75 47 03         [24] 2508 	mov	_display_flash,#0x03
      0013BB 80 03            [24] 2509 	sjmp	00142$
      0013BD                       2510 00139$:
                                   2511 ;	src/fsm.c:240: display_flash = 0x0c;
      0013BD 75 47 0C         [24] 2512 	mov	_display_flash,#0x0c
      0013C0                       2513 00142$:
                                   2514 ;	src/fsm.c:242: display_putdate();
      0013C0 12 07 C5         [24] 2515 	lcall	_display_putdate
                                   2516 ;	src/fsm.c:243: break;
                                   2517 ;	src/fsm.c:244: case fsm_set_yyyy:
      0013C3 80 5C            [24] 2518 	sjmp	00149$
      0013C5                       2519 00143$:
                                   2520 ;	src/fsm.c:245: ds1302.year = bcd_add(ds1302.year,fsm_set_temp);
      0013C5 8D 60            [24] 2521 	mov	_bcd_add_PARM_2,r5
      0013C7 85 52 82         [24] 2522 	mov	dpl,(_ds1302 + 0x0006)
      0013CA 12 0B 9E         [24] 2523 	lcall	_bcd_add
                                   2524 ;	src/fsm.c:246: if(ds1302.year > 0x99)
      0013CD E5 82            [12] 2525 	mov	a,dpl
      0013CF F5 52            [12] 2526 	mov	(_ds1302 + 0x0006),a
      0013D1 24 66            [12] 2527 	add	a,#0xff - 0x99
      0013D3 50 03            [24] 2528 	jnc	00145$
                                   2529 ;	src/fsm.c:247: ds1302.year = 0x00;
      0013D5 75 52 00         [24] 2530 	mov	(_ds1302 + 0x0006),#0x00
      0013D8                       2531 00145$:
                                   2532 ;	src/fsm.c:248: display_flash = 0x0f;
      0013D8 75 47 0F         [24] 2533 	mov	_display_flash,#0x0f
                                   2534 ;	src/fsm.c:249: display_putbcd(0x20,ds1302.year);
      0013DB 85 52 60         [24] 2535 	mov	_display_putbcd_PARM_2,(_ds1302 + 0x0006)
      0013DE 75 82 20         [24] 2536 	mov	dpl,#0x20
      0013E1 12 07 33         [24] 2537 	lcall	_display_putbcd
                                   2538 ;	src/fsm.c:250: break;
                                   2539 ;	src/fsm.c:251: case fsm_set_dow:
      0013E4 80 3B            [24] 2540 	sjmp	00149$
      0013E6                       2541 00146$:
                                   2542 ;	src/fsm.c:252: ds1302.day = bcd_add(ds1302.day,fsm_set_temp);
      0013E6 8D 60            [24] 2543 	mov	_bcd_add_PARM_2,r5
      0013E8 85 51 82         [24] 2544 	mov	dpl,(_ds1302 + 0x0005)
      0013EB 12 0B 9E         [24] 2545 	lcall	_bcd_add
                                   2546 ;	src/fsm.c:253: if(ds1302.day > 0x07)
      0013EE E5 82            [12] 2547 	mov	a,dpl
      0013F0 F5 51            [12] 2548 	mov	(_ds1302 + 0x0005),a
      0013F2 24 F8            [12] 2549 	add	a,#0xff - 0x07
      0013F4 50 03            [24] 2550 	jnc	00148$
                                   2551 ;	src/fsm.c:254: ds1302.day = 0x01; //DOW register only from 0x01 - 0x07
      0013F6 75 51 01         [24] 2552 	mov	(_ds1302 + 0x0005),#0x01
      0013F9                       2553 00148$:
                                   2554 ;	src/fsm.c:255: display_flash = 0x0f;
      0013F9 75 47 0F         [24] 2555 	mov	_display_flash,#0x0f
                                   2556 ;	src/fsm.c:256: display_puts(ledstrings[ds1302.day-1]);
      0013FC AE 51            [24] 2557 	mov	r6,(_ds1302 + 0x0005)
      0013FE 7F 00            [12] 2558 	mov	r7,#0x00
      001400 EE               [12] 2559 	mov	a,r6
      001401 24 FF            [12] 2560 	add	a,#0xff
      001403 F5 60            [12] 2561 	mov	__mulint_PARM_2,a
      001405 EF               [12] 2562 	mov	a,r7
      001406 34 FF            [12] 2563 	addc	a,#0xff
      001408 F5 61            [12] 2564 	mov	(__mulint_PARM_2 + 1),a
      00140A 90 00 05         [24] 2565 	mov	dptr,#0x0005
      00140D 12 1C 67         [24] 2566 	lcall	__mulint
      001410 AE 82            [24] 2567 	mov	r6,dpl
      001412 AF 83            [24] 2568 	mov	r7,dph
      001414 EE               [12] 2569 	mov	a,r6
      001415 24 00            [12] 2570 	add	a,#_ledstrings
      001417 F5 82            [12] 2571 	mov	dpl,a
      001419 EF               [12] 2572 	mov	a,r7
      00141A 34 31            [12] 2573 	addc	a,#(_ledstrings >> 8)
      00141C F5 83            [12] 2574 	mov	dph,a
      00141E 12 06 F8         [24] 2575 	lcall	_display_puts
                                   2576 ;	src/fsm.c:258: }
      001421                       2577 00149$:
                                   2578 ;	src/fsm.c:260: return fsm_repeat;
      001421 75 82 01         [24] 2579 	mov	dpl,#0x01
                                   2580 ;	src/fsm.c:261: }
      001424 22               [24] 2581 	ret
                                   2582 ;------------------------------------------------------------
                                   2583 ;Allocation info for local variables in function 'fsm_alarm_fn'
                                   2584 ;------------------------------------------------------------
                                   2585 ;alarm_temp                Allocated to registers r5 
                                   2586 ;menu_state                Allocated to registers r7 
                                   2587 ;select_state              Allocated to registers r6 
                                   2588 ;__1966080053              Allocated to registers 
                                   2589 ;__2621440058              Allocated to registers 
                                   2590 ;__2621440059              Allocated to registers r4 
                                   2591 ;__2621440060              Allocated to registers r6 
                                   2592 ;index                     Allocated to registers 
                                   2593 ;dow                       Allocated to registers 
                                   2594 ;__2621440064              Allocated to registers r5 
                                   2595 ;__2621440065              Allocated to registers r6 
                                   2596 ;index                     Allocated to registers 
                                   2597 ;dow                       Allocated to registers 
                                   2598 ;curstate                  Allocated with name '_fsm_alarm_fn_curstate_65536_262'
                                   2599 ;sub_curstate              Allocated with name '_fsm_alarm_fn_sub_curstate_65536_262'
                                   2600 ;------------------------------------------------------------
                                   2601 ;	src/fsm.c:262: enum fsm_return fsm_alarm_fn() __reentrant {
                                   2602 ;	-----------------------------------------
                                   2603 ;	 function fsm_alarm_fn
                                   2604 ;	-----------------------------------------
      001425                       2605 _fsm_alarm_fn:
                                   2606 ;	src/fsm.c:270: menu_state = button_read_and_clear_menu();
      001425 12 06 6C         [24] 2607 	lcall	_button_read_and_clear_menu
      001428 AF 82            [24] 2608 	mov	r7,dpl
                                   2609 ;	src/fsm.c:271: select_state = button_read_and_clear_select();
      00142A C0 07            [24] 2610 	push	ar7
      00142C 12 06 40         [24] 2611 	lcall	_button_read_and_clear_select
      00142F AE 82            [24] 2612 	mov	r6,dpl
      001431 D0 07            [24] 2613 	pop	ar7
                                   2614 ;	src/fsm.c:273: alarm_temp = 0;
      001433 7D 00            [12] 2615 	mov	r5,#0x00
                                   2616 ;	src/fsm.c:274: if(select_state == BUTTON_PRESSED || select_state == BUTTON_HELD_DOWN)
      001435 EE               [12] 2617 	mov	a,r6
      001436 60 03            [24] 2618 	jz	00101$
      001438 BE 02 02         [24] 2619 	cjne	r6,#0x02,00102$
      00143B                       2620 00101$:
                                   2621 ;	src/fsm.c:275: alarm_temp = 1;
      00143B 7D 01            [12] 2622 	mov	r5,#0x01
      00143D                       2623 00102$:
                                   2624 ;	src/fsm.c:277: switch(curstate) {
      00143D E4               [12] 2625 	clr	a
      00143E B5 59 02         [24] 2626 	cjne	a,_fsm_alarm_fn_curstate_65536_262,00283$
      001441 80 07            [24] 2627 	sjmp	00104$
      001443                       2628 00283$:
      001443 74 01            [12] 2629 	mov	a,#0x01
                                   2630 ;	src/fsm.c:278: case fsm_alarm_label:
      001445 B5 59 6D         [24] 2631 	cjne	a,_fsm_alarm_fn_curstate_65536_262,00119$
      001448 80 19            [24] 2632 	sjmp	00109$
      00144A                       2633 00104$:
                                   2634 ;	src/fsm.c:279: if(menu_state == BUTTON_PRESSED)
      00144A EF               [12] 2635 	mov	a,r7
      00144B 70 04            [24] 2636 	jnz	00106$
                                   2637 ;	src/fsm.c:281: return fsm_fail;
      00144D 75 82 02         [24] 2638 	mov	dpl,#0x02
      001450 22               [24] 2639 	ret
      001451                       2640 00106$:
                                   2641 ;	src/fsm.c:282: if(select_state == BUTTON_PRESSED){
      001451 EE               [12] 2642 	mov	a,r6
      001452 70 06            [24] 2643 	jnz	00108$
                                   2644 ;	src/fsm.c:284: curstate++;
      001454 05 59            [12] 2645 	inc	_fsm_alarm_fn_curstate_65536_262
                                   2646 ;	src/fsm.c:285: return fsm_repeat;
      001456 75 82 01         [24] 2647 	mov	dpl,#0x01
      001459 22               [24] 2648 	ret
      00145A                       2649 00108$:
                                   2650 ;	src/fsm.c:287: display_puts(ledstrings[ledstrings_seta]);
      00145A 90 31 28         [24] 2651 	mov	dptr,#(_ledstrings + 0x0028)
      00145D 12 06 F8         [24] 2652 	lcall	_display_puts
                                   2653 ;	src/fsm.c:288: break;
      001460 02 17 7E         [24] 2654 	ljmp	00164$
                                   2655 ;	src/fsm.c:289: case fsm_alarm_global_toggle:
      001463                       2656 00109$:
                                   2657 ;	src/fsm.c:290: if(menu_state == BUTTON_LONG_PRESSED){
      001463 BF 01 10         [24] 2658 	cjne	r7,#0x01,00111$
                                   2659 ;	src/fsm.c:291: curstate = fsm_alarm_label;
      001466 75 59 00         [24] 2660 	mov	_fsm_alarm_fn_curstate_65536_262,#0x00
                                   2661 ;	src/fsm.c:292: ds1302_calculate_CRC();
      001469 12 0B 34         [24] 2662 	lcall	_ds1302_calculate_CRC
                                   2663 ;	src/fsm.c:293: ds1302_write_SRAM();	  //Save data
      00146C 12 0A DB         [24] 2664 	lcall	_ds1302_write_SRAM
                                   2665 ;	src/fsm.c:294: alarm_lastpoll = 0x60;	  //Reset last poll time, force compare
      00146F 75 54 60         [24] 2666 	mov	_alarm_lastpoll,#0x60
                                   2667 ;	src/fsm.c:295: return fsm_ok;
      001472 75 82 00         [24] 2668 	mov	dpl,#0x00
      001475 22               [24] 2669 	ret
      001476                       2670 00111$:
                                   2671 ;	src/fsm.c:297: if(select_state == BUTTON_PRESSED)
      001476 EE               [12] 2672 	mov	a,r6
      001477 70 08            [24] 2673 	jnz	00113$
                                   2674 ;	include/alarm.h:94: ds1302_sram_data[3] ^= 0x01;
      001479 90 00 03         [24] 2675 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      00147C E0               [24] 2676 	movx	a,@dptr
      00147D 64 01            [12] 2677 	xrl	a,#0x01
      00147F FC               [12] 2678 	mov	r4,a
      001480 F0               [24] 2679 	movx	@dptr,a
                                   2680 ;	src/fsm.c:298: alarm_global_toggle();
      001481                       2681 00113$:
                                   2682 ;	include/alarm.h:84: return (ds1302_sram_data[3] & 0x01);
      001481 90 00 03         [24] 2683 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      001484 E0               [24] 2684 	movx	a,@dptr
      001485 30 E0 0C         [24] 2685 	jnb	acc.0,00115$
                                   2686 ;	src/fsm.c:299: if(alarm_global_state())
                                   2687 ;	src/fsm.c:300: display_puts(ledstrings[ledstrings_alon]);
      001488 90 31 2D         [24] 2688 	mov	dptr,#(_ledstrings + 0x002d)
      00148B C0 07            [24] 2689 	push	ar7
      00148D 12 06 F8         [24] 2690 	lcall	_display_puts
      001490 D0 07            [24] 2691 	pop	ar7
      001492 80 0A            [24] 2692 	sjmp	00116$
      001494                       2693 00115$:
                                   2694 ;	src/fsm.c:302: display_puts(ledstrings[ledstrings_alof]);
      001494 90 31 32         [24] 2695 	mov	dptr,#(_ledstrings + 0x0032)
      001497 C0 07            [24] 2696 	push	ar7
      001499 12 06 F8         [24] 2697 	lcall	_display_puts
      00149C D0 07            [24] 2698 	pop	ar7
      00149E                       2699 00116$:
                                   2700 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      00149E 74 7F            [12] 2701 	mov	a,#0x7f
      0014A0 55 43            [12] 2702 	anl	a,(_display_buffer + 0x0001)
      0014A2 F5 43            [12] 2703 	mov	(_display_buffer + 0x0001),a
                                   2704 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      0014A4 74 7F            [12] 2705 	mov	a,#0x7f
      0014A6 55 44            [12] 2706 	anl	a,(_display_buffer + 0x0002)
      0014A8 F5 44            [12] 2707 	mov	(_display_buffer + 0x0002),a
                                   2708 ;	src/fsm.c:305: if(menu_state == BUTTON_PRESSED){
      0014AA EF               [12] 2709 	mov	a,r7
      0014AB 60 03            [24] 2710 	jz	00291$
      0014AD 02 17 7E         [24] 2711 	ljmp	00164$
      0014B0                       2712 00291$:
                                   2713 ;	src/fsm.c:306: ++curstate;
      0014B0 05 59            [12] 2714 	inc	_fsm_alarm_fn_curstate_65536_262
                                   2715 ;	src/fsm.c:308: break;
      0014B2 02 17 7E         [24] 2716 	ljmp	00164$
                                   2717 ;	src/fsm.c:309: default:
      0014B5                       2718 00119$:
                                   2719 ;	src/fsm.c:310: switch(sub_curstate){
      0014B5 E5 5A            [12] 2720 	mov	a,_fsm_alarm_fn_sub_curstate_65536_262
      0014B7 24 F6            [12] 2721 	add	a,#0xff - 0x09
      0014B9 50 03            [24] 2722 	jnc	00292$
      0014BB 02 17 7E         [24] 2723 	ljmp	00164$
      0014BE                       2724 00292$:
      0014BE E5 5A            [12] 2725 	mov	a,_fsm_alarm_fn_sub_curstate_65536_262
      0014C0 24 0B            [12] 2726 	add	a,#(00293$-3-.)
      0014C2 83               [24] 2727 	movc	a,@a+pc
      0014C3 F5 82            [12] 2728 	mov	dpl,a
      0014C5 E5 5A            [12] 2729 	mov	a,_fsm_alarm_fn_sub_curstate_65536_262
      0014C7 24 0E            [12] 2730 	add	a,#(00294$-3-.)
      0014C9 83               [24] 2731 	movc	a,@a+pc
      0014CA F5 83            [12] 2732 	mov	dph,a
      0014CC E4               [12] 2733 	clr	a
      0014CD 73               [24] 2734 	jmp	@a+dptr
      0014CE                       2735 00293$:
      0014CE E2                    2736 	.db	00120$
      0014CF 87                    2737 	.db	00132$
      0014D0 87                    2738 	.db	00132$
      0014D1 BC                    2739 	.db	00151$
      0014D2 BC                    2740 	.db	00151$
      0014D3 BC                    2741 	.db	00151$
      0014D4 BC                    2742 	.db	00151$
      0014D5 BC                    2743 	.db	00151$
      0014D6 BC                    2744 	.db	00151$
      0014D7 BC                    2745 	.db	00151$
      0014D8                       2746 00294$:
      0014D8 14                    2747 	.db	00120$>>8
      0014D9 15                    2748 	.db	00132$>>8
      0014DA 15                    2749 	.db	00132$>>8
      0014DB 16                    2750 	.db	00151$>>8
      0014DC 16                    2751 	.db	00151$>>8
      0014DD 16                    2752 	.db	00151$>>8
      0014DE 16                    2753 	.db	00151$>>8
      0014DF 16                    2754 	.db	00151$>>8
      0014E0 16                    2755 	.db	00151$>>8
      0014E1 16                    2756 	.db	00151$>>8
                                   2757 ;	src/fsm.c:311: case fsm_alarm_substate_toggle:
      0014E2                       2758 00120$:
                                   2759 ;	src/fsm.c:312: if(menu_state == BUTTON_PRESSED){
      0014E2 EF               [12] 2760 	mov	a,r7
      0014E3 70 12            [24] 2761 	jnz	00124$
                                   2762 ;	src/fsm.c:313: if(++curstate == (fsm_alarm_end + NUM_ALARMS))
      0014E5 05 59            [12] 2763 	inc	_fsm_alarm_fn_curstate_65536_262
      0014E7 74 09            [12] 2764 	mov	a,#0x09
      0014E9 B5 59 02         [24] 2765 	cjne	a,_fsm_alarm_fn_curstate_65536_262,00296$
      0014EC 80 03            [24] 2766 	sjmp	00297$
      0014EE                       2767 00296$:
      0014EE 02 17 7E         [24] 2768 	ljmp	00164$
      0014F1                       2769 00297$:
                                   2770 ;	src/fsm.c:314: curstate = fsm_alarm_start;
      0014F1 75 59 01         [24] 2771 	mov	_fsm_alarm_fn_curstate_65536_262,#0x01
                                   2772 ;	src/fsm.c:315: break;
      0014F4 02 17 7E         [24] 2773 	ljmp	00164$
      0014F7                       2774 00124$:
                                   2775 ;	src/fsm.c:317: if(select_state == BUTTON_PRESSED){
      0014F7 EE               [12] 2776 	mov	a,r6
      0014F8 70 36            [24] 2777 	jnz	00126$
                                   2778 ;	src/fsm.c:318: alarms[(curstate - fsm_alarm_end)].dow_and_enable ^= 1;
      0014FA C0 06            [24] 2779 	push	ar6
      0014FC E5 59            [12] 2780 	mov	a,_fsm_alarm_fn_curstate_65536_262
      0014FE 24 FE            [12] 2781 	add	a,#0xfe
      001500 75 F0 03         [24] 2782 	mov	b,#0x03
      001503 A4               [48] 2783 	mul	ab
      001504 FB               [12] 2784 	mov	r3,a
      001505 AC F0            [24] 2785 	mov	r4,b
      001507 24 04            [12] 2786 	add	a,#_alarms
      001509 FA               [12] 2787 	mov	r2,a
      00150A EC               [12] 2788 	mov	a,r4
      00150B 34 00            [12] 2789 	addc	a,#(_alarms >> 8)
      00150D FE               [12] 2790 	mov	r6,a
      00150E 74 02            [12] 2791 	mov	a,#0x02
      001510 2A               [12] 2792 	add	a,r2
      001511 FA               [12] 2793 	mov	r2,a
      001512 E4               [12] 2794 	clr	a
      001513 3E               [12] 2795 	addc	a,r6
      001514 FE               [12] 2796 	mov	r6,a
      001515 EB               [12] 2797 	mov	a,r3
      001516 24 04            [12] 2798 	add	a,#_alarms
      001518 FB               [12] 2799 	mov	r3,a
      001519 EC               [12] 2800 	mov	a,r4
      00151A 34 00            [12] 2801 	addc	a,#(_alarms >> 8)
      00151C FC               [12] 2802 	mov	r4,a
      00151D 8B 82            [24] 2803 	mov	dpl,r3
      00151F 8C 83            [24] 2804 	mov	dph,r4
      001521 A3               [24] 2805 	inc	dptr
      001522 A3               [24] 2806 	inc	dptr
      001523 E0               [24] 2807 	movx	a,@dptr
      001524 FC               [12] 2808 	mov	r4,a
      001525 63 04 01         [24] 2809 	xrl	ar4,#0x01
      001528 8A 82            [24] 2810 	mov	dpl,r2
      00152A 8E 83            [24] 2811 	mov	dph,r6
      00152C EC               [12] 2812 	mov	a,r4
      00152D F0               [24] 2813 	movx	@dptr,a
                                   2814 ;	src/fsm.c:392: return fsm_repeat;
      00152E D0 06            [24] 2815 	pop	ar6
                                   2816 ;	src/fsm.c:318: alarms[(curstate - fsm_alarm_end)].dow_and_enable ^= 1;
      001530                       2817 00126$:
                                   2818 ;	src/fsm.c:320: if(select_state == BUTTON_LONG_PRESSED){
      001530 BE 01 05         [24] 2819 	cjne	r6,#0x01,00128$
                                   2820 ;	src/fsm.c:321: sub_curstate++;
      001533 05 5A            [12] 2821 	inc	_fsm_alarm_fn_sub_curstate_65536_262
                                   2822 ;	src/fsm.c:322: break;
      001535 02 17 7E         [24] 2823 	ljmp	00164$
      001538                       2824 00128$:
                                   2825 ;	src/fsm.c:324: if(menu_state == BUTTON_LONG_PRESSED){
      001538 BF 01 0A         [24] 2826 	cjne	r7,#0x01,00130$
                                   2827 ;	src/fsm.c:325: sub_curstate = fsm_alarm_substate_toggle;
      00153B 75 5A 00         [24] 2828 	mov	_fsm_alarm_fn_sub_curstate_65536_262,#0x00
                                   2829 ;	src/fsm.c:326: curstate = fsm_alarm_label;
      00153E 75 59 00         [24] 2830 	mov	_fsm_alarm_fn_curstate_65536_262,#0x00
                                   2831 ;	src/fsm.c:327: return fsm_ok;
      001541 75 82 00         [24] 2832 	mov	dpl,#0x00
      001544 22               [24] 2833 	ret
      001545                       2834 00130$:
                                   2835 ;	src/fsm.c:329: display_buffer[0] = ledfonts_numeric_normal['A'];
      001545 90 30 41         [24] 2836 	mov	dptr,#(_ledfonts_numeric_normal + 0x0041)
      001548 E4               [12] 2837 	clr	a
      001549 93               [24] 2838 	movc	a,@a+dptr
      00154A FE               [12] 2839 	mov	r6,a
      00154B 8E 42            [24] 2840 	mov	_display_buffer,r6
                                   2841 ;	src/fsm.c:330: display_buffer[1] = ledfonts_numeric_normal[(curstate - fsm_alarm_end)];
      00154D E5 59            [12] 2842 	mov	a,_fsm_alarm_fn_curstate_65536_262
      00154F 24 FE            [12] 2843 	add	a,#0xfe
      001551 90 30 00         [24] 2844 	mov	dptr,#_ledfonts_numeric_normal
      001554 93               [24] 2845 	movc	a,@a+dptr
      001555 FE               [12] 2846 	mov	r6,a
      001556 8E 43            [24] 2847 	mov	(_display_buffer + 0x0001),r6
                                   2848 ;	src/fsm.c:331: display_putbool(alarms[(curstate - fsm_alarm_end)].dow_and_enable & 0x01);
      001558 E5 59            [12] 2849 	mov	a,_fsm_alarm_fn_curstate_65536_262
      00155A 24 FE            [12] 2850 	add	a,#0xfe
      00155C 75 F0 03         [24] 2851 	mov	b,#0x03
      00155F A4               [48] 2852 	mul	ab
      001560 24 04            [12] 2853 	add	a,#_alarms
      001562 FC               [12] 2854 	mov	r4,a
      001563 74 00            [12] 2855 	mov	a,#(_alarms >> 8)
      001565 35 F0            [12] 2856 	addc	a,b
      001567 FE               [12] 2857 	mov	r6,a
      001568 8C 82            [24] 2858 	mov	dpl,r4
      00156A 8E 83            [24] 2859 	mov	dph,r6
      00156C A3               [24] 2860 	inc	dptr
      00156D A3               [24] 2861 	inc	dptr
      00156E E0               [24] 2862 	movx	a,@dptr
      00156F FE               [12] 2863 	mov	r6,a
      001570 74 01            [12] 2864 	mov	a,#0x01
      001572 5E               [12] 2865 	anl	a,r6
      001573 F5 82            [12] 2866 	mov	dpl,a
      001575 12 08 12         [24] 2867 	lcall	_display_putbool
                                   2868 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      001578 74 7F            [12] 2869 	mov	a,#0x7f
      00157A 55 43            [12] 2870 	anl	a,(_display_buffer + 0x0001)
      00157C F5 43            [12] 2871 	mov	(_display_buffer + 0x0001),a
                                   2872 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      00157E 74 7F            [12] 2873 	mov	a,#0x7f
      001580 55 44            [12] 2874 	anl	a,(_display_buffer + 0x0002)
      001582 F5 44            [12] 2875 	mov	(_display_buffer + 0x0002),a
                                   2876 ;	src/fsm.c:333: break;
      001584 02 17 7E         [24] 2877 	ljmp	00164$
                                   2878 ;	src/fsm.c:335: case fsm_alarm_substate_mm:
      001587                       2879 00132$:
                                   2880 ;	src/fsm.c:336: if(menu_state == BUTTON_PRESSED){
      001587 EF               [12] 2881 	mov	a,r7
      001588 70 08            [24] 2882 	jnz	00134$
                                   2883 ;	src/fsm.c:337: sub_curstate++;
      00158A 05 5A            [12] 2884 	inc	_fsm_alarm_fn_sub_curstate_65536_262
                                   2885 ;	src/fsm.c:338: display_flash = 0x00;
      00158C 75 47 00         [24] 2886 	mov	_display_flash,#0x00
                                   2887 ;	src/fsm.c:339: break;
      00158F 02 17 7E         [24] 2888 	ljmp	00164$
      001592                       2889 00134$:
                                   2890 ;	src/fsm.c:341: if(menu_state == BUTTON_LONG_PRESSED){
      001592 BF 01 09         [24] 2891 	cjne	r7,#0x01,00136$
                                   2892 ;	src/fsm.c:342: sub_curstate = fsm_alarm_substate_toggle;
      001595 75 5A 00         [24] 2893 	mov	_fsm_alarm_fn_sub_curstate_65536_262,#0x00
                                   2894 ;	src/fsm.c:343: display_flash = 0x00;
      001598 75 47 00         [24] 2895 	mov	_display_flash,#0x00
                                   2896 ;	src/fsm.c:344: break;
      00159B 02 17 7E         [24] 2897 	ljmp	00164$
      00159E                       2898 00136$:
                                   2899 ;	src/fsm.c:346: if(sub_curstate == fsm_alarm_substate_hh){
      00159E 74 01            [12] 2900 	mov	a,#0x01
      0015A0 B5 5A 68         [24] 2901 	cjne	a,_fsm_alarm_fn_sub_curstate_65536_262,00140$
                                   2902 ;	src/fsm.c:347: alarms[(curstate - fsm_alarm_end)].hour = bcd_add(alarms[(curstate - fsm_alarm_end)].hour,alarm_temp);
      0015A3 E5 59            [12] 2903 	mov	a,_fsm_alarm_fn_curstate_65536_262
      0015A5 24 FE            [12] 2904 	add	a,#0xfe
      0015A7 75 F0 03         [24] 2905 	mov	b,#0x03
      0015AA A4               [48] 2906 	mul	ab
      0015AB FC               [12] 2907 	mov	r4,a
      0015AC AE F0            [24] 2908 	mov	r6,b
      0015AE 24 04            [12] 2909 	add	a,#_alarms
      0015B0 FA               [12] 2910 	mov	r2,a
      0015B1 EE               [12] 2911 	mov	a,r6
      0015B2 34 00            [12] 2912 	addc	a,#(_alarms >> 8)
      0015B4 FB               [12] 2913 	mov	r3,a
      0015B5 EC               [12] 2914 	mov	a,r4
      0015B6 24 04            [12] 2915 	add	a,#_alarms
      0015B8 F5 82            [12] 2916 	mov	dpl,a
      0015BA EE               [12] 2917 	mov	a,r6
      0015BB 34 00            [12] 2918 	addc	a,#(_alarms >> 8)
      0015BD F5 83            [12] 2919 	mov	dph,a
      0015BF E0               [24] 2920 	movx	a,@dptr
      0015C0 FE               [12] 2921 	mov	r6,a
      0015C1 8D 60            [24] 2922 	mov	_bcd_add_PARM_2,r5
      0015C3 8E 82            [24] 2923 	mov	dpl,r6
      0015C5 C0 05            [24] 2924 	push	ar5
      0015C7 C0 03            [24] 2925 	push	ar3
      0015C9 C0 02            [24] 2926 	push	ar2
      0015CB 12 0B 9E         [24] 2927 	lcall	_bcd_add
      0015CE AE 82            [24] 2928 	mov	r6,dpl
      0015D0 D0 02            [24] 2929 	pop	ar2
      0015D2 D0 03            [24] 2930 	pop	ar3
      0015D4 D0 05            [24] 2931 	pop	ar5
      0015D6 8A 82            [24] 2932 	mov	dpl,r2
      0015D8 8B 83            [24] 2933 	mov	dph,r3
      0015DA EE               [12] 2934 	mov	a,r6
      0015DB F0               [24] 2935 	movx	@dptr,a
                                   2936 ;	src/fsm.c:348: if(alarms[(curstate - fsm_alarm_end)].hour > 0x23)
      0015DC E5 59            [12] 2937 	mov	a,_fsm_alarm_fn_curstate_65536_262
      0015DE 24 FE            [12] 2938 	add	a,#0xfe
      0015E0 75 F0 03         [24] 2939 	mov	b,#0x03
      0015E3 A4               [48] 2940 	mul	ab
      0015E4 24 04            [12] 2941 	add	a,#_alarms
      0015E6 F5 82            [12] 2942 	mov	dpl,a
      0015E8 74 00            [12] 2943 	mov	a,#(_alarms >> 8)
      0015EA 35 F0            [12] 2944 	addc	a,b
      0015EC F5 83            [12] 2945 	mov	dph,a
      0015EE E0               [24] 2946 	movx	a,@dptr
      0015EF FE               [12] 2947 	mov  r6,a
      0015F0 24 DC            [12] 2948 	add	a,#0xff - 0x23
      0015F2 50 14            [24] 2949 	jnc	00138$
                                   2950 ;	src/fsm.c:349: alarms[(curstate - fsm_alarm_end)].hour = 0x00;
      0015F4 E5 59            [12] 2951 	mov	a,_fsm_alarm_fn_curstate_65536_262
      0015F6 24 FE            [12] 2952 	add	a,#0xfe
      0015F8 75 F0 03         [24] 2953 	mov	b,#0x03
      0015FB A4               [48] 2954 	mul	ab
      0015FC 24 04            [12] 2955 	add	a,#_alarms
      0015FE F5 82            [12] 2956 	mov	dpl,a
      001600 74 00            [12] 2957 	mov	a,#(_alarms >> 8)
      001602 35 F0            [12] 2958 	addc	a,b
      001604 F5 83            [12] 2959 	mov	dph,a
      001606 E4               [12] 2960 	clr	a
      001607 F0               [24] 2961 	movx	@dptr,a
      001608                       2962 00138$:
                                   2963 ;	src/fsm.c:350: display_flash = 0x03;
      001608 75 47 03         [24] 2964 	mov	_display_flash,#0x03
      00160B                       2965 00140$:
                                   2966 ;	src/fsm.c:352: if(sub_curstate == fsm_alarm_substate_mm){
      00160B 74 02            [12] 2967 	mov	a,#0x02
      00160D B5 5A 72         [24] 2968 	cjne	a,_fsm_alarm_fn_sub_curstate_65536_262,00144$
                                   2969 ;	src/fsm.c:353: alarms[(curstate - fsm_alarm_end)].minute = bcd_add(alarms[(curstate - fsm_alarm_end)].minute,alarm_temp);
      001610 E5 59            [12] 2970 	mov	a,_fsm_alarm_fn_curstate_65536_262
      001612 24 FE            [12] 2971 	add	a,#0xfe
      001614 75 F0 03         [24] 2972 	mov	b,#0x03
      001617 A4               [48] 2973 	mul	ab
      001618 FC               [12] 2974 	mov	r4,a
      001619 AE F0            [24] 2975 	mov	r6,b
      00161B 24 04            [12] 2976 	add	a,#_alarms
      00161D FA               [12] 2977 	mov	r2,a
      00161E EE               [12] 2978 	mov	a,r6
      00161F 34 00            [12] 2979 	addc	a,#(_alarms >> 8)
      001621 FB               [12] 2980 	mov	r3,a
      001622 0A               [12] 2981 	inc	r2
      001623 BA 00 01         [24] 2982 	cjne	r2,#0x00,00311$
      001626 0B               [12] 2983 	inc	r3
      001627                       2984 00311$:
      001627 EC               [12] 2985 	mov	a,r4
      001628 24 04            [12] 2986 	add	a,#_alarms
      00162A FC               [12] 2987 	mov	r4,a
      00162B EE               [12] 2988 	mov	a,r6
      00162C 34 00            [12] 2989 	addc	a,#(_alarms >> 8)
      00162E FE               [12] 2990 	mov	r6,a
      00162F 8C 82            [24] 2991 	mov	dpl,r4
      001631 8E 83            [24] 2992 	mov	dph,r6
      001633 A3               [24] 2993 	inc	dptr
      001634 E0               [24] 2994 	movx	a,@dptr
      001635 FE               [12] 2995 	mov	r6,a
      001636 8D 60            [24] 2996 	mov	_bcd_add_PARM_2,r5
      001638 8E 82            [24] 2997 	mov	dpl,r6
      00163A C0 03            [24] 2998 	push	ar3
      00163C C0 02            [24] 2999 	push	ar2
      00163E 12 0B 9E         [24] 3000 	lcall	_bcd_add
      001641 AE 82            [24] 3001 	mov	r6,dpl
      001643 D0 02            [24] 3002 	pop	ar2
      001645 D0 03            [24] 3003 	pop	ar3
      001647 8A 82            [24] 3004 	mov	dpl,r2
      001649 8B 83            [24] 3005 	mov	dph,r3
      00164B EE               [12] 3006 	mov	a,r6
      00164C F0               [24] 3007 	movx	@dptr,a
                                   3008 ;	src/fsm.c:354: if(alarms[(curstate - fsm_alarm_end)].minute > 0x59)
      00164D E5 59            [12] 3009 	mov	a,_fsm_alarm_fn_curstate_65536_262
      00164F 24 FE            [12] 3010 	add	a,#0xfe
      001651 75 F0 03         [24] 3011 	mov	b,#0x03
      001654 A4               [48] 3012 	mul	ab
      001655 24 04            [12] 3013 	add	a,#_alarms
      001657 FC               [12] 3014 	mov	r4,a
      001658 74 00            [12] 3015 	mov	a,#(_alarms >> 8)
      00165A 35 F0            [12] 3016 	addc	a,b
      00165C FE               [12] 3017 	mov	r6,a
      00165D 8C 82            [24] 3018 	mov	dpl,r4
      00165F 8E 83            [24] 3019 	mov	dph,r6
      001661 A3               [24] 3020 	inc	dptr
      001662 E0               [24] 3021 	movx	a,@dptr
      001663 FE               [12] 3022 	mov  r6,a
      001664 24 A6            [12] 3023 	add	a,#0xff - 0x59
      001666 50 17            [24] 3024 	jnc	00142$
                                   3025 ;	src/fsm.c:355: alarms[(curstate - fsm_alarm_end)].minute = 0x00;
      001668 E5 59            [12] 3026 	mov	a,_fsm_alarm_fn_curstate_65536_262
      00166A 24 FE            [12] 3027 	add	a,#0xfe
      00166C 75 F0 03         [24] 3028 	mov	b,#0x03
      00166F A4               [48] 3029 	mul	ab
      001670 24 04            [12] 3030 	add	a,#_alarms
      001672 FC               [12] 3031 	mov	r4,a
      001673 74 00            [12] 3032 	mov	a,#(_alarms >> 8)
      001675 35 F0            [12] 3033 	addc	a,b
      001677 FE               [12] 3034 	mov	r6,a
      001678 8C 82            [24] 3035 	mov	dpl,r4
      00167A 8E 83            [24] 3036 	mov	dph,r6
      00167C A3               [24] 3037 	inc	dptr
      00167D E4               [12] 3038 	clr	a
      00167E F0               [24] 3039 	movx	@dptr,a
      00167F                       3040 00142$:
                                   3041 ;	src/fsm.c:356: display_flash = 0x0c;
      00167F 75 47 0C         [24] 3042 	mov	_display_flash,#0x0c
      001682                       3043 00144$:
                                   3044 ;	src/fsm.c:358: display_puttime(alarms[(curstate - fsm_alarm_end)].hour,alarms[(curstate - fsm_alarm_end)].minute);
      001682 E5 59            [12] 3045 	mov	a,_fsm_alarm_fn_curstate_65536_262
      001684 24 FE            [12] 3046 	add	a,#0xfe
      001686 75 F0 03         [24] 3047 	mov	b,#0x03
      001689 A4               [48] 3048 	mul	ab
      00168A FC               [12] 3049 	mov	r4,a
      00168B AE F0            [24] 3050 	mov	r6,b
      00168D 24 04            [12] 3051 	add	a,#_alarms
      00168F F5 82            [12] 3052 	mov	dpl,a
      001691 EE               [12] 3053 	mov	a,r6
      001692 34 00            [12] 3054 	addc	a,#(_alarms >> 8)
      001694 F5 83            [12] 3055 	mov	dph,a
      001696 E0               [24] 3056 	movx	a,@dptr
      001697 FB               [12] 3057 	mov	r3,a
      001698 EC               [12] 3058 	mov	a,r4
      001699 24 04            [12] 3059 	add	a,#_alarms
      00169B FC               [12] 3060 	mov	r4,a
      00169C EE               [12] 3061 	mov	a,r6
      00169D 34 00            [12] 3062 	addc	a,#(_alarms >> 8)
      00169F FE               [12] 3063 	mov	r6,a
      0016A0 8C 82            [24] 3064 	mov	dpl,r4
      0016A2 8E 83            [24] 3065 	mov	dph,r6
      0016A4 A3               [24] 3066 	inc	dptr
      0016A5 E0               [24] 3067 	movx	a,@dptr
      0016A6 F5 4A            [12] 3068 	mov	_display_puttime_PARM_2,a
      0016A8 8B 82            [24] 3069 	mov	dpl,r3
      0016AA 12 07 77         [24] 3070 	lcall	_display_puttime
                                   3071 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      0016AD 74 7F            [12] 3072 	mov	a,#0x7f
      0016AF 55 43            [12] 3073 	anl	a,(_display_buffer + 0x0001)
      0016B1 F5 43            [12] 3074 	mov	(_display_buffer + 0x0001),a
                                   3075 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      0016B3 74 7F            [12] 3076 	mov	a,#0x7f
      0016B5 55 44            [12] 3077 	anl	a,(_display_buffer + 0x0002)
      0016B7 F5 44            [12] 3078 	mov	(_display_buffer + 0x0002),a
                                   3079 ;	src/fsm.c:360: break;
      0016B9 02 17 7E         [24] 3080 	ljmp	00164$
                                   3081 ;	src/fsm.c:367: case fsm_alarm_substate_dow_sun:
      0016BC                       3082 00151$:
                                   3083 ;	src/fsm.c:368: display_puts(ledstrings[sub_curstate - fsm_alarm_substate_mm -1]);
      0016BC AC 5A            [24] 3084 	mov	r4,_fsm_alarm_fn_sub_curstate_65536_262
      0016BE 7E 00            [12] 3085 	mov	r6,#0x00
      0016C0 EC               [12] 3086 	mov	a,r4
      0016C1 24 FD            [12] 3087 	add	a,#0xfd
      0016C3 F5 60            [12] 3088 	mov	__mulint_PARM_2,a
      0016C5 EE               [12] 3089 	mov	a,r6
      0016C6 34 FF            [12] 3090 	addc	a,#0xff
      0016C8 F5 61            [12] 3091 	mov	(__mulint_PARM_2 + 1),a
      0016CA 90 00 05         [24] 3092 	mov	dptr,#0x0005
      0016CD C0 07            [24] 3093 	push	ar7
      0016CF C0 05            [24] 3094 	push	ar5
      0016D1 12 1C 67         [24] 3095 	lcall	__mulint
      0016D4 AC 82            [24] 3096 	mov	r4,dpl
      0016D6 AE 83            [24] 3097 	mov	r6,dph
      0016D8 EC               [12] 3098 	mov	a,r4
      0016D9 24 00            [12] 3099 	add	a,#_ledstrings
      0016DB F5 82            [12] 3100 	mov	dpl,a
      0016DD EE               [12] 3101 	mov	a,r6
      0016DE 34 31            [12] 3102 	addc	a,#(_ledstrings >> 8)
      0016E0 F5 83            [12] 3103 	mov	dph,a
      0016E2 12 06 F8         [24] 3104 	lcall	_display_puts
      0016E5 D0 05            [24] 3105 	pop	ar5
      0016E7 D0 07            [24] 3106 	pop	ar7
                                   3107 ;	src/fsm.c:369: if(alarm_dow_state(curstate - fsm_alarm_end,sub_curstate - fsm_alarm_substate_mm)){
      0016E9 AE 5A            [24] 3108 	mov	r6,_fsm_alarm_fn_sub_curstate_65536_262
      0016EB 1E               [12] 3109 	dec	r6
      0016EC 1E               [12] 3110 	dec	r6
      0016ED E5 59            [12] 3111 	mov	a,_fsm_alarm_fn_curstate_65536_262
      0016EF 24 FE            [12] 3112 	add	a,#0xfe
                                   3113 ;	include/alarm.h:106: return ((alarms[index].dow_and_enable >> dow) & 0x01);
      0016F1 75 F0 03         [24] 3114 	mov	b,#0x03
      0016F4 A4               [48] 3115 	mul	ab
      0016F5 24 04            [12] 3116 	add	a,#_alarms
      0016F7 FB               [12] 3117 	mov	r3,a
      0016F8 74 00            [12] 3118 	mov	a,#(_alarms >> 8)
      0016FA 35 F0            [12] 3119 	addc	a,b
      0016FC FC               [12] 3120 	mov	r4,a
      0016FD 8B 82            [24] 3121 	mov	dpl,r3
      0016FF 8C 83            [24] 3122 	mov	dph,r4
      001701 A3               [24] 3123 	inc	dptr
      001702 A3               [24] 3124 	inc	dptr
      001703 E0               [24] 3125 	movx	a,@dptr
      001704 FC               [12] 3126 	mov	r4,a
      001705 8E F0            [24] 3127 	mov	b,r6
      001707 05 F0            [12] 3128 	inc	b
      001709 EC               [12] 3129 	mov	a,r4
      00170A 80 02            [24] 3130 	sjmp	00314$
      00170C                       3131 00313$:
      00170C C3               [12] 3132 	clr	c
      00170D 13               [12] 3133 	rrc	a
      00170E                       3134 00314$:
      00170E D5 F0 FB         [24] 3135 	djnz	b,00313$
      001711 FE               [12] 3136 	mov	r6,a
      001712 30 E0 08         [24] 3137 	jnb	acc.0,00153$
                                   3138 ;	src/fsm.c:369: if(alarm_dow_state(curstate - fsm_alarm_end,sub_curstate - fsm_alarm_substate_mm)){
                                   3139 ;	include/display.h:175: display_buffer[3] &= 0x7f;
      001715 74 7F            [12] 3140 	mov	a,#0x7f
      001717 55 45            [12] 3141 	anl	a,(_display_buffer + 0x0003)
      001719 F5 45            [12] 3142 	mov	(_display_buffer + 0x0003),a
                                   3143 ;	src/fsm.c:370: display_ampmon();
      00171B 80 06            [24] 3144 	sjmp	00154$
      00171D                       3145 00153$:
                                   3146 ;	include/display.h:190: display_buffer[3] |= 0x80;
      00171D 74 80            [12] 3147 	mov	a,#0x80
      00171F 45 45            [12] 3148 	orl	a,(_display_buffer + 0x0003)
      001721 F5 45            [12] 3149 	mov	(_display_buffer + 0x0003),a
                                   3150 ;	src/fsm.c:372: display_ampmoff();
      001723                       3151 00154$:
                                   3152 ;	src/fsm.c:374: if(alarm_temp)
      001723 ED               [12] 3153 	mov	a,r5
      001724 60 43            [24] 3154 	jz	00156$
                                   3155 ;	src/fsm.c:375: alarm_dow_toggle(curstate - fsm_alarm_end,sub_curstate - fsm_alarm_substate_mm);
      001726 AE 5A            [24] 3156 	mov	r6,_fsm_alarm_fn_sub_curstate_65536_262
      001728 1E               [12] 3157 	dec	r6
      001729 1E               [12] 3158 	dec	r6
      00172A E5 59            [12] 3159 	mov	a,_fsm_alarm_fn_curstate_65536_262
      00172C 24 FE            [12] 3160 	add	a,#0xfe
                                   3161 ;	include/alarm.h:116: alarms[index].dow_and_enable ^= (0x01 << dow);
      00172E 75 F0 03         [24] 3162 	mov	b,#0x03
      001731 A4               [48] 3163 	mul	ab
      001732 FD               [12] 3164 	mov	r5,a
      001733 AC F0            [24] 3165 	mov	r4,b
      001735 24 04            [12] 3166 	add	a,#_alarms
      001737 FA               [12] 3167 	mov	r2,a
      001738 EC               [12] 3168 	mov	a,r4
      001739 34 00            [12] 3169 	addc	a,#(_alarms >> 8)
      00173B FB               [12] 3170 	mov	r3,a
      00173C 74 02            [12] 3171 	mov	a,#0x02
      00173E 2A               [12] 3172 	add	a,r2
      00173F FA               [12] 3173 	mov	r2,a
      001740 E4               [12] 3174 	clr	a
      001741 3B               [12] 3175 	addc	a,r3
      001742 FB               [12] 3176 	mov	r3,a
      001743 ED               [12] 3177 	mov	a,r5
      001744 24 04            [12] 3178 	add	a,#_alarms
      001746 FD               [12] 3179 	mov	r5,a
      001747 EC               [12] 3180 	mov	a,r4
      001748 34 00            [12] 3181 	addc	a,#(_alarms >> 8)
      00174A FC               [12] 3182 	mov	r4,a
      00174B 8D 82            [24] 3183 	mov	dpl,r5
      00174D 8C 83            [24] 3184 	mov	dph,r4
      00174F A3               [24] 3185 	inc	dptr
      001750 A3               [24] 3186 	inc	dptr
      001751 E0               [24] 3187 	movx	a,@dptr
      001752 FD               [12] 3188 	mov	r5,a
      001753 8E F0            [24] 3189 	mov	b,r6
      001755 05 F0            [12] 3190 	inc	b
      001757 74 01            [12] 3191 	mov	a,#0x01
      001759 80 02            [24] 3192 	sjmp	00319$
      00175B                       3193 00317$:
      00175B 25 E0            [12] 3194 	add	a,acc
      00175D                       3195 00319$:
      00175D D5 F0 FB         [24] 3196 	djnz	b,00317$
      001760 FE               [12] 3197 	mov	r6,a
      001761 62 05            [12] 3198 	xrl	ar5,a
      001763 8A 82            [24] 3199 	mov	dpl,r2
      001765 8B 83            [24] 3200 	mov	dph,r3
      001767 ED               [12] 3201 	mov	a,r5
      001768 F0               [24] 3202 	movx	@dptr,a
                                   3203 ;	src/fsm.c:375: alarm_dow_toggle(curstate - fsm_alarm_end,sub_curstate - fsm_alarm_substate_mm);
      001769                       3204 00156$:
                                   3205 ;	src/fsm.c:376: if(menu_state == BUTTON_PRESSED){
      001769 EF               [12] 3206 	mov	a,r7
      00176A 70 0C            [24] 3207 	jnz	00160$
                                   3208 ;	src/fsm.c:377: if(++sub_curstate == fsm_alarm_substate_end){
      00176C 05 5A            [12] 3209 	inc	_fsm_alarm_fn_sub_curstate_65536_262
      00176E 74 0A            [12] 3210 	mov	a,#0x0a
      001770 B5 5A 0B         [24] 3211 	cjne	a,_fsm_alarm_fn_sub_curstate_65536_262,00164$
                                   3212 ;	src/fsm.c:378: sub_curstate = fsm_alarm_substate_start;
      001773 75 5A 01         [24] 3213 	mov	_fsm_alarm_fn_sub_curstate_65536_262,#0x01
                                   3214 ;	src/fsm.c:380: break;
      001776 80 06            [24] 3215 	sjmp	00164$
      001778                       3216 00160$:
                                   3217 ;	src/fsm.c:382: if(menu_state == BUTTON_LONG_PRESSED){
      001778 BF 01 03         [24] 3218 	cjne	r7,#0x01,00164$
                                   3219 ;	src/fsm.c:383: sub_curstate = fsm_alarm_substate_toggle;
      00177B 75 5A 00         [24] 3220 	mov	_fsm_alarm_fn_sub_curstate_65536_262,#0x00
                                   3221 ;	src/fsm.c:390: }
      00177E                       3222 00164$:
                                   3223 ;	src/fsm.c:392: return fsm_repeat;
      00177E 75 82 01         [24] 3224 	mov	dpl,#0x01
                                   3225 ;	src/fsm.c:393: }
      001781 22               [24] 3226 	ret
                                   3227 ;------------------------------------------------------------
                                   3228 ;Allocation info for local variables in function 'fsm_config_fn'
                                   3229 ;------------------------------------------------------------
                                   3230 ;config_tmp2               Allocated to registers r4 r5 
                                   3231 ;menu_state                Allocated to registers r7 
                                   3232 ;select_state              Allocated to registers r6 
                                   3233 ;__1966080071              Allocated to registers 
                                   3234 ;__3276800067              Allocated to registers 
                                   3235 ;tmp                       Allocated to registers r4 r5 
                                   3236 ;__3276800069              Allocated to registers 
                                   3237 ;tmp                       Allocated to registers r4 r5 
                                   3238 ;tmp                       Allocated to registers r4 r5 
                                   3239 ;curstate                  Allocated with name '_fsm_config_fn_curstate_65536_308'
                                   3240 ;config_tmp                Allocated with name '_fsm_config_fn_config_tmp_65536_308'
                                   3241 ;------------------------------------------------------------
                                   3242 ;	src/fsm.c:396: enum fsm_return fsm_config_fn() __reentrant {
                                   3243 ;	-----------------------------------------
                                   3244 ;	 function fsm_config_fn
                                   3245 ;	-----------------------------------------
      001782                       3246 _fsm_config_fn:
                                   3247 ;	src/fsm.c:403: menu_state = button_read_and_clear_menu();
      001782 12 06 6C         [24] 3248 	lcall	_button_read_and_clear_menu
      001785 AF 82            [24] 3249 	mov	r7,dpl
                                   3250 ;	src/fsm.c:404: select_state = button_read_and_clear_select();
      001787 C0 07            [24] 3251 	push	ar7
      001789 12 06 40         [24] 3252 	lcall	_button_read_and_clear_select
      00178C AE 82            [24] 3253 	mov	r6,dpl
      00178E D0 07            [24] 3254 	pop	ar7
                                   3255 ;	src/fsm.c:406: switch(curstate) {
      001790 E5 5B            [12] 3256 	mov	a,_fsm_config_fn_curstate_65536_308
      001792 24 F1            [12] 3257 	add	a,#0xff - 0x0e
      001794 50 03            [24] 3258 	jnc	00286$
      001796 02 19 E7         [24] 3259 	ljmp	00164$
      001799                       3260 00286$:
      001799 E5 5B            [12] 3261 	mov	a,_fsm_config_fn_curstate_65536_308
      00179B 24 0B            [12] 3262 	add	a,#(00287$-3-.)
      00179D 83               [24] 3263 	movc	a,@a+pc
      00179E F5 82            [12] 3264 	mov	dpl,a
      0017A0 E5 5B            [12] 3265 	mov	a,_fsm_config_fn_curstate_65536_308
      0017A2 24 13            [12] 3266 	add	a,#(00288$-3-.)
      0017A4 83               [24] 3267 	movc	a,@a+pc
      0017A5 F5 83            [12] 3268 	mov	dph,a
      0017A7 E4               [12] 3269 	clr	a
      0017A8 73               [24] 3270 	jmp	@a+dptr
      0017A9                       3271 00287$:
      0017A9 C7                    3272 	.db	00101$
      0017AA EB                    3273 	.db	00106$
      0017AB 00                    3274 	.db	00112$
      0017AC 00                    3275 	.db	00112$
      0017AD 65                    3276 	.db	00123$
      0017AE 91                    3277 	.db	00128$
      0017AF 1A                    3278 	.db	00138$
      0017B0 2E                    3279 	.db	00150$
      0017B1 2E                    3280 	.db	00150$
      0017B2 2E                    3281 	.db	00150$
      0017B3 2E                    3282 	.db	00150$
      0017B4 2E                    3283 	.db	00150$
      0017B5 2E                    3284 	.db	00150$
      0017B6 2E                    3285 	.db	00150$
      0017B7 2E                    3286 	.db	00150$
      0017B8                       3287 00288$:
      0017B8 17                    3288 	.db	00101$>>8
      0017B9 17                    3289 	.db	00106$>>8
      0017BA 18                    3290 	.db	00112$>>8
      0017BB 18                    3291 	.db	00112$>>8
      0017BC 18                    3292 	.db	00123$>>8
      0017BD 18                    3293 	.db	00128$>>8
      0017BE 19                    3294 	.db	00138$>>8
      0017BF 19                    3295 	.db	00150$>>8
      0017C0 19                    3296 	.db	00150$>>8
      0017C1 19                    3297 	.db	00150$>>8
      0017C2 19                    3298 	.db	00150$>>8
      0017C3 19                    3299 	.db	00150$>>8
      0017C4 19                    3300 	.db	00150$>>8
      0017C5 19                    3301 	.db	00150$>>8
      0017C6 19                    3302 	.db	00150$>>8
                                   3303 ;	src/fsm.c:407: case fsm_config_label:
      0017C7                       3304 00101$:
                                   3305 ;	src/fsm.c:408: if(menu_state == BUTTON_PRESSED){
      0017C7 EF               [12] 3306 	mov	a,r7
      0017C8 70 13            [24] 3307 	jnz	00103$
                                   3308 ;	src/fsm.c:414: ds1302_calculate_CRC();
      0017CA 12 0B 34         [24] 3309 	lcall	_ds1302_calculate_CRC
                                   3310 ;	src/fsm.c:415: ds1302_write_SRAM();
      0017CD 12 0A DB         [24] 3311 	lcall	_ds1302_write_SRAM
                                   3312 ;	src/fsm.c:416: transition_ticks = centiseconds();
      0017D0 12 1A D4         [24] 3313 	lcall	_centiseconds
      0017D3 85 82 55         [24] 3314 	mov	_transition_ticks,dpl
      0017D6 85 83 56         [24] 3315 	mov	(_transition_ticks + 1),dph
                                   3316 ;	src/fsm.c:417: return fsm_fail;
      0017D9 75 82 02         [24] 3317 	mov	dpl,#0x02
      0017DC 22               [24] 3318 	ret
      0017DD                       3319 00103$:
                                   3320 ;	src/fsm.c:419: if(select_state == BUTTON_PRESSED)
      0017DD EE               [12] 3321 	mov	a,r6
      0017DE 70 02            [24] 3322 	jnz	00105$
                                   3323 ;	src/fsm.c:420: curstate++;
      0017E0 05 5B            [12] 3324 	inc	_fsm_config_fn_curstate_65536_308
      0017E2                       3325 00105$:
                                   3326 ;	src/fsm.c:421: display_puts(ledstrings[ledstrings_conf]);
      0017E2 90 31 37         [24] 3327 	mov	dptr,#(_ledstrings + 0x0037)
      0017E5 12 06 F8         [24] 3328 	lcall	_display_puts
                                   3329 ;	src/fsm.c:422: break;
      0017E8 02 19 E7         [24] 3330 	ljmp	00164$
                                   3331 ;	src/fsm.c:423: case fsm_config_ldr_calib_label:
      0017EB                       3332 00106$:
                                   3333 ;	src/fsm.c:424: if(menu_state == BUTTON_PRESSED)
      0017EB EF               [12] 3334 	mov	a,r7
      0017EC 70 03            [24] 3335 	jnz	00108$
                                   3336 ;	src/fsm.c:425: curstate = fsm_config_thermistor_calib_label;
      0017EE 75 5B 04         [24] 3337 	mov	_fsm_config_fn_curstate_65536_308,#0x04
      0017F1                       3338 00108$:
                                   3339 ;	src/fsm.c:426: if(select_state == BUTTON_PRESSED)
      0017F1 EE               [12] 3340 	mov	a,r6
      0017F2 70 03            [24] 3341 	jnz	00110$
                                   3342 ;	src/fsm.c:427: curstate = fsm_config_ldr_calib_low;
      0017F4 75 5B 02         [24] 3343 	mov	_fsm_config_fn_curstate_65536_308,#0x02
      0017F7                       3344 00110$:
                                   3345 ;	src/fsm.c:428: display_puts(ledstrings[ledstrings_lcal]);
      0017F7 90 31 3C         [24] 3346 	mov	dptr,#(_ledstrings + 0x003c)
      0017FA 12 06 F8         [24] 3347 	lcall	_display_puts
                                   3348 ;	src/fsm.c:429: break;
      0017FD 02 19 E7         [24] 3349 	ljmp	00164$
                                   3350 ;	src/fsm.c:431: case fsm_config_ldr_calib_high:
      001800                       3351 00112$:
                                   3352 ;	src/fsm.c:432: display_autobrightness = 0;
                                   3353 ;	assignBit
      001800 C2 1F            [12] 3354 	clr	_display_autobrightness
                                   3355 ;	src/fsm.c:434: if(menu_state == BUTTON_LONG_PRESSED)
      001802 BF 01 03         [24] 3356 	cjne	r7,#0x01,00114$
                                   3357 ;	src/fsm.c:435: curstate = fsm_config_ldr_calib_label;
      001805 75 5B 01         [24] 3358 	mov	_fsm_config_fn_curstate_65536_308,#0x01
      001808                       3359 00114$:
                                   3360 ;	src/fsm.c:436: if(select_state == BUTTON_PRESSED){
      001808 EE               [12] 3361 	mov	a,r6
      001809 70 2F            [24] 3362 	jnz	00119$
                                   3363 ;	src/fsm.c:437: if(curstate == fsm_config_ldr_calib_low) {
      00180B 74 02            [12] 3364 	mov	a,#0x02
      00180D B5 5B 10         [24] 3365 	cjne	a,_fsm_config_fn_curstate_65536_308,00116$
                                   3366 ;	include/adc.h:133: INT_IE_EADC = 0;				//Disable ADC interrupt
                                   3367 ;	assignBit
      001810 C2 AD            [12] 3368 	clr	_INT_IE_EADC
                                   3369 ;	include/adc.h:134: tmp = adc_ldr_reading;	   		//Store temporary result
      001812 AC 29            [24] 3370 	mov	r4,_adc_ldr_reading
      001814 AD 2A            [24] 3371 	mov	r5,(_adc_ldr_reading + 1)
                                   3372 ;	include/adc.h:135: INT_IE_EADC = 1;				//Enable ADC interrupt
                                   3373 ;	assignBit
      001816 D2 AD            [12] 3374 	setb	_INT_IE_EADC
                                   3375 ;	src/fsm.c:438: config_tmp = adc_get_ldr();
      001818 8C 5C            [24] 3376 	mov	_fsm_config_fn_config_tmp_65536_308,r4
      00181A 8D 5D            [24] 3377 	mov	(_fsm_config_fn_config_tmp_65536_308 + 1),r5
                                   3378 ;	src/fsm.c:439: curstate++;
      00181C 05 5B            [12] 3379 	inc	_fsm_config_fn_curstate_65536_308
      00181E 80 1A            [24] 3380 	sjmp	00119$
      001820                       3381 00116$:
                                   3382 ;	include/adc.h:133: INT_IE_EADC = 0;				//Disable ADC interrupt
                                   3383 ;	assignBit
      001820 C2 AD            [12] 3384 	clr	_INT_IE_EADC
                                   3385 ;	include/adc.h:134: tmp = adc_ldr_reading;	   		//Store temporary result
      001822 AC 29            [24] 3386 	mov	r4,_adc_ldr_reading
      001824 AD 2A            [24] 3387 	mov	r5,(_adc_ldr_reading + 1)
                                   3388 ;	include/adc.h:135: INT_IE_EADC = 1;				//Enable ADC interrupt
                                   3389 ;	assignBit
      001826 D2 AD            [12] 3390 	setb	_INT_IE_EADC
                                   3391 ;	src/fsm.c:441: adc_calibrate_LDR(adc_get_ldr(),config_tmp);
      001828 85 5C 2D         [24] 3392 	mov	_adc_calibrate_LDR_PARM_2,_fsm_config_fn_config_tmp_65536_308
      00182B 85 5D 2E         [24] 3393 	mov	(_adc_calibrate_LDR_PARM_2 + 1),(_fsm_config_fn_config_tmp_65536_308 + 1)
      00182E 8C 82            [24] 3394 	mov	dpl,r4
      001830 8D 83            [24] 3395 	mov	dph,r5
      001832 12 02 6A         [24] 3396 	lcall	_adc_calibrate_LDR
                                   3397 ;	src/fsm.c:442: curstate = fsm_config_ldr_calib_label;
      001835 75 5B 01         [24] 3398 	mov	_fsm_config_fn_curstate_65536_308,#0x01
                                   3399 ;	src/fsm.c:443: display_autobrightness = 1;
                                   3400 ;	assignBit
      001838 D2 1F            [12] 3401 	setb	_display_autobrightness
      00183A                       3402 00119$:
                                   3403 ;	src/fsm.c:446: if(curstate == fsm_config_ldr_calib_low) {
      00183A 74 02            [12] 3404 	mov	a,#0x02
      00183C B5 5B 13         [24] 3405 	cjne	a,_fsm_config_fn_curstate_65536_308,00121$
                                   3406 ;	src/fsm.c:447: display_puts(ledstrings[ledstrings_cllo]);
      00183F 90 31 46         [24] 3407 	mov	dptr,#(_ledstrings + 0x0046)
      001842 12 06 F8         [24] 3408 	lcall	_display_puts
                                   3409 ;	src/fsm.c:448: INT_IE_EA = 0;
                                   3410 ;	assignBit
      001845 C2 AF            [12] 3411 	clr	_INT_IE_EA
                                   3412 ;	src/fsm.c:449: display_counts = DISPLAY_COUNTS_MIN;
      001847 75 48 2C         [24] 3413 	mov	_display_counts,#0x2c
      00184A 75 49 01         [24] 3414 	mov	(_display_counts + 1),#0x01
                                   3415 ;	src/fsm.c:450: INT_IE_EA = 1;
                                   3416 ;	assignBit
      00184D D2 AF            [12] 3417 	setb	_INT_IE_EA
      00184F 02 19 E7         [24] 3418 	ljmp	00164$
      001852                       3419 00121$:
                                   3420 ;	src/fsm.c:452: display_puts(ledstrings[ledstrings_clhi]);
      001852 90 31 4B         [24] 3421 	mov	dptr,#(_ledstrings + 0x004b)
      001855 12 06 F8         [24] 3422 	lcall	_display_puts
                                   3423 ;	src/fsm.c:453: INT_IE_EA = 0;
                                   3424 ;	assignBit
      001858 C2 AF            [12] 3425 	clr	_INT_IE_EA
                                   3426 ;	src/fsm.c:454: display_counts = DISPLAY_COUNTS_MAX;
      00185A 75 48 00         [24] 3427 	mov	_display_counts,#0x00
      00185D 75 49 EA         [24] 3428 	mov	(_display_counts + 1),#0xea
                                   3429 ;	src/fsm.c:455: INT_IE_EA = 1;
                                   3430 ;	assignBit
      001860 D2 AF            [12] 3431 	setb	_INT_IE_EA
                                   3432 ;	src/fsm.c:457: break;
      001862 02 19 E7         [24] 3433 	ljmp	00164$
                                   3434 ;	src/fsm.c:458: case fsm_config_thermistor_calib_label:
      001865                       3435 00123$:
                                   3436 ;	src/fsm.c:459: if(menu_state == BUTTON_PRESSED)
      001865 EF               [12] 3437 	mov	a,r7
      001866 70 03            [24] 3438 	jnz	00125$
                                   3439 ;	src/fsm.c:460: curstate = fsm_config_display_label;
      001868 75 5B 06         [24] 3440 	mov	_fsm_config_fn_curstate_65536_308,#0x06
      00186B                       3441 00125$:
                                   3442 ;	src/fsm.c:461: if(select_state == BUTTON_PRESSED) {
      00186B EE               [12] 3443 	mov	a,r6
      00186C 70 1A            [24] 3444 	jnz	00127$
                                   3445 ;	src/fsm.c:462: curstate = fsm_config_thermistor_calib;
      00186E 75 5B 05         [24] 3446 	mov	_fsm_config_fn_curstate_65536_308,#0x05
                                   3447 ;	src/fsm.c:463: config_tmp = (TEMP_OFFSET_LSB | (TEMP_OFFSET_MSB << 0x08));
      001871 90 00 1D         [24] 3448 	mov	dptr,#(_ds1302_sram_data + 0x001d)
      001874 E0               [24] 3449 	movx	a,@dptr
      001875 FD               [12] 3450 	mov	r5,a
      001876 90 00 1E         [24] 3451 	mov	dptr,#(_ds1302_sram_data + 0x001e)
      001879 E0               [24] 3452 	movx	a,@dptr
      00187A FB               [12] 3453 	mov	r3,a
      00187B E4               [12] 3454 	clr	a
      00187C FC               [12] 3455 	mov	r4,a
      00187D FA               [12] 3456 	mov	r2,a
      00187E ED               [12] 3457 	mov	a,r5
      00187F 42 04            [12] 3458 	orl	ar4,a
      001881 EA               [12] 3459 	mov	a,r2
      001882 42 03            [12] 3460 	orl	ar3,a
      001884 8C 5C            [24] 3461 	mov	_fsm_config_fn_config_tmp_65536_308,r4
      001886 8B 5D            [24] 3462 	mov	(_fsm_config_fn_config_tmp_65536_308 + 1),r3
      001888                       3463 00127$:
                                   3464 ;	src/fsm.c:465: display_puts(ledstrings[ledstrings_tcal]);
      001888 90 31 50         [24] 3465 	mov	dptr,#(_ledstrings + 0x0050)
      00188B 12 06 F8         [24] 3466 	lcall	_display_puts
                                   3467 ;	src/fsm.c:466: break;
      00188E 02 19 E7         [24] 3468 	ljmp	00164$
                                   3469 ;	src/fsm.c:467: case fsm_config_thermistor_calib:
      001891                       3470 00128$:
                                   3471 ;	src/fsm.c:468: if(menu_state == BUTTON_LONG_PRESSED) {
      001891 BF 01 11         [24] 3472 	cjne	r7,#0x01,00130$
                                   3473 ;	src/fsm.c:469: curstate = fsm_config_thermistor_calib_label;
      001894 75 5B 04         [24] 3474 	mov	_fsm_config_fn_curstate_65536_308,#0x04
                                   3475 ;	src/fsm.c:470: TEMP_OFFSET_LSB = (config_tmp & 0x00ff);
      001897 AD 5C            [24] 3476 	mov	r5,_fsm_config_fn_config_tmp_65536_308
      001899 90 00 1D         [24] 3477 	mov	dptr,#(_ds1302_sram_data + 0x001d)
      00189C ED               [12] 3478 	mov	a,r5
      00189D F0               [24] 3479 	movx	@dptr,a
                                   3480 ;	src/fsm.c:471: TEMP_OFFSET_MSB = (config_tmp >> 0x08);
      00189E AD 5D            [24] 3481 	mov	r5,(_fsm_config_fn_config_tmp_65536_308 + 1)
      0018A0 90 00 1E         [24] 3482 	mov	dptr,#(_ds1302_sram_data + 0x001e)
      0018A3 ED               [12] 3483 	mov	a,r5
      0018A4 F0               [24] 3484 	movx	@dptr,a
      0018A5                       3485 00130$:
                                   3486 ;	src/fsm.c:473: if((select_state == BUTTON_PRESSED) || (select_state == BUTTON_HELD_DOWN))
      0018A5 EE               [12] 3487 	mov	a,r6
      0018A6 60 03            [24] 3488 	jz	00131$
      0018A8 BE 02 15         [24] 3489 	cjne	r6,#0x02,00132$
      0018AB                       3490 00131$:
                                   3491 ;	src/fsm.c:474: config_tmp = bcd_add_16(config_tmp,0x0001);
      0018AB 75 60 01         [24] 3492 	mov	_bcd_add_16_PARM_2,#0x01
      0018AE 75 61 00         [24] 3493 	mov	(_bcd_add_16_PARM_2 + 1),#0x00
      0018B1 85 5C 82         [24] 3494 	mov	dpl,_fsm_config_fn_config_tmp_65536_308
      0018B4 85 5D 83         [24] 3495 	mov	dph,(_fsm_config_fn_config_tmp_65536_308 + 1)
      0018B7 12 0B AE         [24] 3496 	lcall	_bcd_add_16
      0018BA 85 82 5C         [24] 3497 	mov	_fsm_config_fn_config_tmp_65536_308,dpl
      0018BD 85 83 5D         [24] 3498 	mov	(_fsm_config_fn_config_tmp_65536_308 + 1),dph
      0018C0                       3499 00132$:
                                   3500 ;	src/fsm.c:476: if(config_tmp > 0x0140)
      0018C0 AC 5C            [24] 3501 	mov	r4,_fsm_config_fn_config_tmp_65536_308
      0018C2 AD 5D            [24] 3502 	mov	r5,(_fsm_config_fn_config_tmp_65536_308 + 1)
      0018C4 C3               [12] 3503 	clr	c
      0018C5 74 40            [12] 3504 	mov	a,#0x40
      0018C7 9C               [12] 3505 	subb	a,r4
      0018C8 74 01            [12] 3506 	mov	a,#0x01
      0018CA 9D               [12] 3507 	subb	a,r5
      0018CB 50 05            [24] 3508 	jnc	00135$
                                   3509 ;	src/fsm.c:477: config_tmp = 0x0000;
      0018CD E4               [12] 3510 	clr	a
      0018CE F5 5C            [12] 3511 	mov	_fsm_config_fn_config_tmp_65536_308,a
      0018D0 F5 5D            [12] 3512 	mov	(_fsm_config_fn_config_tmp_65536_308 + 1),a
      0018D2                       3513 00135$:
                                   3514 ;	src/fsm.c:479: config_tmp2 = EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()];
                                   3515 ;	include/adc.h:147: INT_IE_EADC = 0;				//Disable ADC interrupt
                                   3516 ;	assignBit
      0018D2 C2 AD            [12] 3517 	clr	_INT_IE_EADC
                                   3518 ;	include/adc.h:148: tmp = adc_thermistor_reading;	//Store temporary result
      0018D4 AC 2B            [24] 3519 	mov	r4,_adc_thermistor_reading
      0018D6 AD 2C            [24] 3520 	mov	r5,(_adc_thermistor_reading + 1)
                                   3521 ;	include/adc.h:149: INT_IE_EADC = 1;				//Enable ADC interrupt
                                   3522 ;	assignBit
      0018D8 D2 AD            [12] 3523 	setb	_INT_IE_EADC
                                   3524 ;	src/fsm.c:479: config_tmp2 = EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()];
      0018DA EC               [12] 3525 	mov	a,r4
      0018DB 2C               [12] 3526 	add	a,r4
      0018DC FC               [12] 3527 	mov	r4,a
      0018DD ED               [12] 3528 	mov	a,r5
      0018DE 33               [12] 3529 	rlc	a
      0018DF FD               [12] 3530 	mov	r5,a
      0018E0 8C 82            [24] 3531 	mov	dpl,r4
      0018E2 74 28            [12] 3532 	mov	a,#(_EEPROM_TEMP_FROM_THERMISTOR_TABLE >> 8)
      0018E4 2D               [12] 3533 	add	a,r5
      0018E5 F5 83            [12] 3534 	mov	dph,a
      0018E7 E4               [12] 3535 	clr	a
      0018E8 93               [24] 3536 	movc	a,@a+dptr
      0018E9 FC               [12] 3537 	mov	r4,a
      0018EA A3               [24] 3538 	inc	dptr
      0018EB E4               [12] 3539 	clr	a
      0018EC 93               [24] 3540 	movc	a,@a+dptr
      0018ED FD               [12] 3541 	mov	r5,a
                                   3542 ;	src/fsm.c:480: config_tmp2 = bcd_add_16(config_tmp2,config_tmp);
      0018EE 85 5C 60         [24] 3543 	mov	_bcd_add_16_PARM_2,_fsm_config_fn_config_tmp_65536_308
      0018F1 85 5D 61         [24] 3544 	mov	(_bcd_add_16_PARM_2 + 1),(_fsm_config_fn_config_tmp_65536_308 + 1)
      0018F4 8C 82            [24] 3545 	mov	dpl,r4
      0018F6 8D 83            [24] 3546 	mov	dph,r5
      0018F8 12 0B AE         [24] 3547 	lcall	_bcd_add_16
      0018FB AC 82            [24] 3548 	mov	r4,dpl
      0018FD AD 83            [24] 3549 	mov	r5,dph
                                   3550 ;	src/fsm.c:481: if(config_tmp2 > 0x0999)
      0018FF 8C 02            [24] 3551 	mov	ar2,r4
      001901 8D 03            [24] 3552 	mov	ar3,r5
      001903 C3               [12] 3553 	clr	c
      001904 74 99            [12] 3554 	mov	a,#0x99
      001906 9A               [12] 3555 	subb	a,r2
      001907 74 09            [12] 3556 	mov	a,#0x09
      001909 9B               [12] 3557 	subb	a,r3
      00190A 50 04            [24] 3558 	jnc	00137$
                                   3559 ;	src/fsm.c:482: config_tmp2 = 0x0999;
      00190C 7C 99            [12] 3560 	mov	r4,#0x99
      00190E 7D 09            [12] 3561 	mov	r5,#0x09
      001910                       3562 00137$:
                                   3563 ;	src/fsm.c:483: display_puttemp(config_tmp2);
      001910 8C 82            [24] 3564 	mov	dpl,r4
      001912 8D 83            [24] 3565 	mov	dph,r5
      001914 12 08 38         [24] 3566 	lcall	_display_puttemp
                                   3567 ;	src/fsm.c:484: break;
      001917 02 19 E7         [24] 3568 	ljmp	00164$
                                   3569 ;	src/fsm.c:485: case fsm_config_display_label:
      00191A                       3570 00138$:
                                   3571 ;	src/fsm.c:486: if(select_state == BUTTON_PRESSED)
      00191A EE               [12] 3572 	mov	a,r6
      00191B 70 03            [24] 3573 	jnz	00140$
                                   3574 ;	src/fsm.c:487: curstate = fsm_config_auto_mmss;
      00191D 75 5B 07         [24] 3575 	mov	_fsm_config_fn_curstate_65536_308,#0x07
      001920                       3576 00140$:
                                   3577 ;	src/fsm.c:488: if(menu_state == BUTTON_PRESSED)
      001920 EF               [12] 3578 	mov	a,r7
                                   3579 ;	src/fsm.c:489: curstate = fsm_config_label;
      001921 70 02            [24] 3580 	jnz	00142$
      001923 F5 5B            [12] 3581 	mov	_fsm_config_fn_curstate_65536_308,a
      001925                       3582 00142$:
                                   3583 ;	src/fsm.c:490: display_puts(ledstrings[ledstrings_disp]);
      001925 90 31 55         [24] 3584 	mov	dptr,#(_ledstrings + 0x0055)
      001928 12 06 F8         [24] 3585 	lcall	_display_puts
                                   3586 ;	src/fsm.c:491: break;
      00192B 02 19 E7         [24] 3587 	ljmp	00164$
                                   3588 ;	src/fsm.c:499: case fsm_config_display_remove_lzeroes:
      00192E                       3589 00150$:
                                   3590 ;	src/fsm.c:500: display_puts(ledstrings[curstate + 0x0b]);
      00192E AC 5B            [24] 3591 	mov	r4,_fsm_config_fn_curstate_65536_308
      001930 7D 00            [12] 3592 	mov	r5,#0x00
      001932 74 0B            [12] 3593 	mov	a,#0x0b
      001934 2C               [12] 3594 	add	a,r4
      001935 F5 60            [12] 3595 	mov	__mulint_PARM_2,a
      001937 E4               [12] 3596 	clr	a
      001938 3D               [12] 3597 	addc	a,r5
      001939 F5 61            [12] 3598 	mov	(__mulint_PARM_2 + 1),a
      00193B 90 00 05         [24] 3599 	mov	dptr,#0x0005
      00193E C0 07            [24] 3600 	push	ar7
      001940 C0 06            [24] 3601 	push	ar6
      001942 12 1C 67         [24] 3602 	lcall	__mulint
      001945 AC 82            [24] 3603 	mov	r4,dpl
      001947 AD 83            [24] 3604 	mov	r5,dph
      001949 EC               [12] 3605 	mov	a,r4
      00194A 24 00            [12] 3606 	add	a,#_ledstrings
      00194C F5 82            [12] 3607 	mov	dpl,a
      00194E ED               [12] 3608 	mov	a,r5
      00194F 34 31            [12] 3609 	addc	a,#(_ledstrings >> 8)
      001951 F5 83            [12] 3610 	mov	dph,a
      001953 12 06 F8         [24] 3611 	lcall	_display_puts
      001956 D0 06            [24] 3612 	pop	ar6
      001958 D0 07            [24] 3613 	pop	ar7
                                   3614 ;	src/fsm.c:501: if(curstate != fsm_config_display_remove_lzeroes) {
      00195A 74 0E            [12] 3615 	mov	a,#0x0e
      00195C B5 5B 02         [24] 3616 	cjne	a,_fsm_config_fn_curstate_65536_308,00311$
      00195F 80 47            [24] 3617 	sjmp	00156$
      001961                       3618 00311$:
                                   3619 ;	src/fsm.c:502: display_putbool((SC_1 >> (curstate - 0x06)) & 0x01);
      001961 90 00 03         [24] 3620 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      001964 E0               [24] 3621 	movx	a,@dptr
      001965 FD               [12] 3622 	mov	r5,a
      001966 E5 5B            [12] 3623 	mov	a,_fsm_config_fn_curstate_65536_308
      001968 24 FA            [12] 3624 	add	a,#0xfa
      00196A F5 F0            [12] 3625 	mov	b,a
      00196C 05 F0            [12] 3626 	inc	b
      00196E ED               [12] 3627 	mov	a,r5
      00196F 80 02            [24] 3628 	sjmp	00313$
      001971                       3629 00312$:
      001971 C3               [12] 3630 	clr	c
      001972 13               [12] 3631 	rrc	a
      001973                       3632 00313$:
      001973 D5 F0 FB         [24] 3633 	djnz	b,00312$
      001976 54 01            [12] 3634 	anl	a,#0x01
      001978 F5 82            [12] 3635 	mov	dpl,a
      00197A C0 07            [24] 3636 	push	ar7
      00197C C0 06            [24] 3637 	push	ar6
      00197E 12 08 12         [24] 3638 	lcall	_display_putbool
      001981 D0 06            [24] 3639 	pop	ar6
      001983 D0 07            [24] 3640 	pop	ar7
                                   3641 ;	src/fsm.c:503: if(select_state == BUTTON_PRESSED)
      001985 EE               [12] 3642 	mov	a,r6
      001986 70 40            [24] 3643 	jnz	00157$
                                   3644 ;	src/fsm.c:504: SC_1 ^= (0x01 << (curstate - 0x06));
      001988 90 00 03         [24] 3645 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      00198B E0               [24] 3646 	movx	a,@dptr
      00198C FD               [12] 3647 	mov	r5,a
      00198D E5 5B            [12] 3648 	mov	a,_fsm_config_fn_curstate_65536_308
      00198F 24 FA            [12] 3649 	add	a,#0xfa
      001991 F5 F0            [12] 3650 	mov	b,a
      001993 05 F0            [12] 3651 	inc	b
      001995 74 01            [12] 3652 	mov	a,#0x01
      001997 80 02            [24] 3653 	sjmp	00317$
      001999                       3654 00315$:
      001999 25 E0            [12] 3655 	add	a,acc
      00199B                       3656 00317$:
      00199B D5 F0 FB         [24] 3657 	djnz	b,00315$
      00199E FC               [12] 3658 	mov	r4,a
      00199F 62 05            [12] 3659 	xrl	ar5,a
      0019A1 90 00 03         [24] 3660 	mov	dptr,#(_ds1302_sram_data + 0x0003)
      0019A4 ED               [12] 3661 	mov	a,r5
      0019A5 F0               [24] 3662 	movx	@dptr,a
      0019A6 80 20            [24] 3663 	sjmp	00157$
      0019A8                       3664 00156$:
                                   3665 ;	src/fsm.c:506: display_putbool(DISPLAY_REMOVE_LEADING_ZEROES);
      0019A8 90 00 02         [24] 3666 	mov	dptr,#(_ds1302_sram_data + 0x0002)
      0019AB E0               [24] 3667 	movx	a,@dptr
      0019AC FD               [12] 3668 	mov	r5,a
      0019AD 74 01            [12] 3669 	mov	a,#0x01
      0019AF 5D               [12] 3670 	anl	a,r5
      0019B0 F5 82            [12] 3671 	mov	dpl,a
      0019B2 C0 07            [24] 3672 	push	ar7
      0019B4 C0 06            [24] 3673 	push	ar6
      0019B6 12 08 12         [24] 3674 	lcall	_display_putbool
      0019B9 D0 06            [24] 3675 	pop	ar6
      0019BB D0 07            [24] 3676 	pop	ar7
                                   3677 ;	src/fsm.c:507: if(select_state == BUTTON_PRESSED)
      0019BD EE               [12] 3678 	mov	a,r6
      0019BE 70 08            [24] 3679 	jnz	00157$
                                   3680 ;	src/fsm.c:508: SC_0 ^= 0x01;
      0019C0 90 00 02         [24] 3681 	mov	dptr,#(_ds1302_sram_data + 0x0002)
      0019C3 E0               [24] 3682 	movx	a,@dptr
      0019C4 64 01            [12] 3683 	xrl	a,#0x01
      0019C6 FE               [12] 3684 	mov	r6,a
      0019C7 F0               [24] 3685 	movx	@dptr,a
      0019C8                       3686 00157$:
                                   3687 ;	include/display.h:116: display_buffer[1] &= 0x7f;
      0019C8 74 7F            [12] 3688 	mov	a,#0x7f
      0019CA 55 43            [12] 3689 	anl	a,(_display_buffer + 0x0001)
      0019CC F5 43            [12] 3690 	mov	(_display_buffer + 0x0001),a
                                   3691 ;	include/display.h:117: display_buffer[2] &= 0x7f;
      0019CE 74 7F            [12] 3692 	mov	a,#0x7f
      0019D0 55 44            [12] 3693 	anl	a,(_display_buffer + 0x0002)
      0019D2 F5 44            [12] 3694 	mov	(_display_buffer + 0x0002),a
                                   3695 ;	src/fsm.c:512: if(menu_state == BUTTON_PRESSED)
      0019D4 EF               [12] 3696 	mov	a,r7
      0019D5 70 0A            [24] 3697 	jnz	00161$
                                   3698 ;	src/fsm.c:513: if(++curstate == fsm_config_end)
      0019D7 05 5B            [12] 3699 	inc	_fsm_config_fn_curstate_65536_308
      0019D9 74 0F            [12] 3700 	mov	a,#0x0f
      0019DB B5 5B 03         [24] 3701 	cjne	a,_fsm_config_fn_curstate_65536_308,00161$
                                   3702 ;	src/fsm.c:514: curstate = fsm_config_auto_mmss;
      0019DE 75 5B 07         [24] 3703 	mov	_fsm_config_fn_curstate_65536_308,#0x07
      0019E1                       3704 00161$:
                                   3705 ;	src/fsm.c:515: if(menu_state == BUTTON_LONG_PRESSED)
      0019E1 BF 01 03         [24] 3706 	cjne	r7,#0x01,00164$
                                   3707 ;	src/fsm.c:516: curstate = fsm_config_display_label;
      0019E4 75 5B 06         [24] 3708 	mov	_fsm_config_fn_curstate_65536_308,#0x06
                                   3709 ;	src/fsm.c:518: }
      0019E7                       3710 00164$:
                                   3711 ;	src/fsm.c:520: return fsm_repeat;
      0019E7 75 82 01         [24] 3712 	mov	dpl,#0x01
                                   3713 ;	src/fsm.c:521: }
      0019EA 22               [24] 3714 	ret
                                   3715 	.area CSEG    (CODE)
                                   3716 	.area CONST   (CODE)
                                   3717 	.area XINIT   (CODE)
                                   3718 	.area CABS    (ABS,CODE)
      003300                       3719 	.org 0x3300
      003300                       3720 _fsm_transition_table_fp:
      003300 9A 12                 3721 	.byte _fsm_set_fn, (_fsm_set_fn >> 8)
      003302 0D 0C                 3722 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      003304 0D 0C                 3723 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      003306 0D 0C                 3724 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      003308 9A 12                 3725 	.byte _fsm_set_fn, (_fsm_set_fn >> 8)
      00330A 25 14                 3726 	.byte _fsm_alarm_fn, (_fsm_alarm_fn >> 8)
      00330C 0D 0C                 3727 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      00330E 25 14                 3728 	.byte _fsm_alarm_fn, (_fsm_alarm_fn >> 8)
      003310 82 17                 3729 	.byte _fsm_config_fn, (_fsm_config_fn >> 8)
      003312 0D 0C                 3730 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      003314 82 17                 3731 	.byte _fsm_config_fn, (_fsm_config_fn >> 8)
      003316 0D 0C                 3732 	.byte _fsm_home_fn, (_fsm_home_fn >> 8)
      003318                       3733 	.org 0x3318
      003318                       3734 _fsm_transition_table_s:
      003318 01                    3735 	.db #0x01	; 1
      003319 00                    3736 	.db #0x00	; 0
      00331A 00                    3737 	.db #0x00	; 0
      00331B 00                    3738 	.db #0x00	; 0
      00331C 01                    3739 	.db #0x01	; 1
      00331D 02                    3740 	.db #0x02	; 2
      00331E 00                    3741 	.db #0x00	; 0
      00331F 02                    3742 	.db #0x02	; 2
      003320 03                    3743 	.db #0x03	; 3
      003321 00                    3744 	.db #0x00	; 0
      003322 03                    3745 	.db #0x03	; 3
      003323 00                    3746 	.db #0x00	; 0
