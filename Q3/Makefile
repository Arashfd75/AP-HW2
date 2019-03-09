CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o transaction.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
transaction.o: transaction.h transaction.cpp
	$(CXX) $(CXXFLAGS) transaction.cpp 
clean:
	rm -f $(TARGET) $(OBJECTS)
