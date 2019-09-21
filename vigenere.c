#include "vigenere.h"

int findIndex(const char c)
{
<<<<<<< HEAD
    const size_t len = strlen(AVALAIBLE_CHARS);
    for (int i = 0; i < len; i++)
        if (toupper(c)  == AVALAIBLE_CHARS[i]) return i;
=======
    for (unsigned int i = 0; i < (unsigned int)LENGHT; i++)
        if (c == AVALAIBLE_CHARS[i]) return (int)i;
>>>>>>> master
    
    return -1;
}

bool isavalaible(const char c)
{  
    return (isalnum(c) || c == ' ');
}

char* vencrypt(char msg[], char key[])
{
    const size_t msg_len = strlen(msg);
    const size_t key_len = strlen(key); 
    char *encrypted_msg = malloc(sizeof(char)*(msg_len+1));
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
    encrypted_msg[msg_len] = '\0';
    return encrypted_msg;
}

char* vdecrypt(char encrypted_msg[], char key[])
{
    const size_t cmsg_len = strlen(encrypted_msg);
    const size_t key_len = strlen(key);
    char *msg = malloc(sizeof(char)*(cmsg_len+1));
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
    msg[cmsg_len] = '\0';
    return msg;
}

