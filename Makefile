# Makefile para STC15 LED Clock

CC = sdcc
CFLAGS = --std-sdcc11 --code-size 13312 --iram-size 256
INCLUDES = -Iinclude -I/usr/share/sdcc/include/mcs51 -I/usr/share/sdcc/include

SRC_DIR = src
INC_DIR = include
REL_DIR = Release
BIN_DIR = Binary

SOURCES = main.c eeprom.c adc.c alarm.c button.c crc.c display.c ds1302.c  fsm.c ledfonts.c timer.c
SRC_FILES = $(addprefix $(SRC_DIR)/,$(SOURCES))
REL_FILES = $(addprefix $(REL_DIR)/,$(SOURCES:.c=.rel))

TARGET = DIY_Firmware_13k

.PHONY: all clean size help

all: $(BIN_DIR)/$(TARGET).ihx

$(BIN_DIR)/$(TARGET).ihx: $(REL_FILES) | $(BIN_DIR)
	@echo 'Linking: $@'
	$(CC) -o $@ $(REL_FILES)
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
	@rm -f $(REL_DIR)/*.asm
	@rm -f $(REL_DIR)/*.rst
	@rm -f $(REL_DIR)/*.sym
	@rm -f $(REL_DIR)/*.lst
	@rm -f $(BIN_DIR)/*.ihx
	@rm -f $(BIN_DIR)/*.lk
	@rm -f $(BIN_DIR)/*.mem
	@rm -f $(BIN_DIR)/*.map
	@echo 'Clean done'

size: $(BIN_DIR)/$(TARGET).ihx
	@./check_size.sh

help:
	@echo 'Targets: all, clean, size, help'
