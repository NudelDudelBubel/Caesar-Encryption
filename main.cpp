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
        scanf(" %c", &cryptMode);
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

        if(tmpC == ' ' || !checkCharacter(caesarMode, tmpC))
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

    printf("Complete encrypted:\n");
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

        if(tmpC == ' ' || !checkCharacter(caesarMode, tmpC))
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

    printf("Complete decrypted:\n");
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
    char t;
    scanf(" %c%c", &input, &t);
    printf("\n");

    return input;
}

char* readFromConsole(char* crypt, char cryptMode)
{
    printf("Enter line to %s:\n", cryptMode == '1' ? "encrypt" : "decrypt");

    // regex - regular expression
    scanf("%[^'\n']", crypt);

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
    scanf(" %s", &mode);
    printf("\n");

    return mode;
}

int newInputKey(char cryptMode)
{
    printf("Enter key for %sion:\n", cryptMode == '1' ? "encrypt" : "decrypt");

    int key = 0;
    scanf(" %i", &key);
    printf("\n");

    return key;
}

bool checkCharacter(char mode, char character)
{
    if(character == ' ')
    {
        return true;
    }

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
