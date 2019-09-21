CC=gcc
CFLAGS=-Wall -O2 -march=native -c
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
