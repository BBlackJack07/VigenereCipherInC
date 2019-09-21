#include "vigenere.h"

char readFile(char buffer[], char path_to_file[]);
void showHelp(void);

int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        if (!strcmp("--crypt", argv[1]))
        {
            char* encrypted_msg = vencrypt(argv[2], argv[3]);
            printf("%s\n", encrypted_msg);
            free(encrypted_msg);
            return EXIT_SUCCESS;
        }
        else if (!strcmp("--decrypt", argv[1]))
        {
            char* decrypted_msg = vdecrypt(argv[2], argv[3]);
            printf("%s\n", decrypted_msg);
            free(decrypted_msg);
            return EXIT_SUCCESS;
        }
        else if (!strcmp("--crypt-file", argv[1]))
        {
            char buffer[100000] = "";
            if (readFile(buffer, argv[2]))
            {
                char* encrypted_msg = vencrypt(buffer, argv[3]);
                printf("%s\n", encrypted_msg);
                free(encrypted_msg);
                return EXIT_SUCCESS;
            }
            else
            {
                char error[] = "vigenere: ";
                strcat(error, argv[2]);
                perror(error);
                return EXIT_FAILURE;
            }
        }
        else if (!strcmp("--decrypt-file", argv[1]))
        {
            char buffer[100000] = "";
            if (readFile(buffer, argv[2]))
            {
                char* decrypted_msg = vdecrypt(buffer, argv[3]);
                printf("%s\n", decrypted_msg);
                free(decrypted_msg);
                return EXIT_SUCCESS;
            }
            else
            {
                char error[] = "vigenere: ";
                strcat(error, argv[2]);
                perror(error);
                return EXIT_FAILURE;
            }
        }

        showHelp();
        return EXIT_FAILURE;
    }
    showHelp();
    return EXIT_FAILURE;
}

void showHelp(void)
{
    puts(" Usage: vigenere MODE MSG KEY");
    puts("        vigenere MODE PATH KEY");
    puts(" where MODE should be :");
    puts("\t--crypt          to crypt message MSG using key KEY");
    puts("\t--decrypt        to decrypt message MSG using key KEY");
    puts("\t--crypt-file     to crypt message from file PATH using key KEY");
    puts("\t--decrypt-file   to decrypt message from file PATH using key KEY");
}

char readFile(char buffer[], char path_to_file[])
{
    FILE * file = NULL;
    file = fopen(path_to_file, "r");

    if (file != NULL)
    {
        char line[1000] = "";
        while (fgets(line, 1000, file))
        {
            strncat(buffer, line, (size_t)1000);
        }
        fclose(file);
        return 1;
    } 
    
    return 0;
}

