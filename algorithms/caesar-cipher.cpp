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
        cipherText.append(encryptCharacter(character));
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
        plainText.append(decryptCharacter(character));
    }

    return plainText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void CaesarCipher::setRotation(unsigned int rotation)
{
    generateAlphabet(rotation);
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
        qDebug() << alphabet[i] << " ";
    }

    qDebug() << "";
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QChar CaesarCipher::encryptCharacter(const QChar& character)
{
    return QChar(character);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QChar CaesarCipher::decryptCharacter(const QChar& character)
{
    return QChar(character);
}
