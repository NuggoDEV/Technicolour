#pragma once

#include "UnityEngine/Color.hpp"
#include "sombrero/shared/ColorUtils.hpp"

#include <vector>

class GradientController
{
    private:
        Sombrero::FastColor gradientColour;
        Sombrero::FastColor gradientLeftColour;
        Sombrero::FastColor gradientRightColour;

        std::vector<Sombrero::FastColor> leftSaberPalette;
        std::vector<Sombrero::FastColor> rightSaberPalette;
}