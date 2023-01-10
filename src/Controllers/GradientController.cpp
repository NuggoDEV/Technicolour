#include "Controllers/GradientController.hpp"
#include "sombrero/shared/ColorUtils.hpp"

Sombrero::FastColor Technicolour::Controllers::GradientGen(int ColourPos)
{
    static int c[3];
    static float a[3];
    Sombrero::FastColor OutputColour;

    if(ColourPos < 85) {
     c[0] = ColourPos * 3;
     c[1] = 255 - ColourPos * 3;
     c[2] =0;
    } else if(ColourPos < 170) {
     ColourPos -= 85;
     c[0] = 255 - ColourPos * 3;
     c[1] =0;
     c[2] = ColourPos * 3;
    } else {
     ColourPos -= 170;
     c[0] =0;
     c[1] = ColourPos * 3;
     c[2] =255 - ColourPos * 3;
    }

    a[0] = (float) c[0] / 255.0;
    a[1] = (float) c[1] / 255.0;
    a[2] = (float) c[2] / 255.0;

    OutputColour = Sombrero::FastColor(a[0], a[1], a[2], 1.0f);

    return OutputColour;
}