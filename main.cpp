#include <stdio.h>

#include "caesar.h"


#define ENCRYTABLE 'A'
#define KEY 51

int main(void)
{
    printf("Encrypt char - %c \n", ENCRYTABLE);

    char caesar = encryptCharOnlyBig(ENCRYTABLE, KEY);
    printf("Encrypted char %c to %c \n", ENCRYTABLE, caesar);
    printf("Decrypted char %c to %c \n", caesar, decryptCharOnlyBig(caesar, KEY));

    printf("Encrycpt Big and small - %c to %c \n", 'Z', encryptCharBigAndSmall('Z', KEY));
    printf("Decrycpt Big and small - %c to %c \n", 'z', decryptCharBigAndSmall('z', KEY));

    return 0;
}

char encryptChar(char eChar, short key)
{
    return eChar + key;
}

char decryptChar(char dChar, short key)
{
    return dChar - key;
}

char encryptCharBigAndSmall(char eChar, short key)
{
    eChar -= 'A';
    short caesar = (eChar + key) % 52;

    if(caesar > 26)
    {
        caesar += 6;
    }

    return caesar + 'A';

}

char decryptCharBigAndSmall(char dChar, short key)
{
    key %= 52;

    short t = short(dChar - key - 6);

    if((t >= 65 && t <= 90) || (t >= 97 && t <= 122))
    {
        return t;
    }
    else if(t > 90 && t < 97)
    {
        t -= 6;
    }
    return t;
}

char encryptCharOnlyBig(char eChar, short key)
{
    //Aplhabet größe
    key %= 26;
    short tester = short(eChar + key);

    //65 ist A in ASCII Tabelle  90 ist Z in ASCII Tabelle
    if(tester >= 65 && tester <= 90)
    {
        return eChar + key;
    }

    return eChar;
}

char decryptCharOnlyBig(char dChar, short key)
{
    //Aplhabet größe
    key %= 26;
    short tester = short(dChar - key);

    //65 ist A in ASCII Tabelle  90 ist Z in ASCII Tabelle
    if(tester >= 65 && tester <= 90)
    {
        return dChar - key;
    }

    return dChar;
}
