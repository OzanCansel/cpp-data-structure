CXX_FLAGS= -Wall -g -std=c++17
CXX=g++
CFLAGS= -Wall -g
BUILD_DIR= ./build

test: build_test
	./$(BUILD_DIR)/test

build_test: build_dir
	$(CXX) $(CXX_FLAGS) -I. -I../third-party test.cpp -o $(BUILD_DIR)/test

build_dir:
	mkdir -p $(BUILD_DIR)
