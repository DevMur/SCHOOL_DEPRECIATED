CXX = g++  
CXXFLAGS = -std=c++17 -Wall  

all: main Point

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

Point: Point.cpp 
	$(CXX) $(CXXFLAGS) -c Point.cpp -o Point

clean:
	rm main Point
