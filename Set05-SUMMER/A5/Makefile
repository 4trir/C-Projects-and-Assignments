TARGET = A5
SRC_FILES = main.cpp IsoscelesTriangle.cpp Coordinate.cpp Polygon.cpp Quadrilateral.cpp Rhombus.cpp ScaleneTriangle.cpp EquilateralTriangle.cpp Triangle.cpp
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors -Wno-error=unused-parameter
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
main.o: main.cpp IsoscelesTriangle.h Coordinate.h Polygon.h Quadrilateral.h Rhombus.h ScaleneTriangle.h EquilateralTriangle.h
IsoscelesTriangle.o: IsoscelesTriangle.h Triangle.h Polygon.h Coordinate.h
Coordinate.o: Coordinate.h
Polygon.o: Polygon.h Coordinate.h 
Quadrilateral.o: Quadrilateral.h Polygon.h Coordinate.h 
Rhombus.o: Rhombus.h Quadrilateral.h Polygon.h Coordinate.h
ScaleneTriangle.o: ScaleneTriangle.h Triangle.h Polygon.h Coordinate.h 
EquilateralTriangle.o: EquilateralTriangle.h Triangle.h Polygon.h Coordinate.h
