// main
void chooseEncryptMode();
void encrypt(char encryptMode, char* line, int key, int length);
void chooseDecryptMode();
void decrypt(int decryptMode, char* line, int key, int length);
bool checkCharacter(char mode, char character);
int inputKey();

// crypto
char encryptChar(char eChar, short key);
char decryptChar(char dChar, short key);
char encryptCharBigAndSmall(char eChar, short key);
char decryptCharBigAndSmall(char dChar, short key);
char encryptCharOnlyBig(char eChar, short key);
char decryptCharOnlyBig(char dChar, short key);
