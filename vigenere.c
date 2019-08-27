#include "vigenere.h"

const char AVALAIBLE_CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

int findIndex(const char c)
{
    const size_t len = strlen(AVALAIBLE_CHARS);
    for (int i = 0; i < len; i++)
        if (c == AVALAIBLE_CHARS[i]) return i;
    
    return -1;
}

bool isavalaible(const char c)
{  
    if (findIndex(c) == -1) return false;
    return true;
}

char* vencrypt(char msg[], char key[])
{
    const size_t msg_len = strlen(msg);
    const size_t key_len = strlen(key); 
    const size_t list_len = strlen(AVALAIBLE_CHARS);
    char *encrypted_msg = malloc(sizeof(char)*(msg_len+1));
    int shift;
    
    for (int i = 0; i < msg_len; i++)
    {
        if (isavalaible(msg[i]))
        {
            shift = findIndex(key[i%key_len]);
            encrypted_msg[i]=AVALAIBLE_CHARS[(findIndex(msg[i]) + shift) % list_len];
        }
        else
            encrypted_msg[i] = msg[i];
    }
    encrypted_msg[msg_len] = '\0';
    return encrypted_msg;
}

char* vdecrypt(char encrypted_msg[], char key[])
{
    const int cmsg_len = strlen(encrypted_msg);
    const int key_len = strlen(key);
    const size_t list_len = strlen(AVALAIBLE_CHARS);
    char *msg = malloc(sizeof(char)*(cmsg_len+1));
    int shift;

    for (int i = 0; i < cmsg_len; i++)
    {
        if (isavalaible(encrypted_msg[i]))
        {
            shift = findIndex(key[i%key_len]);
            if (findIndex(encrypted_msg[i]) - shift < 0)
            {

                msg[i] = AVALAIBLE_CHARS[findIndex(encrypted_msg[i]) - shift + list_len];
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

