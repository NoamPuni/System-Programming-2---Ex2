CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
LDFLAGS = 

# Target executables
MAIN_TARGET = Main
TEST_TARGET = test_runner

# Source files
MAIN_SRC = main.cpp SquareMat.cpp
TEST_SRC = test.cpp SquareMat.cpp

# Object files
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target
all: $(MAIN_TARGET) $(TEST_TARGET)

# Rule to compile main executable
$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile test executable
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the main executable
run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

# Run the test executable
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Run valgrind memory leak check
valgrind: $(MAIN_TARGET)
	valgrind --leak-check=full \
          --show-leak-kinds=all \
          --track-origins=yes \
          --verbose \
          ./$(MAIN_TARGET)

# Run valgrind on test executable
valgrind-test: $(TEST_TARGET)
	valgrind --leak-check=full \
          --show-leak-kinds=all \
          --track-origins=yes \
          --verbose \
          ./$(TEST_TARGET)

# Clean up generated files
clean:
	rm -f $(MAIN_TARGET) $(TEST_TARGET) *.o *.gch *~ core

# Phony targets
.PHONY: all run test valgrind valgrind-test clean