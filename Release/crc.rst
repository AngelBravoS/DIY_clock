                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module crc
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _crcSlow_PARM_2
                                     12 	.globl _crcSlow
                                     13 ;--------------------------------------------------------
                                     14 ; special function registers
                                     15 ;--------------------------------------------------------
                                     16 	.area RSEG    (ABS,DATA)
      000000                         17 	.org 0x0000
                                     18 ;--------------------------------------------------------
                                     19 ; special function bits
                                     20 ;--------------------------------------------------------
                                     21 	.area RSEG    (ABS,DATA)
      000000                         22 	.org 0x0000
                                     23 ;--------------------------------------------------------
                                     24 ; overlayable register banks
                                     25 ;--------------------------------------------------------
                                     26 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         27 	.ds 8
                                     28 ;--------------------------------------------------------
                                     29 ; internal ram data
                                     30 ;--------------------------------------------------------
                                     31 	.area DSEG    (DATA)
                                     32 ;--------------------------------------------------------
                                     33 ; overlayable items in internal ram
                                     34 ;--------------------------------------------------------
                                     35 	.area	OSEG    (OVR,DATA)
      000060                         36 _crcSlow_PARM_2:
      000060                         37 	.ds 1
      000061                         38 _crcSlow_message_65536_2:
      000061                         39 	.ds 3
                                     40 ;--------------------------------------------------------
                                     41 ; indirectly addressable internal ram data
                                     42 ;--------------------------------------------------------
                                     43 	.area ISEG    (DATA)
                                     44 ;--------------------------------------------------------
                                     45 ; absolute internal ram data
                                     46 ;--------------------------------------------------------
                                     47 	.area IABS    (ABS,DATA)
                                     48 	.area IABS    (ABS,DATA)
                                     49 ;--------------------------------------------------------
                                     50 ; bit data
                                     51 ;--------------------------------------------------------
                                     52 	.area BSEG    (BIT)
                                     53 ;--------------------------------------------------------
                                     54 ; paged external ram data
                                     55 ;--------------------------------------------------------
                                     56 	.area PSEG    (PAG,XDATA)
                                     57 ;--------------------------------------------------------
                                     58 ; external ram data
                                     59 ;--------------------------------------------------------
                                     60 	.area XSEG    (XDATA)
                                     61 ;--------------------------------------------------------
                                     62 ; absolute external ram data
                                     63 ;--------------------------------------------------------
                                     64 	.area XABS    (ABS,XDATA)
                                     65 ;--------------------------------------------------------
                                     66 ; external initialized ram data
                                     67 ;--------------------------------------------------------
                                     68 	.area XISEG   (XDATA)
                                     69 	.area HOME    (CODE)
                                     70 	.area GSINIT0 (CODE)
                                     71 	.area GSINIT1 (CODE)
                                     72 	.area GSINIT2 (CODE)
                                     73 	.area GSINIT3 (CODE)
                                     74 	.area GSINIT4 (CODE)
                                     75 	.area GSINIT5 (CODE)
                                     76 	.area GSINIT  (CODE)
                                     77 	.area GSFINAL (CODE)
                                     78 	.area CSEG    (CODE)
                                     79 ;--------------------------------------------------------
                                     80 ; global & static initialisations
                                     81 ;--------------------------------------------------------
                                     82 	.area HOME    (CODE)
                                     83 	.area GSINIT  (CODE)
                                     84 	.area GSFINAL (CODE)
                                     85 	.area GSINIT  (CODE)
                                     86 ;--------------------------------------------------------
                                     87 ; Home
                                     88 ;--------------------------------------------------------
                                     89 	.area HOME    (CODE)
                                     90 	.area HOME    (CODE)
                                     91 ;--------------------------------------------------------
                                     92 ; code
                                     93 ;--------------------------------------------------------
                                     94 	.area CSEG    (CODE)
                                     95 ;------------------------------------------------------------
                                     96 ;Allocation info for local variables in function 'crcSlow'
                                     97 ;------------------------------------------------------------
                                     98 ;nBytes                    Allocated with name '_crcSlow_PARM_2'
                                     99 ;message                   Allocated with name '_crcSlow_message_65536_2'
                                    100 ;remainder                 Allocated to registers r3 r4 
                                    101 ;byte                      Allocated to registers r2 
                                    102 ;bit                       Allocated to registers r7 
                                    103 ;------------------------------------------------------------
                                    104 ;	src/crc.c:42: crcSlow(const uint8_t message[], uint8_t nBytes)
                                    105 ;	-----------------------------------------
                                    106 ;	 function crcSlow
                                    107 ;	-----------------------------------------
      000697                        108 _crcSlow:
                           000007   109 	ar7 = 0x07
                           000006   110 	ar6 = 0x06
                           000005   111 	ar5 = 0x05
                           000004   112 	ar4 = 0x04
                           000003   113 	ar3 = 0x03
                           000002   114 	ar2 = 0x02
                           000001   115 	ar1 = 0x01
                           000000   116 	ar0 = 0x00
      000697 85 82 61         [24]  117 	mov	_crcSlow_message_65536_2,dpl
      00069A 85 83 62         [24]  118 	mov	(_crcSlow_message_65536_2 + 1),dph
      00069D 85 F0 63         [24]  119 	mov	(_crcSlow_message_65536_2 + 2),b
                                    120 ;	src/crc.c:44: crc            remainder = INITIAL_REMAINDER;
      0006A0 7B FF            [12]  121 	mov	r3,#0xff
      0006A2 7C FF            [12]  122 	mov	r4,#0xff
                                    123 ;	src/crc.c:52: for (byte = 0; byte < nBytes; ++byte)
      0006A4 7A 00            [12]  124 	mov	r2,#0x00
      0006A6                        125 00109$:
      0006A6 C3               [12]  126 	clr	c
      0006A7 EA               [12]  127 	mov	a,r2
      0006A8 95 60            [12]  128 	subb	a,_crcSlow_PARM_2
      0006AA 50 47            [24]  129 	jnc	00105$
                                    130 ;	src/crc.c:57: remainder ^= (message[byte] << (WIDTH - 8));
      0006AC EA               [12]  131 	mov	a,r2
      0006AD 25 61            [12]  132 	add	a,_crcSlow_message_65536_2
      0006AF F8               [12]  133 	mov	r0,a
      0006B0 E4               [12]  134 	clr	a
      0006B1 35 62            [12]  135 	addc	a,(_crcSlow_message_65536_2 + 1)
      0006B3 F9               [12]  136 	mov	r1,a
      0006B4 AF 63            [24]  137 	mov	r7,(_crcSlow_message_65536_2 + 2)
      0006B6 88 82            [24]  138 	mov	dpl,r0
      0006B8 89 83            [24]  139 	mov	dph,r1
      0006BA 8F F0            [24]  140 	mov	b,r7
      0006BC 12 1E 20         [24]  141 	lcall	__gptrget
      0006BF FF               [12]  142 	mov	r7,a
      0006C0 78 00            [12]  143 	mov	r0,#0x00
      0006C2 8B 05            [24]  144 	mov	ar5,r3
      0006C4 8C 06            [24]  145 	mov	ar6,r4
      0006C6 ED               [12]  146 	mov	a,r5
      0006C7 62 00            [12]  147 	xrl	ar0,a
      0006C9 EE               [12]  148 	mov	a,r6
      0006CA 62 07            [12]  149 	xrl	ar7,a
      0006CC 88 03            [24]  150 	mov	ar3,r0
      0006CE 8F 04            [24]  151 	mov	ar4,r7
                                    152 ;	src/crc.c:62: for (bit = 8; bit > 0; --bit)
      0006D0 7F 08            [12]  153 	mov	r7,#0x08
      0006D2                        154 00106$:
                                    155 ;	src/crc.c:67: if (remainder & TOPBIT)
      0006D2 EC               [12]  156 	mov	a,r4
      0006D3 30 E7 12         [24]  157 	jnb	acc.7,00102$
                                    158 ;	src/crc.c:69: remainder = (remainder << 1) ^ POLYNOMIAL;
      0006D6 EB               [12]  159 	mov	a,r3
      0006D7 2B               [12]  160 	add	a,r3
      0006D8 FD               [12]  161 	mov	r5,a
      0006D9 EC               [12]  162 	mov	a,r4
      0006DA 33               [12]  163 	rlc	a
      0006DB FE               [12]  164 	mov	r6,a
      0006DC 63 05 21         [24]  165 	xrl	ar5,#0x21
      0006DF 63 06 10         [24]  166 	xrl	ar6,#0x10
      0006E2 8D 03            [24]  167 	mov	ar3,r5
      0006E4 8E 04            [24]  168 	mov	ar4,r6
      0006E6 80 06            [24]  169 	sjmp	00107$
      0006E8                        170 00102$:
                                    171 ;	src/crc.c:73: remainder = (remainder << 1);
      0006E8 EB               [12]  172 	mov	a,r3
      0006E9 2B               [12]  173 	add	a,r3
      0006EA FB               [12]  174 	mov	r3,a
      0006EB EC               [12]  175 	mov	a,r4
      0006EC 33               [12]  176 	rlc	a
      0006ED FC               [12]  177 	mov	r4,a
      0006EE                        178 00107$:
                                    179 ;	src/crc.c:62: for (bit = 8; bit > 0; --bit)
      0006EE DF E2            [24]  180 	djnz	r7,00106$
                                    181 ;	src/crc.c:52: for (byte = 0; byte < nBytes; ++byte)
      0006F0 0A               [12]  182 	inc	r2
      0006F1 80 B3            [24]  183 	sjmp	00109$
      0006F3                        184 00105$:
                                    185 ;	src/crc.c:81: return (remainder ^ FINAL_XOR_VALUE);
      0006F3 8B 82            [24]  186 	mov	dpl,r3
      0006F5 8C 83            [24]  187 	mov	dph,r4
                                    188 ;	src/crc.c:83: }   /* crcSlow() */
      0006F7 22               [24]  189 	ret
                                    190 	.area CSEG    (CODE)
                                    191 	.area CONST   (CODE)
                                    192 	.area XINIT   (CODE)
                                    193 	.area CABS    (ABS,CODE)
