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

float leftSaber = 0;
float rightSaber = 180;
float other = 90;

int bPos = 0, lPos = 0, rPos = 180, wPos = 0;


float * Wheel(int WheelPos) {
  static int c[3];
  static float epic[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  epic[0] = (float) c[0] / 255.0;
  epic[1] = (float) c[1] / 255.0;
  epic[2] = (float) c[2] / 255.0;
 
  return epic;
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);
    //int songTime = self->get_songTime();

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "Gradient")
    {
        // Bomb Colour
        float *Bomb = Wheel(bPos);
        FastColor bombColour;
        bombColour.a = 1.0;
        bombColour.r = Bomb[0];
        bombColour.g = Bomb[1];
        bombColour.b = Bomb[2];

        Chroma::BombAPI::setGlobalBombColorSafe(bombColour);
        bPos++;
        if (bPos > 255)
            bPos = 0;
    }
    

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Gradient")
    {
        // Left & Right Colour
        float *lNote = Wheel(lPos);
        FastColor leftColour;
        leftColour.a = 1.0;
        leftColour.r = lNote[0];
        leftColour.g = lNote[1];
        leftColour.b = lNote[2];

        float *rNote = Wheel(rPos);
        FastColor rightColour;
        rightColour.a = 1.0;
        rightColour.r = rNote[0];
        rightColour.g = rNote[1];
        rightColour.b = rNote[2];

        Chroma::NoteAPI::setGlobalNoteColorSafe(leftColour, rightColour);
        if (lPos > 255)
            lPos = 0;
        if (rPos > 255)
            rPos = 0;
    }


    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniWalls.GetValue() == "Gradient")
    {
        // Wall Colour
        float *Wall = Wheel(wPos);
        FastColor wallColour;
        wallColour.a = 1.0;
        wallColour.r = Wall[0];
        wallColour.g = Wall[1];
        wallColour.b = Wall[2];

        Chroma::ObstacleAPI::setAllObstacleColorSafe(wallColour);
        if (wPos > 255)
            wPos = 0;
    }


}