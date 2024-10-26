CXX = g++
CXXFLAGS = -std=c++17

all: $(TARGET)

$(TARGET):
	$(CXX) -o $@ $< $(CXXFLAGS) && ./$(TARGET) 

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)