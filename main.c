#include "vigenere.h"
#define MAX_MSG_SIZE 100000

char readFile(char buffer[], char path_to_file[]);
void showHelp(void);

int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        if (!strcmp("--crypt", argv[1]))
        {
            char encrypted_msg[MAX_MSG_SIZE] = "";
            vencrypt(argv[2], argv[3], encrypted_msg);
            printf("%s\n", encrypted_msg);
            return EXIT_SUCCESS;
        }
        else if (!strcmp("--decrypt", argv[1]))
        {
            char decrypted_msg[MAX_MSG_SIZE] = "";
            vdecrypt(argv[2], argv[3], decrypted_msg);
            printf("%s\n", decrypted_msg);
            return EXIT_SUCCESS;
        }
        else if (!strcmp("--crypt-file", argv[1]))
        {
            char buffer[MAX_MSG_SIZE] = "";
            if (readFile(buffer, argv[2]))
            {
                char encrypted_msg[MAX_MSG_SIZE] = "";
                vencrypt(buffer, argv[3], encrypted_msg);
                printf("%s\n", encrypted_msg);
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
            char buffer[MAX_MSG_SIZE] = "";
            if (readFile(buffer, argv[2]))
            {
                char decrypted_msg[MAX_MSG_SIZE] = "";
                vdecrypt(buffer, argv[3], decrypted_msg);
                printf("%s\n", decrypted_msg);
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
    puts("\t--crypt-file     to crypt message from file PATH (or stdin if PATH is -) using key KEY");
    puts("\t--decrypt-file   to decrypt message from file PATH (or stdin if PATH is -) using key KEY");
}

char readFile(char buffer[], char path_to_file[])
{
    FILE * file = NULL;
    if (!strcmp(path_to_file, "-"))
        file = stdin;
    else
    {
        file = fopen(path_to_file, "r");
    }
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

