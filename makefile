CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2 -g -c
LDFLAGS=
SOURCES=vigenere.c main.c
HEADERS=vigenere.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=vigenere

all: $(EXECUTABLE) $(SOURCES) $(HEADERS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
