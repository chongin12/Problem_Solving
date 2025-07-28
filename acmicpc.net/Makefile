SHELL := /bin/bash
CXX := g++
CXXFLAGS := -std=c++17

.PHONY: all clean run

# 기본 target은 아무것도 하지 않음
all:

# .cpp 파일에 대응되는 컴파일 규칙
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< && ./$(<:.cpp=)

# .py 파일에 대응되는 컴파일 규칙
%: %.py
	python3 $<

# .golfscript 파일에 대응되는 실행 규칙
%: %.golfscript
	ruby golfscript.rb $@.golfscript

# run: $(TARGET) 필요 시 별도 구현 가능
clean:
	rm -f *.o *.out *.exe $(TARGETS)