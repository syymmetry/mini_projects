CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Isrc
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SRC_DIR = src
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(SRC_DIR)/engine/*.c) \
      $(wildcard $(SRC_DIR)/game/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC = snake_game

all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/engine $(BUILD_DIR)/game

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: all clean