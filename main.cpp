#include <stdio.h>
#include <iostream>

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
                encrypt();
                break;
            }
            case '2':
            {
                decrypt();
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

void encrypt()
{
    char encryptMode;
    cout << "Select one encrypt option: \n"
            "1 - Only big Latin letter \n"
            "2 - Big or small Latin letter \n"
            "3 - Any character \n"
            "* - Back \n" << endl;
    cin >> encryptMode;

    char crypt;
    int key;

    switch(encryptMode)
    {
        case '1':
        {
            crypt = inputLetterWithCheck(encryptMode);
            key = inputKey();
            printf("Encrypted %c to %c with key %d \n\n", crypt, encryptCharOnlyBig(crypt, key), key);
            break;
        }
        case '2':
        {
            crypt = inputLetterWithCheck(encryptMode);
            key = inputKey();
            printf("Encrypted %c to %c with key %d \n\n", crypt, encryptCharBigAndSmall(crypt, key), key);
            break;
        }
        case '3':
        {
            crypt = inputLetterWithCheck(encryptMode);
            key = inputKey();
            printf("Encrypted %c to %c with key %d \n\n", crypt, encryptChar(crypt, key), key);
            break;
        }
        default:
        {
            break;
        }
    }
}

void decrypt()
{
    char decryptMode;
    cout << "Select one decrypt option: \n"
            "1 - Only big Latin letter \n"
            "2 - Big or small Latin letter \n"
            "3 - Any character \n"
            "* - Back \n" << endl;
    cin >> decryptMode;

    char crypt;
    int key;

    switch(decryptMode)
    {
        case '1':
        {
            crypt = inputLetterWithCheck(decryptMode);
            key = inputKey();
            printf("Decrypted %c to %c with key %d \n\n", crypt, decryptCharOnlyBig(crypt, key), key);
            break;
        }
        case '2':
        {
            crypt = inputLetterWithCheck(decryptMode);
            key = inputKey();
            printf("Decrypted %c to %c with key %d \n\n", crypt, decryptCharBigAndSmall(crypt, key), key);
            break;
        }
        case '3':
        {
            crypt = inputLetterWithCheck(decryptMode);
            key = inputKey();
            printf("Decrypted %c to %c with key %d \n\n", crypt, decryptChar(crypt, key), key);
            break;
        }
        default:
        {
            break;
        }
    }
}

char inputLetterWithCheck(char mode)
{
    char crypt;

    do
    {
        cout << "Enter letter to crypt:" << endl;
        cin >> crypt;

        if(mode == '1' && (crypt >= 'A' && crypt <= 'Z')) // Only big
        {
            break;
        }
        else if(mode == '2' && ((crypt >= 'A' && crypt <= 'Z') || (crypt >= 'a' && crypt <= 'z'))) // Big and small
        {
            break;
        }
        else if(mode == '3')
        {
            break;
        }

    } while(true);

    return crypt;
}

int inputKey()
{
    int key;
    cout << "Enter caesar key:" << endl;
    cin >> key;

    return key;
}
