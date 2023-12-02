BUILD_DIR:= ./build

CC:= gcc
AR:= ar

TARGET_EXEC:= libCalculator.a
TARGET:= $(BUILD_DIR)/$(TARGET_EXEC)

TARGET_LOCATION:= ../app/lib
PUBLIC_H_FILE:= ./inc/calculator.h

OBJ_DIR:= $(BUILD_DIR)/obj

INC_DIR:= inc
SRC_DIR:= src

SRC:= $(shell find $(SRC_DIR) -name '*.c')
INC:= $(shell find $(INC_DIR) -type d)

OBJ:= $(patsubst %.c,%.o,$(SRC))
OBJS:= $(addprefix $(OBJ_DIR)/,$(OBJ))

INC_FLAGS:= $(addprefix -I,$(INC))

CPP_FLAGS:= $(INC_FLAGS)

LD_FLAGS:= -r

$(TARGET): $(OBJS)
	$(AR) $(LD_FLAGS) $@ $^
	cp $(TARGET) $(TARGET_LOCATION)
	cp $(PUBLIC_H_FILE) $(TARGET_LOCATION)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPP_FLAGS) -c $^ -o $@

list_obj: $(TARGET)
	$(AR) -t $(TARGET)
	
.PHONY: clean

clean:
	rm -r $(BUILD_DIR)