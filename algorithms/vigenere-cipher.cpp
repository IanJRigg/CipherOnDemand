#include "vigenere-cipher.h"
#include "vigenere-table.h"

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
VigenereCipher::VigenereCipher(const QString& key)
    : key(key)
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString encrypt(const QString& plainText)
{
    QString cipherText = "";

    return plainText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString decrypt(const QString& cipherText)
{
    QString plainText = "";

    return plainText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void setKey(const QString& key)
{
    this->key = key;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char encryptCharacter(const char character)
{
    return character;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char decryptCharacter(const char character)
{
    return character;
}
