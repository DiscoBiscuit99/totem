SAN_FLAGS = -fsanitize=leak -fsanitize=address -fsanitize=undefined
CFLAGS = -std=c++17 -O2 -Wall -Wextra -g $(SAN_FLAGS)
LDFLAGS = -lglfw -lGL -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
LIB_FILES = libs
SRC_FILES = src
UTILS_SRC = ${SRC_FILES}/utils
ENGINE_SRC = ${SRC_FILES}/engine
#GRAPHICS_SRC = ${SRC_FILES}/graphics
#PHYSICS_SRC = ${SRC_FILES}/physics
TEST_SRC = tests
ENGINE_TESTS = ${TEST_SRC}/engine

engine: ${ENGINE_SRC}/* ${LIB_FILES}/glad.c
	g++ $(CFLAGS) -o totem $^ $(LDFLAGS)

# Tests

simple_test: ${UTILS_SRC}/* ${ENGINE_SRC}/* ${ENGINE_TESTS}/simple_test/* ${LIB_FILES}/glad.c
	g++ $(CFLAGS) -o totem_test $^ $(LDFLAGS)

deltatime_test: ${ENGINE_SRC}/* ${ENGINE_TESTS}/deltatime_test/* ${LIB_FILES}/glad.c
	g++ $(CFLAGS) -o totem_test $^ $(LDFLAGS)

.PHONY: run test clean

run: engine
	./totem

test: deltatime_test
	./totem_test

clean:
	rm -f totem totem_test
