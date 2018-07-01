#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <QString>

#include "encryption-algorithm.h"

class VigenereCipher : public EncryptionAlgorithm
{
public:
    explicit VigenereCipher(const QString& key);

    QString encrypt(const QString& plainText) override;
    QString decrypt(const QString& cipherText) override;

    void setKey(const QString& key);

private:
    char encrypt(const char plainTextChar, const char keyChar);
    char decrypt(const char cipherTextChar, const char keyChar);

    QString key;
};

#endif // VIGENERECIPHER_H
