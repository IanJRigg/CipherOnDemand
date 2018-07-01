#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "caesar-cipher.h"

class AlgorithmController
{
public:
    AlgorithmController();

    EncryptionAlgorithm& selectedAlgorithm();

    CaesarCipher& caesar();

private:
    CaesarCipher caesarCipher;
};

#endif // ALGORITHMCONTROLLER_H
