# Компилятор и флаги
CC = gcc
CFLAGS = -I./include -I/usr/include/SDL2 -Wall -Wextra
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lcjson

# Пути к исходникам
SRC_DIR = src
BUILD_DIR = build

# Списки файлов
SRCS = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
TARGET = snake_game

# Правила
all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/engine $(BUILD_DIR)/game

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean