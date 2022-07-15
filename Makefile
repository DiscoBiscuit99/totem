SAN_FLAGS = -fsanitize=leak -fsanitize=address -fsanitize=undefined
CFLAGS = -std=c++17 -O2 -Wall -Wextra -g $(SAN_FLAGS)
LDFLAGS = -lglfw -lGL -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
LIB_FILES = libs
SRC_FILES = src
ENGINE_SRC = ${SRC_FILES}/engine
#GRAPHICS_SRC = ${SRC_FILES}/graphics
#PHYSICS_SRC = ${SRC_FILES}/physics
TEST_SRC = tests

engine: ${ENGINE_SRC}/* ${LIB_FILES}/glad.c
	g++ $(CFLAGS) -o totem $^ $(LDFLAGS)

build_test: ${ENGINE_SRC}/* ${TEST_SRC}/simple_test/* ${LIB_FILES}/glad.c
	g++ $(CFLAGS) -o totem_test $^ $(LDFLAGS)

.PHONY: run test clean

run: engine
	./totem

test: build_test
	./totem_test

clean:
	rm -f totem totem_test
