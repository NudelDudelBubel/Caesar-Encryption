#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

#include "caesar.h"

using namespace std;

#define ENCRYTABLE 'A'
#define KEY 103

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

    bool work = true;
    while(work)
    {
        char cryptMode;
        cout << "Select one of the following options: \n"
                "1 - Encrypt \n"
                "2 - Decrypt \n"
                "* - Exit \n" << endl;
        cin >> cryptMode;

        switch(cryptMode)
        {
            case '1':
            {
                chooseEncryptMode();
                break;
            }
            case '2':
            {
                chooseDecryptMode();
                break;
            }
            default:
            {
                work = false;
                break;
            }
        }
    }
}

void chooseEncryptMode()
{
    char encryptMode;
    cout << "Select one encrypt option: \n"
            "1 - Only big Latin letter \n"
            "2 - Big or small Latin letter \n"
            "3 - Any character \n"
            "* - Back \n" << endl;
    cin >> encryptMode;

    if(encryptMode != '1' && encryptMode != '2' && encryptMode != '3')
    {
        return;
    }

    cout << "Enter line to encrypt:" << endl;
    string tmp;
    cin.ignore();
    getline(cin, tmp);

    int length = tmp.length();
    char line[length];
    strcpy(line, tmp.c_str());

    for(char x : line)
    {
        if(!checkCharacter(encryptMode, x))
        {
            cout << "Cannot encrypt char < " << x << " > with choosen mode! \n" << endl;
            encryptMode = 'x';
            return;
        }
    }

    int key = inputKey();

    encrypt(encryptMode, line, key, length);
}

void encrypt(char encryptMode, char *line, int key, int length)
{
    char tmp[length];
    for(int i = 0; i < length; ++i)
    {
        tmp[i] = ' ';
    }

    for(int i = 0; i < length; ++i)
    {
        char crypt = line[i];

        if(crypt == ' ')
        {
            continue;
        }

        switch(encryptMode)
        {
            case '1':
            {
                tmp[i] = encryptCharOnlyBig(crypt, key);
                printf("Encrypted %c to %c with key %d \n", crypt, tmp[i] , key);
                break;
            }
            case '2':
            {
                tmp[i] = encryptCharBigAndSmall(crypt, key);
                printf("Encrypted %c to %c with key %d \n", crypt, tmp[i], key);
                break;
            }
            case '3':
            {
                tmp[i] = encryptChar(crypt, key);
                printf("Encrypted %c to %c with key %d \n", crypt, tmp[i], key);
                break;
            }
            default:
            {
                break;
            }
        }
    }

    printf("\nFully encrypted : \n");
    for(int i = 0; i < length; ++i)
    {
        printf("%c", tmp[i]);
    }
    printf("\n\n\n");
}

void chooseDecryptMode()
{
    char decryptMode;
    cout << "Select one decrypt option: \n"
            "1 - Only big Latin letter \n"
            "2 - Big or small Latin letter \n"
            "3 - Any character \n"
            "* - Back \n" << endl;
    cin >> decryptMode;

    if(decryptMode != '1' && decryptMode != '2' && decryptMode != '3')
    {
        return;
    }

    cout << "Enter line to decrypt:" << endl;
    string tmp;
    cin.ignore();
    getline(cin, tmp);

    int length = tmp.length();
    char line[length];
    strcpy(line, tmp.c_str());

    for(char x : line)
    {
        if(!checkCharacter(decryptMode, x))
        {
            cout << "Cannot decrypt char < " << x << " > with choosen mode!" << endl;
            decryptMode = 'x';
            return;
        }
    }

    int key = inputKey();

    decrypt(decryptMode, line, key, length);
}

void decrypt(int decryptMode, char* line, int key, int length)
{
    char tmp[length];
    for(int i = 0; i < length; ++i)
    {
        tmp[i] = ' ';
    }

    for(int i = 0; i < length; ++i)
    {
        char crypt = line[i];

        if(crypt == ' ')
        {
            continue;
        }

        switch(decryptMode)
        {
            case '1':
            {
                tmp[i] = decryptCharOnlyBig(crypt, key);
                printf("Decrypted %c to %c with key %d \n", crypt, tmp[i], key);
                break;
            }
            case '2':
            {
                tmp[i] = decryptCharBigAndSmall(crypt, key);
                printf("Decrypted %c to %c with key %d \n", crypt, tmp[i], key);
                break;
            }
            case '3':
            {
                tmp[i] = decryptChar(crypt, key);
                printf("Decrypted %c to %c with key %d \n", crypt, tmp[i], key);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    printf("\nFully decrypted : \n");
    for(int i = 0; i < length; ++i)
    {
        printf("%c", tmp[i]);
    }
    printf("\n\n\n");
}

bool checkCharacter(char mode, char character)
{
    if(character == ' ')
    {
        return true;
    }

    if(mode == '1' && (character >= 'A' && character <= 'Z')) // Only big
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

int inputKey()
{
    int key;
    cout << "Enter caesar key:" << endl;
    cin >> key;

    return key;
}
