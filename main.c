#include "vigenere.h"

void showHelp(void);

int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        char* msg = argv[2];
        char* key = argv[3];
        
        if (!strcmp("--crypt", argv[1]))
        {
            char* encrypted_msg = vencrypt(msg, key);
            printf("%s\n", encrypted_msg);
            free(encrypted_msg);
            return EXIT_SUCCESS;
        }
        else if (!strcmp("--decrypt", argv[1]))
        {
            char* decrypted_msg = vdecrypt(msg, key);
            printf("%s\n", decrypted_msg);
            free(decrypted_msg);
            return EXIT_SUCCESS;
        }
        showHelp();
        return EXIT_FAILURE;
    }
    showHelp();
    return EXIT_FAILURE;
}

void showHelp(void)
{
    puts("Usage: vigenere MODE MSG KEY");
    puts("MODE should be :");
    puts("\t--crypt     to crypt message MSG using key KEY");
    puts("\t  or");
    puts("\t--decrypt   to decrypt message MSG using key KEY");
}

