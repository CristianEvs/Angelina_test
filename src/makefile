# Makefile

CXX = g++
CXXFLAGS = -std=c++17 `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
TARGET = Cristian_prod

SOURCES = Cristian_prod.cc
OBJECTS = $(SOURCES:.cc=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clang:
	clang-format -i -style=Google *.cc *.h

clean:
	@-rm -rf *.o $(TARGET)
