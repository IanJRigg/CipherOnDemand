#include "algorithm-controller.h"

#include <QDebug>

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
AlgorithmController::AlgorithmController()
    : caesarCipher(0),
      vigenereCipher("")
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
EncryptionAlgorithm& AlgorithmController::selectedAlgorithm()
{
    if (selectedCipher == Caesar)
    {
        return caesar();
    }
    else if (selectedCipher == Vigenere)
    {
        return vigenere();
    }

    qDebug() << "Critical error! Unknown algorithm is currently selected";
    return caesar();
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
CaesarCipher& AlgorithmController::caesar()
{
    return caesarCipher;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
VigenereCipher& AlgorithmController::vigenere()
{
    return vigenereCipher;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void AlgorithmController::setSelectedToCaesar()
{
    selectedCipher = Caesar;
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void AlgorithmController::setSelectedToVigenere()
{
    selectedCipher = Vigenere;
}
