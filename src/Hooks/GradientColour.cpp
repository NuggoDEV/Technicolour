#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"
#include "Controllers/GradientController.hpp"
using namespace Technicolour::Controllers;

#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

int bPos = 45, lPos = 0, rPos = 128, wPos = 90;

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);
    //int songTime = self->get_songTime();

    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "Gradient")
    {
      // Bomb Colour
      FastColor Bomb = GradientGen(bPos);
      Chroma::BombAPI::setGlobalBombColorSafe(Bomb);
      bPos++;
      if (bPos > 255)
        bPos =0;
    }
    
    if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Gradient")
    {
      // Left & Right Colour
      FastColor LeftColour = GradientGen(lPos);
      FastColor RightColour = GradientGen(rPos);

      Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);
      Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
      Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);
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
        FastColor Wall = GradientGen(wPos);
        FastColor wallColour;


        Chroma::ObstacleAPI::setAllObstacleColorSafe(wallColour);
        wPos++;
        if (wPos > 255)
          wPos = 0;
    }


}

