#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define AVALAIBLE_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "
#define LENGHT 63 

#define bool char
#define true 1
#define false 0

int findIndex(const char c);
bool isavalaible(const char c);

void vencrypt(char msg[], char key[], char encrypted_msg[]);
void vdecrypt(char encrypted_msg[], char key[], char msg[]);

#endif //VIGENERE_CIPHER
