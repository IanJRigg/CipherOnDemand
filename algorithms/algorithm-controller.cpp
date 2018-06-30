#include "algorithm-controller.h"


/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
AlgorithmController::AlgorithmController()
    : caeserCipher(0)
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
EncryptionAlgorithm& AlgorithmController::selectedAlgorithm()
{
    return caeserCipher;
}
