CXX_FLAGS= -Wall -g
CXX=g++
CFLAGS= -Wall -g
BUILD_DIR= ./build

run_test: test
	./$(BUILD_DIR)/test

test: build_dir
	$(CXX) $(CXX_FLAGS) -I. -I../third-party test.cpp -o $(BUILD_DIR)/test

build_dir:
	mkdir -p $(BUILD_DIR)
