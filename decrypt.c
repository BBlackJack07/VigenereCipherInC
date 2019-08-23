#include "vigenere.h"

int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        char* encrypted_msg = argv[1];
        char* key = argv[2];
    
        char* msg = vdecrypt(encrypted_msg, key);
    
        printf("%s\n", msg);
    
        free(msg);
    }

    return 0;
}
