#ifndef CAESER_H
#define CAESER_H

#include <QString>

#include "encryption-algorithm.h"

class CaesarCipher : public EncryptionAlgorithm
{
public:
    explicit CaesarCipher(unsigned int rotation = 0UL);

    QString encrypt(const QString& plainText) override;
    QString decrypt(const QString& cipherText) override;

    void setRotation(unsigned int rotation);

private:
    void generateAlphabet(unsigned int rotation);

    char encrypt(const char character);
    char decrypt(const char character);

    char alphabet[26UL];
};

#endif // CAESER_H
