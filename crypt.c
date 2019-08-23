#include "vigenere.h"

int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        char* msg = argv[1];
        char* key = argv[2];
    
        char* encrypted_msg = vencrypt(msg, key);
    
        printf("%s\n", encrypted_msg);
    
        free(encrypted_msg);
    }

    return 0;
}
