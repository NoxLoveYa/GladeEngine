CC = g++
CFLAGS = -Wall -Wextra -std=c++17 
LIBS = -lGL -lglfw

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET = GladeEngine

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(TARGET)

test: $(TARGET) clean
	clear
	./$(TARGET)