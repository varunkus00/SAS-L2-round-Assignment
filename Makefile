CC := gcc
CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -Iinclude
CFLAGS   := -Wall -Wextra -Werror -Iinclude

SRCS_DIR := src
INCS := include
TEST_DIR := tests
BIN	:= exec

.PHONY : all clean test

all: $(BIN)

# Rule to compile src/api/*.c and tests/sampleTest.cc into exec
$(BIN): $(SRCS_DIR)/api/*.c $(SRCS_DIR)/*.cc $(TEST_DIR)/sampleTest.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run tests directly
test: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(BIN).exe