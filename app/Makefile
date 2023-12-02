BUILD_DIR:= ./build

CC:= gcc
AR:= ar

TARGET_EXEC:= main
TARGET:= $(BUILD_DIR)/$(TARGET_EXEC)

OBJ_DIR:= $(BUILD_DIR)/obj

LIB_DIR:= ./lib
#LIBS:= $(LIB_DIR)/libCalculator.a
LIB_NAME:= Calculator
LIBS:= $(addprefix -l,$(LIB_NAME))

INC_DIR:= .
SRC_DIR:= .

SRC:= $(shell find $(SRC_DIR) -name '*.c')
INC_PATH:= $(shell find $(INC_DIR) -type d)

#INC:= $(shell find $(INC_DIR) -name '*.h')
#INC_PATH:= $(dir $(INC))

OBJ:= $(patsubst %.c,%.o,$(SRC))
OBJS:= $(addprefix $(OBJ_DIR)/,$(OBJ))

INC_FLAGS:= $(addprefix -I,$(INC_PATH))

CPP_FLAGS:= $(INC_FLAGS)

LD_FLAGS:= $(addprefix -L,$(LIB_DIR))

$(TARGET): $(OBJS)
	$(CC) $(LD_FLAGS) $(LIBS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPP_FLAGS) -c $^ -o $@
	
.PHONY: clean

debug:
	echo $(INC)
	echo $(INC_PATH)

clean:
	rm -r $(BUILD_DIR)