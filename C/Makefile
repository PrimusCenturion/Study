CC := gcc

TARGET_EXEC := output

OBJ_DIRS := ./obj
SRC_DIRS := ./src
BUILD_DIRS := ./bin

DATASTRUCTURES_DIRS := $(SRC_DIRS)/datastructures

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS = $(shell find $(OBJ_DIRS) -name '*.o')

SRCS_DATASTRUCTURES := $(shell find $(DATASTRUCTURES_DIRS) -name '*.c')

$(BUILD_DIRS)/$(TARGET_EXEC): setup
	$(CC) $(OBJS) -o $@ 
	
setup:
	$(CC) -c $(SRCS_DATASTRUCTURES) $(SRCS)
	mv *.o $(OBJ_DIRS)	

run:
	$(BUILD_DIRS)/$(TARGET_EXEC) 

rerun: clean # THIS IS A TEMORARY COMMAND TO BUILD THE learning.c correctly
	$(CC) $(SRC_DIRS)/learning.c -o $(BUILD_DIRS)/$(TARGET_EXEC)

clean:
	rm -f $(OBJS)
	rm -f $(BUILD_DIRS)/$(TARGET_EXEC)


