#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
<<<<<<< HEAD
=======

#define AVALAIBLE_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "
#define LENGHT 63 
>>>>>>> master

#define bool char
#define true 1
#define false 0

<<<<<<< HEAD
#define AVALAIBLE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

=======
>>>>>>> master
int findIndex(const char c);
bool isavalaible(const char c);

char* vencrypt(char msg[], char key[]);
char* vdecrypt(char encrypted_msg[], char key[]);

#endif //VIGENERE_CIPHER
