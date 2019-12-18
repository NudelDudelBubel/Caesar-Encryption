#include <stdio.h>

#include "caesar.h"

#define ENCRYTABLE 'A'
#define KEY 103
#define MAX_CHARACTERS 256

int main(void)
{
    printf("Encrypt char - %c with %d \n", ENCRYTABLE, KEY);

    char caesar = encryptCharOnlyBig(ENCRYTABLE, KEY);
    printf("Encrypted char - %c to %c \n", ENCRYTABLE, caesar);
    printf("Decrypted char - %c to %c \n", caesar, decryptCharOnlyBig(caesar, KEY));

    caesar = encryptCharBigAndSmall(ENCRYTABLE, KEY);
    printf("Encrycpt Big and small - %c to %c \n", ENCRYTABLE, caesar);
    printf("Decrycpt Big and small - %c to %c \n", caesar, decryptCharBigAndSmall(caesar, KEY));

    caesar = encryptChar(ENCRYTABLE, KEY);
    printf("Encrypt all chars - %c to %c \n", ENCRYTABLE, caesar);
    printf("Decrypt all chars - %c to %c \n", caesar, decryptChar(caesar, KEY));

    printf("\n \n \n");

    //startCPPMode();
    startCMode();
}

void startCMode()
{
    bool work = true;
    do
    {
        printf("Select one of the following options: \n");
        printf("1 - Encrypt \n");
        printf("2 - Decrypt \n");
        printf("* - Exit \n");

        char cryptMode;
        scanf("%c", &cryptMode);
        clearBuffer();
        printf("\n");

        switch(cryptMode)
        {
            case '1':
            {
                encryptMode(cryptMode, chooseInput());
                break;
            }
            case '2':
            {
                decryptMode(cryptMode, chooseInput());
                break;
            }
            default:
            {
                work = false;
                break;
            }
        }
    }
    while(work);
}

void encryptMode(char cryptMode, char inputMode)
{
    char crypt[MAX_CHARACTERS];
    char* cryptP;

    for(int i = 0; i < MAX_CHARACTERS; ++i)
    {
        crypt[i] = NULL;
    }

    switch(inputMode)
    {
        case '1':
        {
            cryptP = readFromConsole(crypt, cryptMode);
            break;
        }
        case '2':
        {
            break;
        }
        default:
        {
            return;
        }
    }

    encrypt(cryptP, chooseCaesarMode(cryptMode), cryptMode);
}

void encrypt(char* ecrypt, char caesarMode, char cryptMode)
{
    char tc;
    int tmpSize = -1;
    do
    {
        ++tmpSize;
        tc = ecrypt[tmpSize];
    }
    while(tc != NULL);

    char tmp[tmpSize];

    for(int i = 0; i < tmpSize; ++i)
    {
        tmp[i] = ' ';
    }

    short key = newInputKey(cryptMode);

    for(int i = 0; i < tmpSize; ++i)
    {
        char tmpC = ecrypt[i];

        if(caesarMode != '3' && (tmpC == ' ' || !checkCharacter(caesarMode, tmpC)))
        {
            tmp[i] = tmpC;
            continue;
        }

        switch(caesarMode)
        {
            case '1':
            {
                tmp[i] = encryptCharOnlyBig(tmpC, key);
                break;
            }
            case '2':
            {
                tmp[i] = encryptCharBigAndSmall(tmpC, key);
                break;
            }
            case '3':
            {
                tmp[i] = encryptChar(tmpC, key);
                break;
            }
            default:
            {
                break;
            }
        }

        printf("Encrypted %c to %c with key %d\n", tmpC, tmp[i], key);
    }

    printf("\nComplete encrypted:\n");

    for(int i = 0; i < tmpSize; ++i)
    {
        printf("%c", ecrypt[i]);
    }
    printf("\n--- TO ---\n\n");
    for(char c : tmp)
    {
        printf("%c", c);
    }
    printf("\n\n\n");
}

void decryptMode(char cryptMode, char inputMode)
{
    char crypt[MAX_CHARACTERS];
    char* cryptP;

    for(int i = 0; i < MAX_CHARACTERS; ++i)
    {
        crypt[i] = NULL;
    }

    switch(inputMode)
    {
        case '1':
        {
            cryptP = readFromConsole(crypt, cryptMode);
            break;
        }
        case '2':
        {
            break;
        }
        default:
        {
            return;
        }
    }

    decrypt(cryptP, chooseCaesarMode(cryptMode), cryptMode);
}

void decrypt(char* dcrypt, char caesarMode, char cryptMode)
{
    char tc;
    int tmpSize = -1;
    do
    {
        ++tmpSize;
        tc = dcrypt[tmpSize];
    }
    while(tc != NULL);

    char tmp[tmpSize];

    for(int i = 0; i < tmpSize; ++i)
    {
        tmp[i] = ' ';
    }

    short key = newInputKey(cryptMode);

    for(int i = 0; i < tmpSize; ++i)
    {
        char tmpC = dcrypt[i];

        if(caesarMode != '3' && (tmpC == ' ' || !checkCharacter(caesarMode, tmpC)))
        {
            tmp[i] = tmpC;
            continue;
        }

        switch(caesarMode)
        {
            case '1':
            {
                tmp[i] = decryptCharOnlyBig(tmpC, key);
                break;
            }
            case '2':
            {
                tmp[i] = decryptCharBigAndSmall(tmpC, key);
                break;
            }
            case '3':
            {
                tmp[i] = decryptChar(tmpC, key);
                break;
            }
            default:
            {
                break;
            }
        }

        printf("Decrypted %c to %c with key %d\n", tmpC, tmp[i], key);
    }

    printf("\nComplete decrypted:\n");

    for(int i = 0; i < tmpSize; ++i)
    {
        printf("%c", dcrypt[i]);
    }
    printf("\n--- TO ---\n\n");
    for(char c : tmp)
    {
        printf("%c", c);
    }
    printf("\n\n\n");
}

char chooseInput()
{
    printf("Choose input mode:\n");
    printf("1 - Console\n");
    printf("2 - File\n");
    printf("* - Back\n");

    char input;
    scanf("%c", &input);
    clearBuffer();
    printf("\n");

    return input;
}

char* readFromConsole(char* crypt, char cryptMode)
{
    printf("Enter line to %s:\n", cryptMode == '1' ? "encrypt" : "decrypt");

    // regex - regular expression
    scanf("%[^'\n']", crypt);
    clearBuffer();
    printf("\n");

    return crypt;
}

char chooseCaesarMode(char cryptMode)
{
    printf("Choose one of the following modes to %s:\n", cryptMode == '1' ? "encrypt" : "decrypt");
    printf("1 - Capital letters\n");
    printf("2 - All letters\n");
    printf("3 - Everything\n");
    printf("* - Back\n");

    char mode;
    scanf("%s", &mode);
    clearBuffer();
    printf("\n");

    return mode;
}

int newInputKey(char cryptMode)
{
    printf("Enter (digit) key for %s: ", cryptMode == '1' ? "encryption" : "decryption");

    int key = 0;
    while(scanf("%d", &key) != 1)
    {
        printf("Enter (digit) key for %s: ", cryptMode == '1' ? "encryption" : "decryption");
        while(getchar() != '\n');
    }


    clearBuffer();
    printf("\n");

    return key;
}

bool checkCharacter(char mode, char character)
{
    if(mode == '1' && (character >= 'A' && character <= 'Z')) // Only capital letters
    {
        return true;
    }
    else if(mode == '2' && ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))) // Big and small
    {
        return true;
    }
    else if(mode == '3') // All character
    {
        return true;
    }

    return false;
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
