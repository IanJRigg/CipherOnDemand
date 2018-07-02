#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "caesar-cipher.h"
#include "vigenere-cipher.h"

class AlgorithmController
{
public:
    AlgorithmController();

    EncryptionAlgorithm& selectedAlgorithm();

    CaesarCipher& caesar();
    VigenereCipher& vigenere();

    void setSelectedToCaesar();
    void setSelectedToVigenere();

private:
    enum Cipher_t
    {
        Caesar,
        Vigenere,

        Invalid_Cipher
    };

    CaesarCipher caesarCipher;
    VigenereCipher vigenereCipher;

    Cipher_t selectedCipher;
};

#endif // ALGORITHMCONTROLLER_H
