BUILD_DIR:= ./build

TARGET_EXEC:= libCalculator.a
TARGET:= $(BUILD_DIR)/$(TARGET_EXEC)

OBJ_DIR:= $(BUILD_DIR)/obj

INC_DIR:= inc
SRC_DIR:= src

CC:= gcc
AR:= ar

SRC:= $(shell find $(SRC_DIR) -name '*.c')
INC:= $(shell find $(INC_DIR) -type d)

OBJ:= $(patsubst %.c,%.o,$(SRC))
OBJS:= $(addprefix $(OBJ_DIR)/,$(OBJ))

INC_FLAGS:= $(addprefix -I,$(INC))

CPP_FLAGS:= $(INC_FLAGS)

LD_FLAGS:= -r

$(TARGET): $(OBJS)
	$(AR) $(LD_FLAGS) $@ $^

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPP_FLAGS) -c $^ -o $@

list_obj: $(TARGET)
	$(AR) -t $(TARGET)
	
.PHONY: clean

clean:
	rm -r $(BUILD_DIR)