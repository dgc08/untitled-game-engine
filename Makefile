TARGET = rayshlong
LIB = librayengine.a

AR = ar
CC = clang++
CFLAGS = -Wall -Wextra
LIBFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/game.cpp
OBJECTS = $(SRCS:.cpp=.o)

src/game.hpp: src/game_core.h
$(SRCS): src/game.hpp

$(LIB): $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(SRCS) example.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFLAGS)

.PHONY: run rcample
run: $(TARGET)
	./$(TARGET)

cample: $(LIB)
	gcc $(LIB) example.c -lrayengine -L. $(LIBFLAGS) -o cample

rcample: cample
	./cample
