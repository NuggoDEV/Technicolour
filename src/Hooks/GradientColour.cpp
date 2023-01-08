#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"


#include "GlobalNamespace/AudioTimeSyncController.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Mathf.hpp"
#include "UnityEngine/WaitForSeconds.hpp"
#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include <cmath>

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

int bPos = 0, lPos = 0, rPos = 180, wPos = 0;

FastColor ColourGen(int ColourPos) {
  static int c[3];
  static float a[3];
  FastColor epic;

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


  epic = FastColor(a[0], a[1], a[2], 1.0f);

  return epic;
}


MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);
    //int songTime = self->get_songTime();

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "Gradient")
    {
      // Bomb Colour
      FastColor Bomb = ColourGen(bPos);
      Chroma::BombAPI::setGlobalBombColorSafe(Bomb);
      bPos++;
      if (bPos > 255)
        bPos =0;
    }
    
    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Gradient")
    {
      // Left & Right Colour
      FastColor LeftColour = ColourGen(lPos);
      FastColor RightColour = ColourGen(rPos);

      Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);
      lPos++;
      rPos++;
      if (lPos > 255)
        lPos = 0;
      if (rPos > 255)
        rPos = 0;
    }


    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniWalls.GetValue() == "Gradient")
    {
        // Wall Colour
        FastColor Wall = ColourGen(wPos);
        FastColor wallColour;


        Chroma::ObstacleAPI::setAllObstacleColorSafe(wallColour);
        wPos++;
        if (wPos > 255)
          wPos = 0;
    }


}

