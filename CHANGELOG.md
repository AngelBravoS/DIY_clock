   # Changelog - AP15W413AS Migration Fork
   
   ## [1.0.0-ap15w413as] - 2026-02-26
   
   ### Fixed
   - Bug #1: PORT_P5_7 incorrect address (0xcd → 0xcf)
   - Bug #2: UART_SM0 incorrect address (0x9e → 0x9f)
   - Bug #3: adc_read_thermistor() calling wrong function
   - Bug #4: lut_24h_to_12h table overlap (0x3227 → 0x3250)
   - Bug #5: eeprom_erase() missing IAP_ADDRL
   - Bug #6: Timer0 HELD_DOWN detection (== → >=)
   
   ### Changed
   - Migrated to AP15W413AS (13KB Flash)
   - FSM_HOME_RESET_TICKS: 10s → 5s
   - Year base: 2017 → 2026
   
   ### Added
   - Clean Makefile for src/include structure
   - Memory allocation documentation (PDF)
   - Automated build scripts
