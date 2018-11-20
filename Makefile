OBJS = structs.h main.cpp find.cpp pickup.cpp Teleport.cpp Riddle.cpp leave.cpp
CC = g++
COMPILER_FLAGS =
OBJ_NAME = give_me_a_raise

all: $(OBJS)
	$(CC) $(OBJS) $(COMPLIER_FLAGS) -o $(OBJ_NAME)
