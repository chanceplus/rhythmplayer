#pragma once

// (for any u.s. personage, I only did 'colour' because it was specified in the docs)

enum EColourType
{
    Combo,
    SliderTrackOveride,
    SliderBorder
};

struct Colour
{
    EColourType ColourType;
    int ComboNum;
    int Red;
    int Green;
    int Blue;
    int Alpha;

    int getComboNum() const;
};