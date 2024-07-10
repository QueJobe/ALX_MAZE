CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

SRC_DIR = src
INC_DIR = headers

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(wildcard $(INC_DIR)/*.h)

TARGET = raycasting_game

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
