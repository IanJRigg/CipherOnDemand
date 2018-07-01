#include "caesar-cipher.h"
#include "algorithms-common.h"

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
        cipherText.append(encrypt(character.toLatin1()));
    }

    qDebug() << plainText;

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
        plainText.append(decrypt(character.toLatin1()));
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
char CaesarCipher::encrypt(const char character)
{
    char result = character;

    if (charIsAlpha(character))
    {
        result = alphabet[charToAlphaIndex(character)];
    }

    return result;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char CaesarCipher::decrypt(const char character)
{
    char result = character;

    if (charIsLowerCase(character))
    {
        for(int i = 0L; i < 26L; ++i)
        {
            if (alphabet[i] == character)
            {
                result = 'a' + i;
                 break;
            }
        }
    }
    else if (charIsUpperCase(character))
    {
        for(int i = 0L; i < 26L; ++i)
        {
            if (alphabet[i] == character + 32UL)
            {
                result = 'A' + i;
                break;
            }
        }
    }

    return result;
}
