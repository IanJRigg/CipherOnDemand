#ifndef CAESER_H
#define CAESER_H

#include <QChar>
#include <QString>

#include "encryption-algorithm.h"

class CaeserCipher : public EncryptionAlgorithm
{
public:
    explicit CaeserCipher(int rotation);

    QString encrypt(const QString& plainText) override;
    QString decrypt(const QString& cipherText) override;

private:
    QChar encryptCharacter(const QChar& character);
    QChar decryptCharacter(const QChar& character);

    int rotationFactor;
};

#endif // CAESER_H
