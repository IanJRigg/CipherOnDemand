#include "algorithm-controller.h"


/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
AlgorithmController::AlgorithmController()
    : caesarCipher(0)
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
EncryptionAlgorithm& AlgorithmController::selectedAlgorithm()
{
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
