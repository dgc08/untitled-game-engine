TARGET = rayshlong
LIB = librayengine.a

AR = ar
CC = clang++
CFLAGS = -Wall -Wextra -g -Iinclude/
LIBFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

OBJECTS = $(SRCS:.cpp=.o)
GAME_OBJECTS := $(wildcard src/objects/*.cpp)
SRCS = src/game.cpp src/cpp_impls.cpp $(GAME_OBJECTS)

include/game.hpp: include/game_core.h
$(SRCS): include/cpp_core.hpp
$(GAME_OBJECTS): include/objects.hpp include/objects.h

$(LIB): $(OBJECTS) $(SRC)
	$(AR) rcs $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

example.cpp: include/game.hpp
$(TARGET): $(SRCS) example.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFLAGS)

.PHONY: run rcample
run: $(TARGET)
	./$(TARGET)

include/game.h: include/game_core.h
example.c: include/game.h
cample: example.c $(LIB)
	gcc $^ -lrayengine -L. -o cample $(LIBFLAGS) $(CFLAGS) -lstdc++

rcample: cample
	./cample
