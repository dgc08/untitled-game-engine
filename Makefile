TARGET = rayshlong
LIB = librayengine.a

AR = ar
CC = clang++
CFLAGS = -Wall -Wextra -g
LIBFLAGS = -Iinclude/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/game.cpp src/cpp_impls.cpp
OBJECTS = $(SRCS:.cpp=.o)

include/game.hpp: include/game_core.h
$(SRCS): include/cpp_core.hpp

$(LIB): $(OBJECTS)
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
	gcc $^ -lrayengine -L. -o cample $(LIBFLAGS) -lstdc++

rcample: cample
	./cample
