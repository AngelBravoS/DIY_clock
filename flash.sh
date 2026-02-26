source stcgal-env/bin/activate
cd DIY_clock/Release/
sudo chmod 666 /dev/ttyACM0

stcgal -P stc15 -p /dev/ttyACM0 -t 22118.4 -o eeprom_erase_enabled=True stc_led_clock_8k.ihx
