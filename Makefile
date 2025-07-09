TARGET = rayshlong

CC = clang++ -Wall -Wextra
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/game.cpp

$(SRCS): src/game.hpp

$(TARGET): $(SRCS) example.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: run
run: $(TARGET)
	./$(TARGET)
