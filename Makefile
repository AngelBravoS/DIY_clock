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

.PHONY: all clean size help

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
	@touch $(REL_DIR)/.gitkeep

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)
	@touch $(BIN_DIR)/.gitkeep

clean:
	@rm -f $(REL_DIR)/*.rel
	@rm -f $(BIN_DIR)/*.ihx
	@echo 'Clean done'

size: $(BIN_DIR)/$(TARGET).ihx
	@./check_size.sh

help:
	@echo 'Targets: all, clean, size, help'
