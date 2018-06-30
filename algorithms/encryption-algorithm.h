#ifndef ENCRYPTIONALGORITHM_H
#define ENCRYPTIONALGORITHM_H

class EncryptionAlgorithm
{
public:
    virtual QString encrypt(const QString& plainText) = 0;
    virtual QString decrypt(const QString& cipherText) = 0;
};

#endif // ENCRYPTIONALGORITHM_H
