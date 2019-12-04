#include "caesar.h"

/*
 *
 * All functions require correct values in order to save reducing code
 *
 * Encrypt/Decrypt-Char reqires any character
 * Encrypt/Decrypt-CharBigAndSmall requires BIG and SMALL-Latin letters
 * Encrypt/Decrypt-CharOnlyBig requires BIG-Latin letters
 *
 * All Keys have to be positive
 *
 * */

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
    short tKey = key % 52;

    short caesar = eChar + tKey;

    if(caesar > 'z')
    {
        caesar -= 58;
    }

    if(caesar > 'Z' && eChar <= 'Z')
    {
        caesar += 6;
    }

    return caesar;
}

char decryptCharBigAndSmall(char dChar, short key)
{
    short tKey = key % 52;

    short caesar = dChar - tKey;

    if(caesar < 'A')
    {
        caesar += 58;
    }

    if(caesar < 'a' && dChar >= 'a')
    {
        caesar -= 6;
    }

    return caesar;
}

char encryptCharOnlyBig(char eChar, short key)
{
    //Aplhabet größe
    key %= 26;
    short tester = short(eChar + key);

    //65 ist A in ASCII Tabelle  90 ist Z in ASCII Tabelle
    if(tester >= 65 && tester <= 90)
    {
        eChar += key;
    }

    if(tester > 90)
    {
        eChar = eChar + key - 26;
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
        dChar -= key;
    }

    if(tester < 65)
    {
        dChar = dChar - key + 26;
    }

    return dChar;
}
