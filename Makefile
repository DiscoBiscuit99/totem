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

ALL_FILES_ENGINE = ${UTILS_SRC}/*.cpp ${ENGINE_SRC}/*.cpp ${LIB_FILES}/glad.c

engine: ${ALL_FILES_ENGINE}
	g++ $(CFLAGS) -o totem $^ $(LDFLAGS)

# Tests

simple_test: ${ALL_FILES_ENGINE} ${ENGINE_TESTS}/simple_test/*.cpp
	g++ $(CFLAGS) -o totem_test $^ $(LDFLAGS)

deltatime_test: ${ALL_FILES_ENGINE} ${ENGINE_TESTS}/deltatime_test/*.cpp
	g++ $(CFLAGS) -o totem_test $^ $(LDFLAGS)

.PHONY: run test clean

run: engine
	./totem

test: simple_test
	./totem_test

clean:
	rm -f totem totem_test
