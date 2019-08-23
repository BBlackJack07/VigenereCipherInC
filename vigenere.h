#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

#define AVALAIBLE_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "

int findIndex(const char c);
bool isavalaible(const char c);

char* vencrypt(char msg[], char key[]);
char* vdecrypt(char encrypted_msg[], char key[]);

