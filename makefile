CC=gcc
CFLAGS=-Wall -O2 -march=native -c
LDFLAGS=
SOURCES=vigenere.c crypt.c decrypt.c
HEADERS=vigenere.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=crypt decrypt

all: $(EXECUTABLES) $(SOURCES) $(HEADERS)

crypt: $(OBJECTS)
	$(CC) $(LDFLAGS) vigenere.o crypt.o   -o crypt

decrypt: $(OBJECTS)
	$(CC) $(LDFLAGS) vigenere.o decrypt.o -o decrypt

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLES)
