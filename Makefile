CC = g++
CFLAGS = -Wall -Wextra -std=c++17 
LIBS = -lglfw3 -lGL -lX11

GLAD_DIR = /usr/include/glad
SRC_DIR = src
SRC_FILES = $(wildcard $(GLAD_DIR)/glad.c $(SRC_DIR)/**.cpp)
OBJ_DIR = obj
OBJ_FILES = $(patsubst wildcard $(GLAD_DIR)/glad.c $(SRC_DIR)/%%.cpp,$(OBJ_DIR)/%%.o,$(SRC_FILES))

TARGET = GladeEngine

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(TARGET)

re: fclean $(TARGET)

test: re clean
	./$(TARGET)