CC = g++
CXX_FLAGS = -Wall -Wextra
SRCS = main.cpp \
	HUD.cpp \
	Screen.cpp \
	Building.cpp \
	SheepFarm.cpp \
	ChickenFarm.cpp \
	CowFarm.cpp \
	UserProfile.cpp \
	Shop.cpp \
	Market.cpp \
	HomeScreen.cpp

LINK = -I"/opt/homebrew/Cellar/sfml/2.6.0/include" -L"/opt/homebrew/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system

game: $(SRCS)
	$(CC) $(CXX_FLAGS) $^ -o $@ $(LINK)

.PHONY: run
run: game
	./game

.PHONY: clean
clean:
	rm -f game