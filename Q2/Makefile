CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o libVec.o libArr.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
libvec.o: libVec.cpp libvec.h
	$(CXX) $(CXXFLAGS) libVec.cpp
libarr.o: libArr.cpp libArr.h
	$(CXX) $(CXXFLAGS) libArr.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
