#include "vigenere.h"

static const char* AVALAIBLE_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
static const int   LENGHT = 63;
static char** vigenere_square;

void set_vigenere_square()
{
    vigenere_square = malloc(sizeof(char*) * (LENGHT+1));
    for (int i = 0; i < LENGHT; i++) {
        vigenere_square[i] = malloc(LENGHT+1);
        for (int j = 0; j < LENGHT; j++) {
            vigenere_square[i][j] = AVALAIBLE_CHARS[(j+i) % LENGHT];
        } 
    }
}

void free_vigenere_square()
{
    for (int i = 0; i < LENGHT; i++) {
        free(vigenere_square[i]);
    }
    free(vigenere_square);
    vigenere_square = NULL;
}

static int findIndex(const char c) 
{
    for (unsigned int i = 0; i < (unsigned int)LENGHT; i++) {
        if (c == AVALAIBLE_CHARS[i]) return (int)i; 
    }
    return -1; 
}

static bool isavalaible(const char c) { return (isalnum(c) || c == ' '); }

void vigenere_encrypt(const char* msg, const char* key, char* encrypted_msg)
{
    const size_t msg_size = strlen(msg);
    const size_t key_size = strlen(key); 
    
    for (unsigned int i = 0; i < (unsigned int)msg_size; i++)
    {
        if (isavalaible(msg[i]))
        {
            encrypted_msg[i] = get_vigenere_encrypt_char(msg[i], i, key, (int)key_size);
        }
        else
            encrypted_msg[i] = msg[i];
    }
}

bool vigenere_encrypt_file(const char* input_file, const char* key, const char* output_file)
{
    const size_t key_size = strlen(key); 
    FILE* input  = fopen(input_file, "r");
    FILE* output = NULL;
    if (!strcmp(output_file, "-")) {
        output = stdout;
    }
    else {
        output = fopen(output_file, "w");
    }

    if (input != NULL && output != NULL) {
        char c = 0x00;
        int i = 0;
        while ((c = fgetc(input)) != EOF)
        {
            if (isavalaible(c))
            {
                putc(get_vigenere_encrypt_char(c, i, key, (int)key_size), output);
            }
            else
                putc(c, output);
            i++;
        }
        fclose(input);
        fclose(output);
        return true;
    }
    return false;
}

void vigenere_decrypt(const char* encrypted_msg, const char* key, char* msg)
{
    const size_t msg_size = strlen(encrypted_msg);
    const size_t key_size = strlen(key);

    for (unsigned int i = 0; i < (unsigned int)msg_size; i++)
    {
        if (isavalaible(encrypted_msg[i]))
        {
            msg[i] = get_vigenere_decrypt_char(encrypted_msg[i], i, key, (int)key_size);
        }
        else
            msg[i] = encrypted_msg[i];
    }
}

bool vigenere_decrypt_file(const char* input_file, const char* key, const char* output_file)
{
    const size_t key_size = strlen(key);
    FILE* input = fopen(input_file, "r");
    FILE* output = NULL;
    if (!strcmp(output_file, "-")) {
        output = stdout;
    } 
    else {
        output = fopen(output_file, "w");
    }

    if (input != NULL && output != NULL) {
        char c = 0x00;
        int i = 0;
        while ((c = fgetc(input)) != EOF)
        {
            if (isavalaible(c))
            {
                putc(get_vigenere_decrypt_char(c, i, key, (int)key_size), output);
            }
            else
                putc(c, output);
            i++;
        }
        fclose(input);
        fclose(output);
        return true;
    }
    return false;
}


char get_vigenere_encrypt_char(const char c, const int position, const char* key, const int key_size)
{
    char c_to_return = 0x00;
    int row = findIndex(key[position % key_size]);
    int column = findIndex(c);
    if ((0 <= row) && (row < LENGHT) && (0 <= column) && (column < LENGHT)) {
        c_to_return = vigenere_square[findIndex(key[position % key_size])][findIndex(c)];
    }
    return c_to_return;
}

char get_vigenere_decrypt_char(const char c, const int position, const char* key, const int key_size)
{
    char c_to_return = c;
    int row = findIndex(key[position % key_size]);
    for (int i = 0; i < LENGHT; i++) {
        if (vigenere_square[i][row] == c) {
            c_to_return = AVALAIBLE_CHARS[i];
        }
    }
    return c_to_return;
}

