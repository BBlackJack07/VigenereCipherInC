#include "vigenere.h"
#define MAX_MSG_SIZE 20000

void showHelp(void);

int main(int argc, char* argv[])
{
    int ret = EXIT_FAILURE;
    set_vigenere_square();
    if (argc == 4)
    {
        if (!strcmp("--encrypt", argv[1]))
        {
            char encrypted_msg[MAX_MSG_SIZE] = "";
            vigenere_encrypt(argv[2], argv[3], encrypted_msg);
            printf("%s\n", encrypted_msg);
            ret = EXIT_SUCCESS;
        }
        else if (!strcmp("--decrypt", argv[1]))
        {
            char decrypted_msg[MAX_MSG_SIZE] = "";
            vigenere_decrypt(argv[2], argv[3], decrypted_msg);
            printf("%s\n", decrypted_msg);
            ret = EXIT_SUCCESS;
        }

        else {
            showHelp();
        }
    }

    else if (argc == 5)
    {
        if (!strcmp("--encrypt-file", argv[1]))
        {
            if (vigenere_encrypt_file(argv[2], argv[3], argv[4])) {
                printf("The file %s was created with ouput.\n", argv[4]);
                ret = EXIT_SUCCESS;
            }
            else {
                char error[] = "vigenere: ";
                strcat(error, argv[2]);
                perror(error);
            }
        }
        else if (!strcmp("--decrypt-file", argv[1]))
        {
            if (vigenere_decrypt_file(argv[2], argv[3], argv[4])) {
                printf("The file %s was created with ouput.\n", argv[4]);
                ret = EXIT_SUCCESS;
            }
            else {
                char error[] = "vigenere: ";
                strcat(error, argv[2]);
                perror(error);
            }
        }
        
        else {
            showHelp();
        }

    }
    
    else {
    showHelp();
    }

    free_vigenere_square();
    return ret;
}

void showHelp(void)
{
    puts(" Usage: vigenere MODE MSG KEY");
    puts("        vigenere MODE INPUT KEY OUTPUT");
    puts(" where MODE should be :");
    puts("\t--encrypt         to encrypt message MSG using key KEY");
    puts("\t--decrypt         to decrypt message MSG using key KEY");
    puts("\t--encrypt-file    to encrypt message from file INPUT to file OUTPUT using key KEY");
    puts("\t--decrypt-file    to decrypt message from file INPUT to file OUTPUT using key KEY");
}

