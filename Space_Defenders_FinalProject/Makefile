TARGET = SpaceDefenders
SRC_FILES = main.cpp mainShip.cpp LaserBolt.cpp Ships.cpp Enemies.cpp enemyLaser.cpp
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -Wno-error=unused-parameter
CXXFLAGS_DEBUG = -g
CXXVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
	Q=
else
	DEL = rm -f
	Q="
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(SFML_LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CXXVERSION) $(CXXFLAGS_DEBUG) -c -o $@ $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) Makefile.bak

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES
main.o: mainShip.h LaserBolt.h Enemies.h Ships.h enemyLaser.h
Enemies.o: Ships.h
#Ships.o: Ships.cpp Ships.h

