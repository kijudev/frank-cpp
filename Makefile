CXX      := clang++
CXXOPT   := -O1 -g
CXXFLAGS := -std=c++23 -Wall -Wextra -Iinclude 

APPS      := $(wildcard apps/*/main.cpp)
APP_BINS  := $(patsubst apps/%/main.cpp,bin/%,$(APPS))

TESTS     := $(wildcard tests/*.cpp)
TEST_BINS := $(patsubst tests/%.cpp,bin/tests/%,$(TESTS))

.PHONY: all apps tests clean compile-commands

all: apps tests compile-commands

apps: $(APP_BINS)

tests: $(TEST_BINS)

bin/%: apps/%/main.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(CXXOPT) $< -o $@

bin/tests/%: tests/%.cpp
	mkdir -p bin/tests
	$(CXX) $(CXXFLAGS) $(CXXOPT) $< -o $@

compile-command: clean
	bear -- make

clean:
	rm -rf bin
	rm -f compile_commands.json
