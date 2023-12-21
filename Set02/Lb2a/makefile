TARGET = main
SRC_FILES = main.cpp

CXX = g++ -Wall
OBJECTS = $(SRC_FILES:.cpp=.o)
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del

else
	DEL = rm

endif

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -o $@ -c $<

clean:

	$(DEL) $(TARGET) $(OBJECTS)