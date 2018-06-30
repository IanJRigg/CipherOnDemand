#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "caeser-cipher.h"

class AlgorithmController
{
public:
    AlgorithmController();

    EncryptionAlgorithm& selectedAlgorithm();

private:
    CaeserCipher caeserCipher;
};

#endif // ALGORITHMCONTROLLER_H
