#include "caesar-cipher.h"

#include <QDebug>

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
CaesarCipher::CaesarCipher(unsigned int rotation)
{
    generateAlphabet(rotation);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString CaesarCipher::encrypt(const QString& plainText)
{
    QString cipherText = "";

    for(const QChar& character : plainText)
    {
        cipherText.append(encryptCharacter(character.toLatin1()));
    }

    return cipherText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString CaesarCipher::decrypt(const QString& cipherText)
{
    QString plainText = "";

    for(const QChar& character : cipherText)
    {
        plainText.append(decryptCharacter(character.toLatin1()));
    }

    return plainText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void CaesarCipher::setRotation(unsigned int rotation)
{
    if (rotation <= 26UL)
    {
        generateAlphabet(rotation);
    }
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void CaesarCipher::generateAlphabet(unsigned int rotation)
{
    char tracker = 'a' + rotation;
    for(unsigned int i = 0UL; i < 26UL; ++i)
    {
        if (tracker > 'z')
        {
            tracker = 'a';
        }

        alphabet[i] = tracker++;
    }
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char CaesarCipher::encryptCharacter(const char character)
{
    char result = character;

    if (character <= 'z' && character >= 'a')
    {
        result = alphabet[character - 'a'];
    }
    else if (character <= 'Z' && character >= 'A')
    {
        result = alphabet[character - 'A'] - 32UL;
    }

    return result;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char CaesarCipher::decryptCharacter(const char character)
{
    char result = character;

    if (character <= 'z' && character >= 'a')
    {
        for(int i = 0L; i < 26L; ++i)
        {
            if (alphabet[i] == character)
            {
                result = 'a' + i;
            }
        }
    }
    else if (character <= 'Z' && character >= 'A')
    {
        for(int i = 0L; i < 26L; ++i)
        {
            if (alphabet[i] == character + 32UL)
            {
                result = 'A' + i;
            }
        }
    }

    return result;
}
