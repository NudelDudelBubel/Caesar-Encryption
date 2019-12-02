#include <stdio.h>

#include "caesar.h"


#define ENCRYTABLE 'A'
#define KEY 1

int main(void)
{
    printf("Encrypt char - %c \n", ENCRYTABLE);
//Gewöhn dir mal lieber an die Ergebnisse direkt in ne Variable zu speichern während wir ncoh testen
//dadurch wird es einfacher das ganze mti veränderten Parametern zu testen.
//Solange Werte hart Codiert sind, kann man keine Allgemeingültigkeit voraussetzen
    char caesar = encryptCharOnlyBig(ENCRYTABLE, KEY);
    printf("Encrypted char - %c to %c \n", ENCRYTABLE, caesar);
    printf("Decrypted char - %c to %c \n", caesar, decryptCharOnlyBig(caesar, KEY));
    
    printf("Encrycpt Big and small - %c to %c \n", 'z', encryptCharBigAndSmall('z', KEY));
    printf("Decrycpt Big and small - %c to %c \n", 'A', decryptCharBigAndSmall('A', KEY));

    return 0;
}

//passed
char encryptChar(char eChar, short key)
{
    return eChar + key;
}

//passed
char decryptChar(char dChar, short key)
{
    return dChar - key;
}

char encryptCharBigAndSmall(char eChar, short key)
{
    short tKey = key % 52;

    if(tKey == 0)
    {
        ++tKey;
    }

    short caesar = eChar + tKey;

    if(caesar > 'z')
    {
        caesar -= 58;
    }

    if(caesar > 'Z')
    {
        caesar += 6;
    }

    return caesar;
}

char decryptCharBigAndSmall(char dChar, short key)
{
    short tKey = key % 52;

    if(tKey == 0)
    {
        ++tKey;
    }

    short caesar = dChar - tKey;

    if(caesar < 'A')
    {
        caesar += 58;
    }

    if(caesar < 'a')
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
    
//Was passiert wenn tester kleiner ist als 65?
//Es wird nicht geprüft ob eChar ein lateinischer Buchstabe ist
    if(tester >= 65 && tester <= 90)
    {
//Schöner wäre EIN Funktionsausstiegspunkt am Ende der Funktion
        return eChar + key;
    }

    if(tester > 90)
    {
//Schöner wäre EIN Funktionsausstiegspunkt am Ende der Funktion
        return eChar + key - 26;
    }

    return eChar;
}

char decryptCharOnlyBig(char dChar, short key)
{
    //Aplhabet größe
    key %= 26;
    short tester = short(dChar - key);

    //65 ist A in ASCII Tabelle  90 ist Z in ASCII Tabelle   
    
//Was passiert wenn tester kleiner ist als 65?
//Es wird nicht geprüft ob eChar ein lateinischer Buchstabe ist
    if(tester >= 65 && tester <= 90)
    {
//Schöner wäre EIN Funktionsausstiegspunkt am Ende der Funktion
        return dChar - key;
    }

    if(tester < 65)
    {
//Schöner wäre EIN Funktionsausstiegspunkt am Ende der Funktion
        return dChar - key + 26;
    }

    return dChar;
}
