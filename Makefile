##
# Things that i always forget
# @ -> On the left of ":"
# ^ -> Dependencies (on the right of ":").
# < -> Who caused the action.
# % -> Anything.
##

.PHONY: all

CC		 := g++
CCVERS   := -std=c++17
CCFLAGS  := -Wall -Wextra -pedantic-errors
LIBS	 := -lSDL2 -lpthread
SRC_DIR  := src
OBJ_DIR  := obj
EXE_NAME := exe
ALL_DIRS := $(shell find $(SRC_DIR) -type d)
OBJ_DIRS := $(subst $(SRC_DIR),$(OBJ_DIR),$(ALL_DIRS))
SOURCES  := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS  := $(subst .cpp,.o,$(SOURCES))
OBJECTS  := $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJECTS))

ifdef REL
	CCFLAGS += -O3
else
	CCFLAGS += -g
endif

all: $(OBJ_DIR)/ $(EXE_NAME)

$(OBJ_DIR)/:
	mkdir -p $(OBJ_DIR) $(OBJ_DIRS)

$(EXE_NAME): $(OBJECTS) main.cpp
	$(CC) $(CCVERS) $(CCFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CCVERS) -o $@ -c $^ $(CCFLAGS)

cls : clean

clc : clean

clear: clean

clean:
	rm -rf $(EXE_NAME)
	rm -rf $(OBJ_DIR)

info-srcs:
	$(info $(SOURCES))

info-objs:
	$(info $(OBJECTS))

info-objdirs:
	$(info $(OBJ_DIRS))