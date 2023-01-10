#include "Controllers/RandomController.hpp"


#include "sombrero/shared/ColorUtils.hpp"
#include "sombrero/shared/FastColor.hpp"

#include <iostream>
#include <cstdlib>
#include <random>

Sombrero::FastColor Technicolour::Controllers::RandomColourGen()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    float hue = dis(gen);
    float saturation = 1.0f;
    float value = 1.0f;

    Sombrero::FastColor colour = Sombrero::FastColor::HSVToRGB(hue, saturation, value);
    return colour;   
}