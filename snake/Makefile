CC = gcc
CFLAGS = -Wall -Wextra -std=99c -02
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SRC_DIR = src
BUILD_DIR = BUILD_DIR

SRC = $(wildcard $(SRC_DIR)/*.c) \
	  $(wildcard $(SRC_DIR)/engine/*.c) \
	  $(wildcard $(SRC_DIR)/game/*.c) \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC = snake_game

all: $(EXEC)

$(EXEC): $(OBJ)
		 $(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: all clean