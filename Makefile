CC = gcc
SRC = main.c
OUT_DIR = out
OUT = $(OUT_DIR)/main

all: $(OUT_DIR) $(OUT)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT): $(SRC) | $(OUT_DIR)
	$(CC) $(SRC) -o $(OUT)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean