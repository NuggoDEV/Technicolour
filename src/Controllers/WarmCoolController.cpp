#include "Controllers/WarmCoolController.hpp"
#include "sombrero/shared/ColorUtils.hpp"
using namespace Sombrero;

Sombrero::FastColor Technicolour::Controllers::WarmColourGen(int ColourPos)
{
    static int c[3];
    static float a[3];
    FastColor epic;

    if (WarmToggle)
    {
        if(ColourPos < 85) {
            c[0] = ColourPos * 3;
            c[1] = 255 - ColourPos * 3;
            c[2] = 0;
        } else if(ColourPos < 170) {
            ColourPos -= 85;
            c[0] = 255 - ColourPos * 3;
            c[1] = 0;
            c[2] = ColourPos * 3;
    } else {
      ColourPos -= 170;
      c[0] = 0;
      c[1] = ColourPos * 3;
      c[2] = 255 - ColourPos * 3;
    }

    if (ColourPos > 255)
      WarmToggle = false;
  } else if (!WarmToggle)
  {
      if(ColourPos > 85) {
      c[0] = ColourPos * 3;
      c[1] = 255 + ColourPos * 3;
      c[2] = 0;
    } else if(ColourPos > 170) {
      ColourPos += 85;
      c[0] = 255 + ColourPos * 3;
      c[1] = 0;
      c[2] = ColourPos * 3;
    } else {
      ColourPos += 170;
      c[0] = 0;
      c[1] = ColourPos * 3;
      c[2] = 255 + ColourPos * 3;
    }

    if (ColourPos < 151)
      WarmToggle = true;
  }

  a[0] = (float) c[0] / 255.0;
  a[1] = (float) c[1] / 255.0;
  a[2] = (float) c[2] / 255.0;

  epic = FastColor(a[0], a[1], a[2], 1.0f);

  return epic;
}


FastColor Technicolour::Controllers::WarmColourGen(int ColourPos)
{
    static int c[3];
    static float a[3];
    FastColor OutputColour;

    if (CoolToggle)
    {
      if(ColourPos < 85) {
        c[0] = ColourPos * 3;
        c[1] = 255 - ColourPos * 3;
        c[2] = 0;
      } else if(ColourPos < 170) {
        ColourPos -= 85;
        c[0] = 255 - ColourPos * 3;
        c[1] = 0;
        c[2] = ColourPos * 3;
      } else {
        ColourPos -= 170;
        c[0] = 0;
        c[1] = ColourPos * 3;
        c[2] = 255 - ColourPos * 3;
      }

      if (ColourPos > 255)
        WarmToggle = false;
    } else if (!WarmToggle)
    {
        if(ColourPos > 85) {
        c[0] = ColourPos * 3;
        c[1] = 255 + ColourPos * 3;
        c[2] = 0;
      } else if(ColourPos > 170) {
        ColourPos += 85;
        c[0] = 255 + ColourPos * 3;
        c[1] = 0;
        c[2] = ColourPos * 3;
      } else {
        ColourPos += 170;
        c[0] = 0;
        c[1] = ColourPos * 3;
        c[2] = 255 + ColourPos * 3;
      }

      if (ColourPos < 151)
        WarmToggle = true;
    }

    a[0] = (float) c[0] / 255.0;
    a[1] = (float) c[1] / 255.0;
    a[2] = (float) c[2] / 255.0;

    OutputColour = FastColor(a[0], a[1], a[2], 1.0f);

    return OutputColour;
}