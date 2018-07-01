#include "caeser-cipher.h"

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
CaeserCipher::CaeserCipher(int rotation) :
    rotationFactor(rotation)
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString CaeserCipher::encrypt(const QString& plainText)
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
QString CaeserCipher::decrypt(const QString& cipherText)
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
QChar CaeserCipher::encryptCharacter(const QChar& character)
{
    return QChar('a');
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QChar CaeserCipher::decryptCharacter(const QChar& character)
{
    return QChar('a');
}
