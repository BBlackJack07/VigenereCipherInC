#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define bool char
#define true 1
#define false 0

void vigenere_encrypt(const char* msg, const char* key, char* encrypted_msg);
bool vigenere_encrypt_file(const char* path_to_file, const char* key, const char* output_file);

void vigenere_decrypt(const char* encrypted_msg, const char* key, char* msg);
bool vigenere_decrypt_file(const char* input_file, const char* key, const char* output_file);

char get_vigenere_encrypt_char(const char c, const int position, const char* key, const int key_size);
char get_vigenere_decrypt_char(const char c, const int position, const char* key, const int key_size);


void set_vigenere_square();
void free_vigenere_square();

#endif //VIGENERE_CIPHER
