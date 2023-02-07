#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"
//#include "Controllers/GradientController.hpp"
//using namespace Technicolour::Controllers;

#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"


#include <array>
#include <unordered_map>

int bPos = 45, lPos = 0, rPos = 128, wPos = 90;

const int GRADIENT_STEPS = 256;

std::array<FastColor, GRADIENT_STEPS> gradientColours;
std::unordered_map<int, FastColor> gradientColourCache;


FastColor GradientGen(int index)
{
    auto cachedResult = gradientColourCache.find(index);
    if (cachedResult != gradientColourCache.end())
      return cachedResult->second;
    
    int gradientIndex = abs(index % 256 - 128);
    FastColor colour = FastColor(0.0f, (255 - gradientIndex * 3) / 255.0f, gradientIndex * 3 / 255.0f, 1.0f);

    gradientColourCache[index] = colour;
    
    return colour;
}

void generateGradientColours()
{
    for (int i = 0; i < GRADIENT_STEPS; ++i)
    {
        gradientColours[i] = GradientGen(i);
    }
}


MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
  GameplayCoreInstaller_InstallBindings(self);
  generateGradientColours();
}


MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
  AudioTimeSyncController_Update(self);
  // int songTime = self->get_songTime();

  if (getModConfig().ModToggle.GetValue() && getModConfig().TechniBombs.GetValue() == "Gradient")
  {
    // Bomb Colour
    FastColor Bomb = GradientGen(bPos);
    Chroma::BombAPI::setGlobalBombColorSafe(Bomb);
    bPos++;
    if (bPos > 255)
      bPos = 0;
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
