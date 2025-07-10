TARGET = rayshlong
LIB = librayengine.a

AR = ar
CC = clang++
CFLAGS = -Wall -Wextra -g
LIBFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/game.cpp src/cpp_impls.cpp
OBJECTS = $(SRCS:.cpp=.o)

src/game.hpp: src/game_core.h
$(SRCS): src/game.hpp src/cpp_core.hpp

$(LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(SRCS) example.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFLAGS)

.PHONY: run rcample
run: $(TARGET)
	./$(TARGET)

example.c: src/game_core.h
cample: example.c $(LIB)
	gcc $^ -lrayengine -L. -o cample $(LIBFLAGS) -lstdc++

rcample: cample
	./cample
