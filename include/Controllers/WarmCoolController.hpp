#pragma once

#include "sombrero/shared/FastColor.hpp"

namespace Technicolour::Controllers
{
    static Sombrero::FastColor WarmColourGen(int ColourPos);
    static Sombrero::FastColor CoolColourGen(int ColourPos);

    static bool WarmToggle;
    static bool CoolToggle;
}
