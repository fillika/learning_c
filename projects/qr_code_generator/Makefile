CC := gcc
CFLAGS := -Wall -Wextra -std=c11

SOURCES := $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJECTS := $(SOURCES:.c=.o)

qr_encoder: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o qr_encoder