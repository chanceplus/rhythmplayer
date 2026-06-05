#include "timingpoints.h"

#include <stdexcept>

/*
    TimingPoint BeatLength:
    x>=0 -> bpm
    x<=0 -> sv
*/
double TimingPoint::getBPM() const
{
    if (BeatLength >= 0)
    {
        return BeatLength / 60000.0; // ms -> bpm
    }
    throw std::invalid_argument("BeatLength is negative. Cannot convert to BPM.");
}

double TimingPoint::getSV() const
{
    if (BeatLength < 0)
    {
        return -100.0 / BeatLength; // ms -> multiplier
    }
    throw std::invalid_argument("BeatLength is positive or 0. Cannot convert to SV.");
}

/*
    TimingPoint Effects:
    0th bit -> kiai enabled
    3rd bit -> first barline omitted
*/
bool TimingPoint::isKiaiEnabled() const
{
    return 1 & Effects == 1; // 0th bit on = 1
}

bool TimingPoint::isFirstBarlineOmitted() const
{
    return 8 & Effects == 8; // 3rd bit on = 8
}