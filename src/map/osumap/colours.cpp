#include "colours.h"

#include <stdexcept>

int Colour::getComboNum() const
{
    if (ColourType == EColourType::Combo)
    {
        return ComboNum;
    }
    throw std::invalid_argument("EventType is not combo.");
}