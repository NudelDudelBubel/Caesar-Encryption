#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

#include "caesar.h"

using namespace std;

void startCPPMode()
{
    bool work = true;
    while(work)
    {
        char cryptMode;
        cout << "Select one of the following options: \n"
                "1 - Encrypt \n"
                "2 - Decrypt \n"
                "* - Exit" << endl;

        cin >> cryptMode;

        cout << "" << endl;

        switch(cryptMode)
        {
            case '1':
            {
                cppChooseEncryptMode();
                break;
            }
            case '2':
            {
                cppChooseDecryptMode();
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

void cppChooseEncryptMode()
{
    char encryptMode;
    cout << "Select one encrypt option: \n"
            "1 - Capitol letters \n"
            "2 - All letters \n"
            "3 - Any characters \n"
            "* - Back" << endl;
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

    int key = cppInputKey();

    cppEncrypt(encryptMode, line, key, length);
}

void cppEncrypt(char encryptMode, char *line, int key, int length)
{
    char tmp[length];

    for(int i = 0; i < length; ++i)
    {
        tmp[i] = ' ';

        char crypt = line[i];

        if(!cppCheckCharacter(encryptMode, crypt))
        {
            tmp[i] = crypt;
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
    printf("\n");
    for(int i = 0; i < length; ++i)
    {
        printf("_");
    }
    printf("\n\n\n");
}

void cppChooseDecryptMode()
{
    char decryptMode;
    cout << "Select one decrypt option: \n"
            "1 - Capitol letters \n"
            "2 - All letters \n"
            "3 - Any characters \n"
            "* - Back" << endl;
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

    int key = cppInputKey();

    cppDecrypt(decryptMode, line, key, length);
}

void cppDecrypt(int decryptMode, char* line, int key, int length)
{
    char tmp[length];

    for(int i = 0; i < length; ++i)
    {
        tmp[i] = ' ';

        char crypt = line[i];

        if(!cppCheckCharacter(decryptMode, crypt))
        {
            tmp[i] = crypt;
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
    printf("\n");
    for(int i = 0; i < length; ++i)
    {
        printf("_");
    }
    printf("\n\n\n");
}

bool cppCheckCharacter(char mode, char character)
{
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

int cppInputKey()
{
    int key;
    cout << "Enter caesar key:" << endl;
    cin >> key;

    return key;
}
