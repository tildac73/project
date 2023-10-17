CC = g++
CXX_FLAGS = -Wall -Wextra
SFML_INCLUDE = -I"/opt/homebrew/Cellar/sfml/2.6.0/include"
SFML_LIBS =  -L"/opt/homebrew/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system

BUILD_DIR = build
BIN = game

SRCS = main.cpp \
HUD.cpp\
Screen.cpp\
Building.cpp\
SheepFarm.cpp\
ChickenFarm.cpp\
CowFarm.cpp\
UserProfile.cpp\
Shop.cpp\
Market.cpp\
HomeScreen.cpp

# This automatically generates the object file names from source files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CXX_FLAGS) $^ -o $@ $(SFML_LIBS)

%.o: %.cpp
	$(CC) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(BIN)