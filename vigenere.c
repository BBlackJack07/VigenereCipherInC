#include "vigenere.h"

int findIndex(const char c)
{
    for (unsigned int i = 0; i < (unsigned int)LENGHT; i++)
        if (c == AVALAIBLE_CHARS[i]) return (int)i; 
    return -1;
}

bool isavalaible(const char c)
{  
    return (isalnum(c) || c == ' ');
}

void vencrypt(char msg[], char key[], char encrypted_msg[])
{
    const size_t msg_len = strlen(msg);
    const size_t key_len = strlen(key); 
    int shift;
    
    for (unsigned int i = 0; i < (unsigned int)msg_len; i++)
    {
        if (isavalaible(msg[i]))
        {
            shift = findIndex(key[i%key_len]);
            encrypted_msg[i]=AVALAIBLE_CHARS[(findIndex(msg[i]) + shift) % LENGHT];
        }
        else
            encrypted_msg[i] = msg[i];
    }
}

void vdecrypt(char encrypted_msg[], char key[], char msg[])
{
    const size_t cmsg_len = strlen(encrypted_msg);
    const size_t key_len = strlen(key);
    int shift;

    for (unsigned int i = 0; i < (unsigned int)cmsg_len; i++)
    {
        if (isavalaible(encrypted_msg[i]))
        {
            shift = findIndex(key[i%key_len]);
            if (findIndex(encrypted_msg[i]) - shift < 0)
            {

                msg[i] = AVALAIBLE_CHARS[findIndex(encrypted_msg[i]) - shift + LENGHT];
            }
            else
            {
                msg[i] = AVALAIBLE_CHARS[findIndex(encrypted_msg[i]) - shift];
            }
        }
        else
            msg[i] = encrypted_msg[i];
    }
}

