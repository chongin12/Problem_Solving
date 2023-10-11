CXX = g++
CXXFLAGS = -std=c++17
TARGET = 1249
SRC = 1249.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $@ $< $(CXXFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)