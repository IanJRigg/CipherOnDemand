#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "encryption-algorithm.h"

class VigenereCipher : public EncryptionAlgorithm
{
public:
    explicit VigenereCipher(const QString& key);

    QString encrypt(const QString& plainText) override;
    QString decrypt(const QString& cipherText) override;

    void setKey(const QString& key);

private:
    char encryptCharacter(const char character);
    char decryptCharacter(const char character);

    QString key;
};

#endif // VIGENERECIPHER_H
