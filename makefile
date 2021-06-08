# Compiler options
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
EXECUTABLE_NAME=solution

# Folders
SRC=src
BIN=bin
OBJ=$(BIN)/obj

# Files
SOURCE_FILES=\
    main.c \
	Tableau/Pivot.c \
	Tableau/Solver.c \
	Tableau/Tableau.c
EXECUTABLE_FILES = $(EXECUTABLE_NAME:%=$(BIN)/%)
OBJECT_FILES     = $(SOURCE_FILES:%.c=$(OBJ)/%.o)
# ^^^ A more succinct expression for $(OBJECT_FILES), using
#     http://www.gnu.org/software/make/manual/make.html#Substitution-Refs

build: $(EXECUTABLE_FILES)

clean:
	rm -r -f $(BIN)
	rm -r -f $(EXECUTABLE_NAME)
	rm -r -f solution.txt
	@# ^^^ I don't recommend suppressing the echoing of the command using @

# http://www.gnu.org/software/make/manual/make.html#Phony-Targets
.PHONY: build clean
Debug: build

$(EXECUTABLE_FILES): $(OBJECT_FILES)
	@$(CC) $(LDFLAGS) -o $@ $^
	@# ^^^ http://www.gnu.org/software/make/manual/make.html#Automatic-Variables
	@mv $(EXECUTABLE_FILES) $(EXECUTABLE_NAME)
	@echo "Build successful!"

# http://www.gnu.org/software/make/manual/make.html#Static-Pattern
$(OBJECT_FILES): $(OBJ)/%.o: %.c definitions/defs.h
	@echo Compiling $<
	@# ^^^ Your terminology is weird: you "compile a .c file" to create a .o file.
	@mkdir -p $(@D)
	@# ^^^ http://www.gnu.org/software/make/manual/make.html#index-_0024_0028_0040D_0029
	@$(CC) $(CFLAGS) -o $@ $<
	@# ^^^ Use $(CFLAGS), not $(LDFLAGS), when compiling.
