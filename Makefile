# Makefile para STC15 LED Clock

CC = sdcc
CFLAGS = --std-sdcc11 --opt-code-size --fomit-frame-pointer --data-loc 0x24 --model-small --iram-size 256 --xram-size 256 --code-size 8192 --stack-size 128
INCLUDES = -Iinclude -I/usr/share/sdcc/include/mcs51 -I/usr/share/sdcc/include

SRC_DIR = src
INC_DIR = include
REL_DIR = Release
BIN_DIR = Binary

SOURCES = main.c adc.c alarm.c button.c crc.c display.c ds1302.c eeprom.c fsm.c ledfonts.c timer.c uart.c
SRC_FILES = $(addprefix $(SRC_DIR)/,$(SOURCES))
REL_FILES = $(addprefix $(REL_DIR)/,$(SOURCES:.c=.rel))

TARGET = DIY_Firmware_13k

.PHONY: all clean size flash help

all: $(BIN_DIR)/$(TARGET).ihx

$(BIN_DIR)/$(TARGET).ihx: $(REL_FILES) | $(BIN_DIR)
	@echo 'Linking: $@'
	$(CC) --data-loc 0x24 -o $@ $(REL_FILES)
	@echo 'Done'

$(REL_DIR)/%.rel: $(SRC_DIR)/%.c | $(REL_DIR)
	@echo 'Building: $<'
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(REL_DIR):
	@mkdir -p $(REL_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(REL_DIR)/* $(BIN_DIR)/*
	@echo 'Clean done'

size: $(BIN_DIR)/$(TARGET).ihx
	@./check_size.sh

flash: $(BIN_DIR)/$(TARGET).ihx
	@sudo chmod 666 /dev/ttyACM0 2>/dev/null || true
	@stcgal -P stc15 -p /dev/ttyACM0 -t 22118.4 -o eeprom_erase_enabled=True $

help:
	@echo 'Targets: all, clean, size, flash, help'
