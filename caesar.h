#ifndef CAESAR_H
#define CAESAR_H

// main
void startCMode();
void encryptMode(char cryptMode, char inputMode);
void encrypt(char* encrypt, char caesarMode, char cryptMode);
void decryptMode(char cryptMode, char inputMode);
void decrypt(char* dcrypt, char caesarMode, char cryptMode);
char chooseInput();
char* readFromConsole(char* crypt, char cryptMode);
char chooseCaesarMode(char cryptMode);
int newInputKey(char cryptMode);
bool checkCharacter(char mode, char character);
void clearBuffer();

// crypto
char encryptChar(char eChar, short key);
char decryptChar(char dChar, short key);
char encryptCharBigAndSmall(char eChar, short key);
char decryptCharBigAndSmall(char dChar, short key);
char encryptCharOnlyBig(char eChar, short key);
char decryptCharOnlyBig(char dChar, short key);

// cppui
void startCPPMode();
void cppChooseEncryptMode();
void cppEncrypt(char encryptMode, char* line, int key, int length);
void cppChooseDecryptMode();
void cppDecrypt(int decryptMode, char* line, int key, int length);
bool cppCheckCharacter(char mode, char character);
int cppInputKey();

#endif // CAESAR_H
