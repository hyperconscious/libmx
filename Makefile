CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
TARGET = exec

OBJ_FOLDER = obj
INC_FOLDER = inc
SRC_FOLDER = src

SRC_FILES = $(wildcard $(SRC_FOLDER)/*.c)
OBJ_FILES = $(addprefix $(OBJ_FOLDER)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INC_FOLDER)/*.h)

RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(INC_FOLDER)

$(OBJ_FILES): | $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_FOLDER)

$(OBJ_FOLDER):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_FOLDER)

uninstall: clean
	@$(RM) $(TARGET)

reinstall: uninstall all
