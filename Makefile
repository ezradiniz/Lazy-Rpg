CC       	= gcc
CFLAGS    = -Wall
LIBS      = -lSDL2 -lSDL2_image
SRC_DIR 	= src
OBJ_DIR 	= obj
BIN      	= game

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	    $(RM) $(OBJ)

$(BIN): $(OBJ)
		$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	    $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
