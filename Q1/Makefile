CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = main.o Map.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
Map.o: Map.h Map.cpp
	$(CXX) $(CXXFLAGS) Map.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
