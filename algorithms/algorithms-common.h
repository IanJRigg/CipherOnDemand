#ifndef ALGORITHMSCOMMON_H
#define ALGORITHMSCOMMON_H

#include <QDebug>

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
inline bool charIsLowerCase(const char character)
{
    return (character <= 'z') && (character >= 'a');
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
inline bool charIsUpperCase(const char character)
{
    return (character <= 'Z') && (character >= 'A');
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
inline bool charIsAlpha(const char character)
{
    return charIsLowerCase(character) || charIsUpperCase(character);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
inline unsigned int charToAlphaIndex(const char character)
{
    char result = character;

    if (charIsLowerCase(character))
    {
        result = character - 'a';
    }
    else if (charIsUpperCase(character))
    {
        result = character - 'A';
    }

    return result;
}

#endif // ALGORITHMSCOMMON_H
