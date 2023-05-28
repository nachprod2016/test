TARGET = Test

CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

LIB = -lgtest -lgmock -lmysqlclient

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIB)
	
%.o: %.cpp 
	$(CC) -c $< -o $@

clear:
	rm -f *.o