#include "vigenere-cipher.h"
#include "vigenere-table.h"

#include "algorithms-common.h"

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
QString VigenereCipher::encrypt(const QString& plainText)
{
    QString cipherText = "";

    int tracker = 0L;
    const int max = plainText.size();

    for(const QChar& character : plainText)
    {
        qDebug() << "(Encrypt) Tracker is : " << tracker << ". For " << key;
        cipherText.append(encrypt(character.toLatin1(), key.at(tracker).toLatin1()));

        if (tracker >= max - 1L)
        {
            tracker = 0L;
        }

        ++tracker;
    }

    return cipherText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
QString VigenereCipher::decrypt(const QString& cipherText)
{
    QString plainText = "";

    int tracker = 0L;
    const int max = cipherText.size();

    for(const QChar& character : cipherText)
    {
        qDebug() << "(Decrypt) Tracker is : " << tracker << ". For " << key;
        plainText.append(decrypt(character.toLatin1(), key.at(tracker).toLatin1()));

        if (tracker >= max - 1L)
        {
            tracker = 0L;
        }

        ++tracker;
    }

    return plainText;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void VigenereCipher::setKey(const QString& key)
{
    this->key = key;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char VigenereCipher::encrypt(const char plainTextChar, const char keyChar)
{
    char result = plainTextChar;

    if (charIsAlpha(plainTextChar) && charIsAlpha(keyChar))
    {
        unsigned int keyIndex = charToAlphaIndex(keyChar);
        unsigned int plainTextIndex = charToAlphaIndex(plainTextChar);

        qDebug() << keyIndex << " " << plainTextIndex;

        if ((keyIndex < 26UL) && (plainTextIndex < 26UL))
        {
            result = VIGENERE_TABLE[keyIndex][plainTextIndex];
        }
    }

    return result;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
char VigenereCipher::decrypt(const char cipherTextChar, const char keyChar)
{
    char result = cipherTextChar;

    if (charIsLowerCase(cipherTextChar))
    {
        unsigned int keyIndex = charToAlphaIndex(keyChar);

        for(int i = 0L; i < 26L; ++i)
        {
            if (VIGENERE_TABLE[keyIndex][i] == cipherTextChar)
            {
                result = 'a' + i;
                break;
            }
        }
    }
    else if (charIsUpperCase(cipherTextChar))
    {
        unsigned int keyIndex = charToAlphaIndex(keyChar);

        for(int i = 0L; i < 26L; ++i)
        {
            if (VIGENERE_TABLE[keyIndex][i] == cipherTextChar)
            {
                result = 'A' + i;
                break;
            }
        }
    }

    return result;
}
